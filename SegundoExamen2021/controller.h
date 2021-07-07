#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee);
LinkedList* controller_estadisticas (LinkedList* pArrayListEmployee);
LinkedList* controller_filterExito (LinkedList* pArrayListEmployee);
LinkedList* controller_filterHorno (LinkedList* pArrayListEmployee);
int controller_ordenar (LinkedList* pArrayListEmployee);


#endif // CONTROLLER_H_INCLUDED
