#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"



void calculateEuler(int x, char * nomeArquivo){

    FILE *gnu = popen("gnuplot -persistent", "w");

    fprintf(gnu, "set terminal png\n");
    fprintf(gnu, "set output '%s'\n", nomeArquivo);
    fprintf(gnu, "set logscale x\n");
    fprintf(gnu, "set yrange [0:4]\n");
    

    if (x == 0){
        fprintf(gnu, "Float Euler'\n");

        fprintf(gnu, "plot '-' w l\n");

        float i;
        float result;
        for (i = 1; i <= 10e20; i *= 10){
            result = powf((1 + 1/i), i);
            fprintf(gnu, "%g %f\n", i, result);
            
        }

    }

    else if (x == 1){
        fprintf(gnu, "set title 'Long Double Euler'\n");

        fprintf(gnu, "plot '-' w l\n");

        long double i;
        long double result;
        for (i = 1; i <= 10e20; i *= 10){
            result = powl((1 + 1/i), i);
            fprintf(gnu, "%Lg %Lf\n", i, result);
            
        }

    }

    else if (x == 2){
        fprintf(gnu, "set title 'Double Euler'\n");

        fprintf(gnu, "plot '-' w l\n");

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


