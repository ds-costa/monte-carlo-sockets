/**
 * Authors: David Costa, Murilo Carvalho {ds.costa, murilo.ignacio}@unesp.br
 * Description: Standalone program to compute PI using Monte Carlo method.
 * MIT License 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "src/montecarlo.h"
#include "src/exectime.h"


int main(int argc, char **argv) {
    
    srand(SEED);
    
    // Time values
    bool is_measuring_time = (argc > 1 && strcmp(argv[1], "--exectime") == 0);
    timespec start = {0, 0};
    timespec end = {0, 0};
    uint64_t start_ns = 0;
    uint64_t end_ns = 0;
    int64_t elapsed_time = 0;
    // 
    int n;
    printf("== Standalone Implementation ==\n");
    printf("Number of points(3 <= n <= 10): 10^");
    scanf("%d", &n);

    
    unsigned long total_points = pow(10, n);
    if(is_measuring_time == true) {
        clock_gettime(CLOCK_MONOTONIC, &start);
    }

    double pi = monte_carlo_pi(total_points);

    if(is_measuring_time == true) {
        clock_gettime(CLOCK_MONOTONIC, &end);

        start_ns = exectime_timespec_to_nanosconds(start);
        end_ns = exectime_timespec_to_nanosconds(end);
        elapsed_time = end_ns - start_ns;
    
        printf("monte_carlo> start: %luns\n", start_ns);
        printf("monte_carlo> end: %luns\n", end_ns);
        printf("monte_carlo> elapsed_time: %ldns\n", elapsed_time);
    }


    printf("monte_carlo> Aproximation: %.10lf\n", pi);
    printf("monte_carlo> Error: %g\n", fabs(M_PI - pi));

    return 0;
}