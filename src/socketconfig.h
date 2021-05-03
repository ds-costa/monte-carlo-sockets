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
 * function: scof_get_address_host
 * Return a socket address (IPV4, PORT, INADDR_ANY)
 */
struct sockaddr_in scof_get_address_host();

/**
 * function: scof_create_default_connection_type
 * Create a socket with the default configuration
 */
socketdata_t scof_create_default_connection_type();

/**
 * function: scof_activate_listener_mode
 * Creates, set the option, bind, define listen quenue lenght of listener socket
 * @param sock, Socket struct with all information 
 */
int scof_activate_listener_mode(socketdata_t* sock);

#endif