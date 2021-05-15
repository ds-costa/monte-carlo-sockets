#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "src/socketconfig.h"
#include "src/convert.h"

int main(int argc, char **argv) {
 
    socketdata_t server_socket;    
    int number_of_clients = 2;
    int i;
    unsigned long number_points = 5000000000;
    //read(n_clients)
    
    int clients[number_of_clients];
    pipe_t clients_pipes[number_of_clients];

    server_socket = sc_new_socket_data_server();
    sc_activate_listener_mode(&server_socket);
    

    for(i = 0; i < number_of_clients; i++) {
        system("./client &");
        clients[i] = accept(
            server_socket.file_descriptor, 
            (struct sockaddr *)&server_socket.address, 
            (socklen_t *)sizeof(server_socket.address)
        );
        pipe(clients_pipes[i]);

        printf("[+]Receiving connection (Client: %s , Port: %d)\n", inet_ntoa(server_socket.address.sin_addr), ntohs(server_socket.address.sin_port));
    }
    //conectado
    //lê/tem que ter number_points
    
    for(i = 0; i < number_of_clients; i++) {
    
    }
    // unsigned int child_process_counter = 0;
    // pid_t child_pid;

    // while(true) {
    //     child_pid = fork();
    //     if(child_pid < 0) {
    //         perror("[-]Fork error\n");
    //         return 0;
    //     }
    //     else if(child_pid == 0) {
    //         //Handle tcp
    //         printf("[+]Handle TCP client\n");
    //         exit(0);
    //     }
    // }


    return 0;
}