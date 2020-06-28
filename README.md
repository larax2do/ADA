# ADA
Cosas de Ada:

## Quick vs Merge 
Tiempo de complejidad de quicksort en el mejor de los casos es nlg(n) y en el peor de los casos n^2.

Tiempo de complejidad de mergesort siempre es nlg(n).

Utilice la implementación quicksort por defecto para su lenguaje de programación y compárela entonces contra mergesort (con intercalación visto en clases).

OBS: ALGUNAS LIBRERÍAS TIENEN OTRA ORDENACIÓN QUE NO ES QUICKSORT PARA SUS SORT NATIVOS. POR EJEMPLO, PYTHON NO USA QUICKSORT SINO TIMSORT. EN ESE CASO, ESCOJAN ALGUNA IMPLEMENTACIÓN QUE ENCUENTREN EN INTERNET.

Para este caso, genere solo números aleatorios de tamaño:
1000, 2000, 3000 ... hasta el valor de 100 mil e imprima el tiempo (si es posible) para las ejecuciones.

## ada1

[1] Crear un generador de arreglos
10 / 1mil / 100 mil / 1 millón

[2]  Copiar codigos en el lenguaje  de su preferencia:
1. Copiar el código de insert sort Wikipedia
2. Copiar el código de buble sort Wikipedia.
Medir el tiempo.

[3] Utilizando los algoritmos de ordenación:
1. Realizar un análisis de la cantidad de comparaciones
2. Realizar un análisis de la cantidad de asignaciones
3. Realizar un análisis de la cantidad de asignación de memoria
6. Imprimir su valor:
x2 comparaciones
x8 asignaciones
x200 creación de un objeto
x50 + n x 10 separa memoria para un arreglo o lista de tamanho 'n'

## ada3

Primer ejercicio.
---------------------------
El algoritmo de insert sort tiene una complejidad de n para el mejor de los casos y n^2 para el peor de los casos.

El algoritmo de mergesort tiene una complejidad de nlg(n).

En teoría para n suficientemente grandes, la complejidad de insertsort es mayor que mergesort a no ser que tengamos un arreglo con la mayor cantidad de sus elementos ya ordenados.

Encontrar, de forma gráfica, para qué valores de n, insertsort es mejor que mergesort. La respuesta está en un valor inferior a n < 1000.


Segundo ejercicio.
-----------------------------
En clases vimos el algoritmo de intercalación o también llamado merge. Nuestro algoritmo de intercalación realiza una operación particular que es el de invertir el orden de los elementos del segundo segmento.

Esta operación tiene cosas positivas y cosas negativas.

En un documento explique brevemente por qué tendría cosas positivas y negativas. Mediante un gráfico fundamente sus respuestas.

## medio
generar.cpp genera un txt con muchos numeros aleatorios, una matriz de 8000 por 8001 y lo que algoritmo hace es encontrar el numero del indice del medio una vez ordenados.Para este problema se modifica el quicksort, cuando `q=particione(A,p,r)` por la ayuda de Dios cae en el indice medio Return. Ademas que ya no se llama recursivamente en ambos lado de donde haya caido q, sino solo en el lado que potencialmente esta el 'indice medio'

El algoritmo 2 usa stl::array y td::partition, pero resulta ser mucho mas lento.

## sumMax
Vendedor salió a vender


Eres el vendedor de un suplemento alimenticio y deseas repartirlo en un cierto distrito. Infelizmente en ese distrito hay varias pendientes y en algunos casos, subir esas pendientes te cuesta bastante pero en algunos casos hay calles que ya tienes registrado que te harán pedido y tienes incluso la cantidad de los pedidos que recibirás.

Ninguna calle está en más de una ruta.

Por ejemplo:
Tenemos 3 rutas:
1era ruta: -1, 6
2da ruta: 4, -5, 4, -3, 4, 4, -4, 4, -5
3era ruta: -3, -4, -5.

La primera ruta tiene 3 calles y se lee: 
"Para ir de la calle 1 a la calle 2 cuesta 1"
"Para ir de la calle 2 a la calle 3 hay un beneficio de 6"

La segunda ruta tiene 10 calles y se lee: 
"Para ir de la calle 1 a la calle 2 hay un beneficio de 4"
"Para ir de la calle 2 a la calle 3 hay cuesta 5"
"Para ir de la calle 3 a la calle 4 hay un beneficio de 4"
y así sucesivamente.

Se entiende que la calle 1 de la ruta 1 es distinta de la calle 1 de la ruta 2 y lo mismo para las demás calles.

Quieres escoger aquella ruta con la mayor cantidad de pedidos relativamente cerca que te convendría visitar.

FORMATO DE ENTRADA:
1era línea tiene un elemento 0<R<10^5 indicando la cantidad de rutas.
A seguir vienen R rutas
Para la R[i] ruta, la primera línea tendrá el número de calles 0<C[i]<20000
A seguir, vendrá C[i] - 1 líneas indicando el costo o beneficio de ir de la calle C[i] a la calle C[i+1].


FORMATO DE SALIDA
“La mejor parte de la ruta [R] es entre las calles C[i] y C[j]” ; En caso haya solución
“La ruta 3 no tiene calles interesantes”   ; En caso no haya solución.



EJEMPLO:
3
3
-1
6
10
4
-5
4
-3
4
4
-4
4
-5
4
-3
-4
-5

SALIDA
La mejor parte de la ruta 1 es entre las calles 2 y 3
La mejor parte de la ruta 2 es entre las calles 3 y 9
La ruta 3 no tiene calles interesantes
