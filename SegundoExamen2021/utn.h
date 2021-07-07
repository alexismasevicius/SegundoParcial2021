#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int esNumerica ( char * cadena);

int getInt( int * pResultado);

//int getFloat(float* pResultado);

int utn_getNumero( int * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos);

int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int esSoloLetras(char str[]);

int esAlfaNumerico(char str[]);

void getString(char mensaje[],char input[]);

int getStringLetras(char mensaje[],char input[]);

int getStringAlfanumerico(char mensaje[],char input[]);

int getStringNombre(char mensaje[],int tam,char input[]);

void utn_getSoloTexto(char requestMessage[],char errorMessage[], char input[]);

void utn_getTextoYNumeros(char requestMessage[],char errorMessage[], char input[]);

void utn_getNombre(char requestMessage[],char errorMessage[], int tam, char input[]);



#endif // UTN_H_INCLUDED

