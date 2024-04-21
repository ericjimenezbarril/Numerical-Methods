#include <stdio.h>
#include<math.h>

int main (void) {

    int n;
    printf("Numero maximo de terminos a sumar: ");
    scanf("%d", &n);
    printf("\n");


    float S=0.;
    float ca;
    float sa;
    for(int k=1; k<=n; k++){
        float s=1;
        for(int i=1; i<=k-1;i++){
            s=2*s;
        }
        ca=k;
        sa=s;
        S= 1./(ca*ca*sa) +S;
    }

    printf("Valor en precision simple: %.8G", logf(2)*logf(2)+S);


}

