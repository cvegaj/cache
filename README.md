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
## Niveles de Asociatividad Disponibles (<parámetro del código>)
#####           - Directo (*1*)
#####           - 2-Way Associative (*2*)
#####           - 4-Way Associative (*3*)
# 
## Parámetros de Entrada 
####   Asociatividad | Nivel de asociatividad deseado, esperando como parámetro los posibles valores enteros 1, 2 ó 3, según la asociatividad correspondiente.
####   Tamaño del Cache | Tamaño del Cache deseado, esperando como parámetro un valor entero.
####   Tamaño del Bloque | Tamaño del Bloque deseado, esperando como parámetro un valor entero.
#
## Corriendo el Programa
    $ make -f Makefile
    $ ./cache <Asociatividad> <Tamaño del Cache> <Tamaño del Bloque>
#
#### Se generará el ejecutable *cache*, el cuál utilizará el archivo *aligned.trace* que deberá incluir en el directorio donde se encuentra el ejecutable. Ingrese los parámetros requeridos y en pantalla se mostrará los resultados de Hits, Total de solicitudes y Miss Rate para el *.trace*. 
#
## Eliminando Archivos Generados
    $ make clean
    #### Elimina el ejecutable
