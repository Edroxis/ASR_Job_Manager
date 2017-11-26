// source: https://cygwin.com/ml/cygwin/2000-08/msg00784.html

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int         sockfd;
    int         len;
    sockaddr_un address;
    int         result;
    char        ch       = 'A';

    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

    address.sun_family = AF_UNIX;
    strcpy(address.sun_path, "server_socket");
    len = sizeof(address);

    result = connect(sockfd, (sockaddr*)&address, len);

    if(result == -1)
    {
        perror("oops:  client1");
        return 1;
    }

    write(sockfd, &ch, 1);
    read(sockfd, &ch, 1);
    printf("char from server = %c\n", ch);
    close(sockfd);
    return 0;
}
