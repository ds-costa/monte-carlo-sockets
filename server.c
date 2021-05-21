#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "src/socketconfig.h"
#include "src/convert.h"
#include "src/data.h"

void handle_tcp_connection(unsigned long number_points, char* buffer, int file_descriptor) { 
    printf("[+]Handle TCP client\n");
    
    conv_ulong_2_string(number_points, buffer);

    data_send(file_descriptor, buffer);
    data_receive(file_descriptor, buffer);
}

double wait_and_sum_clients_results(int number_of_clients, pipe_t* clients_pipes, char* buffer) {
    double sum;
    int i;

    for(i = 0; i < number_of_clients; i++) {
        read(clients_pipes[i][0], buffer, sizeof(buffer)); //wait and read clients' result
        printf("%lf\n", conv_string_2_double(buffer));
        sum += conv_string_2_double(buffer); 
    }
    return sum;
}

void close_all_tcp_handlers(int number_of_clients, int (*clients)[number_of_clients]) {
    int i;

    for(i = 0; i < number_of_clients; i++) { //close all sockets tcp handlers
        close(*(clients[i]));
    }
}

void close_read_mode_pipes(int number_of_clients, pipe_t (*clients_pipes)[2]) {
    int i;

    for(i = 0; i < number_of_clients; i++) { //close all pipes
        close(*(clients_pipes[i][0]));
    }
}

void initilize_and_connect_clients(socketdata_t* server_socket, int number_of_clients, int *clients, pipe_t* clients_pipes) {
    int i;
    struct sockaddr_in newAddr;
    socklen_t addr_size = sizeof(newAddr);  

    for(i = 0; i < number_of_clients; i++) {
        system("./client &");
        
        clients[i] = accept(
            server_socket->file_descriptor, 
            (struct sockaddr *)&newAddr, 
            &addr_size 
        );
        pipe(clients_pipes[i]);

        printf("[+]Receiving connection (Client: %s , Port: %d)\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
    }
}

int main(int argc, char **argv) {
 
    socketdata_t server_socket;      
    
    int number_of_clients = 4;
    unsigned long number_points = 1000000;

    int clients[number_of_clients];
    pipe_t clients_pipes[number_of_clients];

    //aux variables
    int i;
    double sum = 0.0;
    
    char buffer[1014];

    pid_t child_pid;

    server_socket = sc_new_socket_data_server();
    sc_activate_listener_mode(&server_socket);
    
    initilize_and_connect_clients(&server_socket, number_of_clients, clients, clients_pipes);

    for(i = 0; i < number_of_clients; i++) {
        if((child_pid = fork()) < 0) {
            perror("[-]Fork error\n");
        }
        else if(child_pid != 0) { //parent
            close(clients_pipes[i][1]); //read only
        }
        else { //child
            close(clients_pipes[i][0]); //writing only
            handle_tcp_connection(number_points, buffer, clients[i]);
            
            write(clients_pipes[i][1], &buffer, strlen(buffer)+1); //writes client's result in pipe
            close(clients_pipes[i][1]);
            exit(0);
        }
    }

    sum = wait_and_sum_clients_results(number_of_clients, clients_pipes, buffer);
    sum /= number_of_clients;

    printf("\nPI: %.10lf\n", sum);
    
    close_all_tcp_handlers(number_of_clients, &clients);
    close_read_mode_pipes(number_of_clients, &clients_pipes);

    close(server_socket.file_descriptor); //close parent server process
    
    return 0;
}