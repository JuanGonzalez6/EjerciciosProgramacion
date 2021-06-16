
/* Realizar un programa que lea desde el teclado el ancho,
 alto y profundidad de un  prisma rectangular (cuerpo geométrico de 6 caras 
 rectangulares, como una caja)
 e  informe su volumen y área de la superficie formada por sus caras.  */ 

 
#include <stdio.h>
main()

{
    float ancho;
    float alto;
    float profundidad;
    float volumen = 0;
    float area = 0;

    printf("Ingrese las dimensiones del prisma  \n");
    printf("ancho:\n");
    scanf("%f", &ancho);
    printf("alto:\n");
    scanf("%f", &alto);
    printf("profundidad:\n"); 
    scanf("%f", &profundidad); 

    volumen = ancho * alto * profundidad;
    area = (profundidad*ancho*2) + (profundidad*alto*2) + (ancho*alto*2);

    printf("el volumen del prisma es: %1.02f\n",volumen);
    printf("el area del prisma es: %1.02f",area);

}
