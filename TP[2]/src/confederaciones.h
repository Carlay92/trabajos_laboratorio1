#ifndef CONFEDERACIONES_H_
#define CONFEDERACIONES_H_

typedef struct
{
	int id;
	char nombre[51];
	char region[51];
	int anioCreacion;
	int isEmpty;
} eConfederacion;

/// \fn int arrayIsEmpty(eConfederacion*, int, int*)
/// \brief Inicia el array de confederaciones.
///
/// \param listaConfederaciones
/// \param length
/// \param posicionVacia
/// \return '0' si salio Ok. '-1' si hubo error.
int arrayConfederacionesIsEmpty (eConfederacion* listaConfederaciones, int length, int* posicionVacia);
/// \fn int ingresaConfederacion(eConfederacion*, int*)
/// \brief Ingresa confederacion nueva al array de structuras.
///
/// \param ConfederacionUnica
/// \param id
/// \return '0' si salio Ok. '-1' si hubo error.
int ingresaConfederacion (eConfederacion* ConfederacionUnica, int* id);
/// \fn int buscarConfePorID(eConfederacion*, int, int*)
/// \brief Busca confederacion mediante ID.
///
/// \param listaConfederaciones
/// \param length
/// \param posicionConfe
/// \return '0' si salio Ok. '-1' si hubo error.
int buscarConfePorID (eConfederacion* listaConfederaciones, int length, int * posicionConfe);
/// \fn int darBajaConfederacion(eConfederacion*, int)
/// \brief Elimina confederacion colocando el ID  en -1 y el isEmpty en 1.
///
/// \param listaConfederaciones
/// \param posicionConfe
/// \return '0' si salio Ok. '-1' si hubo error.
int darBajaConfederacion(eConfederacion* listaConfederaciones, int posicionConfe);
/// \fn int modificaNombreConfe(eConfederacion*, int)
/// \brief Modifica el nombre de la confederacion.
///
/// \param listaConfederaciones
/// \param posicionConfe
/// \return '0' si salio Ok. '-1' si hubo error.
int modificaNombreConfe (eConfederacion* listaConfederaciones, int posicionConfe);
/// \fn int modificaRegionConfe(eConfederacion*, int)
/// \brief Modifica Region de la confederacion
///
/// \param listaConfederaciones
/// \param posicionConfe
/// \return '0' si salio Ok. '-1' si hubo error.
int modificaRegionConfe (eConfederacion* listaConfederaciones, int posicionConfe);
/// \fn int modificaAnioCreacionConfe(eConfederacion*, int)
/// \brief Modifica año de creacion de la confederacion.
///
/// \param listaConfederaciones
/// \param posicionConfe
/// \return '0' si salio Ok. '-1' si hubo error.
int modificaAnioCreacionConfe (eConfederacion* listaConfederaciones, int posicionConfe);

#endif /* CONFEDERACIONES_H_ */
