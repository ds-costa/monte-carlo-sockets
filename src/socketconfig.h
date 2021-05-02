#ifndef SOCKET_CONFIG
#define SOCKET_CONFIG

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