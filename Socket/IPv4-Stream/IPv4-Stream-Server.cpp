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
    int connfd = -1;
    int listenfd = -1;
    struct sockaddr_in client_addr, server_addr;
    char send_buffer[1024];

    memset(send_buffer, 0, sizeof(send_buffer));
    memset(&client_addr, 0, sizeof(client_addr));

    sprintf(send_buffer, "Hello World");

    /* Setup a socket */
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1){
        cout << "Error line 28 " <<endl;
    }
    /* Config for Address Structure */
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(LOCAL_PORT);

    /* Bind the connection to socket*/
    if(bind(listenfd, (struct sockaddr*)&server_addr, sizeof(server_addr))== - 1){
        cout << "Error binding " <<endl;
    }
    if(listen(listenfd, 10) == -1)
    {
        cout << "Error listening " <<endl;
    }
    /* Setup the connect */
    
    cout << "Server is listening" << endl;
    connfd = accept(listenfd, (struct sockaddr*)&client_addr, (socklen_t*)sizeof(client_addr));
    if (connfd == -1){
        cout << "Error width code " << connfd << endl;
    }
    else{
        cout << "Server : got connection" << endl;
        write(connfd, send_buffer, (sizeof(send_buffer)));
        cout << "Sended " << send_buffer << endl;
    }

    close(connfd);
    close(listenfd);
    
    return 0;
}