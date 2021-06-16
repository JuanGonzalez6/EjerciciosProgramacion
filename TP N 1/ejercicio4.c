/* 4) Escribir un programa que para una fecha ingresada por un usuario 
(año, mes, día)  determine: 
a) Si es una fecha válida. 
b) Si el año es bisiesto o no. 
c) La cantidad de días que faltan para fin de mes. 
Nota: un año es bisiesto si es un número divisible por 4, pero no si es divisible por 100,
 excepto  que también sea divisible por 400. */

#include <stdio.h>

main()

{
    int dia;
    int mes;
    int anio;
    int cantdias = 0;

    printf("Ingrese una fecha: \n");
  
    printf("Dia: ");
    scanf("%d", &dia);
    printf("Mes: ");
    scanf("%d", &mes);
    printf("Anio: ");
    scanf("%d", &anio);

    if (dia > 31 || dia < 1 || mes > 12 || mes < 1 || anio < 1)
    {
       printf("Ingrese una fecha valida:");
    }
    else
    {
        printf("La fecha es valida");   
    }
        printf("\n");    

    if(anio%4 == 0 || anio%100 == 0 && anio %400 == 0)
    {
        printf("El anio es bisiesto \n");
    }
    else
    {
        printf("El anio no es bisiesto \n");
    }

    switch (mes)
    {
        case 1:
            cantdias = 31 - dia;
            break;
        case 2:
            if(anio%4 == 0 || anio%100 == 0 && anio %400 == 0)
            {
                cantdias = 29 - dia;
            }
            else
            cantdias = 28 - dia;
            break;
        case 3:  
            cantdias = 31 - dia;
            break;
        case 4: 
            cantdias = 30 - dia;
            break;
        case 5: 
            cantdias = 30 - dia;
            break;
        case 7: 
            cantdias = 31 - dia;
            break;
        case 8: 
            cantdias = 30 - dia;
            break;
        case 9:
            cantdias = 31 - dia;
            break;
        case 10: 
            cantdias = 31 -dia;
            break;
        case 11: 
            cantdias = 30 - dia;
            break;
        case 12: 
            cantdias = 31 - dia;
            break;           
    }
    printf("Para fin de mes faltan: %d dias", cantdias);
}
