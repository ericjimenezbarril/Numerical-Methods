#include<math.h>
#include<stdio.h>
#define MAX 10000

float newtondoble(float, float);
float func (float);
float der (float);


int main (void)
{
    float x0, tol;

    printf("Introduce un valor de x0\n");
    printf("x0= ");
    scanf("%f", &x0);

    printf("Introduce la tolerancia: ");
    scanf("%f",&tol);

    newtondoble(x0, tol);
    return 0;
}



float newtondoble(float x0, float tol)
{
    int n=0;
    float x[MAX];
    x[0]=x0;
    for (int i=0; i<MAX; i++){
      n+=1;
      x[i+1]= x[i]-(func(x[i])/der(x[i]));
      if (fabsf(x[i+1]-x[i])<tol){
        printf("Se han necesitado %d iteraciones\n", n);
        printf("El valor de x[%d] es: %.8G\n", i+1, x[i+1]);
        printf("El valor de f(x[%d]) es: %.16G\n", i+1, func(x[i+1]));
        return 0;
      }

}
if (fabsf(x[MAX-1]-x[MAX-2])>=tol){
    printf("Se ha llegado al maximo de iteraciones.");
    return 1;
}
}

float func(float x)
{
    return (x*x*x-x-40);
}
float der(float x)
{
    return (3*x*x-1);
}

