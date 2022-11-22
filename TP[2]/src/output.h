#ifndef OUTPUT_H_
#define OUTPUT_H_

void mostrarMenu(void);

void subMenu(void);

void menuInformes(void);
/// \fn void mostrarConfederaciones(eConfederacion*, int)
/// \brief Muestra el listado de confederaciones cargadas.
///
/// \param confederaciones
/// \param length
void mostrarConfederaciones(eConfederacion* confederaciones, int length);
/// \fn int mostrarJugadores(eJugador*, int, eConfederacion*, int)
/// \brief Muestra jugadores ordenados por ID.
///
/// \param listaJugadores
/// \param length
/// \param confederaciones
/// \param tam
/// \return
int mostrarJugadores(eJugador* listaJugadores, int length, eConfederacion* confederaciones, int tam);
/// \fn int printInformeUno(eJugador*, int, eConfederacion*)
/// \brief Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador.
///
/// \param listaJugadores
/// \param length
/// \param confederaciones
/// \return '0' sin errores, '-1' en caso de error.
int printInformeUno (eJugador* listaJugadores, int length, eConfederacion* confederaciones, int tam);
/// \fn int printInformeDos(eJugador*, int)
/// \brief  Listado de confederaciones con sus jugadores.
///
/// \param listaJugadores
/// \param length
/// \return '0' sin errores, '-1' en caso de error.
int printInformeDos (eJugador* listaJugadores, int length, eConfederacion* confederaciones, int tam);
/// \fn int printInformeTres(eJugador*, int)
/// \brief Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio.
///
/// \param listaJugadores
/// \param length
/// \return '0' sin errores, '-1' en caso de error.
int printInformeTres (eJugador* listaJugadores, int length);
/// \fn int printInformeCuatro(eJugador*, int, eConfederacion*, int)
/// \brief Imprime el informe de la confederación con mayor cantidad de años de contratos total.
///
/// \param listaJugadores
/// \param length
/// \param confederaciones
/// \param tam
/// \return  '0' sin errores, '-1' en caso de error.
int printInformeCuatro (eJugador* listaJugadores, int length, eConfederacion* confederaciones, int tam);
/// \fn int printInformeQuinto(eJugador*, int, eConfederacion*, int, int)
/// \brief Imprime el porcentaje de jugadores por cada confederación.
///
/// \param listaJugadores
/// \param length
/// \param confederaciones
/// \param tam
/// \param contadorJugadores
/// \return '0' sin errores, '-1' en caso de error.
int printInformeQuinto (eJugador* listaJugadores, int length, eConfederacion* confederaciones, int tam, int contadorJugadores);
/// \fn int printInformeSeis(eJugador*, int, eConfederacion*, int)
/// \brief Imprime el informe de cual es la región con más jugadores y el listado de los mismos.
///
/// \param listaJugadores
/// \param length
/// \param confederaciones
/// \param tam
/// \return '0' sin errores, '-1' en caso de error.
int printInformeSeis (eJugador* listaJugadores, int length, eConfederacion* confederaciones, int tam);

#endif /* OUTPUT_H_ */
