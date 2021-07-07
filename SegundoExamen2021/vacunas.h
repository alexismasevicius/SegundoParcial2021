#ifndef VACUNAS_H_INCLUDED
#define VACUNAS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;
}eVacunas;

#endif // VACUNAS_H_INCLUDED

eVacunas* pais_new();

eVacunas* pais_newParametros(char* idStr,char* nombreStr,char* vac1,char* vac2,char* sinVac);

int pais_setId(eVacunas* this,int id);

int pais_getId(eVacunas* this,int* id);
int pais_setNombre(eVacunas* this,char* nombre);
int pais_getNombre(eVacunas* this,char* nombre);
int pais_setSinVac(eVacunas* this,int sinVac);
int pais_getSinVac(eVacunas* this,int* sinVac);
int pais_setVacUno(eVacunas* this,int vac1);
int pais_getVacUno(eVacunas* this,int* vac1);
int pais_setVacDos(eVacunas* this,int vac2);
int pais_getVacDos(eVacunas* this,int* vac2);

int pais_list(LinkedList* pArrayListEmployee, int len);
int mostrarPais(eVacunas* aux);

void* pais_estadisticas(void* pElement);
int pais_exitosos(void* pElement);
int pais_alHorno (void* pElement);
int pais_SortBy1Dosis (void* e1, void* e2);
int pais_masCastigados(LinkedList* pArrayListEmployee);
