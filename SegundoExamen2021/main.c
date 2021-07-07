#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "controller.h"
#include "utn.h"
#include "vacunas.h"


void menu ();

int main()
{
    srand(time(NULL));
    int opcion;
    LinkedList* miLista;
    LinkedList* miListaDos;
    LinkedList* miListaExitosos;
    LinkedList* miListaAlHorno;


    char archivo[40];
    int flag=0;
    int flagDos=0;

    miLista = ll_newLinkedList();

    if(miLista==NULL)
    {
        printf("No se pudo crear la lista.  \n");
    }
    else
    {
        do
        {
            printf("\n");
            menu();

            utn_getNumero(&opcion,"Ingrese una opcion: \n", "Error. Ingrese una opcion valida.\n",1,10,100);

            switch(opcion)
            {
                case 1:
                    system("cls");
                    printf("Ingrese nombre del archivo :\n");
                    scanf("%s" ,archivo);
                    if(controller_loadFromText(archivo, miLista)==0)
                    {
                        printf("\nError en la carga\n");
                    }
                    break;
                case 2:
                    system("cls");
                    if(flag==0)
                    {
                        pais_list(miLista,ll_len(miLista));
                    }
                    else
                    {
                        pais_list(miListaDos,ll_len(miLista));
                        if(flag==2)
                        {
                            printf("\n    PAISES EXITOSOS:   \n");
                            pais_list(miListaExitosos,ll_len(miListaExitosos));
                            if(flagDos==1)
                            {
                                printf("\n    PAISES AL HORNO:   \n");

                                pais_list(miListaAlHorno,ll_len(miListaAlHorno));
                            }
                        }
                    }
                    break;
                case 3:
                    miListaDos=controller_estadisticas(miLista);
                    flag=1;
                    break;
                case 4:
                    miListaExitosos=controller_filterExito(miListaDos);
                    flag=2;
                    break;
                case 5:
                    miListaAlHorno=controller_filterHorno(miListaDos);
                    flagDos=1;
                    break;
                case 6:
                    controller_ordenar(miListaDos);
                    break;
                case 7:
                    pais_masCastigados(miListaDos);
                    break;
                case 8:
                    ll_deleteLinkedList(miLista);
                    ll_deleteLinkedList(miListaDos);
                    ll_deleteLinkedList(miListaExitosos);
                    ll_deleteLinkedList(miListaAlHorno);


                    break;
           }
        }while(opcion!=8);
    }
    return 0;
}


void menu ()
{
    printf("*******************************\n");
    printf("1-Cargar archivos .csv\n");
    printf("2-Imprimir lista.\n");
    printf("3-Asignar estadisticas\n");
    printf("4-Filtrar por paises exitosos\n");
    printf("5-Filtrar por paises en el horno\n");
    printf("6-Ordenar por nivel de vacunacion\n");
    printf("7-Mostrar mas castigado \n");
    printf("8-Salir.\n");
    printf("*******************************\n");

}
