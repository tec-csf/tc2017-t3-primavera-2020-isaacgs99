# Tarea *3*. *Técnicas de diseño de algoritmos*

---

##### Integrantes:
1. *[Isaac Garza Strimlingas]* - *[A01025798]* - *[CSF]*
---
## 1. Aspectos generales

Las orientaciones de la tarea se encuentran disponibles en la plataforma **Canvas**.

Este documento es una guía sobre qué información debe entregar como parte de la tarea, qué requerimientos técnicos debe cumplir y la estructura que debe seguir para organizar su entrega.


### 1.1 Requerimientos técnicos

A continuación se mencionan los requerimientos técnicos mínimos de la tarea, favor de tenerlos presente para que cumpla con todos.

* El código debe desarrollarse en C++, cumpliendo con el último estándar [C++17](https://isocpp.org/std/the-standard).
* Toda la programación debe realizarse utilizando Programación Genérica.
* Deben utilizarse las [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md).
* Todo el código debe estar correctamente documentado, siguiendo los lineamientos que aparecen en [Documenting C++ Code](https://developer.lsst.io/cpp/api-docs.html).
* Todo el código de la tarea debe alojarse en este repositorio de GitHub.
* Debe configurar su repositorio para que utilice el sistema de Integración Continua [Travis CI](https://travis-ci.org/).

### 1.2 Estructura del repositorio

El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz del repositorio
    - README.md			# Archivo con la información general de la actividad (este archivo)
    - sources  			# Códigos fuente con la solución
    - examples			# Archivos de ejemplo que pueden utilizarse para verificar que la solución funciona.
```

## 2. Solución

*[El primer problema que se planteó para resolver, fue el de ciclos hamiltonianos (este problema también se le conoce por el viajante de comercios. En este problema lo que se resuelve es encontrar el camino de coste menor, en el que se viaje por todas las ciudades (vértices) a partir de una ciudad origen y regresear a ella misma. Para resolver este problema, utilizamos la técnica de "Branch and bound" y el uso de matrices para calcular el costo mínimo y óptimo para determinar el mejor camino y seguir desarrollandose hasta llegar al mismo nodo. Cabe aclarar que se coloca en las mátrices el infinito, cuando no hay un camino directo de la ciudad i a la j; cuando si la hay, se usan cordenadas de la mátriz para determinar el costo (i,j). El proceso que se lleva en las mátrices es la reducción de cada columna y fila, por su valor mínimo para colocar por lo menos un cero en cada columna y fila, para calcular el límite inferior del nodo raíz. Después de esto, para determinar cual es el siguiente nodo que se debe de usar, hacemos los diferentes calculos de las posibles rutas; se sustituye en la matriz reducida del nodo padre con infinito, todos los numeros que esten conectados del padre (la fila) y del hijo (columna), después hacer lo mismo para la coordenada (hijo, padre). Se realiza el mismo cálculo del limite inferior para el nodo hijo, para así sumar el costo; costo = costo_nodo_padre + costo_arista_padre_hijo + limite_inferior_nodo_hijo. El algoritmo acaba cuando, se encuentra alguna hoja que ya estuvo dentro del árbol.]*

### 2.1 Pasos a seguir para utilizar la aplicación

*[Incluya aquí una guía paso a paso para poder utilizar la aplicación, desde la clonación del repositorio, la compilación del código hasta la ejecución de los ejemplos para visualizar los resultados.]*

## 3. Referencias

*[https://www.techiedelight.com/travelling-salesman-problem-using-branch-and-bound/]*
*[https://www.rosettacode.org/wiki/Word_wrap#C.2B.2B]*

