#ifndef SOCKET_CONFIG
#define SOCKET_CONFIG

#define IPV4 AF_INET
#define TCP SOCK_STREAM
#define LISTEN_QUENUE_LENGTH 16

#define MAX_CLIENTS 16

#include <stdbool.h>
#include <sys/socket.h> 
#include <netinet/in.h>

typedef struct {
    struct sockaddr_in address;
    int file_descriptor;
    int address_size;
    bool option_name;
} socketdata_t;

#endif