/**
 * Authors: David Costa, Murilo Carvalho {ds.costa, murilo.ignacio}@unesp.br
 * Description: Standalone program to compute PI using Monte Carlo method.
 * MIT License 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Random numbers seed
#define SEED time(NULL)

// Return a random number in [lo, hi] interval (inclusive)
#define RANDOM_DOUBLE(lo, hi) lo + ((double) rand() / (double) (RAND_MAX) * (hi - lo))

/**
 * function: monte_carlo_pi
 * Monte Carlo PI computation method implementation
 * @param total_points, Number of random points to be generated
 */
double monte_carlo_pi(unsigned long total_points);

int main(int argc, char **argv) {
    
    srand(SEED);
    printf("== Standalone Implementation ==\n");
    
    unsigned long total_points = (argc > 1) ? atoi(argv[1]) : 0;
    double pi = monte_carlo_pi(total_points);

    printf("monte_carlo> Aproximation: %.10lf\n", pi);
    printf("monte_carlo> Error: %g\n", fabs(M_PI - pi));

    return 0;
}

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