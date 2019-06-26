#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "LinkedList.h"

#endif // LINKEDLIST_H_INCLUDED

#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include "Input.h"

#endif // INPUT_H_INCLUDED

#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "Employee.h"

#endif // EMPLOYEE_H_INCLUDED

employee* employee_newEmployee()
{
    employee* newEmployee = (employee*) malloc(sizeof(employee));

    if ( newEmployee != NULL )
    {
        newEmployee->id = 0;
        strcpy( newEmployee->nombre, " " );
        strcpy( newEmployee->apellido, " " );
        strcpy( newEmployee->sector, " " );
        newEmployee->salario = 0;
    }

    return newEmployee;
}

int employee_guardarListaAImprimir ( LinkedList* lista, char* path )
{
    int len;
    int auxReturn = -1;

    employee* employeeToSave = employee_newEmployee();
    FILE* file;

    if ( ll_len(lista) > 0 )
    {
        file = fopen(path, "w");
    }
    else
    {
        file = NULL;
    }


    if ( lista != NULL && file != NULL )
    {
        len = ll_len(lista);

        fprintf(file, "id,Nombre,Apellido,Salario,Sector\n" );
        for ( int i = 0; i < len; i++ )
        {
            employeeToSave = ll_get(lista, i);
            fprintf(file, "%d,%s,%s,$%8.2f,%s\n", employeeToSave->id, employeeToSave->nombre, employeeToSave->apellido, employeeToSave->salario, employeeToSave->sector);
        }

        auxReturn = 0;
    }

    fclose(file);
    return auxReturn;
}

int employee_cargarListaAImprimir( LinkedList* lista, char* path )
{
    int auxReturn = -1;
    int cant;
    char buffer [5][25];

    employee* employeeToLoad;

    FILE* file;

    file = fopen(path, "r");

    if ( file != NULL && lista != NULL)
    {
        fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4] );
        ll_clear(lista);

        while( !feof(file) )
        {
            cant = fscanf(file, "%[^,],%[^,],%[^,],$%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4] );
            if ( cant != 5 )
            {
                if ( feof(file) )
                {
                    break;
                }
                else
                {
                    system("cls");
                    printf("//ERROR// no se pudo leer el ultimo registro");
                    break;
                }
            }

            employeeToLoad = employee_newEmployee();

            if ( employeeToLoad != NULL )
            {
                employeeToLoad->id = atoi(buffer[0]);
                strcpy(employeeToLoad->nombre, buffer[1]);
                strcpy(employeeToLoad->apellido, buffer[2]);
                strcpy(employeeToLoad->sector, buffer[4]);
                employeeToLoad->salario = atof(buffer[3]);

                ll_add(lista, employeeToLoad);
            }
            else
            {
                printf("algo salio para el tuje...");
                ll_clear(lista);
                break;
            }
            auxReturn = 0;
        }
    }

    fclose(file);
    return auxReturn;
}

