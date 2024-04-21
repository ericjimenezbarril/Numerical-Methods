#include<math.h>
#include<stdio.h>
#define MAX 10000

double newtondoble(double, double);
double func (double);
double der (double);


int main (void)
{
    double x0, tol;

    printf("Introduce un valor de x0\n");
    printf("x0= ");
    scanf("%lf", &x0);

    printf("Introduce la tolerancia: ");
    scanf("%lf",&tol);

    newtondoble(x0, tol);
    return 0;

}



double newtondoble(double x0, double tol)
{
    int n=0;
    double x[MAX];
    x[0]=x0;
    for (int i=0; i<MAX; i++){
      n+=1;
      x[i+1]= x[i]-(func(x[i])/der(x[i]));
      if (fabs(x[i+1]-x[i])<tol){
        printf("Se han necesitado %d iteraciones\n", n);
        printf("El valor de x[%d] es: %.16G\n", i+1, x[i+1]);
        printf("El valor de f(x[%d]) es: %.16G\n", i+1, func(x[i+1]));
        return 0;
      }
}
    if (fabs(x[MAX-1]-x[MAX-2])>=tol){
    printf("Se ha llegado al maximo de iteraciones.");
    return 1;
}
}

double func(double x)
{
    return (x*x*x-x-40);
}
double der(double x)
{
    return (3*x*x-1);
}

