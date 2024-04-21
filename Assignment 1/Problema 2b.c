#include <stdio.h>
#include<math.h>

///DESCRIPCIÓN
//En este programa comenzamos declarando dos arrays, uno de doubles y otro de floats llamados 'a' y 'b' respectivamente, de 3 componenetes cada uno.
//Luego declaramos cuatro variables también dos doubles 'x_0' y 'x_1' y dos floats 'y_0' y 'y_1'.
//Las componentes del array las fijamos para comprobar que se produce un error de cancelación.
//Estas componentes deben ser a, b y c de la expresión ax^2 +bx +c respectivamente en cada uno de los arrays.
//Así, los arrays pasan a ser constantes.
//Cabe notar que los valores de a[1] y b[1] son diferentes por que el error de cancelación se produce por la 'b' de la expresión (2), así,
//la precisión de cada uno hace que se necesiten más cifras para producir este error.


//Una vez introducidas las variables el programa comprueba que a>0 y b^2>4ac.
//Si esto no se cumple, el programa se detiene y devuelve 1.
//En caso contrario, damos el valor a 'x_0' y 'x_1' y a 'y_0' e 'y_1', que serán las dos expresiónes (2) del problema 2 en cada caso con su determinada precisión.
//Observamos que en el caso de 'x' utilizamos sqrt() para calcular la raíz cuadrada de un double (precisión doble) y en el caso de 'y' utilizamos sqrtf() para la de un float (precisión simple).
//El programa imprime por pantalla el valor de las variables x_0 y x_1 respectivamente con 16 cifras significativas que son las que sabemos que son correctas en un double.
//El programa imprime por pantalla el valor de las variables y_0 y y_1 respectivamente con 8 cifras significativas que son las que sabemos que son correctas en un float.

int main(void){
    double a[3], x_0, x_1;
    float b[3], y_0, y_1;
    a[0]=a[2]=1.;
    b[0]=b[2]=1.;
    a[1]=1000000000.;
    b[1]=10000.;

    if (a[0]<=0 || a[1]*a[1] <= 4*a[0]*a[2] || b[0]<=0 || b[1]*b[1] <= 4*b[0]*b[2]){
        return 1;
    }
    else{
    printf("La solucio amb precisio simple amb b=10000 es:");
    x_0= ((-a[1]+sqrtf(a[1]*a[1]-4.*a[0]*a[2]))/(2.*a[0]));    // mantisa 16
    printf("x_0=%.8G i", x_0);
    x_1= ((-a[1]-sqrtf(a[1]*a[1]-4.*a[0]*a[2]))/(2.*a[0]));
    printf(" x_1=%.8G\n", x_1);
    printf("La solucio amb precisio doble amb b=1000000000 es:");
    x_0= ((-a[1]+sqrt(a[1]*a[1]-4.*a[0]*a[2]))/(2.*a[0]));    // mantisa 16
    printf("x_0=%.16G i", x_0);
    x_1= ((-a[1]-sqrt(a[1]*a[1]-4.*a[0]*a[2]))/(2.*a[0]));
    printf(" x_1=%.16G\n", x_1);
}
}


