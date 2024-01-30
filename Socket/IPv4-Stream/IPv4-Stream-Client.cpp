#include <iostream>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

using namespace std;
#define LOCAL_IP "127.0.0.1"
#define LOCAL_PORT 2234

int main(){
    int sockfd = -1;
    struct sockaddr_in server_addr;
    char recv_buffer[1024];

    memset(recv_buffer, 0, sizeof(recv_buffer));
    memset(&server_addr, 0, sizeof(server_addr));

    /* Setup a socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    /* Config for Address Structure */
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(LOCAL_IP);
    server_addr.sin_port = htons(LOCAL_PORT);

    /* Bind the connection to socket*/
    bind(sockfd, (struct sockaddr*)(&server_addr), sizeof(server_addr));
    /* Setup the connect */
    if(connect(sockfd, (struct sockaddr*)(&server_addr), sizeof(server_addr)) == 0 ){
        read(sockfd, recv_buffer, sizeof(recv_buffer));
        cout << "Received: "<< recv_buffer << endl;
        close(sockfd);
    }
    
    return 0;
}