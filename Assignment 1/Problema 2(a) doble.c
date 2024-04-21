#include <stdio.h>
#include<math.h>

///DESCRIPCI�N
//En este programa comenzamos declarando un array de doubles llamado 'a' de 3 componenetes, y dos variables tambi�n doubles 'x_0' y 'x_1'.
//Las componentes del array las introducir� el lector por pantalla una vez compilado el programa. Se escanea un '%lf' ya que queremos escanear doubles.
//Estas componentes deben ser a, b y c de la expresi�n ax^2 +bx +c respectivamente.

//Una vez introducidas las variables el programa comprueba que a>0 y b^2>4ac.
//Si esto no se cumple, el programa se detiene y devuelve 1.
//En caso contrario, damos el valor a 'x_0' y 'x_1', que ser�n las dos expresi�nes (2)  del problema 2. La positiva y negativa respectivamente.
//Observamos que en este caso utilizamos sqrt() para calcular la ra�z cuadrada de un double (precisi�n doble).
//El programa imprime por pantalla el valor de las variables x_0 y x_1 respectivamente con 16 cifras significativas que son las que sabemos que son correctas en un double.

int main(void){
    double a[3], x_0, x_1;
    printf("Introdueix un valor per a, b i c \n");
    for (int i=0; i<3; i++){
        scanf("%lf", &a[i]);
    }
    if (a[0]<=0 || a[1]*a[1] <= 4*a[0]*a[2]){
        return 1;
    }
    else{
    x_0= ((-a[1]+sqrt(a[1]*a[1]-4*a[0]*a[2]))/(2*a[0]));    // mantisa 16
    printf("x_0=%.16G\n", x_0);
    x_1= ((-a[1]-sqrt(a[1]*a[1]-4*a[0]*a[2]))/(2*a[0]));
    printf("x_1=%.16G\n", x_1);
}
}

