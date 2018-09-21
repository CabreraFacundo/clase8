#ifndef PARCIAL_H_INCLUDED
#define PARCIAL_H_INCLUDED


typedef struct
{
    int id;
    int tipo;
    float precio;
    char nombre[50];
    char direccion[60];
    int isEmpty;

}Pantalla;

void init_isEmpty(Pantalla* pPantalla, int limite);
void altaPantalla(Pantalla* pPantalla);
int getEspacioVacio(Pantalla* pPantalla , int limite);
void get_tipo(Pantalla* pPantalla);

int buscarPantallaPorID(Pantalla* pPantalla, int limite, int id);

#endif // PARCIAL_H_INCLUDED
