#ifndef CONFEDERACIONES_H_
#define CONFEDERACIONES_H_

typedef struct
{
	int id;
	char nombre[51];
	char region[51];
	int anioCreacion;
	//int isEmpty
} eConfederacion;
/*
/// \fn int arrayIsEmpty(eConfederacion*, int, int*)
/// \brief Devuelve
///
/// \param listaConfederaciones
/// \param length
/// \param posicionVacia
/// \return
int arrayIsEmpty (eConfederacion* listaConfederaciones, int length, int* posicionVacia);

int ingresaConfederacion (eConfederacion* ConfederacionUnica, int* id);

int buscarPorID (eConfederacion* listaConfederaciones, int length, int * posicionConfe);

int darBaja(eConfederacion* listaConfederaciones, int posicionConfe);

int modificaNombre (eConfederacion* listaConfederaciones, int posicionConfe);

int modificaRegion (eConfederacion* listaConfederaciones, int posicionConfe);

int modificaAnioCreacion (eConfederacion* listaConfederaciones, int posicionConfe);
*/

#endif /* CONFEDERACIONES_H_ */
