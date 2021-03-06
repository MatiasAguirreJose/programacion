#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Input.h"
#include "ArrayEmployees.h"
#define TRUE 0
#define FALSE 1

int initEmployees(Employee* list, int len){

    int retorno;
    retorno = -1;
	int i;
	if(list != NULL && len >= 0){

		for(i = 0; i < len; i++)
		{
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}

	return retorno;
}

int buscarLibre(Employee* list, int len){
    int retorno = -1;
    if(list != NULL && len >= 0){
		for (int i = 0; i < len; ++i) {
			if(list[i].isEmpty == TRUE){
				retorno = i;
				break;
			}
		}
    }
    return retorno;
}

int cargarEmpleado(char name[],char lastName[],float* salary,int* sector){
	int retorno = 0;

	if(name != NULL && lastName != NULL && salary != NULL && sector != NULL){
		if(ObtenerString("Ingrese el nombre del empleado",name,21,3) == -1){
			puts ("Cancelando carga...");
			  retorno = -1;
			  return retorno;

		}
		else if(ObtenerString("Ingrese el apellido del empleado",lastName,21,3) == -1){
			puts ("Cancelando carga...");
			 retorno = -1;
			 return retorno;
		}
		else if(ObtenerFlotanteMayorACero(salary,"Ingresar el salario del empleado\n",3) == -1){
			retorno = -1;
			return retorno;
		}
		else if(ObtenerEnteroMayorACero(sector,"Ingresar el sector del empleado\n",3) == -1){
			retorno = -1;
			return retorno;
		}
	}

		return retorno;
}
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno = -1;

	 if(list != NULL && len >= 0 && id >= 0 && salary >= 0 && sector >=0 ){

		int posicion;
		posicion = searchFreeSpace(list,len);
		if(posicion != -1){
			list[posicion].id = id;
			strcpy(list[posicion].name, name);
			strcpy(list[posicion].lastName, lastName);
			list[posicion].salary = salary;
			list[posicion].sector = sector;
			list[posicion].isEmpty= FALSE;
			retorno = 0;

		}
	 }

    return retorno;
}

int findEmployeeById(Employee* list, int len,int id){
	int retorno = -1;
	if(list != NULL && len >= 0 && id >= 0){
		for (int i = 0; i < len; ++i) {

				 if(list[i].id == id && list[retorno].isEmpty==FALSE){

					 retorno = i;
					 break;
				}
		 }
	}
    return retorno;
}

int modifyEmployee( Employee* list, int len, int id){

	int ModificarMenu;
    int retorno = -1;
    if(list != NULL && len >= 0 && id >= 0){
		 retorno = findEmployeeById(list,len,id);

		if(retorno != -1 ){
			 ObtenerEnteroEntreRango(&ModificarMenu,"?Que desea modificar? \n 1- Nombre \n 2- Apellido \n 3- Salario \n 4- Sector\nOpcion: ",1,4,3);


			 switch (ModificarMenu) {
				case 1:
					ObtenerString("Ingrese el Nombre nuevo",list[retorno].name,sizeof(list[retorno].name),3);
					break;
				case 2:
					ObtenerString("Ingrese el Apellido nuevo",list[retorno].lastName,sizeof(list[retorno].lastName),3);
					break;
				case 3:
					ObtenerFlotanteMayorACero(&list[retorno].salary, "Ingrese el Salario nuevo",3);
					break;
				case 4:
					ObtenerEnteroMayorACero(&list[retorno].sector ,"Ingrese el Sector nuevo",3);
					break;
			 }
		}else{
			puts("\nNo existe ningun empleado con ese ID\n");
		}
    }
	return retorno;
}
int removeEmployee(Employee* list, int len, int id){

	int retorno = -1;

	retorno = findEmployeeById(list,len,id);
	if(retorno != -1 && list != NULL && len >= 0 && list[retorno].id == id && list[retorno].isEmpty == FALSE){

        list[retorno].isEmpty = TRUE;

	}

	return retorno;
}

int sortEmployees(Employee* list, int len, int order){

	int retorno = -1;

	if(list != NULL && len >= 0 && (order == 0 || order == 1)){
		retorno = 0;



				Employee auxiliarProducto;
				for(int i=0; i<len-1; i++)
				{
					for(int j=i+1; j<len; j++)
					{
						if(order == 1){
							//a b c d e ....

							if(strncmp(list[i].lastName, list[j].lastName,sizeof(list[i].lastName)) == 0)
							{
								if(list[i].sector > list[j].sector){
									auxiliarProducto = list[i];
									list[i] = list[j];
									list[j] = auxiliarProducto;
								}


							}else if(strncmp(list[i].lastName, list[j].lastName,sizeof(list[i].lastName)) > 0){
								auxiliarProducto = list[i];
								list[i] = list[j];
								list[j] = auxiliarProducto;
							}


						}
						else{
							//z y x w....
							if(strncmp(list[i].lastName, list[j].lastName,sizeof(list[i].lastName)) == 0)
							{
								if(list[i].sector < list[j].sector){
									auxiliarProducto = list[i];
									list[i] = list[j];
									list[j] = auxiliarProducto;
								}


							}
							else if(strncmp(list[i].lastName, list[j].lastName,sizeof(list[i].lastName)) < 0){
									auxiliarProducto = list[i];
									list[i] = list[j];
									list[j] = auxiliarProducto;
								}
						}
					}
				}
		}
	return retorno;
}
int printEmployees(Employee* list, int len){
	int retorno = -1;


	if(list != NULL && len >= 0){
			retorno = 0;
			puts("|ID|         NOMBRE        |         APELLIDO          |     SALARIO    |    SECTOR   |");
			int i;
			for (i = 0; i < len; ++i) {
				if(list[i].isEmpty==FALSE){

					printf(" %d ",list[i].id);
					printf(" %15s ",list[i].name);
					printf("%25s ",list[i].lastName);
					printf(" %20.2f ",list[i].salary);
					printf(" %15d \n",list[i].sector);

				}

			}
	}

	return retorno;
}
int PromedioSalario(Employee* list, int len){
	int retorno = -1;
	if(list != NULL && len >= 0){

		float acumulador;
		int contador;
		int contadorPromedio;
		float promedio;

		contadorPromedio = 0;
		acumulador = 0;
		contador = 0;


		for(int i = 0; i < len ; i++){
			if(list[i].isEmpty == FALSE){
				contador++;
				acumulador = acumulador + list[i].salary;
			}

		}
		promedio = acumulador/contador;
		for(int i = 0; i < len; i ++){
			if(list[i].salary > promedio && list[i].isEmpty == FALSE){
				contadorPromedio++;
			}
		}

		printf("El total del salario es: %f\n",acumulador);
		printf("Y el promedio de los salarios es: %f\n",promedio);
		printf("La cantidad de salarios superiores al promedio es de: %d \n",contadorPromedio);

		retorno = 0;
	}
	return retorno;
}



