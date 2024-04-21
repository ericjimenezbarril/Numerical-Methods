#include <stdio.h>
#include<math.h>
///DESCRIPCI�N
//Este programa introduce una variable 'x_0' de tipo 'double' que recibe el valor indicado en la pr�ctica.
//Posteriormente se define una variable 'y' tambi�n de tipo 'double', que recibir� el valor de evaluar x_0 en la expresi�n  (1) de la pr�ctica.
// Observamos que se utiliza el cos para evaluar el coseno de una variable de tipo 'double'.

//El programa imprime por pantalla el valor de 'y'.
// Utilizamos %.16G para imprimir 16 cifras significativas del resultado ya que sabemos que es la precisi�n de un double, en caso de poner m�s, no sabriamos si son correctas.

int main (void) {
    double x_0;
    x_0=1.2E-5;
    double y;
    if (x_0==0){
        y=1./2.;
        printf("%.16G\n", y);
    }
    else{
        y=((1.-cos(x_0))/(x_0*x_0));
        printf("%.16G\n", y);
    }
    return 0;
}
