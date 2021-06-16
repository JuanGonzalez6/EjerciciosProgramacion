/* 3) realizar una función que reciba un caracter en minúscula como parámetro
 y devuelva  convertido a mayúscula.
 Hacer la función inversa, que convierta de mayúscula a  minúscula
 . Crear un programa que utilice ambas funciones.   */
#include <stdio.h>

void convierto_caracter_minus(char *c)
    { 
        *c = *c -32;
        return;
    }

void convierto_caracter_mayus(char *c)
    {
        *c = *c +32;
        return;
    }
main()

{
    char c;
    
    printf("Ingrese un caracter: ");
    scanf("%c", &c);
    if ((c >= 65) && (c <= 90))
    {
        convierto_caracter_mayus(&c);
        printf("%c", c);
    }
    else if ((c >= 97) && (c <= 122))
    {
        convierto_caracter_minus(&c);
        printf("%c", c);
    }
    else 
    printf("El caracter ingresado no es una letra");
}

    



    

