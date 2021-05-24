#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "src/socketconfig.h"
#include "src/convert.h"
#include "src/data.h"
#include "src/montecarlo.h"

int main(int argc, char **argv) {
    socketdata_t client_socket;
    char buffer[MAX_BUFFER_LENGTH];
    double pi;

    client_socket = sc_new_socket_data_client();
    sc_establish_client_connection(&client_socket);

    srand(SEED + client_socket.file_descriptor * 100000); //making each client have different seeds
    data_receive(client_socket.file_descriptor, buffer);

    printf("client(%d)> %s\n", client_socket.file_descriptor, buffer);
    
    //monte carlo
    //conv_double_2_string(pi, buffer);
    pi = monte_carlo_pi(conv_string_2_double(buffer));
    conv_double_2_string(pi, buffer);

    data_send(client_socket.file_descriptor, buffer);

    close(client_socket.file_descriptor);
    return 0;
}