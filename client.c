#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "src/socketconfig.h"
#include "src/convert.h"
#include "src/data.h"

int main(int argc, char **argv) {

    socketdata_t client_socket;
    char buffer[MAX_BUFFER_LENGTH];

    client_socket = sc_new_socket_data_client();

    sc_establish_client_connection(&client_socket);

    data_receive(client_socket.file_descriptor, buffer);

    printf("client(%d)> %s\n", client_socket.file_descriptor, buffer);

    close(client_socket.file_descriptor);
    return 0;
}