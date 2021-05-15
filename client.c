#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "src/socketconfig.h"
#include"src/convert.h"


int main(int argc, char **argv) {

    socketdata_t client_socket;
    char buffer[1024];

    client_socket = sc_new_socket_data_client();

    sc_establish_client_connection(&client_socket);
    recv(client_socket.file_descriptor,buffer,1024,0);

    close(client_socket.file_descriptor);
    return 0;
}