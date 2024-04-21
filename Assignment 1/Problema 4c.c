#include <stdio.h>
#include<math.h>

int main (void) {

    int n;
    printf("Numero maximo de terminos a sumar: ");
    scanf("%d", &n);
    printf("\n");


    float S=0.;         //On guardarem el sumatori
    double T=0.;

    float ca;
    double da;


    float sa;
    double ta;

    for(int k=1; k<=n; k++){
        float s=1;
        double t=1;
        for(int i=1; i<=k-1;i++){
            s=2*s;
            t=2*t;
        }
        ca=k;
        da=k;

        sa=s;
        ta=t;

        S= 1./(ca*ca*sa) +S;
        T= 1./(da*da*ta) +T;
    }

    printf("Valor en precision simple: %.8G \n", logf(2)*logf(2)+S);
    printf("Valor en precision doble: %.16G", log(2)*log(2)+T);


}

