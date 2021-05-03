#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "src/socketconfig.h"

int main(int argc, char **argv) {
 
    socketdata_t server_socket;    
    server_socket = scof_create_default_connection_type();
    scof_activate_listener_mode(&server_socket);
    
    return 0;
}