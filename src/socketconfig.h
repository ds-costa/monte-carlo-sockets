#ifndef SOCKET_CONFIG
#define SOCKET_CONFIG

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

typedef struct {
    //[!] ainda precisa adicionar informação para ter controle de x clientes
    //[!] no código do thiago leal fica na struct SocketSet
    //[!] não adicionei pq a gente pode fazer diferente
    struct sockaddr_in address;
    int file_descriptor;
    int address_size;
    int option_name;
} socketdata_t;

/**
 * function: scof_get_address_host
 * Writes to the array the (int) content read in the stdin
 */
struct sockaddr_in scof_get_address_host();

/**
 * function: scof_create_default_connection_type
 * Writes to the array the (int) content read in the stdin
 */
socketdata_t scof_create_default_connection_type();

/**
 * function: scof_activate_listener_mode
 * Creates, set the option, bind, define listen quenue lenght of listener socket
 * @param sock, Socket struct with all information 
 */
int scof_activate_listener_mode(socketdata_t* sock);

#endif