#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "src/socketconfig.h"
#include"src/convert.h"

int main(int argc, char **argv) {
 
    socketdata_t server_socket;    
    server_socket = sc_new_socket_data_server();
    sc_activate_listener_mode(&server_socket);
    
    int client_fd;

    while(true) {

        client_fd = accept(
            server_socket.file_descriptor, 
            (struct sockaddr *)&server_socket.address, 
            (socklen_t *)sizeof(server_socket.address)
        );
        
        printf("\nReceiving connection (Client: %s , Port: %d)\n", inet_ntoa(server_socket.address.sin_addr), ntohs(server_socket.address.sin_port));

    }


    return 0;
}