#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "src/socketconfig.h"

int main(int argc, char **argv) {
 
    socketdata_t server_socket;    
    server_socket = sc_new_socket_data();
    sc_activate_listener_mode(&server_socket);
    
    return 0;
}