int employee_altaEmpelado(LinkedList* lista)
{
    int auxReturn = -1;
    int ultimoID;
    int opcion;

    employee* newEmployee = employee_newEmployee();

    if ( lista != NULL && newEmployee != NULL )
    {
        ultimoID = employee_findLastId(lista);

        newEmployee->id = ultimoID + 1;
        input_getName(newEmployee->nombre, "||\n|| Ingrese el nombre del empleado: ", "||\n|| //ERROR// El nombre debe tener mas de 2 letras y menos de 25", 2, 25);
        input_getName(newEmployee->apellido, "||\n|| Ingrese el apellido del empleado: ", "||\n|| //ERROR// El apellido debe tener mas de 2 letras y menos de 25", 2, 25);
        input_getFloat(&newEmployee->salario, "||\n|| Ingrese el salario del empleado: ", "||\n|| //ERROR// El nombre debe tener mas de 2 letras y menos de 25", 8000, 100000);


        printf("||\n|| 1) Analista\n");
        printf("|| 2) Programador\n");
        printf("|| 3) Tester\n");

        input_getInt( &opcion, "||\n|| Ingrese el sector al que pertenece el empleado: ", "||\n|| //ERROR// Opcion invalida o inexistente",1,3);

        fflush(stdin);

        switch ( opcion )
        {
            case 1:
                strcpy(newEmployee->sector , "Analista");
                break;

            case 2:
                strcpy(newEmployee->sector , "Programador");
                break;

            case 3:
                strcpy(newEmployee->sector , "Tester");
                break;
        }
        ll_add(lista, newEmployee);
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_findLastId ( LinkedList* lista )
{
    int max = 0;
    employee* employeeToFind = NULL;

    if ( lista != NULL )
    {
        for ( int i = 0; i < ll_len(lista); i++ )
        {
            employeeToFind  = ll_get(lista, i);

            if ( employeeToFind->id > max )
            {
                max = employeeToFind->id;
            }
        }
    }
    return max;
}

int employee_listarEmpleados( LinkedList* lista )
{
    int len;
    int auxReturn = -1;

    employee* employeeToList = NULL;

    if ( ll_isEmpty(lista) == 0 )
    {
        if ( lista != NULL  )
        {
            system("cls");
            len = ll_len(lista);

            printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("||  ID  | NOMBRE                    | APELLIDO                  | SALARIO    | SECTOR                    ||\n");
            printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");

            for ( int i = 0; i < len; i++ )
            {
                employeeToList = ll_get(lista, i);
                printf("|| %04d | %-25s | %-25s | $%-9.2f | %-25s ||\n", employeeToList->id, employeeToList->nombre, employeeToList->apellido, employeeToList->salario, employeeToList->sector);
            }
            printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");

            auxReturn = 0;
        }
    }

    return auxReturn;
}

int ordenarListaSector ( void* employeeA, void* employeeB )
{
    int auxReturn = 0;
    int compareSector;

    compareSector = stricmp( ((employee*) employeeA)->sector,((employee*) employeeB)->sector );

    if(  compareSector > 0 )
    {
        auxReturn = 1;
    }

    if( compareSector < 0 )
    {
        auxReturn = -1;
    }

    return auxReturn;
}

int ordenarListaNombreYApellido ( void* employeeA, void* employeeB )
{
    int auxReturn = 0;
    int compareNames;
    int compareSurnames;

    compareNames = stricmp( ((employee*) employeeA)->nombre,((employee*) employeeB)->nombre );
    compareSurnames = stricmp( ((employee*) employeeA)->apellido,((employee*) employeeB)->apellido );

    if(  compareNames > 0 )
    {
        auxReturn = 1;
    }

    if( compareNames == 0 && compareSurnames > 0 )
    {
        auxReturn = 1;
    }

    if( compareNames < 0 )
    {
        auxReturn = -1;
    }

    if( compareNames == 0 && compareSurnames < 0 )
    {
        auxReturn = -1;
    }

    return auxReturn;
}

int employee_ordenarLista ( LinkedList* lista )
{
    int auxReturn = ll_isEmpty(lista);

    if ( auxReturn == 0 )
    {
        auxReturn = ll_sort( lista, ordenarListaNombreYApellido, 1 );
    }
    if ( auxReturn == 0)
    {
        auxReturn = ll_sort( lista, ordenarListaSector, 1 );
    }

    return auxReturn;
}

int FiltradoPorSalarioYSector(void* elemento, void* sector)
{
    int returnAux = 0;

    if ( *((float*) elemento)> 60000.00 && strcmp( ((char*) sector), "Programador") == 0 )
    {
        returnAux = 1;
    }

    return returnAux;
}

LinkedList* employee_filter(LinkedList* lista)
{

    int len;
    LinkedList* newLinkedList = NULL;
    employee* auxEmployee = NULL;

    if ( lista != NULL && ll_isEmpty(lista) == 0 )
    {
        newLinkedList = ll_newLinkedList();
        auxEmployee =  employee_newEmployee();

        if ( newLinkedList != NULL && auxEmployee != NULL )
        {
            system("cls");
            len = ll_len(lista);

            for ( int i = 0; i < len; i++ )
            {
                auxEmployee = ll_get(lista, i);

                if ( FiltradoPorSalarioYSector( &auxEmployee->salario, auxEmployee->sector ) )
                {
                    ll_add(newLinkedList, auxEmployee);
                }
            }
        }
    }

    return newLinkedList;
}
