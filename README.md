# Simulador de Memoria Cache con diferentes niveles de asociatividad
## Tarea Programada 1/IE-0521 Estructuras de Computadores Digitales II
#
### Autores:
####         Carla Vega J.    B06763
####         Lennon Núñez M.  B34943
### Profesor: 
####   José Daniel Hernández
######################################################################
#
### El programa consiste en un simulador del comportamiento de una Memoria Cache para diferentes niveles de asociatividad en lenguaje de programación de alto nivel (C++). El programa puede cambiar en tres diferentes niveles de asociatividad y recibir del usuario los valores deseados para el Tamaño del Cache y el Tamaño del Bloque. La implementación utiliza como Política de Reemplazo de Bloques es Random.
### Se requiere incluir en el mismo directorio donde se ubica el programa un archivo .trace con las direcciones de memoria y datos y el tipo de solicitud (Lectura/Escritura). 
### Se incluye el archivo main.cpp con el código de la implementación y un Makefile para realizar la compilación y creación del ejecutable. El Makefile utiliza g++ para la compilación, en caso de querer usar otro compilador omitir el uso del Makefile y usar el código correspondiente a preferencia.

## Niveles de Asociatividad Disponibles (parámetro del código)
#####           - Directo (*1*)
#####           - 2-Way Associative (*2*)
#####           - 4-Way Associative (*3*)
# 
## Parámetros de Entrada 
####   Asociatividad | Nivel de asociatividad deseado, esperando como parámetro los posibles valores enteros 1, 2 ó 3, según la asociatividad correspondiente.
####   Tamaño del Cache | Tamaño del Cache deseado, esperando como parámetro un valor entero indicando los Bytes asignados.
####   Tamaño del Bloque | Tamaño del Bloque deseado, esperando como parámetro un valor entero indicando los Bytes asignados.
#
## Corriendo el Programa
    $ make -f Makefile
    $ ./cache <Asociatividad> <Tamaño del Cache> <Tamaño del Bloque>
    
###Ejemplo: Probando 2-Way Set Associative, con tamaño de cache de 1024 B y tamaño del bloque de 255 B
    $ ./cache 2 1024 255
#
#### Se generará el ejecutable *cache*, el cuál utilizará el archivo *aligned.trace* que deberá incluir en el directorio donde se encuentra el ejecutable. Ingrese los parámetros requeridos y en pantalla se mostrará los resultados de Hits, Total de solicitudes y Miss Rate para el *.trace*. 
#
## Eliminando Archivos Generados
    $ make clean
#### Elimina el ejecutable
