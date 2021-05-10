/**
 * Authors: David Costa, Murilo Carvalho {ds.costa, murilo.ignacio}@unesp.br
 * Description: Standalone program to compute PI using Monte Carlo method.
 * MIT License 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "src/montecarlo.h"


int main(int argc, char **argv) {
    
    srand(SEED);
    printf("== Standalone Implementation ==\n");
    
    unsigned long total_points = (argc > 1) ? atoi(argv[1]) : 0;
    double pi = monte_carlo_pi(total_points);

    printf("monte_carlo> Aproximation: %.10lf\n", pi);
    printf("monte_carlo> Error: %g\n", fabs(M_PI - pi));

    return 0;
}