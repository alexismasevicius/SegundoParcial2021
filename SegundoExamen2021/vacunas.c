#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "vacunas.h"
#include "vacunas.h"


eVacunas* pais_new()
{
    eVacunas* miPais;

    miPais=(eVacunas*) malloc (sizeof(eVacunas));

    return miPais;

}

eVacunas* pais_newParametros(char* idStr,char* nombreStr,char* vac1,char* vac2,char* sinVac)
{
    eVacunas* miPais;


    miPais=pais_new();


    if(pais_setId(miPais,atoi(idStr))==0 ||
        pais_setNombre(miPais,nombreStr)==0 ||
        pais_setVacUno(miPais,atoi(vac1))==0 ||
        pais_setVacDos(miPais,atoi(vac2))==0 ||
        pais_setSinVac(miPais,atoi(sinVac))==0)
    {
        free(miPais);
        miPais=NULL;
    }

    return miPais;// retornar  // si no =NULL

}



int pais_setId(eVacunas* this,int id)
{
    if(id>=0 && this!=NULL)
    {
        this -> id = id;
        return 1;
    }
    else
    {
        return 0;
    }
}

int pais_getId(eVacunas* this,int* id)
{
    if(this!=NULL && id!=NULL)
    {
        *id = this->id;
        return 1;
    }
    else
    {
        return 0;
    }
}

int pais_setNombre(eVacunas* this,char* nombre)
{
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        return 1;
    }
    else
    {
        return 0;
    }
}
int pais_getNombre(eVacunas* this,char* nombre)
{
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        return 1;
    }
    else
    {
        return 0;
    }
}

int pais_setSinVac(eVacunas* this,int sinVac)
{
    if(this!=NULL)
    {
        this -> sinVacunar = sinVac;
        return 1;
    }
    else
    {
        return 0;
    }
}

int pais_getSinVac(eVacunas* this,int* sinVac)
{
    if(this!=NULL && sinVac!=NULL)
    {
        *sinVac = this->sinVacunar;
        return 1;
    }
    else
    {
        return 0;
    }

}

int pais_setVacUno(eVacunas* this,int vac1)
{
    if(this!=NULL)
    {
        this -> vac1dosis = vac1;
        return 1;
    }
    else
    {
        return 0;
    }
}

int pais_getVacUno(eVacunas* this,int* vac1)
{
    if(this!=NULL && vac1!=NULL)
    {
        *vac1 = this->vac1dosis;
        return 1;
    }
    else
    {
        return 0;
    }
}

int pais_setVacDos(eVacunas* this,int vac2)
{
    if(vac2>=0 && this!=NULL)
    {
        this -> vac2dosis = vac2;
        return 1;
    }
    else
    {
        return 0;
    }
}

int pais_getVacDos(eVacunas* this,int* vac2)
{
    if(this!=NULL && vac2!=NULL)
    {
        *vac2 = this->vac2dosis;
        return 1;
    }
    else
    {
        return 0;
    }
}


int pais_list(LinkedList* pArrayListEmployee, int len)
{
    int i;
    eVacunas* aux;

    printf("ID   |        NOMBRE  | VAC 1   |  VAC 2 | SIN VAC \n");
    for(i=0; i<len; i++)
    {
        aux=(eVacunas*)ll_get(pArrayListEmployee, i);
        mostrarPais(aux);
    }

    return 0;
}

int mostrarPais(eVacunas* aux)
{
    int todoOk=0;
    int id;
    int vac1;
    char nombre[50];
    int vac2;
    int sinVac;
    int auxInt;
    int auxNom;
    int auxVac1;
    int auxVac2;
    int auxSinVac;



    auxInt=pais_getId(aux, &id); //PONER LA VALIDACION DENTRO IF
    auxNom=pais_getNombre(aux, nombre);
    auxVac1=pais_getVacUno(aux, &vac1);
    auxVac2=pais_getVacDos(aux,&vac2);
    auxSinVac=pais_getSinVac(aux,&sinVac);


    if(auxInt==1 && auxNom==1 && auxVac1==1 && auxVac2==1 && auxSinVac==1)
    {
        printf("%4d |%15s |%8d | %8d | %8d\n",id,nombre,vac1,vac2,sinVac);
        todoOk=1;
    }

    return todoOk;
}


void* pais_estadisticas(void* pElement)
{

    eVacunas* aux;

    aux=pais_new();

    aux->id=((eVacunas*)pElement)->id;
    strcpy(aux->nombre,((eVacunas*)pElement)->nombre);
    aux->vac1dosis=((eVacunas*)pElement)->vac1dosis;
    aux->vac2dosis=((eVacunas*)pElement)->vac2dosis;
    aux->sinVacunar=((eVacunas*)pElement)->sinVacunar;

    aux->vac1dosis=rand() % 58 + 1;
    aux->vac2dosis=rand() %  38 + 1;
    aux->sinVacunar=100 - (aux->vac1dosis+aux->vac2dosis);

    return aux;
}

int pais_exitosos(void* pElement)
{
    return ((eVacunas*) pElement)->vac2dosis>30;
}

int pais_alHorno (void* pElement)
{
    int todoOk=0;
    eVacunas* miPais=NULL;
    int vac;
    int noVac;


    miPais=(eVacunas*) pElement;
    vac=(miPais->vac1dosis)+(miPais->vac2dosis);
    noVac=miPais->sinVacunar;
    if(noVac>vac)
    {
        todoOk=1;
    }


    return todoOk;
}


int pais_SortBy1Dosis (void* e1, void* e2)
{
    int resultado = 0;

    eVacunas* auxEmpleado;
    eVacunas* auxEmpleadoDos;
    auxEmpleado=e1;
    auxEmpleadoDos=e2;
    int idUno;
    int idDos;

    if(e1!=NULL && e2!=NULL)
    {
        pais_getVacUno(auxEmpleado, &idUno);
        pais_getVacUno(auxEmpleadoDos, &idDos);
        if(idUno>idDos)
        {
            resultado=1;
        }
        else
        {
            resultado=-1;
        }
    }
    return resultado;
}

int pais_masCastigados(LinkedList* pArrayListEmployee)
{
    eVacunas* aux=NULL;
    int len=ll_len(pArrayListEmployee);
    int acumulador[len];
    int flag=0;
    int mayor;

    for(int i=0; i<len; i++)
    {
        acumulador[i]=0;
    }

    for(int i=0; i<len; i++)
    {
        aux=(eVacunas*) ll_get(pArrayListEmployee, i);
        acumulador[i]=aux->sinVacunar;
    }

    for(int i=0; i<len; i++)
    {
        if(flag==0||acumulador[i]>mayor)
        {
            flag=1;
            mayor=acumulador[i];
        }
    }

    printf("Paises con mayor cantidad de personas SIN VACUNAR: \n");
     for(int i=0; i<len; i++)
    {
        if(acumulador[i]==mayor)
        {
            aux=(eVacunas*) ll_get(pArrayListEmployee, i);
            mostrarPais(aux);
        }
    }

    return 0;
}

