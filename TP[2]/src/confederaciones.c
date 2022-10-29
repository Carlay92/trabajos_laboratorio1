#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "confederaciones.h"
#include "jugadores.h"
#include "utn_input.h"

/*int arrayIsEmpty (eConfederacion* listaConfederaciones, int length, int* posicionVacia)
{
	int retorno = -1;
	int i;
	if (listaConfederaciones != NULL && length >0 && posicionVacia !=NULL)
	{
		for (i=0; i<length; i++)
		{
			if ((*(listaConfederaciones+i)).isEmpty == 1)
			{
				*posicionVacia = i;
				retorno = 0;
				break;
			}
		}

	}
	return retorno;
}

int ingresaConfederacion (eConfederacion* ConfederacionUnica, int* id)
{
	int retorno = -1;

	if (ConfederacionUnica!=NULL && id !=NULL)
	{
		if (getStringconEspacio((*(ConfederacionUnica)).nombre, 51, "Ingrese nombre de la confederacion (max 50 caracteres)\n", "ERROR: intente nuevamente\n", 3) == 0 &&
			getStringconEspacio((*(ConfederacionUnica)).region, 51, "Ingrese region correspondiente: \n", "Region no válida\n", 3) == 0 &&
			utn_getNumero(&(*(ConfederacionUnica)).anioCreacion, "Ingrese el año de creacion de la confederacion correspondiente\n", "No es un año válido\n", 1900, 2022, 3) == 0)
		{
			(*(ConfederacionUnica)).isEmpty = 0;
			*id = *id + 1;
			retorno = 0;
		}
	}

	return retorno;
}

int buscarPorID (eConfederacion* listaConfederaciones, int length, int * posicionConfe)
{
	int retorno = -1;
	int i;
	int idBuscar;

	if (listaConfederaciones != NULL && length > 0 && posicionConfe != NULL)
	{
		if (utn_getNumero(&idBuscar, "Ingrese el ID de la confederacion a buscar\n","No es un ID válido",100,300,3) == 0)
		{
			for (i=0; i<length;i++)
			{
				if ((*(listaConfederaciones+i)).id == idBuscar)
				{
					*posicionConfe = i;
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

int darBaja(eConfederacion* listaConfederaciones, int posicionConfe)
{
	int retorno = -1;

	if (listaConfederaciones != NULL && posicionConfe >=0)
	{
		(*(listaConfederaciones+posicionConfe)).id = -1;
		(*(listaConfederaciones+posicionConfe)).isEmpty = 1;
		retorno = 0;
	}
	return retorno;
}

int modificaNombre (eConfederacion* listaConfederaciones, int posicionConfe)
{
	int retorno = -1;
	char auxNombre[51];

	if (listaConfederaciones != NULL)
	{
		if (getStringconEspacio(auxNombre, 51, "Ingrese nuevo nombre de la Confederacion (max 50 caracteres)\n", "ERROR: intente nuevamente\n", 3) == 0)
		{
			strcpy((*(listaConfederaciones+posicionConfe)).nombre, auxNombre);
			retorno = 0;
		}
	}
	return retorno;
}

int modificaRegion (eConfederacion* listaConfederaciones, int posicionConfe)
{
	int retorno = -1;
	char auxRegion[51];

	if (listaConfederaciones != NULL)
	{
		if (getStringconEspacio(auxRegion, 51, "Ingrese region modificada de la Confederacion (max 50 caracteres)\n", "ERROR: intente nuevamente\n", 3) == 0)
		{
			strcpy((*(listaConfederaciones+posicionConfe)).region, auxRegion);
			retorno = 0;
		}
	}
	return retorno;
}

int modificaAnioCreacion (eConfederacion* listaConfederaciones, int posicionConfe)
{
	int retorno = -1;

	if (listaConfederaciones != NULL)
	{
		if (utn_getShort(&(*(listaConfederaciones+posicionConfe)).anioCreacion, "Ingrese el año de creacion (1900/2022)\n", "No ingresó un número válido\n", 1900, 2022, 3) == 0)
		{
			retorno = 0;
		}
	}
	return retorno;
}
*/
