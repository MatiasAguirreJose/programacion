
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "ArrayEmployees.h"
#include "input.h"
#include "output.h"

#define TAM 1000
#define TRUE 0
#define FALSE 1
int main(void) {
	setbuf(stdout,NULL);

	int id = 0;
	int idModificar;
	int idEliminar;
	char nombre[21];
	char apellido[21];
	float salario ;
	int sector;
	int opcion;
	int libre;
    int flag = 0;

	Employee listaEmpleados[TAM];

	initEmployees(listaEmpleados,TAM);

	do{
			MostrarMenu();
			ObtenerEntero(&opcion,"\nIngrese una opcion: ",3);
			switch(opcion){
				case 1:
					libre = buscarLibre(listaEmpleados,TAM);
					if( libre != -1 ){
						if (cargarEmpleado(nombre,apellido,&salario,&sector) == 0){
							id++;
							if(addEmployee(listaEmpleados,TAM,id,nombre,apellido,salario,sector) != -1){
								puts("El empleado se cargo exitosamente\n");
								flag = 1;
							}
							else{
								id--;
								puts("El empleado no pudo cargarse\n");
							}
						}
					}
					else{
					  printf("Ya ha llegado al limite de: %d empleados.\nSi desea, puede eliminar alguno en la opcion 3\n",TAM);
					}
				break;
				case 2:
					if(flag == 1){
						printEmployees(listaEmpleados, TAM);
						ObtenerEntero(&idModificar,"Ingrese el ID a modificar: ",3);

						if(modifyEmployee(listaEmpleados, TAM,idModificar)!= -1){
							puts("El empleado se modific� exitosamente\n");
						}

					}else{
						puts("Aun no hay ningun empleado cargado ");
					}


				break;
				case 3:
					if(flag == 1){
						printEmployees(listaEmpleados, TAM);
						ObtenerEntero(&idEliminar,"Ingrese el ID a eliminar: ",3);
						if(removeEmployee(listaEmpleados, TAM,idEliminar)!=-1){
							printf("El empleado se borro exitosamente.\n");
						}
						else{
							printf("no se pudo borrar el empleado.\n");
						}
					}
					else{
						puts("Aun no hay ningun empleado cargado ");
					}

					break;

				case 4:
					if(flag == 1){
						sortEmployees(listaEmpleados, TAM, FALSE);
						printEmployees(listaEmpleados, TAM);
						PromedioSalario(listaEmpleados,TAM);
					}else{
						puts("Aun no hay ningun empleado cargado ");
					}
				break;
				case 5:
					printf("Ha salido con exito!");
					break;
			}

		}while(opcion != 5);


	return EXIT_SUCCESS;
	}

