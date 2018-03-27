#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

#define PI 3.1415

int main(int argc, char const *argv[])
{
	double x = atoi(argv[1]);
	x = x*(PI/180);
	x = calcularSeno(x);
	printf("%lf\n",x);

	int i = 0;
	double rad;
	double erroAbsoluto = 0.0;
	double erroRelativo = 0.0;
	double resultado = 0.0;
    FILE *aSeno;
    FILE *aCosse;

    aSeno = fopen("seno.dat", "a");

    for(i=0;i<=720;i++){
    	rad = i*(PI/180);
    	resultado = calcularSeno(rad);
    	erroAbsoluto = fabs(sin(rad) - resultado);
		erroRelativo = fabs(erroAbsoluto / resultado);
        
		fprintf(aSeno,"%d\t%f\t%f\t%f\n",i,resultado,erroAbsoluto,erroRelativo);
    }
	fclose(aSeno);

    aCosse = fopen("cosseno.dat", "a");
   
    for(i=0;i<=720;i++){
    	rad = i*(PI/180);
    	resultado = calcularCosseno(rad);
    	erroAbsoluto = fabs(cos(rad) - resultado);
		erroRelativo = fabs(erroAbsoluto / resultado);
        
		fprintf(aSeno,"%d\t%f\t%f\t%f\n",i,resultado,erroAbsoluto,erroRelativo);
    }
    fclose(aCosse);

    FILE *gnuplot = popen("gnuplot -persistent", "w");
    fprintf(gnuplot, "%s\n%s","set terminal png size 800,600\nset output 'seno.png'","plot 'seno.dat'\n");
    fprintf(gnuplot, "%s\n%s","set terminal png size 800,600\nset output 'cosseno.png'","plot 'cosseno.dat'");



	return 0;
}