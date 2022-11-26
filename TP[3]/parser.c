#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int.
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	char id[10];
	char nombreCompleto[100];
	char edad[10];
	char posicion[30];
	char nacionalidad[30];
	char idSeleccion[10];
	Jugador* unJugador = NULL;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion); // lecturaFantasma

		while (!feof(pFile))
		{
			fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
			//printf("%s %s %s %s %s %s", id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
			unJugador = jug_newParametros(id , nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
			if (unJugador != NULL)
			{
				ll_add(pArrayListJugador, unJugador);
			}
		}
		retorno = 0;
	}
	return retorno;
}


/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	Jugador* auxJugador = NULL;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		do
		{
			if((auxJugador = jug_new()) != NULL && fread(auxJugador, sizeof(Jugador), 1, pFile) == 1)
			{
				ll_add(pArrayListJugador, auxJugador);
				retorno = 0;
			}
			else
			{
				if(auxJugador != NULL)
				{
					jug_delete(auxJugador);
				}
			}
		} while(!feof(pFile));
		fclose(pFile);
	}
	return retorno;
}

/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	char id[10];
	char pais[30];
	char confederacion[30];
	char convocados[10];
	Seleccion* unaSeleccion = NULL;

	if(pFile != NULL && pArrayListSeleccion!= NULL)
	{
		fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]\n", id, pais, confederacion, convocados);
		do
		{
			if(fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]\n", id, pais, confederacion, convocados) == 4)
			{
				if((unaSeleccion = selec_newParametros(id , pais, confederacion, convocados)) != NULL)
				{
					ll_add(pArrayListSeleccion, unaSeleccion);
				}
			}
		} while(!feof(pFile));

	retorno = 0;
	}
	return retorno;
}
/// \fn int parser_getId(char*, int*)
/// \brief toma el ultimo id cargado en el archivo
///
/// \param path
/// \param id
/// \return '0' si salio sin errores. '-1' caso contrario.
int parser_getId(char* path, int* id)
 {
 	char idLeido[10];
	int retorno = -1;
	FILE* pFile = NULL;

	if(id != NULL && (pFile = fopen(path, "r")) != NULL)
	{
		fscanf(pFile, "%[^\n]\n", idLeido);
		if (idLeido != NULL)
		{
			//printf("%s",idLeido);
			*id = atoi(idLeido);
			fclose(pFile);
			retorno = 0;
		}
	}
	return retorno;
}
/// \fn int parser_guardarId(char*, int)
/// \brief guarda el ultimo id (ya incrementado) en un archivo.
///
/// \param path
/// \param id
/// \return '0' si no hubo errores.
int parser_guardarId(char* path, int id)
{
	int retorno = -1;
	char idGuardar[10];
	FILE* pFile = NULL;

	pFile = fopen(path, "w");

	if(pFile != NULL)
	{
		itoa(id, idGuardar, 10);
		fprintf(pFile, idGuardar);
		fclose(pFile);
		retorno = 0;
	}
	return retorno;
}
