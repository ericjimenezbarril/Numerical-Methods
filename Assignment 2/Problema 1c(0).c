#include <stdio.h>
#include <math.h>


int main (void) {

    double a;
    a=pow((400./2.)+sqrt((400.*400./4.)+(-1./27.)),1./3.) + pow((400./2.)-sqrt((400.*400./4.)+(-1./27.)),1./3.);
    printf("Valor de la raiz: %.16G", a);
    printf("\nLa funcion en este punto vale: %.16G", a*a*a-a-400);

}
