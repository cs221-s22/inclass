#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    struct addrinfo *addr;
    int result = getaddrinfo(argv[1], NULL, NULL, &addr);
    if (result) {
        printf("getaddrinfo: %s\n", gai_strerror(result));
        return -1;
    }

    struct sockaddr_in* internet_addr = (struct sockaddr_in*) addr->ai_addr;
    printf("%s is at: %s\n", argv[1], inet_ntoa(internet_addr->sin_addr));
    return 0;
}
