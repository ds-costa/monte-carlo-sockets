#ifndef DATA_H
#define DATA_H

#include "socketconfig.h"

int data_receive(int file_descriptor, char *buffer);
int data_send(int file_descriptor, char *buffer);


#endif