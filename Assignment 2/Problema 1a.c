#include <stdio.h>
#include <math.h>


int main (void) {
    float a1;
    double a2;

    a1= powf(20+(1./9.)*sqrtf(32397.),1./3.) + powf(20-(1./9.)*sqrtf(32397.),1./3.);
    a2= pow(20+(1./9.)*sqrt(32397.),1./3.) + pow(20-(1./9.)*sqrt(32397.),1./3.);

    printf("En float: %.8G \n", a1);
    printf("En double: %.16G \n", a2);

    printf("Solucion en float: %.8G \n", a1*a1*a1-a1-40);
    printf("Solucion en double: %.16G \n", a2*a2*a2-a2-40);

    //Dona mal en cada precisio (no arriba tot 0s)
}
