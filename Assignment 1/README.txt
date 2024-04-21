PROBLEMA 1.
-----------------CÓDIGO PROBLEMA 1A: --------------------------------------------------------------------------------------------------------------------
·Las instrucciones para el código 1(a) simple y 1(a) doble sonigual considerando los cambios de precisión.
·Funcionamiento: 
	Este programa introduce una variable 'x_0' de tipo 'float' (resp. 'double') que recibe el valor indicado en la práctica.
	Posteriormente se define una variable 'y' también de tipo 'float' (resp. 'double'), que recibirá el valor de evaluar x_0 en la expresión  (1)
	de la práctica.
	Observamos que se utiliza el cosf() (resp. cos()) para evaluar el coseno de una variable de tipo 'float' (resp. 'double').

	El programa imprime por pantalla el valor de 'y'.
	Utilizamos %.8G (resp. %.16G) para imprimir 8 (resp. 16) cifras significativas del resultado ya que sabemos que es la precisión de un
	'float' (resp. 'double'), en caso de poner más, no sabriamos si son correctas.
	

-----------------CÓDIGO PROBLEMA 1B: --------------------------------------------------------------------------------------------------------------------
·Funcionamiento: 
	Este programa introduce una variable 'x_0' de tipo 'float' que recibe el valor indicado en la práctica.
	Posteriormente se define una variable 'y' también de tipo 'float', que recibirá el valor de evaluar x_0 en la expresión  (4) que se puede 
	ver en el informe. Observamos que se utiliza el sinf para evaluar el coseno de una variable de tipo 'float'.
	El programa imprime por pantalla el valor de 'y'.
	Utilizamos %.8G para imprimir 8 cifras significativas del resultado ya que sabemos que es la precisión de un float, en caso de poner más, 
	no sabriamos si son correctas.

-----------------CÓDIGO PROBLEMA 2A: --------------------------------------------------------------------------------------------------------------------
·Las instrucciones para el código 2(a) simple y 2(a) doble sonigual considerando los cambios de precisión.
·Funcionamiento: 
	En este programa comenzamos declarando un array de floats (resp. doubles) llamado 'b[]' (resp. 'a[]') de 3 componenetes, y dos variables también 
	floats 'y_0' e 'y_1' (resp. doubles 'x_0' y 'x_1').
	Las componentes del array las introducirá el lector por pantalla una vez compilado el programa. Se escanea un '%f' (resp. '%lf')
	ya que queremos escanear floats (resp. doubles).
	Estas componentes deben ser a, b y c de la expresión ax^2 +bx +c respectivamente.

	Una vez introducidas las variables el programa comprueba que a>0 y b^2>4ac.
	Si esto no se cumple, el programa se detiene y devuelve 1.
	En caso contrario, damos el valor a 'y_0' e 'y_1' (resp. 'x_0' y 'x_1'), que serán las dos expresiónes (2)  del problema 2. La positiva y negativa
	respectivamente.
	Observamos que en este caso utilizamos sqrtf() (resp. sqrt()) para calcular la raíz cuadrada de un float (resp. double).
	El programa imprime por pantalla el valor de las variables 'y_0' e 'y_1' (resp. 'x_0' y 'x_1') respectivamente con 8 (resp. 16) cifras 
	significativas que son las que sabemos que son correctas en un float (resp. double).

-----------------CÓDIGO PROBLEMA 2B: --------------------------------------------------------------------------------------------------------------------
Este es un ejemplo del 2A con los valores asignados al inicio del programa. 

-----------------CÓDIGO PROBLEMA 2D: --------------------------------------------------------------------------------------------------------------------

-Explicaremos el funcionamiento de 2D (intr. valor) y 2D (ejemplo) es una aplicación de este asignando unos valores concretos que se indican en el código.
·Funcionamiento:
	En este programa comenzamos declarando dos arrays, uno de doubles y otro de floats llamados 'a[]' y 'b[]' respectivamente, de 3 componenetes cada uno.
	Luego declaramos cuatro variables también dos doubles 'x_0' y 'x_1' y dos floats 'y_0' y 'y_1'.
	Los valores de ambos arrays son introducidos por el lector por pantalla una vez compilados por pantalla.
	Se intorducirán los valores de a, b y c de la expresión ax^2 +bx +c respectivamente en cada uno de los arrays.
	En el caso de 'a' se escanea con '%lf' ya que son doubles y en el caso de 'b' con '%f' ya que son floats.
	Así, los arrays pasan a ser constantes.

	Una vez introducidas las variables el programa comprueba que a>0 y b^2>4ac tanto en las variables de precisión doble como las simples.
	Si esto no se cumple, el programa se detiene y devuelve 1.
	En caso contrario, el programa da dos valores distintos a 'x_0' y 'x_1' y a 'y_0' e 'y_1' que imprime por pantalla.
	Primeramente les da el valor de las dos expresiónes (2) del problema 2 en cada caso con su determinada precisión y los imprime.
	Observamos que en el caso de 'x' utilizamos sqrt() para calcular la raíz cuadrada de un double (precisión doble) y en el caso de 'y'
	utilizamos sqrtf() para la de un float (precisión simple).
	Seguidamente el programa da a 'x_0' y a 'y_0' los valores de la expresión (4) del informe en caso que b>0 y a 'x_1' e 'y_1' los valores de
	la expresión (2) del problema 2 de la práctica.
	En caso que b<0, dará a 'x_1' y a 'y_1' los valores de la expresión (4) del informe y a 'x_0' e 'y_0' los valores de la expresión (2) del 
	problema 2 de la práctica.
	El programa imprime por pantalla el valor de las variables y_0 y y_1 (resp. x_0 y x_1) con 8 cifras significativas (resp. 16) que son las que 
	sabemos que son correctas en un float (resp. double).





