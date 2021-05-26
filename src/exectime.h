#ifndef EXECTIME_H
#define EXECTIME_H

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct timespec timespec;

/**
 * macro: exectime_timespec_to_nanosconds
 * Convert a timespec struct value to nanoseconds
 * @param time_, timespect struct
 */
#define exectime_timespec_to_nanosconds(time_) (time_.tv_sec * 1000000000) + time_.tv_nsec

#endif