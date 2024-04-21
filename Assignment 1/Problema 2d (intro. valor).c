#include <stdio.h>
#include<math.h>
///DESCRIPCIÓN
//En este programa comenzamos declarando dos arrays, uno de doubles y otro de floats llamados 'a' y 'b' respectivamente, de 3 componenetes cada uno.
//Luego declaramos cuatro variables también dos doubles 'x_0' y 'x_1' y dos floats 'y_0' y 'y_1'.
//Los valores de ambos arrays son introducidos por el lector por pantalla una vez compilados por pantalla.
//Se intorducirán los valores de a, b y c de la expresión ax^2 +bx +c respectivamente en cada uno de los arrays.
//En el caso de 'a' se escanea con '%lf' ya que son doubles y en el caso de 'b' con '%f' ya que son floats.
//Así, los arrays pasan a ser constantes.

//Una vez introducidas las variables el programa comprueba que a>0 y b^2>4ac tanto en las variables de precisión doble como las simples.
//Si esto no se cumple, el programa se detiene y devuelve 1.
//En caso contrario, el programa da dos valores distintos a 'x_0' y 'x_1' y a 'y_0' e 'y_1' que imprime por pantalla.
//Primeramente les da el valor de las dos expresiónes (2) del problema 2 en cada caso con su determinada precisión y los imprime.
//Observamos que en el caso de 'x' utilizamos sqrt() para calcular la raíz cuadrada de un double (precisión doble) y en el caso de 'y' utilizamos sqrtf() para la de un float (precisión simple).
//Seguidamente el programa da a 'x_0' y a 'y_0' los valores de la expresión (4) del informe en caso que b>0 y a 'x_1' e 'y_1' los valores de la expresión (2) del problema 2 de la práctica.
// En caso que b<0, dará a 'x_1' y a 'y_1' los valores de la expresión (4) del informe y a 'x_0' e 'y_0' los valores de la expresión (2) del problema 2 de la práctica.
//El programa imprime por pantalla el valor de las variables x_0 y x_1 respectivamente con 16 cifras significativas que son las que sabemos que son correctas en un double.
//El programa imprime por pantalla el valor de las variables y_0 y y_1 respectivamente con 8 cifras significativas que son las que sabemos que son correctas en un float.


int main(void){
    double a[3], x_0, x_1;
    float b[3], y_0, y_1;


    printf("Introdueix un valor per a, b i c doubles \n");
    for (int i=0; i<3; i++){
        scanf("%lf", &a[i]);
    }
    printf("Introdueix un valor per a, b i c floats\n");
    for (int i=0; i<3; i++){
        scanf("%f", &b[i]);
    }


    if (a[0]<=0 || a[1]*a[1] <= 4*a[0]*a[2] || b[0]<=0 || b[1]*b[1] <= 4*b[0]*b[2]){
        return 1;
    }
    else{
    printf("La solucion con precision simple con b escogida usando (2) es:");
    y_0= ((-b[1]+sqrtf(b[1]*b[1]-4.*b[0]*b[2]))/(2.*b[0]));    // mantisa 16
    printf("y_0=%.8G i", y_0);
    y_1= ((-b[1]-sqrtf(b[1]*b[1]-4.*b[0]*b[2]))/(2.*b[0]));
    printf(" y_1=%.8G\n", y_1);
    printf("La solucion con precision doble con b escogida usando (2) es:");
    x_0= ((-a[1]+sqrt(a[1]*a[1]-4.*a[0]*a[2]))/(2.*a[0]));    // mantisa 16
    printf("x_0=%.16G i", x_0);
    x_1= ((-a[1]-sqrt(a[1]*a[1]-4.*a[0]*a[2]))/(2.*a[0]));
    printf(" x_1=%.16G\n", x_1);


    if (b[1]>=0){
         printf("La solucion con precision simple con b escogida usando (c) es:");
    y_0= (-2*b[2]/(b[1]+sqrtf(b[1]*b[1]-4.*b[0]*b[2])));    // mantisa 16
    printf("y_0=%.8G i", y_0);
    y_1= ((-b[1]-sqrtf(b[1]*b[1]-4.*b[0]*b[2]))/(2.*b[0]));
    printf(" y_1=%.8G\n", y_1);
    }
    else{
        printf("La solucion con precision simple con b escogida usando (c) es:");
    y_0= ((-b[1]+sqrtf(b[1]*b[1]-4.*b[0]*b[2]))/(2.*b[0]));    // mantisa 16
    printf("y_0=%.8G i", y_0);
    y_1= (2*b[2]/(-b[1]+sqrtf(b[1]*b[1]-4*b[0]*b[2])));
    printf(" y_1=%.8G\n", y_1);
    }

   if (a[1]>0){
    printf("La solucion con precision doble  con b escogida usando (c) es:");
    x_0= (-2*a[2]/(a[1]+sqrt(a[1]*a[1]-4.*a[0]*a[2])));    // mantisa 16
    printf("x_0=%.16G i", x_0);
    x_1= ((-a[1]-sqrt(a[1]*a[1]-4.*a[0]*a[2]))/(2.*a[0]));
    printf(" x_1=%.16G\n", x_1);
   }
   else{
    printf("La solucion con precision doble con b escogida usando (c) es:");
    x_0= ((-a[1]+sqrt(a[1]*a[1]-4.*a[0]*a[2]))/(2.*a[0]));    // mantisa 16
    printf("x_0=%.16G i", x_0);
    x_1= (2*a[2]/(-a[1]+sqrt(a[1]*a[1]-4*a[0]*a[2])));
    printf(" x_1=%.16G\n", x_1);
    }
}
}

