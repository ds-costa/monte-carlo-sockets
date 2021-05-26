#ifndef EXECTIME_H
#define EXECTIME_H

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct timespec timespec;

#define exectime_timespec_to_nanosconds(time_) (time_.tv_sec * 1000000000) + time_.tv_nsec

#endif