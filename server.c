#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "src/socketconfig.h"

int main(int argc, char **argv) {
    //socketdata_t sock;

    //sock = scof_create_default_connection_type();
    scof_activate_listener_mode(&sock);
    
    printf("Hello Server...\n");
    return 0;
}