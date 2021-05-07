#ifndef SOCKET_CONFIG
#define SOCKET_CONFIG

#include <sys/socket.h> 
#include <netinet/in.h>

#define IPV4 AF_INET
#define TCP SOCK_STREAM
#define LISTEN_QUENUE_LENGTH 16
#define PORT 5000

#define MAX_CLIENTS 16

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

#endif