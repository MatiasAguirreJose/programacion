
#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

struct
{
	 int id;
	 char name[51];
	 char lastName[51];
	 float salary;
	 int sector;
	 int isEmpty;
}typedef Employee;


/// \brief Para indicar que todas las posiciones del array est?n vac?as, esta funci?n pone la bandera (isEmpty) en TRUE en todas las posiciones del array.
/// \param list Employee*
/// \param len int
/// \return int Return (-1) si hay error [tama?o invalido o puntero nulo] - (0) si esta Ok
int initEmployees(Employee* list, int len);


/// \brief Agrega en un array de empleados existente los valores recibidos como par?metro en la primer posici?n libre.
/// \param list Employee*
/// \param len int
/// \param id int
/// \param name[] char
/// \param lastName[] char
/// \param salary float
/// \param sector int
/// \return int Return (-1) si hay error [tama?o invalido o puntero nulo o sin espacios libres] - (0) si esta Ok
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);


/// \brief Busca un empleado recibiendo como par?metro de b?squeda su Id.
/// \param list Employee*
/// \param len int
/// \param id int
/// \return Return posicion del index del empleado o (-1) si [tama?o invalido o puntero nulo o empleado no encontrado]
int findEmployeeById(Employee* list, int len,int id);


/// \brief Elimina de manera l?gica (isEmpty Flag en 1) un empleado recibiendo como par?metro su Id.
/// \param list Employee*
/// \param len int
/// \param id int
/// \return int Return (-1) si hay error [tama?o invalido o puntero nulo o empleado no encontrado] - (0) si esta Ok
int removeEmployee(Employee* list, int len, int id);

/// \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
/// \param list Employee*
/// \param length int
/// \param order int [1] de manera ascendente - [0] de manera descendente
/// \return int Return (-1) si hay error [Invalid length or NULL pointer] - (0) si esta  Ok

int sortEmployees(Employee* list, int len, int order);

/// \brief Busca una posicion libre dentro del array
/// \param list Employee*
/// \param len int
/// \return int Return (-1) si hay error [Invalid length or NULL pointer] - (0) si esta  Ok
int buscarLibre(Employee* list, int len);

/// \brief Modifica el nombre, apellido, salario o sector de un usuario .
/// \param list Employee*
/// \param length int
/// \param id int
/// \return int Return (-1) si hay error [Invalid length or NULL pointer] - (0) si esta  Ok
int modifyEmployee( Employee* list, int len, int id);


/// \brief Imprime el array de empleados de forma encolumnada.
/// \param lista empleados*
/// \param tam int
/// \return int Return (-1) si hay error [Invalid length or NULL pointer] - (0) si esta  Ok
int printEmployees(Employee* list, int length);

/// \brief Calcula el promedio y el salario de los empleados cargados con anteriridad
/// \param lista empleados*
/// \param len int
/// \return int Return (-1) si hay error [Invalid length or NULL pointer] - (0) si esta  Ok
int PromedioSalario(Employee* list, int len);

/// \brief Pide al usuario por consola los datos del empelado
/// \param name[] char
/// \param lastName[] char
/// \param salary float*
/// \param sector int*
/// \return int Return (-1) si hay error [Invalid length or NULL pointer] - (0) si esta  Ok
int cargarEmpleado(char name[],char lastName[],float* salary,int* sector);


#endif /* ARRAYEMPLOYEES_H_ */
