#include "Jugador.h"
#include "Seleccion.h"


Jugador* jug_new()
{
	Jugador* unJugador = NULL;
	unJugador = (Jugador*)malloc(sizeof(Jugador));

	if (unJugador!= NULL)
	{
		unJugador->id = 0;
		strcpy(unJugador->nombreCompleto, "\0");
		unJugador->edad = 0;
		strcpy(unJugador->posicion, "\0");
		strcpy(unJugador->nacionalidad, "\0");
		unJugador->idSeleccion = 0;
	}

	return unJugador;
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr)
{

	Jugador* auxJugador = NULL;
	Jugador* unJugador = NULL;
	//auxJugador = jug_new();

	if (idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL && idSeleccionStr != NULL)
	{
		if ((auxJugador = jug_new()) != NULL)
		{
			if (jug_setId(auxJugador, atoi(idStr)) == 0 && jug_setNombreCompleto(auxJugador, nombreCompletoStr) == 0 &&
				jug_setEdad(auxJugador, atoi(edadStr)) == 0 && jug_setPosicion(auxJugador, posicionStr) == 0 &&
				jug_setNacionalidad(auxJugador, nacionalidadStr) == 0 && jug_setIdSeleccion(auxJugador, atoi(idSeleccionStr)) == 0)
			{
				unJugador = auxJugador;
			}
			else
			{
				jug_delete(auxJugador);
			}
		}
	}
	return unJugador;
}

void jug_delete(Jugador* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int jug_setId(Jugador* this,int id)
{
	int retorno = -1;
	if (this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}
		return retorno;
}

int jug_getId(Jugador* this,int* id)
{
	int retorno = -1;
	if (this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int jug_setNombreCompleto(Jugador* this, char* nombreCompleto)
{
	int retorno = -1;
	if(this != NULL && nombreCompleto!= NULL)
	{
		strcpy(this->nombreCompleto, nombreCompleto);
		retorno = 0;
	}
	return retorno;
}

int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = -1;
	if (this != NULL && nombreCompleto != NULL)
	{
		strcpy(nombreCompleto, this->nombreCompleto);
		retorno = 0;
	}
	return retorno;
}

int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno = -1;
	if(this != NULL && posicion!= NULL)
	{
		strcpy(this->posicion, posicion);
		retorno = 0;
	}
	return retorno;
}

int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno = -1;
	if (this != NULL && posicion != NULL)
	{
		strcpy(posicion, this->posicion);
		retorno = 0;
	}
	return retorno;
}

int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;
	if(this != NULL && nacionalidad!= NULL)
	{
		strcpy(this->nacionalidad, nacionalidad);
		retorno = 0;
	}
	return retorno;
}

int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;
	if (this != NULL && nacionalidad != NULL)
	{
		strcpy(nacionalidad, this->nacionalidad);
		retorno = 0;
	}
	return retorno;
}

int jug_setEdad(Jugador* this,int edad)
{
	int retorno = -1;
	if (this != NULL && edad > 0)
	{
		this->edad = edad;
		retorno = 0;
	}
	return retorno;
}

int jug_getEdad(Jugador* this,int* edad)
{
	int retorno = -1;
	if (this != NULL && edad != NULL)
	{
		*edad = this->edad;
		retorno = 0;
	}
		return retorno;
}

int jug_setIdSeleccion(Jugador* this, int idSeleccion)
{
	int retorno = -1;
	if (this != NULL && idSeleccion >= 0)
	{
		this->idSeleccion = idSeleccion;
		retorno = 0;
	}
	return retorno;
}

int jug_getIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno = -1;
	if (this != NULL && idSeleccion != NULL)
	{
		*idSeleccion = this->idSeleccion;
		retorno = 0;
	}
	return retorno;
}

int jug_ordenarPorId (void* this, void *this2)
{
	int retorno = -1;
	int idPrimerJugador;
	int idSegundoJugador;
	Jugador* pPrimerJug;
	Jugador* pSegundoJug;

	if (this != NULL && this2 != NULL)
	{
		pPrimerJug = (Jugador*)this;
		pSegundoJug = (Jugador*)this2;
		jug_getId(pPrimerJug, &idPrimerJugador);
		jug_getId(pSegundoJug, &idSegundoJugador);

		if (idPrimerJugador > idSegundoJugador)
		{
			retorno = 1;
		}
		else if (idPrimerJugador == idSegundoJugador)
		{
			retorno = 0;
		}
	}
	return retorno;
}

