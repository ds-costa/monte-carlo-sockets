#include "convert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

void conv_points_2_string(unsigned long points, char* buffer) {
    sprintf(buffer, "%lu", points);
}

unsigned long conv_string_2_points(char* buffer) {
    unsigned long points;
    points = strtod(buffer, NULL);
    
    return points;
}

void conv_double_2_string(double number, char* buffer) {
    sprintf(buffer, "%.10lf", number);
}

double conv_double_2_pi(char* buffer) {
    double pi;
    pi = strtod(buffer, NULL);

    return pi;
}
