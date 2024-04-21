#include <stdio.h>
#include<math.h>
///DESCRIPCIÓN
//Este programa introduce una variable 'x_0' de tipo 'float' que recibe el valor indicado en la práctica.
//Posteriormente se define una variable 'y' también de tipo 'float', que recibirá el valor de evaluar x_0 en la expresión  (1).
// Observamos que se utiliza el cosf para evaluar el coseno de una variable de tipo 'float'.

//El programa imprime por pantalla el valor de 'y'.
// Utilizamos %.8G para imprimir 8 cifras significativas del resultado ya que sabemos que es la precisión de un float, en caso de poner más, no sabriamos si son correctas.
int main (void) {
    float x_0;
    x_0=1.2E-5;
    float y;
    if (x_0==0.){
        y=1./2.;
        printf("%.8G\n", y);
    }
    else{
        y=((1.-cosf(x_0))/(x_0*x_0));
        printf("%.8G\n", y);
    }
    return 0;
}

