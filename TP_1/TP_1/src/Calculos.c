#include "Funciones.h"


float Resta (float num1,float num2){
		float respuesta;
			respuesta = num1 - num2;
			return respuesta;

		}




float Suma(float num1, float num2){

	float respuesta;
	respuesta = num1 + num2;
	return respuesta;
}


float Multiplicacion (float num1, float num2){
	float respuesta;
		respuesta = num1 * num2;
		return respuesta;
	}


float Divicion (float num1,float num2){
		float respuesta;
		respuesta = num1 / num2;;
		return respuesta;
	}





int CalcularFactorial(int num)
{
	int resultado;
if( num == 0){

	resultado = 1;

}

else{

	resultado =  num * CalcularFactorial( num - 1);
}

return resultado;

}
