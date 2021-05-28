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
#include "src/convert.h"


int main(int argc, char **argv) {
    
    srand(SEED);
    
    // Time values
    timespec start = {0, 0};
    timespec end = {0, 0};
    uint64_t start_ns = 0;
    uint64_t end_ns = 0;
    int64_t elapsed_time = 0;
    // 
    int n = (int) conv_string_2_ulong(argv[1]);  
    // scanf("%d", &n);
    
    unsigned long total_points = pow(10, n);
    clock_gettime(CLOCK_MONOTONIC, &start);

    double pi = monte_carlo_pi(total_points);

    clock_gettime(CLOCK_MONOTONIC, &end);

    start_ns = exectime_timespec_to_nanosconds(start);
    end_ns = exectime_timespec_to_nanosconds(end);
    elapsed_time = end_ns - start_ns;

    fflush(stdout);
    char out[1000];
    conv_ulong_2_string(elapsed_time, out);
    FILE *fp = fopen("time_out.txt", "a");
    FILE *fp2 = fopen("pi_out.txt", "a");
    fprintf(fp, "%s\n", out);
    fprintf(fp2, "%.10lf\n", pi);
    fclose(fp);
    fclose(fp2);


    return 0;
}