#include <stdio.h>
#include <math.h>
#define MAX 1000
#define tol 10e-15

double func(double);
double der(double);

int main(void){

    int n=0;

    double x0;
    printf("x0 = ");
    scanf("%lf",&x0);
    printf("\n");

    double x[MAX];
    double b[MAX];
    x[0]=x0;
    b[0]=1./der(x0);

    double e1[10];
    double e2[10];
    double e3[10];

    for(int k=0; k<MAX; k++){
        n=n+1;
        x[k+1] = x[k] - b[k]*func(x[k]);
        b[k+1] = b[k]*(2.-der(x[k+1])*b[k]);
        printf("x[%d] = %.16G\n", k+1, x[k+1]);

        if(fabs(x[k+1]-x[k])<tol){
            printf("\nRaiz: %.16G \n", x[k+1]);
            printf("Numero iteraciones: %d \n", n);
            printf("Funcion evaluada: %.16G \n\n", func(x[k+1]));
            for(int k=0; k<n; k++){
                e1[k+1+1]=fabs(x[k+1+1]-x[k+1])/fabs(x[k+1]-x[k-1+1]);
                e2[k+1+1]=fabs(x[k+1+1]-x[k+1])/(fabs(x[k+1]-x[k-1+1])*fabs(x[k+1]-x[k-1+1]));
                e3[k+1+1]=fabs(x[k+1+1]-x[k+1])/(fabs(x[k+1]-x[k-1+1])*fabs(x[k+1]-x[k-1+1])*fabs(x[k+1]-x[k-1+1]));
            }
            printf("Cociente 1: %.16G --> %.16G --> %.16G --> %.16G --> %.16G --> %.16G \n", e1[1],e1[2],e1[3],e1[4],e1[5],e1[6]);
            printf("Cociente 2: %.16G --> %.16G --> %.16G --> %.16G --> %.16G --> %.16G \n", e2[1],e2[2],e2[3],e2[4],e2[5],e2[6]);
            printf("Cociente 3: %.16G --> %.16G --> %.16G --> %.16G --> %.16G --> %.16G \n", e3[1],e3[2],e3[3],e3[4],e3[5],e3[6]);
            return 0;
        }
    }

    if(fabs(x[MAX]-x[MAX-1])>=tol){
        printf("Limite iteraciones");
        return 1;
    }
    return 0;
}

double func(double x){
    return (x*x*x -x -400.);
}
double der(double x){
    return (3.*x*x -1.);
}
