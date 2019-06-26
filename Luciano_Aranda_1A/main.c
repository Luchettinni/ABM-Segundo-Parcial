#include <stdio.h>
#include <stdlib.h>

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "LinkedList.h"

#endif // LINKEDLIST_H_INCLUDED

#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "Employee.h"

#endif // EMPLOYEE_H_INCLUDED

int menuPrincipal( char* buildInfo );

int main()
{
    int opcionMenu = 0;
    char buildInfo [] = "Version: 5.5.1";

    LinkedList* lista = ll_newLinkedList();
    LinkedList* listaFiltrada = NULL;

    do
    {
        opcionMenu = 0;
        system("cls");

        switch ( menuPrincipal(buildInfo) )
        {
            case 1:
                if ( employee_altaEmpelado(lista) )
                {
                     printf("||\n|| //ERROR// No hay elementos que listar... \n\n");
                }
                else
                {
                    printf("||\n|| //EXITO// Se realizo esta operacion satisfactoriamente!\n\n");
                }
                system("pause");
                break;

            case 2:
                employee_ordenarLista(lista);

                if ( employee_listarEmpleados(lista) )
                {
                     printf("||\n|| //ERROR// No hay elementos que listar... \n\n");
                }
                else
                {
                    printf("||\n|| //EXITO// Se realizo esta operacion satisfactoriamente!\n\n");
                }
                system("pause");
                break;

            case 3:
                if ( employee_cargarListaAImprimir(lista, "data.csv") )
                {
                    printf("||\n|| //ERROR// no se encontro el archivo - data.csv - // lista NULA \n\n");
                }
                else
                {
                    printf("||\n|| //EXITO// Se cargaron los datos correctamente!\n\n");
                }
                system("pause");
                break;

            case 4:
                if ( employee_guardarListaAImprimir(lista, "data.csv") )
                {
                    printf("||\n|| //ERROR// puede que lo siguiente este causando este problema...\n");
                    printf("||\n|| // 1) // no hay elementos que guardar\n");
                    printf("|| // 2) // no hay espacio para realizar el guardado\n");
                    printf("|| // 3) // Lista NULA\n\n");
                }
                else
                {
                    printf("||\n|| //EXITO// Se guardaron los datos correctamente!\n\n");
                }
                system("pause");
                break;

            case 5:
                listaFiltrada = employee_filter(lista);

                if ( listaFiltrada != NULL  )
                {
                    if ( ll_isEmpty(listaFiltrada) != 1 )
                    {
                        employee_listarEmpleados(listaFiltrada);
                        printf("||\n|| //EXITO// Se realizo el filtrado satisfactoriamente!\n");
                        employee_guardarListaAImprimir(listaFiltrada, "out.csv" );
                        printf("||\n|| //EXITO// Se realizo el guardado de esta lista satisfactoriamente!\n\n");
                    }
                    else
                    {
                        printf("||\n|| //ADVERTENCIA// Nadie paso el filtro, por lo cual no se guardo ningun archivo\n\n");
                    }
                }
                else
                {
                    printf("||\n|| //ERROR// No hay elementos que filtrar\n\n");
                }

                system("pause");
                break;

            case 6:
                opcionMenu = 1;
                system("pause");
                break;

            default:
                printf("||\n|| //ERROR// Numero de opcion invalido...\n");
                printf("||\n|| //Sugerencia// Intenta utilizando NUMEROS correspondientes a los del menu.\n\n");
                system("pause");
                break;
        }

    } while (opcionMenu != 1);

    return 0;
}

int menuPrincipal( char* buildInfo )
{
    int opcion;
    char solapaActual [] = "Menu principal";

    fflush(stdin);

    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("||  %-14s  || ABM Empleaditos ||  %-15s  ||\n", buildInfo, solapaActual);
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");

    printf("||- - - - - - - - - - - - - - - - - - - - \n");
    printf("|| 1) Alta de empleado\n");
    printf("||- - - - - - - - - - - - - - - - - - - - \n");
    printf("|| 2) Mostrar lista actual \n");
    printf("||- - - - - - - - - - - - - - - - - - - - \n");
    printf("|| 3) Cargar lista de empleados a imprimir (csv)\n");
    printf("|| 4) Crear/Guardar lista de empleados a imprimir(csv)\n");
    printf("||- - - - - - - - - - - - - - - - - - - - \n");
    printf("|| 5) Filtrar...\n");
    printf("|| 6) Salir... \n");

    printf("||\n|| Que desea hacer?: ");
    scanf("%d", &opcion);

    return opcion;
}
