#include <stdio.h>
#include<math.h>


int main (void) {

    int n;
    printf("Longitud del vector: ");
    scanf("%d", &n);
    printf("\n");

    double v[n];
    for(int j=0; j<n; j++){
        printf("Component v[%d]: ",j);
        scanf("%lf",&v[j]);
        printf("\n");
    }

    //Expresion 1
    double x=0.;
    for(int i=0;i<n;i++){
        x=(1./n)*v[i] + x;
    }
    double s1=0.;
    for(int i=0;i<n;i++){
        s1=(1./(n-1))*(v[i]-x)*(v[i]-x) +s1;
    }
    printf("Varianza muestral expresion 1: %.16G\n", s1);

    //Expresion 2
    double x1=0.;
    double x2=0.;
    double s2;
    for(int i=0; i<n; i++){
        x1= v[i]*v[i] +x1;
    }
    for(int i=0; i<n; i++){
        x2= v[i] +x2;
    }
    s2=(1./(n-1))*(x1-(1./n)*x2*x2);
    printf("Varianza muestral expresion 2: %.16G\n", s2);
}

