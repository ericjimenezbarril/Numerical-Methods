#include <stdio.h>
#include<math.h>


int main (void) {

    int n;
    printf("Numero maximo de terminos a sumar: ");
    scanf("%d", &n);
    printf("\n");

    float S=0.;
    float ca;
    for(int k=n; 1<=k; k--){
        ca=k;
       S= 1./(ca*ca) +S;
    }

    printf("Valor en precision simple: %.8G", S);

}

