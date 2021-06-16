/* 2) 
Un cyber café necesita un programa para procesar la información relacionada con las
computadoras que posee. Se necesita leer cantidad de computadoras, y precio por hora  de uso
Luego ingresar la cantidad de horas de uso de cada computadora en el mes.  se pide:  
a) calcular el monto total recaudado por el cyber en el mes.  
b) informar cual fue la computadora con menor cantidad de horas de uso y monto recaudado  por la misma.   */

#include <stdio.h>
main()

{
       
    int precioPorHS;
    int cantHS = 0;
    int CanComputadoras;
    int i = 0;
    int montoTotal = 0;
    int cantmenor = 9999;
    int menorpos;
    float montomenor = -1;

    
    printf("Ingrese la cantidad de computadoras que hay en el cyber:\n"); 
    scanf("%d", &CanComputadoras);

    printf("Ingrese el precio por hora: \n");
    scanf("%d", &precioPorHS);

    
    int computadoras[CanComputadoras];

    
    
    for(int i = 0; i <CanComputadoras; i++)
    {
        printf("Ingrese la cantidad de horas de uso de la computadora %d durante este mes: \n", i+1);
        scanf("%d", &computadoras[i]);  
        montoTotal = montoTotal + computadoras[i]*precioPorHS; 
        
        if (computadoras[i] < cantmenor)
        {
            cantmenor = computadoras[i];
            menorpos = i;
        }
        montomenor = cantmenor*precioPorHS;
  
    }

   printf("Este mes el cyber recaudo $%d\n", montoTotal);
   printf("La computadora menos usada fue la numero %d, con un monto todal de: $%1.02f",menorpos+1, montomenor);

}