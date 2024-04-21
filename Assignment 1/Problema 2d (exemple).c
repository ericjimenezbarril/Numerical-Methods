#include <stdio.h>
#include<math.h>
#include<math.h>
///DESCRIPCI�N
//En este programa comenzamos declarando dos arrays, uno de doubles y otro de floats llamados 'a' y 'b' respectivamente, de 3 componenetes cada uno.
//Luego declaramos cuatro variables tambi�n dos doubles 'x_0' y 'x_1' y dos floats 'y_0' y 'y_1'.
//Los valores de ambos arrays son declaran al principio del programa y son los mismos que hab�amos declarado en 2b, para comprobar que la nueva expresi�n soluciona los errores de cancelaci�n.
//Los valores introducidos se corresponden con los valores de a, b y c de la expresi�n ax^2 +bx +c respectivamente en cada uno de los arrays.
//As�, los arrays pasan a ser constantes.

//Una vez introducidas las variables el programa comprueba que a>0 y b^2>4ac tanto en las variables de precisi�n doble como las simples.
//Si esto no se cumple, el programa se detiene y devuelve 1.
//En caso contrario, el programa da dos valores distintos a 'x_0' y 'x_1' y a 'y_0' e 'y_1' que imprime por pantalla.
//Primeramente les da el valor de las dos expresi�nes (2) del problema 2 en cada caso con su determinada precisi�n y los imprime.
//Observamos que en el caso de 'x' utilizamos sqrt() para calcular la ra�z cuadrada de un double (precisi�n doble) y en el caso de 'y' utilizamos sqrtf() para la de un float (precisi�n simple).
//Seguidamente el programa da a 'x_0' y a 'y_0' los valores de la expresi�n (4) del informe en caso que b>0 y a 'x_1' e 'y_1' los valores de la expresi�n (2) del problema 2 de la pr�ctica.
// En caso que b<0, dar� a 'x_1' y a 'y_1' los valores de la expresi�n (4) del informe y a 'x_0' e 'y_0' los valores de la expresi�n (2) del problema 2 de la pr�ctica.
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
    printf("La solucion con precision simple con b=10000 usando (2) es:");
    y_0= ((-b[1]+sqrtf(b[1]*b[1]-4.*b[0]*b[2]))/(2.*b[0]));    // mantisa 16
    printf("y_0=%.8G i", y_0);
    y_1= ((-b[1]-sqrtf(b[1]*b[1]-4.*b[0]*b[2]))/(2.*b[0]));
    printf(" y_1=%.8G\n", y_1);
    printf("La solucion con precision doble con b=1000000000 usando (2) es:");
    x_0= ((-a[1]+sqrt(a[1]*a[1]-4.*a[0]*a[2]))/(2.*a[0]));    // mantisa 16
    printf("x_0=%.16G i", x_0);
    x_1= ((-a[1]-sqrt(a[1]*a[1]-4.*a[0]*a[2]))/(2.*a[0]));
    printf(" x_1=%.16G\n", x_1);


    if (b[1]>=0){
         printf("La solucion con precision simple con b=10000 usando (c) es:");
    y_0= (-2*b[2]/(b[1]+sqrtf(b[1]*b[1]-4.*b[0]*b[2])));    // mantisa 16
    printf("y_0=%.8G i", y_0);
    y_1= ((-b[1]-sqrtf(b[1]*b[1]-4.*b[0]*b[2]))/(2.*b[0]));
    printf(" y_1=%.8G\n", y_1);
    }
    else{
        printf("La solucion con precision simple con b=10000 usando (c) es:");
    y_0= ((-b[1]+sqrtf(b[1]*b[1]-4.*b[0]*b[2]))/(2.*b[0]));    // mantisa 16
    printf("y_0=%.8G i", y_0);
    y_1= (2*b[2]/(-b[1]+sqrtf(b[1]*b[1]-4*b[0]*b[2])));
    printf(" y_1=%.8G\n", y_1);
    }

   if (a[1]>0){
    printf("La solucion con precision doble con b=1000000000 usando (c) es:");
    x_0= (-2*a[2]/(a[1]+sqrt(a[1]*a[1]-4.*a[0]*a[2])));    // mantisa 16
    printf("x_0=%.16G i", x_0);
    x_1= ((-a[1]-sqrt(a[1]*a[1]-4.*a[0]*a[2]))/(2.*a[0]));
    printf(" x_1=%.16G\n", x_1);
   }
   else{
    printf("La solucion con precision doble con b=1000000000 usando (c) es:");
    x_0= ((-a[1]+sqrt(a[1]*a[1]-4.*a[0]*a[2]))/(2.*a[0]));    // mantisa 16
    printf("x_0=%.16G i", x_0);
    x_1= (2*a[2]/(-a[1]+sqrt(a[1]*a[1]-4*a[0]*a[2])));
    printf(" x_1=%.16G\n", x_1);
    }
}
}

