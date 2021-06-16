// Metodo Selection Sort:

// Este es un algoritmo que permite ordenar un array de manera especial.
// Como toda estructura, tiene sus ventajas y desventajas, es un algoritmo que es facil de implementar,
// no requiere memoria adicional y tiene un funcionamiento de intercambio constante, por otra parte
// puede llegar a ser lento y poco eficiente si se tienen que analizar listas de numeros muy grandes
// ya que realiza numerosas comparaciones.

// Existen varios tipos, en este caso  lo que hace este metodo es seleccionar al menor elemento del array e
// intercambiarlo a la primer posicion y asi sucesivamente con los demas elementos (en caso de que querramos
// ordenar el array de manera ascendente).

// Supongamos que tenemos un array de 5 elementos;
// En la posicion 0 tenemos el elemento (15), en la posicion 1 el elemento (7), en la posicion 2 el elemento (6);
// en la posicion 3 el elemento (16) y en la posicion 4 el elemento (2);

// Mediante for anidados, pregunta cual de todos los elementos del array es el mas pequeño,
// empezando desde el primer elemento, en este caso va a preguntar si hay algun elemento
// de nuestro array que sea menor a 15(primer elemento en posicion 0), ahora vemos que 7(segundo elemento en posicion 1)
// es menor, ahi se produce un cambio(cambian de posicion dejando al 7 en posicion 0)
// luego sigue preguntando, si 7 es menor a algun otro elemento,
// vemos que si, ya que (el valor del elemento de la posicion 2, es 6), se produce otro cambio, ahora sigue preguntando, 
// llega hasta el ultimo elemento del array el cual es un 2(posicion 4) y ahi se produce el ultimo cambio, dejando asi
// el elemento mas pequeño en primera posicion.(Todos los cambios siempre son entre un elemento cualquiera
// y el que se encuentre en ese momento en posicion 0)
// esto pasa en la primer iteracion de nuestro bucle for, luego se va ordenando en cada iteracion usando el mismo mecanismo.



#include <stdio.h>

void selec_sort(int *vec)       // paso el array por referencia para pasarlo al main.
{ 
int i,j,aux,menor;              // declaro i y j para los ciclos for, menor para la posicion del menor elemento y 
                                // aux para guardar el valor de la posicion a cambiar y que no se pierda

for (i = 0; i < 5; i++)
    {
        menor = i;                          // empieza el for e inicio menor  en i, osea i = 0;
        for (j = i + 1; j < 5; j++)          
        {
            if (vec[j] < vec[i])            // compara el elemento de la posicion 1 con el de la posicion 0, y asi con las demas posiciones
            {                               
                menor = j;                  // cuando recorra las 5 posiciones del array, menor toma el valor del indice con el elemento mas chico
            }
        }
        aux = vec[i];                       // le asignamos a un auxilar el valor de i, osea el de la primer posicion en esta primer ronda
        vec[i] = vec[menor];                // el valor de i, toma el valor de menor, osea el valor del elemento mas pequeño(dejando asi el elemento mas pequeño en primera posicion)
        vec[menor] = aux;                   // ahora el valor pisado de i,el que estaba antes, recupera su valor ya que lo guardamos en una auxiliar.
    }
}
void print_array(int *vec)        // funcion para immprimir el array
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", vec[i]);
    }
}

int main()
{
    int array[5] = {15, 7, 6, 16, 2};  // declaro el array con sus elementos

    printf("Vector desordenado:\n");
    print_array(&array);

    printf("\n"); 

    printf("Vector ordenado:\n");
    selec_sort(&array);              //llamo a la funcion
    print_array(&array);             //llamo a la funcion    
}
