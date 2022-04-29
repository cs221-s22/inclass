#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
    struct addrinfo hints;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    struct addrinfo *res;
    int rc = getaddrinfo(argv[1], argv[2], &hints, &res);
    if (rc != 0)
        printf("%s\n", gai_strerror(rc));
    int fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    if (connect(fd, res->ai_addr, res->ai_addrlen) != 0)
        perror("connect");

    char *msg = "test";
    int len = strlen(msg) + 1;
    if (send(fd, msg, len, 0) == -1)
        perror("send");

    if (close(fd) == -1)
        perror("close");

    return 0;
}
