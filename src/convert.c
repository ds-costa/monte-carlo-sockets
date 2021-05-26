#include "convert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

/**
 * function: conv_ulong_2_string
 * Converts a usingned long number into a char array
 * @param number, Holds the quantity of number 
 * @param buffer, Vector that will receive the convertion  
 */
void conv_ulong_2_string(unsigned long number, char* buffer) {
    sprintf(buffer, "%lu", number);
}

/**
 * function: conv_string_2_ulong
 * Converts a char array into a unsigned long number 
 * @param buffer, char array
 */
unsigned long conv_string_2_ulong(char* buffer) {
    unsigned long number;
    number = strtod(buffer, NULL);
    
    return number;
}

/**
 * function: conv_double_2_string
 * Converts the double number into a vector of char
 * @param buffer, Vector that will receive the convertion
 */
void conv_double_2_string(double number, char* buffer) {
    sprintf(buffer, "%.10lf", number);
}

/**
 * function: conv_string_2_double
 * Returns the convertion of a vector of char into double
 * @param buffer, Vector char that contains the double number
 */
double conv_string_2_double(char* buffer) {
    double number;
    number = strtod(buffer, NULL);

    return number;
}
