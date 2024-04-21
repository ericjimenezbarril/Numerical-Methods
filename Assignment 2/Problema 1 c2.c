#include<math.h>
#include<stdio.h>
#define MAX 10000

double func(double);
double secante (double, double , double);

int main(void)
{
    double tol, x0, x1;

    printf("Introduce el valor de a0 i b0 \n");
    printf("x0= ");
    scanf("%lf", &x0);
    printf("\nx1= ");
    scanf("%lf", &x1);

    printf("\nIntroduce la tolerancia: ");
    scanf("%lf",&tol);

    secante(x0, x1, tol);

}
double func(double x)
{
    return (x*x*x-x-400);
}

double secante (double x0, double x1, double tol)
{
    int n=0; //control de iteracions
    double x[MAX];

    x[0]=x0;
    x[1]=x1;

    for (int i=1; i<MAX; i++){
        x[i+1]= x[i-1]-func(x[i-1])*((x[i]-x[i-1])/(func(x[i])-func(x[i-1])));
        n+=1;

        if ((fabs(x[i+1]-x[i])< tol)){
            printf("\nEl valor de n es %d\n", n);
            printf("La solucion es x[%d]=%.16G\n", i+1, x[i+1]);
            printf("La funcion evaluada en este punto vale f=%.16G\n", func(x[i+1]));
            return 0;
        }
}
if ((fabs(x[MAX]-x[MAX-1])>=tol)){
        printf("Se ha llegado al maximo de iteraciones ");
    return 1;

}

}
