#ifndef JUGADORES_H_
#define JUGADORES_H_

typedef struct
{
	int id;
	char nombre[51];
	char posicion[51];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
} eJugador;

/// \fn int iniciaArrayJugadores(eJugador*, int)
/// \brief Inicia el array de jugadores en 0.
///
/// \param array	array a iniciar
/// \param length	longitud a recorrer
/// \return			'0' si salio OK. '-1' si hubo error.
int iniciaArrayJugadores (eJugador* array, int length);
/// \fn int arrayIsEmpty(eJugador*, int, int*)
/// \brief hace un chequeo de la posicion del array que se puede hacer una carga de datos
///
/// \param listaJugadores	array a recorrer
/// \param length			longitud del array
/// \param posicionVacia	posicion del indice donde se encuentra vacio
/// \return 				'0' si salio OK. '-1' si hubo error.
int arrayIsEmpty (eJugador* listaJugadores, int length, int* posicionVacia);
/// \fn int ingresaJugador(eJugador*, eConfederacion*, int, int*)
/// \brief Pide al usuario los datos de ingreso del jugador.
///  		Genera un id autoincremental si se aprobo el ingreso total de los datos.
/// \param jugadorUnico		genera una variable de tipo estructura eJugador para unir al array
/// \param confederaciones  muestra el listado de confederaciones para elegir por id
/// \param length
/// \param idJugador	incrementa un id para devolverlo luego que se hace la carga de datos.
/// \return '0' si no hubo errores en la carga.  '-1' en caso de error
int ingresaJugador(eJugador* jugadorUnico, eConfederacion* confederaciones, int length, int* idJugador);
/// \fn int buscarPorID(eJugador*, int, int*)
/// \brief Busca un id ingresado manualmente por el usuario
///
/// \param listaJugadores	array a recorrer
/// \param length			longitud del array
/// \param posicionJugador	numero de indice donde se encuentra el id buscado
/// \return					'0' en caso de exito.  '-1' en caso de error
int buscarPorID (eJugador* listaJugadores, int length, int * posicionJugador);
/// \fn int darBaja(eJugador*, int)
/// \brief Se coloca en -1 el numero de id para que este no pueda ser encontrado. Se cambia a 1 el valor isEmpty para que pueda reutilizarse el indice
/// \param listaJugadores 		array a recorrer
/// \param posicionJugador		numero de indice a modificar para reutilizarse luego
/// \return						'0' en caso de exito. '-1' en caso de error
int darBaja(eJugador* listaJugadores, int posicionJugador);
/// \fn int modificaNombre(eJugador*, int)
/// \brief Modifica nombre completo del jugador
///
/// \param listaJugadores
/// \param posicionJugador
/// \return '0' en caso de exito. '-1' en caso de error
int modificaNombre (eJugador* listaJugadores, int posicionJugador);
/// \fn int modificaPosicion(eJugador*, int)
/// \brief modifica posicion del jugador
///
/// \param listaJugadores
/// \param posicionJugadorenArray
/// \return '0' en caso de exito. '-1' en caso de error
int modificaPosicion (eJugador* listaJugadores, int posicionJugadorenArray);
/// \fn int modificaCamiseta(eJugador*, int)
/// \brief Modifica numero de camiseta del jugador
///
/// \param listaJugadores
/// \param posicionJugadorenArray
/// \return '0' en caso de exito. '-1' en caso de error
int modificaCamiseta (eJugador* listaJugadores, int posicionJugadorenArray);
/// \fn int modificaConfederacion(eJugador*, int, eConfederacion*, int)
/// \brief Modifica id de confederacion del jugador
///
/// \param listaJugadores
/// \param posicionJugadorenArray
/// \param confederaciones
/// \param length
/// \return '0' en caso de exito. '-1' en caso de error
int modificaConfederacion (eJugador* listaJugadores, int posicionJugadorenArray, eConfederacion* confederaciones, int length);
///  \fn int modificaSalario(eJugador*, int)
/// \brief modifica salario del jugador
///
/// \param listaJugadores
/// \param posicionJugadorenArray
/// \return '0' en caso de exito. '-1' en caso de error
int modificaSalario (eJugador* listaJugadores, int posicionJugadorenArray);
/// \fn int modificaContrato(eJugador*, int)
/// \brief Modifica años de contrato del jugador
///
/// \param listaJugadores
/// \param posicionJugadorenArray
/// \return '0' en caso de exito. '-1' en caso de error
int modificaContrato (eJugador* listaJugadores, int posicionJugadorenArray);
/// \fn int ordenarConfederacionyJugadores(eJugador*, int, eConfederacion*, int)
/// \brief Ordena por nombre de confederacion. En caso de ser misma confederacion, ordena por apellido/nombre del jugador
///
/// \param listaJugadores
/// \param length
/// \param confederaciones
/// \param tam
/// \return '0' si salio OK. '-1' si hubo error.
int ordenarConfederacionyJugadores (eJugador* listaJugadores, int length, eConfederacion* confederaciones, int tam);
/// \fn int deIDaDescripcion(eJugador*, int, eConfederacion*, int, char*)
/// \brief Envía un jugador en una posicion para leer su ID de confederacion y devolver el nombre (caracteres alfanumericos) de la misma.
/// \param jugador
/// \param i
/// \param confederaciones
/// \param tam
/// \param descripcion
/// \return '0' si salio OK. '-1' si hubo error.
int deIDaDescripcion(eJugador* jugador, int i, eConfederacion* confederaciones, int tam, char* descripcion);
/// \fn int salarioTotalJugadores(eJugador*, int, float*)
/// \brief Calcula el salario total de los jugadores, sumandolos.
///
/// \param listaJugadores
/// \param length
/// \param salarioTotal
/// \return '0' si salio OK. '-1' si hubo error.
int salarioTotalJugadores(eJugador* listaJugadores,int length,float* salarioTotal);
/// \fn int salarioPromedioJugadores(eJugador*, int, float*, float)
/// \brief Calcula el salario promedio, dividiendo el total por la cantidad de salarios.
/// \param listaJugadores
/// \param length
/// \param salarioPromedio
/// \param salarioTotal
/// \return '0' si salio Ok. '-1' si hubo error.
int salarioPromedioJugadores(eJugador* listaJugadores,int length,float* salarioPromedio,float salarioTotal);
/// \fn int contarDuracionContratosPorConfederacion(eJugador*, int, eConfederacion*, int, int*)
/// \brief Suma los años de contrato por cada confederacion, agrupandolos en un array.
///
/// \param listaJugadores
/// \param len
/// \param confederaciones
/// \param tam
/// \param arrayContadorConfederaciones
/// \return '0' si salio Ok. '-1' si hubo error.
int contarDuracionContratosPorConfederacion(eJugador* listaJugadores, int len, eConfederacion* confederaciones, int tam, int* arrayContadorConfederaciones);
/// \fn int buscarMax(int[], int, int*, int*)
/// \brief Busca el numero maximo de un array, devolviendo su contenido e indice por referencia.
///
/// \param array
/// \param length
/// \param numMaximo
/// \param posicionMaximo
/// \return '0' si salio Ok. '-1' si hubo error.
int buscarMax (int array[], int length, int * numMaximo, int * posicionMaximo);
/// \fn int contarJugadoresPorConfederacion(eJugador*, int, eConfederacion*, int, int*)
/// \brief Agrupa en array la cantidad de jugadores por confederacion.
///
/// \param listaJugadores
/// \param length
/// \param confederaciones
/// \param tam
/// \param arrayContadorJugadoresConfederaciones
/// \return '0' si salio Ok. '-1' si hubo error.
int contarJugadoresPorConfederacion(eJugador* listaJugadores, int length, eConfederacion* confederaciones, int tam, int* arrayContadorJugadoresConfederaciones);

#endif /* JUGADORES_H_ */
