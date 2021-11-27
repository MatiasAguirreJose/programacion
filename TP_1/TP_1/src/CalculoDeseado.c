#include "Funciones.h"
#include "inputs.h"
#include <stdio.h>

void CalculoDeseado(char mensaje[]){
	int numeroIngresado;
	float numeroFinal;
	float numeroFinal2 ;
	float num1 = 0;
	float num2 = 0;
do{
	numeroIngresado = MenuCalculadora();


	switch (numeroIngresado) {
		case 1:

			getNumeroFloat(&num1, "Ingrese un numero");


		break;

		case 2:
			getNumeroFloat(&num2, "Ingrese un numero");


		break;

		case 3:
			printf(" ***********************************************************\n ");
			printf(" |suma*  A(%.2f) + B(%.2f)                             | \n ",num1,num2);
			printf(" |resta* A(%.2f) - B(%.2f)                             | \n ",num1,num2);
			printf(" |multiplicacion*  A(%.2f) * B(%.2f)                   | \n ",num1,num2);
			if(num2 == 0){
			printf(" |el numero es 0 la divicion no se puede hacer         | \n");
			}else
			{
			printf(" |divicion*  A(%.2f) / B(%.2f)                         | \n",num1,num2);
			}


			printf("  |Calcular El factorial de A(%.2f!)                     |\n",num1 );




			printf("  |Calcular el factorial de B(%.2f!)                      |\n",num2);

			printf(" *******************************************************\n\n ");
		break;

		case 4:
			printf(" **********************************************************\n ");
			numeroFinal = Suma(num1,num2);
			printf("la Suma de A(%.2f) + B(%.2f) es %.2f                    |\n",num1,num2, numeroFinal);

			numeroFinal = Resta(num1,num2);
			printf(" la Resta de A(%.2f) - B(%.2f) es %.2f                  |\n",num1,num2, numeroFinal);


			numeroFinal = Multiplicacion(num1,num2);
			printf(" la Multiplicacion de A(%.2f) * B(%.2f) es %.2f         |\n",num1,num2, numeroFinal);

			if(num2 == 0){
			printf(" el numero es 0 la divicion no se puede hacer            |\n");
			}else
			{
			numeroFinal = Divicion(num1,num2);
			printf(" la Divicion de A(%.2f) / B(%.2f) es %.2f                |\n",num1,num2, numeroFinal);
			}




			if(num1 >= 0){

				numeroFinal =   CalcularFactorial(num1);
				printf(" El factorial de A(%.2f!) es %.2f!                      |\n",num1, numeroFinal);

			}else{

					printf(" no se pudo haces el factorial de (%.2f!)                          |\n ",num1);
			}

			if(num2>=0){
				    numeroFinal2 =  CalcularFactorial( num2);
					printf(" el factorial de B(%.2f!) es %.2f!                      |\n",num2, numeroFinal2);
				}else{
					printf(" no se pudo haces el factorial de (%.2f!)                               |\n ",num2);
				}

			printf(" ********************************************************* ");

		break;


printf(" no se puedo factoriar porque el numero es menor         |\n");


	}
	}while(numeroIngresado!=5);

}
