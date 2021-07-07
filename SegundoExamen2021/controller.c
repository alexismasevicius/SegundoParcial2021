#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"
#include "parser.h"
#include "vacunas.h"

/** \brief carga un archivo csv
 *
 * \param char* dirección del archivo
 * \param LinkedList* puntero a la lista
 * \return 1 si se cargó correctamente, 0 si hubo un error
 *
 */

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int controlador;
    int todoOk=0;

    controlador=ll_isEmpty(pArrayListEmployee);
    pFile = fopen(path, "r");

    if(controlador==1)
    {
        if(pFile!=NULL && pArrayListEmployee!=NULL)
        {
            parser_FromText(pFile, pArrayListEmployee);
            todoOk=1;
        }
    }
    else
    {
        printf("\nYa hay una lista cargada\n\n");
    }

    return todoOk;
}



LinkedList* controller_estadisticas (LinkedList* pArrayListEmployee)
{
    LinkedList* miListaDos;
    miListaDos=ll_map(pArrayListEmployee,pais_estadisticas);
    pais_list(miListaDos,ll_len(miListaDos));


    return miListaDos;
}



LinkedList* controller_filterExito (LinkedList* pArrayListEmployee)
{
    LinkedList* miListaTres;
    miListaTres=ll_filter(pArrayListEmployee,pais_exitosos);
    printf("\n    PAISES EXITOSOS:   \n");
    pais_list(miListaTres,ll_len(miListaTres));

    return miListaTres;
}



LinkedList* controller_filterHorno (LinkedList* pArrayListEmployee)
{
    LinkedList* miListaTres;
    miListaTres=ll_filter(pArrayListEmployee,pais_alHorno);
        printf("\n    PAISES AL HORNO:   \n");

    pais_list(miListaTres,ll_len(miListaTres));

    return miListaTres;
}



int controller_ordenar (LinkedList* pArrayListEmployee)
{
    int todoOk=0;

    if(pArrayListEmployee!=NULL)
    {
        printf("\nOrdenando...\n");
        if(ll_sort(pArrayListEmployee,pais_SortBy1Dosis, 1)==0) //valido puntero a lista
        {
            todoOk=1;
            printf("\nPaises ordenados por PRIMERA DOSIS:\n");

            pais_list(pArrayListEmployee,ll_len(pArrayListEmployee));
        }

    }

    return todoOk;

}
