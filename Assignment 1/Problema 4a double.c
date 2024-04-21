#include <stdio.h>
#include<math.h>


int main (void) {

    int n;
    printf("Numero maximo de terminos a sumar: ");
    scanf("%d", &n);
    printf("\n");

    double S=0.;
    double ca;
    for(int k=1; k<=n; k++){
        ca=k;
       S= 1./(ca*ca) +S;
    }

    printf("Valor en precision simple: %.16G", S);

}

