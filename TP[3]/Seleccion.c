#include "Seleccion.h"

#define char_LEN 30

Seleccion* selec_new()
{
	Seleccion* unaSeleccion = NULL;
	unaSeleccion = (Seleccion*)malloc(sizeof(Seleccion));

	if (unaSeleccion!= NULL)
	{
		unaSeleccion->id = 0;
		strcpy(unaSeleccion->pais, "\0");
		strcpy(unaSeleccion->confederacion, "\0");
		unaSeleccion->convocados = 0;
	}
	return unaSeleccion;
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* unaSeleccion = NULL;
	unaSeleccion = selec_new();

	if (idStr != NULL && paisStr != NULL && confederacionStr != NULL && convocadosStr != NULL)
	{
		if (unaSeleccion != NULL)
		{
			unaSeleccion->id = atoi(idStr);
			strcpy(unaSeleccion->pais, paisStr);
			strcpy(unaSeleccion->confederacion, confederacionStr);
			if (selec_setConvocados(unaSeleccion, atoi(convocadosStr)) == 0)
			{

			}
		}
	}
	return unaSeleccion;
}

void selec_delete(Seleccion* this)
{
	if (this != NULL)
	{
		free(this);
	}
}

int selec_getId(Seleccion* this,int* id)
{
	int retorno = -1;
	if (this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int selec_getPais(Seleccion* this,char* pais)
{
	int retorno = -1;
	if (this != NULL && pais != NULL)
	{
		strcpy(pais,this->pais);
		retorno = 0;
	}
	return retorno;
}

int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno = -1;
	if (this != NULL && confederacion != NULL)
	{
		strcpy(confederacion, this->confederacion);
		retorno = 0;
	}
	return retorno;
}

int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno = -1;
	if (this != NULL && convocados >= 0)
	{
		this->convocados = convocados;
		retorno = 0;
	}
		return retorno;
}
int selec_getConvocados(Seleccion* this, int* convocados)
{
	int retorno = -1;
	if (this != NULL && convocados != NULL)
	{
		*convocados = this->convocados;
		retorno = 0;
	}
	return retorno;
}

int Selec_ordenarPorConfederacion (void* this, void *this2)
{
	int retorno;
	char confederacionPrimerSelec[30];
	char confederacionSegundaSelec[30];
	Seleccion* pPrimerSelec;
	Seleccion* pSegundaSelec;

	if (this != NULL && this2 != NULL)
	{
		pPrimerSelec = (Seleccion*)this;
		pSegundaSelec = (Seleccion*)this2;
		selec_getConfederacion(pPrimerSelec, confederacionPrimerSelec);
		selec_getConfederacion(pSegundaSelec, confederacionSegundaSelec);
		retorno = strcmp(confederacionPrimerSelec, confederacionSegundaSelec);
	}
	return retorno;
}

int Selec_ordenarPorId (void* this, void *this2)
{
	int retorno = -1;
	int idPrimerSelec;
	int idSegundaSelec;
	Seleccion* pPrimerSelec;
	Seleccion* pSegundaSelec;

	if (this != NULL && this2 != NULL)
	{
		pPrimerSelec = (Seleccion*)this;
		pSegundaSelec = (Seleccion*)this2;
		selec_getId(pPrimerSelec, &idPrimerSelec);
		selec_getId(pSegundaSelec, &idSegundaSelec);

		if (idPrimerSelec > idSegundaSelec)
		{
			retorno = 1;
		}
		else if (idPrimerSelec == idSegundaSelec)
		{
			retorno = 0;
		}
	}
	return retorno;
}
