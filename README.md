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

*[El primer problema que se planteó para resolver, fue el de ciclos hamiltonianos (este problema también se le conoce por el viajante de comercios. En este problema lo que se resuelve es encontrar el camino de coste menor, en el que se viaje por todas las ciudades (vértices) a partir de una ciudad origen y regresear a ella misma. Para resolver este problema, utilizamos la técnica de "Branch and bound" y el uso de matrices para calcular el costo mínimo y óptimo para determinar el mejor camino y seguir desarrollandose hasta llegar al mismo nodo. Cabe aclarar que se coloca en las mátrices el infinito, cuando no hay un camino directo de la ciudad i a la j; cuando si la hay, se usan cordenadas de la mátriz para determinar el costo (i,j). El proceso que se lleva en las mátrices es la reducción de cada columna y fila, por su valor mínimo para colocar por lo menos un cero en cada columna y fila, para calcular el límite inferior del nodo raíz. Después de esto, para determinar cual es el siguiente nodo que se debe de usar, hacemos los diferentes calculos de las posibles rutas; se sustituye en la matriz reducida del nodo padre con infinito, todos los numeros que esten conectados del padre (la fila) y del hijo (columna), después hacer lo mismo para la coordenada (hijo, padre). Se realiza el mismo cálculo del limite inferior para el nodo hijo, para así sumar el costo; costo = costo_nodo_padre + costo_arista_padre_hijo + limite_inferior_nodo_hijo. El algoritmo acaba cuando, se encuentra alguna hoja que ya estuvo dentro del árbol. Tiene una complejidad O(A^n) donde a puede estar entre 1 a 2, pero tambien se puede clasificar como factorial. Cabe aclarar que es un tipo de problema NP (No se puede resolver en tiempo polinomial)]*

*[El segundo problema planteado fue el de división de parrafos. Este problema plantea que se debe de realizar un algoritmo que, acomode un x cantidad de palabras en un espacio delimitado por renglón, para que así lo acomode de manera óptima y con el menor costo, hasta llegar a la última palabra; este mismo esta condicionado a que los párrafos siempre deben de tener una longitud L y con un tamaño entre palabras óptimo (este se puede reducir o aumentar y se escoge por el de menor costo). Este algoritmo fue resuelto a través de un algoritmo ávido, que determina por etapas, si se debe de colocar una palabra en ese renglón o disminuir espacios óptimos y ponerlo en el mismo renglón o aumentar espacio entre estos mismos para colocarlo en el siguiente renglón. Para calcular el costo, se utiliza la fórmula mencionada en el capítulo 4 del libro "Técnicas de diseño de algoritmos" de Rosa Guerequeta y Antonio Vallecillo, en el problema "división de párrafos"; esta fórmula dice lo siguiente: "El costo de fijar la línea pi, pi+1, ..., pj es (j – i)|b’ – b|, siendo b’ el ancho real de los espacios, es decir (L – li – li+1 – ... – lj)/(j – i).", siendo b el espacio óptimo entre palabras.]*

*[Este proceso se repite hasta llegar a la última palabra. El algoritmo es O(n) donde n es la cantidad de palabras.]*

### 2.1 Pasos a seguir para utilizar la aplicación

*1.- Abrir la terminal.*

*2.- Acceder al directorio donde vas a clonar el repositorio. Ej: cd desktop.*

*3.- Usar el comando "git clone" seguido del link del repositorio, que es  el siguiente: https://github.com/tec-csf/tc2017-t3-primavera-2020-isaacgs99.git . Quedaria de la siguente manera: "git clone https://github.com/tec-csf/tc2017-t3-primavera-2020-isaacgs99.git.*

*4.- Acceder al clon/carpeta del repositorio desde la terminal, el cuál se guardó donde se hizo el "git clone". Ej: "cd tc2017-t3-primavera-2020-isaacgs99".*

*5.- Una vez que estés dentro de la carpeta del repositorio tendras que acceder a la carpeta de sources con el siguente comando: "cd sources".*

*-Hamilton.*

*6.- Se debe de modificar el código en  caso de querer poner diferentes problemas. Si quieres definir la cantidad de nodos presentes en el frado, debes de hacerlo en la línea 14.*

*7.- Para colocar el grafo, se debe de hacer a través de una matríz (para colocar los ceros o cuando el nodo se conecte asi mismo, deberas de sustituirlo por INF)*

*8.- Para poder utilizar el primer programa primero deberas compilar con el siguiente comando: "g++ hamilton.cpp -o hami".*

*9.- El siguiente paso, para poder correrlo, es ingresar el siguiente comando: "./hami.*

*-División de párrafos.*

*6.- Se debe de modificar el código en caso de querer poner diferentes problemas. Para definir cuakquiera de los datos, se debe de hacer con un decimal por lo menos.*

*7.- En la línea 138, se puede modificar el ancho de cada línea y abajo de esta el espacio óptimo entre palabras*

*8.- Se debe de crear un vector con el tamaño de las letras que se desean e insertarlas con el método push_back()*

*9.- Para poder utilizar el primer programa primero deberas compilar con el siguiente comando: "g++ division.cpp -o div2".*

*10.- El siguiente paso, para poder correrlo, es ingresar el siguiente comando: "./div2.*

## 3. Referencias

*[https://www.techiedelight.com/travelling-salesman-problem-using-branch-and-bound/]*
*[https://www.rosettacode.org/wiki/Word_wrap#C.2B.2B]*
*[Asesoría con el profesor Vicente Cubbells]*

