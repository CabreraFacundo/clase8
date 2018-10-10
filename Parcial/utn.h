#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_getInt();
float utn_getFloat();
char utn_getChar();

char utn_getNumeroAleatorio(int desde , int hasta, int iniciar);

int utn_esNumerico(char *str) ;
int utn_esTelefono(char *str);
int utn_esAlfaNumerico(char *str);
int utn_esSoloLetras(char *str);
int utn_esNumericoFlotante(char str[]);

void utn_getString(char mensaje[],char input[],int limite);
int utn_getStringLetras(char mensaje[],char input[],int limite);
int utn_getStringNumeros(char mensaje[],char input[]);
int utn_getStringNumerosFlotantes(char mensaje[],char input[]);

int utn_getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
void utn_getValidString(char requestMessage[],char errorMessage[], char input[]);

void utn_cleanStdin(void);


#endif // UTN_H_INCLUDED
