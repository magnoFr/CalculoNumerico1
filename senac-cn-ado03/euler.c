#include <stdio.h>
#include <stdlib.h>
#include "lib.h"


int main(){

calculateEuler(0, "euler_flt.png");
calculateEuler(1, "euler_ldbl.png");
calculateEuler(0, "euler_dbl.png");


exit(0);
}