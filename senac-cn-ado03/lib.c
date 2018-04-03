#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"


void calculateEuler(int x){

    FILE *gnu = popen("gnuplot -persistent", "w");

    fprintf(gnu, "set terminal png\n");
    fprintf(gnu, "set output 'FloatEuler.png'\n");
    fprintf(gnu, "set logscale x\n");
    fprintf(gnu, "set yrange [0:4]\n");
    fprintf(gnu, "set title 'Euler Approximation with Float'\n");

    fprintf(gnu, "plot '-' w l\n");

    if (x == 0){

        float i;
        float result;
        for (i = 1; i <= 10e20; i *= 10){
            result = powf((1 + 1/i), i);
            fprintf(gnu, "%g %f\n", i, result);
            
        }

    }

    else if (x == 1){

        long double i;
        long double result;
        for (i = 1; i <= 10e20; i *= 10){
            result = powl((1 + 1/i), i);
            fprintf(gnu, "%Lg %Lf\n", i, result);
            
        }

    }

    else if (x == 2){

        double i;
        double result;
        for (i = 1; i <= 10e20; i *= 10){
            result = pow((1 + 1/i), i);
            fprintf(gnu, "%g %f\n", i, result);
            
        }

    }

    fprintf(gnu, "e");

    fclose(gnu);
}


