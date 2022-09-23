/*
 * Input.h

 *      Author: Carla Baro
 */

#ifndef INPUT_H_
#define INPUT_H_

/// \brief Solicita un numero ENTERO que devuelve por referencia, con validación.
/// \param pResultado Puntero por el cual se devuelve el valor ingresado por el usuario.
/// \param mensaje Enunciado por el que se le solicita el numero al usuario.
/// \param mensajeError Enunciado que indica al usuario que el numero no se ajusta a los parámetros solicitados.
/// \param minimo Valor mínimo solicitado.
/// \param maximo Valor máximo solicitado.
/// \param reintentos Cantidad posible de intentos, en el caso que haya error.
/// \return Devuelve "0" si el usuario ingresó un num entero que se ajusta a los parámetros pedidos. Devuelve "-1" en caso contrario.
int utn_getNumero(int * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos);

/// \brief Solicita un numero DECIMAL que devuelve por referencia, con validación.
/// \param pResultado Puntero por el cual se devuelve el valor ingresado por el usuario.
/// \param mensaje Enunciado por el que se le solicita el numero al usuario.
/// \param mensajeError Enunciado que indica al usuario que el numero no se ajusta a los parámetros solicitados.
/// \param minimo Valor mínimo solicitado.
/// \param maximo Valor máximo solicitado.
/// \param reintentos Cantidad posible de intentos, en el caso que haya error.
/// \return Devuelve "0" si el usuario ingresó un num decimal que se ajusta a los parámetros pedidos. Devuelve "-1" en caso contrario.
int utn_getFloat(float * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos);

/// \fn int cargaJugador(int*, int*, int*, int*, int*, int*)
/// \brief Solicita la carga de un jugador.
///
/// \param afc Devuelve por referencia, en caso de ser modificado, el valor nuevo de la variable.
/// \param caf  Devuelve por referencia, en caso de ser modificado, el valor nuevo de la variable.
/// \param concacaf  Devuelve por ref, en caso de ser modificado, el valor nuevo de la variable.
/// \param conmebol  Devuelve por ref, en caso de ser modificado, el valor nuevo de la variable.
/// \param uefa  Devuelve por ref, en caso de ser modificado, el valor nuevo de la variable.
/// \param ofc  Devuelve por ref, en caso de ser modificado, el valor nuevo de la variable.
/// \return Devuelve "0" si el usuario ingresó un jugador de manera correcta. Devuelve "-1" en caso contrario.
int cargaJugador (int * afc, int * caf, int * concacaf, int * conmebol, int * uefa, int * ofc);


#endif /* INPUT_H_ */