int jug_ordenarPorEdadAscendente (void* this, void *this2)
{
	int retorno = -1;
	int edadPrimerJugador;
	int edadSegundoJugador;
	Jugador* pPrimerJug;
	Jugador* pSegundoJug;

	if (this != NULL && this2 != NULL)
	{
		pPrimerJug = (Jugador*)this;
		pSegundoJug = (Jugador*)this2;
		jug_getEdad(pPrimerJug, &edadPrimerJugador);
		jug_getEdad(pSegundoJug, &edadSegundoJugador);

		if (edadPrimerJugador > edadSegundoJugador)
		{
			retorno = 1;
		}
		else if (edadPrimerJugador == edadSegundoJugador)
		{
			retorno = 0;
		}
	}
	return retorno;
}
int jug_ordenarPorEdadDescendente (void* this, void *this2)
{
	int retorno = -1;
	int edadPrimerJugador;
	int edadSegundoJugador;
	Jugador* pPrimerJug;
	Jugador* pSegundoJug;

	if (this != NULL && this2 != NULL)
	{
		pPrimerJug = (Jugador*)this;
		pSegundoJug = (Jugador*)this2;
		jug_getEdad(pPrimerJug, &edadPrimerJugador);
		jug_getEdad(pSegundoJug, &edadSegundoJugador);

		if (edadPrimerJugador < edadSegundoJugador)
		{
			retorno = 1;
		}
		else if (edadPrimerJugador == edadSegundoJugador)
		{
			retorno = 0;
		}
	}
	return retorno;
}

int jug_ordenarPorNacionalidad (void* this, void *this2)
{
	int retorno;
	char nacionalidadPrimerJug[30];
	char nacionalidadSegundoJug[30];
	Jugador* pPrimerJug;
	Jugador* pSegundoJug;

	if (this != NULL && this2 != NULL)
	{
			pPrimerJug = (Jugador*)this;
			pSegundoJug = (Jugador*)this2;
			jug_getNacionalidad(pPrimerJug, nacionalidadPrimerJug);
			jug_getNacionalidad(pSegundoJug, nacionalidadSegundoJug);
			retorno = stricmp(nacionalidadPrimerJug, nacionalidadSegundoJug);
	}
		return retorno;
}

int jug_ordenarPorNombre (void* this, void *this2)
{
	int retorno;
	char nombrePrimerJugador[30];
	char nombreSegundoJug[30];
	Jugador* pPrimerJug;
	Jugador* pSegundoJug;

	if (this != NULL && this2 != NULL)
	{
			pPrimerJug = (Jugador*)this;
			pSegundoJug = (Jugador*)this2;
			jug_getNombreCompleto(pPrimerJug, nombrePrimerJugador);
			jug_getNombreCompleto(pSegundoJug, nombreSegundoJug);
			retorno = stricmp(nombrePrimerJugador, nombreSegundoJug);
	}
		return retorno;
}

int jug_deIdASeleccion (Jugador* unJugador, LinkedList* selecciones, char* seleccionPais)
{
	int retorno = -1;
	int len;
	int i;
	int auxId;
	char auxPais[30];
	Seleccion* pSeleccion = NULL;

	if (unJugador != NULL && selecciones != NULL && !ll_isEmpty(selecciones))
	{
		len=ll_len(selecciones);
		for (i=0;i<len;i++)
		{
			pSeleccion = (Seleccion*)ll_get(selecciones, i);
			if (selec_getId(pSeleccion, &auxId) == 0 && selec_getPais(pSeleccion, auxPais)== 0)
			{
				if ((*(unJugador)).idSeleccion == auxId)
				{
					strcpy(seleccionPais, auxPais);
					retorno = 0;
				}
				else if ((*(unJugador)).idSeleccion == 0)
				{
					strcpy(seleccionPais, "No convocado");
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
