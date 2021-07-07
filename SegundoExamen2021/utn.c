
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
* \brief Verifica  si una cadema de caracteres es numerica
* \ param cadena Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*
*/
int esNumerica ( char * cadena)
{
    int i=0;
    int retorno = 1;
    if (cadena != NULL && strlen (cadena) > 0)
    {
        while (cadena[i] != '\0' )
        {
            if (cadena[i] < '0' || cadena[i] > '9' )
            {
                retorno = 0;
                break ;
            }
            i++;
        }
    }
    return retorno;
}



/**
* \brief Verifica si es numerico
* \ param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*
*/

int getInt(int * pResultado)
{
    int ret=-1;
    char buffer[64];
    scanf("%s" ,buffer);
    if (esNumerica(buffer))
    {
        *pResultado = atoi(buffer);
        ret=1;
    }
    return ret;
}



/**
* \brief Solicita un numero al usuario , leuego de verificarlo devuelve el resultado
* \ param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \ param mensaje Es el mensaje a ser mostrado
* \ param mensajeError Es el mensaje de Error a ser mostrado
* \ param minimo Es el numero maximo a ser aceptado
* \ param maximo Es el minimo minimo a ser aceptado
* \return Retorna 0 si se obtuvo el numero y -1 si no
*/

int utn_getNumero ( int * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos)
{
    int bufferInt;
    int retorno = 0;
    while (reintentos>0)
    {
        reintentos--;
        printf ( "%s" ,mensaje);
        if (getInt(&bufferInt) == 1)
        {
            if (bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 1;
                break ;
            }
        }
        printf ( "%s" ,mensajeError);
    }
    return retorno;
}

int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    float buffer;
    int todoOk = 0;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<= maximo && reintentos>=0) // valido los parametros que recibo
    {
        do
        {
            printf("%s", mensaje);

            if(scanf("%f", &buffer)==1)
            {
                if(buffer>=minimo && buffer<=maximo)
                {
                    *pResultado = buffer;
                    todoOk=1;
                    break;
                }
            }
            fflush(stdin);

            printf("%s", mensajeError);
            reintentos--;


        }while(reintentos>=0);
    }
    return todoOk;

}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{

    printf("%s",mensaje);
    fflush(stdin);
    gets(input);

}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto alfanumerico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo alfanumerico
 */
int getStringAlfanumerico(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esAlfaNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un nombre al usuario y lo devuelve con mayuscula en las primeras letras de cada palabra
 * \param mensaje Es el mensaje a ser mostrado
 * \param tam Es el tamanio del array
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo alfanumerico
 */
int getStringNombre(char mensaje[],int tam,char input[])
{
    char aux[256];

    getString(mensaje,aux);

    if(esSoloLetras(aux) && strlen(aux)<=tam)
    {
        strlwr(aux);
        aux[0]=toupper(aux[0]);
        for(int i=0; aux[i] !='\0'; i++)
        {
            if(aux[i]== ' ')
            {
                aux[i+1] = toupper(aux[i+1]);//convierto a mayuscula el caracter siguiente al indice
            }
        }
        strcpy(input,aux);

        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un string de texto unicamente
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */
void utn_getSoloTexto(char requestMessage[],char errorMessage[], char input[])

{
    while(1) // no sale de la condicion, vuelve a pedirla con el continue y break si es correcta.
    {
        if (getStringLetras(requestMessage,input)==0)
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        fflush(stdin);
        break;
    }

}


/**
 * \brief Solicita un string de texto alfanumerico
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */
void utn_getTextoYNumeros(char requestMessage[],char errorMessage[], char input[])

{
    while(1) // no sale de la condicion, vuelve a pedirla con el continue y break si es correcta.
    {
        if (getStringAlfanumerico(requestMessage,input)==0)
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        fflush(stdin);
        break;
    }

}


/**
 * \brief Solicita un nombre y lo carga con la primer letra en mayuscula
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param tam extension maxima del nombre
 * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */
void utn_getNombre(char requestMessage[],char errorMessage[], int tam, char input[])

{
    while(1) // no sale de la condicion, vuelve a pedirla con el continue y break si es correcta.
    {
        if (getStringNombre(requestMessage,tam,input)==0)
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        fflush(stdin);
        break;
    }

}
