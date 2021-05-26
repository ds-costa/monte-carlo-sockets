#ifndef DATA_H
#define DATA_H

#include "socketconfig.h"

/**
 * function: data_receive
 * Fetch data from a file descriptor to a buffer
 * @param file_descriptor, Socket struct with all information 
 * @param buffer 
 */
int data_receive(int file_descriptor, char *buffer);

/**
 * function: data_send
 * Send data from buffer to a file descriptor
 * @param file_descriptor, Socket struct with all information 
 * @param buffer
 */
int data_send(int file_descriptor, char *buffer);


#endif