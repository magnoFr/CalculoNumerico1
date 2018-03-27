#include <stdio.h>
#include <math.h>
#include "lib.h"
#define PI 3.1415

long long int fatorial(int k){
	int count = k-1;
	while(count > 1){
		k *= count;
		count--;
	}

	return k;
}

long double powe(double x, int times){
    double val = 1;
	while(times >=1){
		val = x * val;
		times--;
	}

	return val;
}


double calcularSeno(double x){
	double sin = x;
	int k = 3;
	int sig = -1;
	int count = 0;
	long double power;
	long long int fat;

	while (count <=7){
	    power = powe(x, k);
	    fat = fatorial(k);
		sin = sin + (power/fat) * sig;
		sig *= -1;
		k += 2;
		count++;
	}

	return sin;

}

double calcularCosseno(double x){
	double sin = x;
	int k = 2;
	int sig = -1;
	int count = 0;
	long double power;
	long long int fat;

	while (count <=7){
	    power = powe(x, k);
	    fat = fatorial(k);
		sin = sin + (power/fat) * sig;
		sig *= -1;
		k += 2;
		count++;
	}

	return sin;

}