#include <stdio.h>
#include<math.h>


int main (void) {

    int n;
    printf("Longitud del vector: ");
    scanf("%d", &n);
    printf("\n");

    float v[n];
    for(int j=0; j<n; j++){
        printf("Component v[%d]: ",j);
        scanf("%f",&v[j]);
        printf("\n");
    }

    //Expresion 1
    float x=0.;
    for(int i=0;i<n;i++){
        x=(1./n)*v[i] + x;
    }
    float s1=0.;
    for(int i=0;i<n;i++){
        s1=(1./(n-1))*(v[i]-x)*(v[i]-x) +s1;
    }
    printf("Varianza muestral expresion 1: %.8G\n", s1);

    //Expresion 2
    float x1=0.;
    float x2=0.;
    float s2;
    for(int i=0; i<n; i++){
        x1= v[i]*v[i] +x1;
    }
    for(int i=0; i<n; i++){
        x2= v[i] +x2;
    }
    s2=(1./(n-1))*(x1-(1./n)*x2*x2);
    printf("Varianza muestral expresion 2: %.8G\n", s2);
}

