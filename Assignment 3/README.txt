-----------------------PROBLEMA 1------------------------------------------------------------------
Al compilar este programa aparece por pantalla una tabla con información sobre el ejercicio

-En la primera columna se indican los nodos de interpolación.
-En la segunda columna aparece el error MÁXIMO cometido entre el valor del polinomio de 
interpolación de grado correspondiente a los nodos indicados evaluado en nodos equidistantes 
y la función dada  |f(x_j)-p(x_j)|donde x_j es el nodo equidistante que hace máxima la expresión.
-En la tercera columna aparece el error MÁXIMO cometido entre el valor del polinomio de 
interpolación de grado correspondiente a los nodos indicados evaluado en nodos de Chebishev 
y la función dada  |f(x_j)-p(y_j)|donde y_j es el nodo de Chebishev que hace máxima la expresión.
-Por último, la cuarta columna, indica el valor de los cuocientes |f(x_j)-p(x_j)|/|f(x_j)-p(y_j)|.

Además, el programa crea para cada número de nodos, un fichero .txt que contiene el valor de los 
180 puntos y la imagen de estos puntos en p(x). También crea otro fichero .txt que contiene estos 
puntos y su imagen por f(x). 
Estos ficheros los usaremos para compilarlos en gnuplot. 
Una vez dentro de la consola de gnuplot, para obtener la gráfica del informe, introducimos:
              plot 'nombre fichero.txt'u 1:2 w l 
y obtenemos por pantalla la gráfica de los puntos de 'nombre fichero.txt'.

-----------------------PROBLEMA 2a------------------------------------------------------------------
En este problema al compilar aparecen por pantalla el valor de p_n(0) donde n=1, 3, 5, donde n es el
grado del polinomio (el número de nodos -1) y p_n(x) es el polinomio interpolador
inverso de J_0(x) para nodos positivos más cercanos al cambio de signo.  

-----------------------PROBLEMA 2b------------------------------------------------------------------
En este problema al compilar aparecen por pantalla el valor de p_n(0) donde n=1, 3, 5, donde n es el
grado del polinomio (el número de nodos -1) y p_n(x) es el polinomio interpolador
inverso de J_0(x) para nodos negativos más cercanos al cambio de signo.

-----------------------PROBLEMA 2c------------------------------------------------------------------
En este problema al compilar aparecen por pantalla el valor de p_n(0) donde n=1, 3, 5, donde n es el
grado del polinomio (el número de nodos -1) y p_n(x) es el polinomio interpolador
inverso de J_0(x) para nodos simétricos respecto al cambio de signo.
