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

	int retorno = -1;

		Employee* empleado;

		char id[128];
		char nombre[128];
		char horasTrabajadas[128];
		char sueldo[128];

		if(pFile != NULL &&  pArrayListEmployee!= NULL){

				fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);



			while(!feof(pFile)){

				fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", id, nombre, horasTrabajadas, sueldo);
				printf("%s - %s - %s - %s\n", id, nombre, horasTrabajadas, sueldo);
				empleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

				if(empleado != NULL){
					if(ll_add(pArrayListEmployee, empleado) == -1){
						puts("Error");

					}else{
						retorno = 0;
					}
				}
			}
		}
		return retorno;
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
    int retorno = -1;

    Employee* empleado;

    if(pFile != NULL && pArrayListEmployee){


         while(!feof(pFile)){



        	 empleado = employee_new();
             if(empleado != NULL){
                 fread(empleado,sizeof(Employee),1,pFile);
                 if(!feof(pFile)){


                        retorno =  ll_add(pArrayListEmployee,empleado);

                 }
             }

         }
    }

    return retorno;
}
