#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "vacunas.h"

int parser_FromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int i;
    int cont;
    int len;
    char id[50];
    char nombre[50];
    char vac1dosis[50];
    char vac2dosis[50];
    char sinVac[50];

    eVacunas* miPais;


    i=0;

    cont = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]",id,nombre,vac1dosis,vac2dosis,sinVac);
    while(!feof(pFile))
    {
        cont = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]",id,nombre,vac1dosis,vac2dosis,sinVac);

        if(cont==5)
        {
            miPais=pais_newParametros(id,nombre,vac1dosis,vac2dosis,sinVac);

            ll_add(pArrayListEmployee, miPais);

            i++;
        }

    }
    fclose(pFile);

    len = ll_len(pArrayListEmployee);

    pais_list(pArrayListEmployee,len);

    printf("cantidad de elementos cargados es de: %d \n", len);

    return 0;

}
