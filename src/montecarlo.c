#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "montecarlo.h"

/**
 * function: monte_carlo_pi
 * Monte Carlo PI computation method implementation
 * @param total_points, Number of random points to be generated
 */
double monte_carlo_pi(unsigned long total_points) {
    
    unsigned long points_inside_circle = 0;
    unsigned long i;
    double x, y;

    for(i = 0; i < total_points; i++) {
        x = RANDOM_DOUBLE(0, 1);
        y = RANDOM_DOUBLE(0, 1);

        if((x * x) + (y * y) <= 1.0) {
            points_inside_circle++;
        }
    }

    return 4.0 * ((double) points_inside_circle / (double) total_points);
}