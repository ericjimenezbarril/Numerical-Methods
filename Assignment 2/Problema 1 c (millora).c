#include<math.h>
#include<stdio.h>

double func(double);
double der(double);
double newtondoble (double, double);

int main(void)
{
    double tol, x0, x1;

    printf("Introduce el valor de a0 i b0 \n");
    printf("x0= ");
    scanf("%lf", &x0);
    printf("\nx1= ");
    scanf("%lf", &x1);

    int n=0; //control de iteracions
    double x[2];

    x[0]=x0;
    x[1]=x1;

    for (int i=1; i<3; i++){
        x[i+1]= x[i-1]-func(x[i-1])*((x[i]-x[i-1])/(func(x[i])-func(x[i-1])));
        n+=1;
    }

    newtondoble(x[3],tol);

}

double newtondoble(double y0, double tol)
{
    int n=0;
    double y[100];
    y[0]=y0;
    for (int i=0; i<100; i++){
      n+=1;
      y[i+1]= y[i]-(func(y[i])/der(y[i]));
      printf("%.16G\n", y[i+1]);

      if (fabs(y[i+1]-y[i])<10e-15){
        printf("\nSe han necesitado %d iteraciones\n", n+2);
        printf("El valor de x[%d] es: %.16G\n", i+1, y[i+1]);
        printf("Funcion evaluada: %.16G", func(y[i+1]));
        return 0;
      }
}
    if (fabsf(y[100-1]-y[100-2])>=10e-15){
    printf("Se ha llegado al maximo de iteraciones.");
    return 1;
}
}

double func(double x)
{
    return (x*x*x-x-400);
}
double der(double x)
{
    return (3*x*x-1);
}
