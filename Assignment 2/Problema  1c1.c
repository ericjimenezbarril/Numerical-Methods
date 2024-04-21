#include<math.h>
#include<stdio.h>
#define MAX 10000

double func(double);
double biseccion (double,double , double);

int main(void)
{
    double tol, a0, b0;

    printf("Introduce el valor de a0 i b0 \n");
    printf("a0= ");
    scanf("%lf", &a0);
    printf("\nb0= ");
    scanf("%lf", &b0);

    printf("\nIntroduce la tolerancia: ");
    scanf("%lf",&tol);

    biseccion(a0, b0, tol);

}
double func(double x)
{
    return (x*x*x-x-400);
}

double biseccion (double a0, double b0, double tol)
{
    int n=0; //control de iteracions
    double a[MAX], b[MAX], p[MAX];

    a[0]=a0;
    b[0]=b0;
    for (int i=0; i<=MAX; i++){
        p[i]= (a[i]+b[i])/2;
        if (func(p[i])*func(a[i])<0){
            a[i+1]=a[i];
            b[i+1]=p[i];
        }
        else{
            a[i+1]=p[i];
            b[i+1]=b[i];
        }
        n+=1;
    if (fabs((p[i]-p[i-1]))<=0){
        printf("El valor de n es %d", n);
        printf("\nLa solucion es %.16G", p[i]);
        printf("\nLa funcion evaluada en este punto vale f=%.16G", func(p[i]));
        return 0;
    }
}
if ((fabs(p[n]-p[n-1]))>=tol){

        printf("Se ha llegado al maximo de iteraciones ");
    return 1;

}

}









