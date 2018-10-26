#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];
    Employee* auxEmployee;
    int flag = 1;
    int ret;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            if(flag)
            {
                fscanf(pFile,"%s\n",bufferId);
                flag = 0;
            }

            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                                    bufferId,
                                    bufferNombre,
                                    bufferHorasTrabajadas,
                                    bufferSueldo)==4)
            {
                auxEmployee = Employee_newConParametros(bufferId,
                                                    bufferNombre,
                                                    bufferHorasTrabajadas,
                                                    bufferSueldo);

                ll_add(pArrayListEmployee, auxEmployee);
                ret=1;
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        printf("\nError!!!");
        ret = 0;
    }

    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
