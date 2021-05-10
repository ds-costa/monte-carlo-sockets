#include "convert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

void conv_ulong_2_string(unsigned long number, char* buffer) {
    sprintf(buffer, "%lu", number);
}

unsigned long conv_string_2_ulong(char* buffer) {
    unsigned long number;
    number = strtod(buffer, NULL);
    
    return number;
}

void conv_double_2_string(double number, char* buffer) {
    sprintf(buffer, "%.10lf", number);
}

double conv_string_2_double(char* buffer) {
    double number;
    number = strtod(buffer, NULL);

    return number;
}
