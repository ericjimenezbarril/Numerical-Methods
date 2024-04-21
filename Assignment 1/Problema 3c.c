#include <stdio.h>
#include<math.h>


int main (void) {

    int n;
    printf("Longitud del vector: ");
    scanf("%d", &n);
    printf("\n");

    float u[n];
    double v[n];
    for(int j=0; j<n; j++){
        u[j]=10000. + j;
        v[j]=10000. + j;
    }

    //Expresion 1
    float x=0.;
    double y=0.;
    for(int i=0;i<n;i++){
        x=(1./n)*u[i] + x;
        y=(1./n)*v[i] + y;
    }
    float s1=0.;
    double t1=0.;
    for(int i=0;i<n;i++){
        s1=(1./(n-1))*(u[i]-x)*(u[i]-x) +s1;
        t1=(1./(n-1))*(v[i]-y)*(v[i]-y) +t1;
    }
    printf("Varianza muestral expresion 1 en precision simple: %.8G\n", s1);
    printf("Varianza muestral expresion 1 en precision double: %.16G\n\n", t1);

    //Expresion 2
    float x1=0.;
    float x2=0.;
    double y1=0.;
    double y2=0.;
    float s2;
    double t2;
    for(int i=0; i<n; i++){
        x1= u[i]*u[i] +x1;
        y1= v[i]*v[i] +y1;
    }
    for(int i=0; i<n; i++){
        x2= u[i] +x2;
        y2= v[i] +y2;
    }
    s2=(1./(n-1))*(x1-(1./n)*x2*x2);
    t2=(1./(n-1))*(y1-(1./n)*y2*y2);
    printf("Varianza muestral expresion 2 en precision simple: %.8G\n", s2);
    printf("Varianza muestral expresion 2 en precision double: %.16G\n", t2);
}

