#include "socketconfig.h"



/**
 * function: sc_new_socket_client
 * Return a socket address (IPV4, PORT, INADDR_ANY)
 */
struct sockaddr_in sc_new_socket_adress_server() {
    struct sockaddr_in server_addr;

    server_addr.sin_family = IPV4;
    server_addr.sin_port = htons(PORT); // host-endian to network-endian
    server_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(server_addr.sin_zero),8);

    return server_addr;
}

/**
 * function: sc_new_socket_adress_client
 * Return a socket address (IPV4, PORT, HOME_IP)
 */
struct sockaddr_in sc_new_socket_adress_client() {
    struct sockaddr_in server_addr;

    server_addr.sin_family = IPV4;
    server_addr.sin_port = htons(PORT); // host-endian to network-endian
    server_addr.sin_addr.s_addr = inet_addr(HOME_IP);
    bzero(&(server_addr.sin_zero),8);

    return server_addr;
}

/**
 * function: sc_new_socket_data_server
 * Create a socketdata_t ADT with the default socket configuration (IPV4, Port 5000)
 */
socketdata_t sc_new_socket_data_server(){
    socketdata_t sock;
    
    sock.file_descriptor = -1;
    sock.option_name = true;
    sock.address = sc_new_socket_adress_server();

    return sock;
}

/**
 * function: sc_new_socket_data_client
 * Create a socketdata_t ADT with the default socket configuration (IPV4, Port 5000)
 */
socketdata_t sc_new_socket_data_client(){
    socketdata_t sock;
    
    sock.file_descriptor = -1;
    sock.option_name = true;
    sock.address = sc_new_socket_adress_client();

    return sock;
}


/**
 * function: sc_activate_listener_mode
 * Creates, set the option, bind, define listen quenue lenght of listener socket
 * @param sock, Socket struct with all information 
 */
int sc_activate_listener_mode(socketdata_t* sock) {
    
    // int socket_file_descriptor;
    // socket_file_descriptor = socket(IPV4, TCP, 0);
    sock->file_descriptor = socket(IPV4, TCP, 0);

    if(sock->file_descriptor == -1) {
        perror("[-] Server> Error creating Socket\n");
        exit(1);
    }

    if(setsockopt(sock->file_descriptor, SOL_SOCKET, SO_REUSEADDR, &(sock->option_name), sizeof(sock->option_name)) == -1){
        perror("[-]Error in Setsockopt\n");
        exit(1);
    }

    if(bind(sock->file_descriptor, (struct sockaddr *) &(sock->address), sizeof(struct sockaddr))){
        perror("[-]It was not possible to bind\n");
        exit(1);
    }

    if (listen(sock->file_descriptor, LISTEN_QUENUE_LENGTH) == -1) {
        perror("[-]Error defining input queue size\n");
        exit(1);
    }

    printf("\n[+]TCP Server created! Waiting client at port: %d\n", PORT);
    return sock->file_descriptor;
}

/**
 * function: sc_establish_client_connection
 * @param sock, Socket struct with all information 
 */
int sc_establish_client_connection(socketdata_t *sock) {

    sock->file_descriptor = socket(IPV4, TCP, 0);

    if(sock->file_descriptor == -1) {
        perror("[-] Client> Error creating Socket\n");
        exit(1);
    }

    // Converte ipv4 e ipv6 para forma binária 
    if(inet_pton(AF_INET, HOME_IP, &sock->address.sin_addr) <= 0)   { 
        fprintf(stderr,"invalid adress"); 
        exit(EXIT_FAILURE); 
    } 
   
    if (connect(sock->file_descriptor, (struct sockaddr *)&sock->address, sizeof(sock->address)) < 0) { 
        fprintf(stderr,"Conection failed");
        exit(EXIT_FAILURE);     
    }

    return sock->file_descriptor;
}