#include "data.h"
#include <string.h>

/**
 * function: data_receive
 * Fetch data from a file descriptor to a buffer
 * @param file_descriptor, Socket struct with all information 
 * @param buffer 
 */
int data_receive(int file_descriptor, char *buffer) {
    int bytes_recv;
    bytes_recv = recv(file_descriptor, buffer, MAX_BUFFER_LENGTH, 0);
    buffer[bytes_recv] = '\0';
    return bytes_recv;
}

/**
 * function: data_send
 * Send data from a buffer to a file descriptor
 * @param file_descriptor, Socket struct with all information 
 * @param buffer
 */
int data_send(int file_descriptor, char *buffer) {
    send(file_descriptor, buffer, strlen(buffer), 0);    
    return 0;
}