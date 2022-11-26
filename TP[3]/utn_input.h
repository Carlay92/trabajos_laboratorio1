#ifndef UTN_INPUT_H_
#define UTN_INPUT_H_
/// \fn int getRespuesta(char*, char*, char*, char, char, int, char*)
/// \brief Solicita un caracter verificando entre SOLO dos opciones ya establecidas.
/// 		Usada comunmente para recibir una respuesta por SI o por NO en un solo char.
/// \param letra	Devuelve por referencia (en caso de validarse) la letra ingresada por teclado.
/// \param mensaje	Se explica al usuario lo pedido
/// \param mensajeError	Cuando el usuario no ingresa lo solicitado
/// \param opcionUno	parametro de validacion 1
/// \param opcionDos 	parametro de validacion 2
/// \param reintentos	cantidad de posibilidades
/// \param mensajeSalida	cuando se terminan los intentos.
/// \return Devuelve "0" si se ingreso un char correctamente. "-1" caso contrario.
int getRespuesta (char* letra, char* mensaje, char * mensajeError, char opcionUno, char opcionDos , int reintentos, char* mensajeSalida);
/// \fn int getChar(char*, char*, char*, char, char, int, char*)
/// \brief Toma un caracter entre dos parametros que serviran de minimos y maximos.
/// 		Comunmente utilizada para navegar en un menu de varias opciones tipo CHAR.
/// \param letra	Devuelve por referencia, en caso de ser válido, el char ingresado por teclado.
/// \param mensaje	Solicita al usuario CHAR segun parametros.
/// \param mensajeError	Cuando el usuario no ingresa lo solicitado.
/// \param min	Caracter minimo segun tabla ASCII
/// \param max	Caracter maximo segun tabla ASCII
/// \param reintentos	Posibilidades de equivocacion
/// \param mensajeSalida	Break de reinicio por falta de reintentos.
/// \return Devuelve "0" si se ingreso un char correctamente. "-1" caso contrario.
int getChar (char* letra, char* mensaje, char * mensajeError, char min, char max, int reintentos, char*mensajeSalida);
/// \fn int utn_getNumero(int*, char*, char*, int, int, int)
/// \brief Devuelve un numero entero por referencia en caso de pasar todas las validaciones.
///
/// \param pResultado	Numero entero por referencia.
/// \param mensaje		Solicita al usuario un numero con requisitos
/// \param mensajeError	El usuario no ingreso lo solicitado.
/// \param min			Numero minimo a ingresar
/// \param max			Numero maximo a ingresar
/// \param reintentos	Posibilidades de ingresar un numero de manera incorrecta.
/// \return Devuelve "0" si se ingreso un num correctamente. "-1" caso contrario.
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int min, int max, int reintentos);
/// \fn int getInt(int*)
/// \brief Utiliza las funciones getString y esNumerica, para obtener y validar	una cadena como numero respectivamente
/// Si se pudo realizar, transforma la cadena en un entero.
/// \param pResultado numero a utilizar en otras funciones.
/// \return	"0" si pudo convertirlo correctamente. -1 caso contrario.

int utn_getShort(short *pResultado, char *mensaje, char *mensajeError, int min, int max, int reintentos);

int getInt(int* pResultado);
/// \fn int utn_getFloat(float*, char*, char*, int, int, int)
/// \brief Devuelve un numero decimal por referencia en caso de pasar todas las validaciones.
///
/// \param pResultado	Numero decimal por referencia.
/// \param mensaje		Solicita al usuario un numero con requisitos
/// \param mensajeError	El usuario no ingreso lo solicitado.
/// \param min			Numero minimo a ingresar
/// \param max			Numero maximo a ingresar
/// \param reintentos	Posibilidades de ingresar un numero de manera incorrecta.
/// \return Devuelve "0" si se ingreso un num correctamente. "-1" caso contrario.
int utn_getFloat(float * pResultado, char*pMensaje, char*pMensajeError, int min, int max, int reintentos);
/// \fn int getFloat(float*)
/// \brief Obtiene la cadena desde myGets.
///
/// \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// \return "0" si lo obtuvo correctamente, "-1" si falló.
int getFloat(float* pResultado);
/// \fn int myGets(char*, int)
/// \brief
///
/// \param cadena
/// \param longitud
/// \return
int myGets(char* cadena, int longitud);
/// \fn int esNumerica(char*)
/// \brief Verifica si la cadena recibida es numerica, si contiene solo los caracteres "1 al 9"
///
/// \param cadena
/// \return "0" si son todos numeros. "-1" si fallo.
int esNumerica(char* cadena);
/// \fn int esNumericaDecimal(char*)
/// \brief  Verifica si la cadena flotante es numerica y contiene los simbolos "," o "."
///
/// \param cadena
/// \return "0" si es numerica y "-1" si no es así.
int esNumericaDecimal(char* cadena);
/// \fn int getString(char*, int)
/// \brief Obtiene un string, reemplaza los caracteres "\n" si los encuentra, y los reemplaza con el caracter "\0"
///
/// \param cadena cadena recibida por teclado
/// \param longitud	longitud del array de char
/// \return	"0" si tuvo exito. "-1" caso contrario.
int getString(char *cadena, int longitud);
///  \fn int getStringconEspacio(char*, int, char*, char*, int)
/// \brief Recibe cadena de caracteres con espacios entre ellos.
///
/// \param string	cadena que recibe por teclado
/// \param len		longitud del array de char
/// \param mensaje	solicitud al usuario personalizada
/// \param mensajeError	el usuario no ingreso lo soliciado correctamente
/// \param reintentos	posibilidades de ingresar el string incorrectamente
/// \return	"0" si realizo la carga con exito."-1"  si fallo.
int getStringconEspacio(char *string, int len, char *mensaje, char *mensajeError, int reintentos);

int get_Posicion (char *string, int length, char *mensaje, char *mensajeError, int reintentos);

int isLetrayEspacio (char* string, int lenght);

/// \fn int iniciaArray(int[], int)
/// \brief Inicia un array de tipo INT colocando todos sus elemntos en 0
/// 		para borrar la basura en la memoria
///
/// \param array Array de tipo INT
/// \param cantElementos	cantidad de elementos d
/// \return	"0" si realizo la carga con exito. "-1" si fallo.
int iniciaArray (int array[], int cantElementos);

int isPosicion (char* string, int length);
int get_Nacionalidad (char *string, int length, char *mensaje, char *mensajeError, int reintentos);
int isNacionalidad (char* string, int length);
#endif /* UTN_INPUT_H_ */
