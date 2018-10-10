#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"
#include "ventas.h"
//#include <stdio_ext.h>

static int generarId(void);

/**
    Funcion que genera un id unico.
*/
static int generarId(void)
{
    static int id = 0;
    id++;
    return id;
}
/**
    Funcion que genera todos los "isEmpty" de pCliente en 1, para indicar que estan vacios.
    pCliente: puntero de tipo Cliente
    limite: limite del array de cliente
**/

void cl_init_isEmpty(Cliente* pCliente, int limite)
{
    int i=0;

    if(pCliente!= NULL && i<limite)
    {
        for(i=0; i<limite; i++)
        {
            pCliente[i].isEmpty = 1;
        }
    }
}
/**
    Funcion que busca un espacio vacio y me devuelve el index del primer vacio que encuentre
    pCliente: puntero de tipo cliente
    limite: limite del array de cliente
*/

int cl_getEspacioVacio(Cliente* pCliente , int limite)
{
    int i;
    int index;

    for(i=0;i<limite;i++)
    {
        if(pCliente[i].isEmpty==1)
        {
            index = i;
        }
    }

    return index;
}
/**
    Funcion para dar de alta un cliente
    pCliente: puntero de tipo cliente
    limite: limite del array de cliente
*/
void cl_altaCliente(Cliente* pCliente, int limite)
{
    int index;

    //__fpurge(stdin);
    fflush(stdin);
    index = cl_getEspacioVacio(pCliente,limite);

    pCliente[index].id = generarId();

    //__fpurge(stdin);
    fflush(stdin);
    utn_getString("Ingrese el nombre(maximo 50 letras): ", pCliente[index].nombre,50);

    //__fpurge(stdin);
    fflush(stdin);
    utn_getString("Ingrese el apellido(maximo 50 letras): ", pCliente[index].apellido,50);

    //__fpurge(stdin);
    fflush(stdin);
    pCliente[index].cuit = utn_getInt("Ingrese el cuit: ");


    pCliente[index].isEmpty = 0;

}
/**
    Funcion para modificar un cliente
    pCliente: puntero de cliente
    limite: limite del array de cliente
*/

void cl_modificarCliente(Cliente* pCliente, int limite)
{
    int id;
    int opcion;
    int i;

    id = utn_getInt("Ingrese el ID que desea modificar: ");
    for(i=0;i<limite;i++)
    {
        if(pCliente[i].id == id)
        {
            printf("\nNombre: %s",pCliente[i].nombre);
            printf("\nApellido: %s", pCliente[i].apellido);
            printf("\nCuit: %d", pCliente[i].cuit);

            printf("\nQue dato desea modificar?");
            printf("\n1)Nombre");
            printf("\n2)Apellido");
            printf("\n3)Cuit");

            opcion = utn_getInt("\nSeleccione una opcion: ");
            if(opcion!=1 && opcion!=2 && opcion!=3)
                opcion = utn_getInt("Error. Seleccione una opcion valida: ");

            switch(opcion)
            {
                case 1:
                     utn_getString("Ingrese el nombre(maximo 50 letras): ", pCliente[i].nombre,50);
                    break;
                case 2:
                    utn_getString("Ingrese el apellido(maximo 50 letras): ", pCliente[i].apellido,50);
                    break;
                case 3:
                    pCliente[i].cuit = utn_getInt("\nIngrese el cuit: ");
                    break;
            }
        }
    }

}

/**
    Funcion para eliminar un cliente
    pCliente: puntero de tipo cliente
    limite: limite del array de cliente
*/
void cl_bajaCliente(Cliente* pCliente, int limite)
{
    int i;
    int id;
    char respuesta;

    id = utn_getInt("Ingrese el ID del cliente que desea eliminar: ");

    printf("Seguro desea eliminar este cliente(s 0 n)? Se perderan todos los datos: ");
    while(scanf("%c",&respuesta)==0 || (respuesta != 's' && respuesta!='n' && respuesta!='S' && respuesta!='N'))
    {
        printf("Error. Ingrese s o n: ");
    }


    for(i=0;i<limite;i++)
    {
        if(pCliente[i].id==id)
        {
            pCliente[i].isEmpty = 1;
        }
    }
}

/**
    Funcion para imprimir lista de cliente
    pCliente: puntero de tipo cliente
    pVentas: puntero de tipo ventas
    limiteC: limite del array de cliente
    limiteV: limite del array de ventas
*/

void cl_imprimirCliente(Cliente* pCliente,Ventas* pVentas,int limiteC,int limiteV)
{
    int i;
    int j;
    int aux=0;

    for(i=0;i<limiteC;i++)
    {
        if(pCliente[i].isEmpty==0)
        {
            for(j=0;j<limiteV;j++)
            {
                if(pCliente[i].id == pVentas[j].idCliente && pVentas[j].estado == 1)
                {
                    aux=+1;
                }
            }
            printf("\nNombre: %s",pCliente[i].nombre);
            printf("\nApellido: %s",pCliente[i].apellido);
            printf("\nCuit: %d",pCliente[i].cuit);
            printf("\nID: %d",pCliente[i].id);
            printf("\nCantidad Ventas a cobrar: %d",aux);

        }
    }
}
