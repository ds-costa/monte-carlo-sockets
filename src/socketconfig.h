#ifndef SOCKET_CONFIG
#define SOCKET_CONFIG

#include <sys/socket.h> 
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h> 
#include <netinet/in.h>
#include <arpa/inet.h> 
#include <strings.h>
#include <errno.h>

#define IPV4 AF_INET
#define TCP SOCK_STREAM
#define LISTEN_QUENUE_LENGTH 16
#define PORT 5000

#define MAX_CLIENTS 16

#define MAX_BUFFER_LENGTH 1024 // 1kb
#define HOME_IP "127.0.0.1"

typedef struct {
    //[!] need to add structure to keep following the client 
    struct sockaddr_in address;
    int file_descriptor;
    int address_size;
    int option_name;
} socketdata_t;

/**
 * function: sc_new_socket_adress
 * Return a socket address (IPV4, PORT, INADDR_ANY)
 */
struct sockaddr_in sc_new_socket_adress();

/**
 * function: sc_new_socket_data
 * Create a socket with the default configuration
 */
socketdata_t sc_new_socket_data();

/**
 * function: sc_activate_listener_mode
 * Creates, set the option, bind, define listen quenue lenght of listener socket
 * @param sock, Socket struct with all information 
 */
int sc_activate_listener_mode(socketdata_t* sock);


/**
 * function: sc_establish_client_connection
 * @param sock, Socket struct with all information 
 */
int sc_establish_client_connection(socketdata_t *sock);


#endif