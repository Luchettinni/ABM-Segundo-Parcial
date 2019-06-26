typedef struct
{
    int id;
    char nombre[25];
    char apellido[25];
    float salario;
    char sector[25];

} employee;

/** \brief Construye un puntero a una estructura de un empleado con campos vacios
 *
 * \return retorna el puntero a la estructura del empleado
 *
 */
employee* employee_newEmployee();

/** \brief Guarda una lista de empleados para imprimir en un directorio especificado por parametro
 *
 * \param lista es la lista a guardar
 * \param path es el directorio a guardar la lista
 * \return retorna (0) si tuvo exito
                   (-1) si fallo
 *
 */
int employee_guardarListaAImprimir ( LinkedList* lista, char* path );

/** \brief Carga una lista de empleados en un directorio especificado por parametro
 *
 * \param lista la lista donde seran cargado los datos
 * \param path es el directorio que contiene el archivo a cargar
 * \return retorna (0) si tuvo exito
                   (-1) si fallo
 *
 */
int employee_cargarListaAImprimir( LinkedList* lista, char* path );

/** \brief Da de alta un empleado y lo añade a la lista
 *
 * \param lista es la lista a la que se le añadira este nuevo empleado
 * \return retorna (0) si tuvo exito
                   (-1) si fallo
 *
 */
int employee_altaEmpelado(LinkedList* lista);

/** \brief Encuentra el ID del ultimo empleado
 *
 * \param lista es la lista a utilizar para la busqueda
 * \return retorna (0) si no hay ningun empleado o el ID del ultimo empleado
 *
 */
int employee_findLastId ( LinkedList* lista );

/** \brief genera un listado de empleados
 *
 * \param lista es la lista que se utilizara para mostrar cada uno de sus elementos
 * \return retorna (0) si tuvo exito
                   (-1) si fallo
 *
 */
int employee_listarEmpleados( LinkedList* lista );

/** \brief Realiza el ordenamiento de una lista
 *
 * \param lista es la lista que se utilizara para ordenarse
 * \return retorna (0) si tuvo exito
                   (-1) si fallo
 *
 */
int employee_ordenarLista ( LinkedList* lista );

/** \brief compara nombre y apellido de un empleado con el de otro para realizar un ordenamiento
 *
 * \param employeeA es uno de los elementos a comparar
 * \param employeeB es otro de los elementos a comparar
 * \return retorna (1) si el primer elemento es mayor al segundo
                   (-1) si el primer elemento es menor al segundo
 *
 */
int ordenarListaNombreYApellido ( void* employeeA, void* employeeB );

/** \brief compara el sector de un empleado con el de otro para realizar un ordenamiento
 *
 * \param employeeA es uno de los elementos a comparar
 * \param employeeB es otro de los elementos a comparar
 * \return retorna (1) si el primer elemento es mayor al segundo
                   (-1) si el primer elemento es menor al segundo
 *
 */
int ordenarListaSector ( void* employeeA, void* employeeB );

/** \brief compara si los dos elementos pasados por parametro cumplen con un requisito (comparacion)
 *
 * \param elemento es uno de los elementos a comparar
 * \param sector es uno de los elementos a comparar
 * \return retorna (0) si por lo menos uno de los dos no es verdadero
                   (1) si los son verdaderos frente a la comparacion
 *
 */
int FiltradoPorSalarioYSector(void* elemento, void* sector);

/** \brief Crea una nueva lista a partir de otra, solo que con elementos especificos de la lista original seleccionados mediante filtrado
 *
 * \param lista es la lista original a la que se le realizara el filtrado para la creacion de la nueva lista
 * \return retorna un puntero a la nueva lista
 *
 */
LinkedList* employee_filter(LinkedList* lista);

