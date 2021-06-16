#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Datos
{
    char Nombre[20];
    char Apellido[20];
    int Documento;
    int Dia;
    int Mes;
    int Anio;
    int NumVentanilla;
};
void limpiararchivo()
{
    remove("Planilla.txt");
}
void cargar_archivo(struct Datos personas)
{
    FILE *Archivo;
    Archivo = fopen("Planilla.txt", "at");
    personas.NumVentanilla = rand() % 10;
    
    fprintf(Archivo, "%s %s\n", personas.Nombre, personas.Apellido);
    fprintf(Archivo, "%i\n", personas.Documento);
    fprintf(Archivo, "%i\n %i\n %i\n", personas.Dia, personas.Mes, personas.Anio);
    fprintf(Archivo, "%i", personas.NumVentanilla);
    fclose(Archivo);
}

bool validar_turno(struct Datos personas)
{
    struct Datos PersonaNueva;
    FILE *Archivo;
    Archivo = fopen("Planilla.txt", "a+");

    if (Archivo == NULL)
    {
        printf("Lectura erronea");
        return false;
    }
    while (!feof(Archivo))
    {
        fscanf(Archivo, "%s\t %s\t %i\t %i\t %i\t %i\t %i", &PersonaNueva.Nombre, &PersonaNueva.Apellido,&PersonaNueva.Documento, &PersonaNueva.Dia, &PersonaNueva.Mes, &PersonaNueva.Anio, &PersonaNueva.NumVentanilla);
    }
    
    if (personas.Documento == PersonaNueva.Documento)
    {   
        personas.NumVentanilla = rand() %10;
        printf("Turno ya asignado en la ventanilla numero: %i", personas.NumVentanilla);
        fclose(Archivo);
        return false;
    }
    fclose(Archivo);
    cargar_archivo(personas);
    return true;
}

void cargar_turno(struct Datos personas)
{
    printf("Ingrese su nombre:\n");
    scanf("%s", personas.Nombre);

    printf("Ingrese su apellido:\n");
    scanf("%s", personas.Apellido);

    printf("Ingrese su numero de documento:\n");
    scanf("%i", &personas.Documento);

    printf("Ingrese su fecha de nacimiento: (DD/MM/AA)\n");
    printf("Dia:\n"),
    scanf("%i", &personas.Dia);
    printf("Mes:\n");
    scanf("%i", &personas.Mes);
    printf("Anio:\n");
    scanf("%i", &personas.Anio);
    printf("\n");
    if (validar_turno(personas))
    {
        printf("Se ha cargado correctamente\n");
    }
    else
    {
        printf("\nNo se ha podido cargar correctamente");
    }
}


void listar()
{
    printf("Turnos: \n ");
    struct Datos personaAux;
    FILE *archivo;
    archivo = fopen("Planilla.txt", "rt");

    while (fscanf(archivo, "%s %s %i %i %i %i %i", &personaAux.Nombre, &personaAux.Apellido, &personaAux.Documento, &personaAux.Dia, &personaAux.Mes, &personaAux.Anio, &personaAux.NumVentanilla) != EOF)
    {
        printf("Nombre: %s %s \n Documento: %i\n Fecha: %i %i %i\n Ventanilla: %i\n", personaAux.Nombre, personaAux.Apellido, personaAux.Documento, personaAux.Dia, personaAux.Mes, personaAux.Anio, personaAux.NumVentanilla);
    }

    fclose(archivo);
}
void main()
{   
    srand(time(NULL));
    int menu;
    while (menu != 3)
    {   
        printf("\n");
        printf("Bienvenido:\n");
        printf("\t\tMenu de opciones\n\n1. Ingresar turno\n2. Lista de pacientes\n3. SALIR\n\n");
        printf("Ingrese un numero por favor:\n>");
        scanf("%i", &menu);
        switch (menu)
        {
        case 1:
        {
            struct Datos personas;
            cargar_turno(personas);
        }
        break;
        case 2:
        {
            listar();
        }
        break;
        case 3:
        {   
            limpiararchivo();
            printf("Salio del programa");
        }
        break;
        }
    }
}

