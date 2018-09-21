#include <stdio_ext.h>
#include <stdlib.h>
#include "producto.h"
#define CANTIDAD 200

int main()
{


    Producto productos[CANTIDAD];
    /*printf("\nMenu Principal\n\na-Carga de producto\nb-Imprimir lista de productos cargados\n");
    scanf("Opcion%c")*/



    inicializarArray(productos,CANTIDAD);
    menu(productos,CANTIDAD);
    /*cargaProducto(productos,2);
    imprimirArray(productos,2);
    buscarIndiceVacio(productos,CANTIDAD,&indice);*/




    return 0;
}
