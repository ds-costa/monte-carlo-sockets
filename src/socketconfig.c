#include "socketconfig.h"

#define IPV4 AF_INET
#define TCP SOCK_STREAM
#define LISTEN_QUENUE_LENGTH 16
#define PORT 5000

#define MAX_CLIENTS 16

#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <sys/socket.h> 
#include <netinet/in.h>
#include <strings.h>
#include <errno.h>


/**
 * function: scof_get_address_host
 * Return a socket address (IPV4, PORT, INADDR_ANY)
 */
struct sockaddr_in scof_get_address_host() {
    struct sockaddr_in server_addr;

    server_addr.sin_family = IPV4;
    server_addr.sin_port = htons(PORT); // host-endian to network-endian
    server_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(server_addr.sin_zero),8);

    return server_addr;
}

/**
 * function: scof_create_default_connection_type
 * Create a socket with the default configuration
 */
socketdata_t scof_create_default_connection_type(){
    socketdata_t sock;
    
    sock.file_descriptor = -1;
    sock.option_name = true;
    sock.address = scof_get_address_host();

    return sock;
}

/**
 * function: scof_activate_listener_mode
 * Creates, set the option, bind, define listen quenue lenght of listener socket
 * @param sock, Socket struct with all information 
 */
int scof_activate_listener_mode(socketdata_t* sock) {
    int socket_file_descriptor;

    socket_file_descriptor = socket(IPV4, TCP, 0);
    
    if(socket_file_descriptor == -1) {
        perror("[-]Error creating Socket\n");
        exit(1);
    }

    if(setsockopt(socket_file_descriptor, SOL_SOCKET, SO_REUSEADDR, &(sock->option_name), sizeof(sock->option_name)) == -1){
        perror("[-]Error in Setsockopt\n");
        exit(1);
    }

    if(bind(socket_file_descriptor, (struct sockaddr *) &(sock->address), sizeof(struct sockaddr))){
        perror("[-]It was not possible to bind\n");
        exit(1);
    }

    if (listen(socket_file_descriptor, LISTEN_QUENUE_LENGTH) == -1) {
        perror("[-]Error defining input queue size\n");
        exit(1);
    }

    printf("\n[+]TCP Server created! Waiting client at port: %d\n", PORT);
    return socket_file_descriptor;
}