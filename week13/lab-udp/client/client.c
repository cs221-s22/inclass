#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 500

int main(int argc, char *argv[])
{
    if (argc < 3) {
        fprintf(stderr, "Usage: %s host port msg...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get address(es) matching given host/port 
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;    // Allow IPv4 or IPv6
    hints.ai_socktype = SOCK_DGRAM; // Datagram socket
    hints.ai_flags = 0;
    hints.ai_protocol = 0;          // Any protocol

    struct addrinfo *result, *rp;
    int s = getaddrinfo(argv[1], argv[2], &hints, &result);
    if (s != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
    }

    /* getaddrinfo() returns a list of address structures.
      Try each address until we successfully connect().
      If socket() or connect() fails, close the socket
      and try the next address. 
    */

    int sfd;
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sfd == -1)
            continue;

        if (connect(sfd, rp->ai_addr, rp->ai_addrlen) != -1)
            break;  // Success 

        close(sfd);
    }

    freeaddrinfo(result);  // No longer needed

    if (rp == NULL) {  // No address succeeded
        fprintf(stderr, "Could not connect\n");
        exit(EXIT_FAILURE);
    }

    /* Send remaining command-line arguments as separate
       datagrams, and read responses from server
     */
    size_t len;
    ssize_t nread;
    char buf[BUF_SIZE];
    for (int j = 3; j < argc; j++) {
        len = strlen(argv[j]) + 1;  // +1 for terminating null byte 

        if (len > BUF_SIZE) {
            fprintf(stderr, "Ignoring long message in argument %d\n", j);
            continue;
        }

        if (write(sfd, argv[j], len) != (ssize_t) len) {
            fprintf(stderr, "partial/failed write\n");
            exit(EXIT_FAILURE);
        }

        nread = read(sfd, buf, BUF_SIZE);
        if (nread == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("Received %zd bytes from server: %s\n", nread, buf);
    }

    close(sfd);
    exit(EXIT_SUCCESS);
}
