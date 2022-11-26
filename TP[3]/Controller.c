#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "utn_input.h"
#include "output.h"
#include "Jugador.h"
#include "parser.h"
#include "Seleccion.h"
#include "LinkedList.h"

#define char_LEN 30
#define name_LEN 100
#define MAX 1000000

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	FILE* pFile = NULL;

	if (path != NULL && pArrayListJugador != NULL)
	{
		pFile = fopen(path, "r");
		if (pFile != NULL)
		{
			if (parser_JugadorFromText(pFile , pArrayListJugador) == 0)
			{
				retorno = 0;
			}
		}
		fclose(pFile);
	}
	return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	FILE* pFileBin = NULL;

	if(path != NULL && pArrayListJugador != NULL)
	{
		pFileBin = fopen(path, "rb");
		if(pFileBin != NULL)
		{
			if(parser_JugadorFromBinary(pFileBin, pArrayListJugador) == 0)
			{
				retorno = 0;
			}
		}
		fclose(pFileBin);
	}
	return retorno;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int auxId;
	char auxNombreCompleto[100];
	int auxEdad;
	char auxPosicion[30];
	char auxNacionalidad[30];
	int auxIdSeleccion = 0;
	Jugador* pAuxJugador = NULL;
	Jugador* unJugador = NULL;


	if(pArrayListJugador != NULL)
	{
		if (parser_getId("ids.csv", &auxId) == 0)
		{
			if(getStringconEspacio(auxNombreCompleto, 100, "Ingrese el nombre y apellido del jugador:\n", "Error: El nombre ingresado no es válido\n", 3) == 0 &&
			   utn_getNumero(&auxEdad, "Ingrese la edad del jugador (mayor de edad y hasta los 40 años)\n", "Error: No es una edad válida\n", 18, 40, 3) == 0 &&
			   get_Posicion(auxPosicion, 30, "Ingrese la posicion en la que juega:\n", "Error: posición no válida\n", 3) == 0 &&
			   get_Nacionalidad(auxNacionalidad, 30, "Ingrese nacionalidad del jugador:\n", "Error: Nacionalidad no válida\n", 3) == 0)
			{
				if((pAuxJugador = jug_new()) != NULL)
				{
					if(jug_setId(pAuxJugador, auxId) == 0 && jug_setNombreCompleto(pAuxJugador, auxNombreCompleto) == 0 &&
					   jug_setEdad(pAuxJugador, auxEdad) == 0 && jug_setPosicion(pAuxJugador, auxPosicion) == 0 &&
					   jug_setNacionalidad(pAuxJugador, auxNacionalidad) == 0 && jug_setIdSeleccion(pAuxJugador, auxIdSeleccion) == 0)
					{
						unJugador = pAuxJugador;
						ll_add(pArrayListJugador, unJugador);
						auxId++;
						parser_guardarId("ids.csv", auxId);
						retorno = 0;
					}
					else
					{
						jug_delete(pAuxJugador);
					}
				}
			 }
		}
	}
		return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int idABuscar;
	int index;
	Jugador* pUnJugador = NULL;
	char modificar;
	char auxNombreCompleto[name_LEN];
	int auxEdad;
	char auxPosicion[char_LEN];
	char auxNacionalidad[char_LEN];

	if (pArrayListJugador != NULL && !ll_isEmpty(pArrayListJugador))
	{
		if (controller_listarJugadores(pArrayListJugador, pArrayListSeleccion) == 0)
		{
			if (utn_getNumero(&idABuscar, "Ingrese el ID del jugador a modificar\n", "Error: Ingrese una opcion valida\n", 1, MAX, 3) == 0)
			{
				if ((index = controller_buscarJugadorPorId(pArrayListJugador, idABuscar)) != -1)
				{
					pUnJugador = (Jugador*)ll_get(pArrayListJugador, index);
					controller_mostrarUnJugador(pUnJugador, pArrayListSeleccion);
					mostrarMenuModificaciones();
					if (getChar(&modificar, "Ingrese la opcion que desea modificar\n", "Error: Esa no es una opcion listada\n", 'A', 'E', 3, "Se quedo sin reintentos, vuelva a acceder\n") == 0)
					{
						switch (modificar)
						{
							case 'A':
								printf("MODIFICAR NOMBRE\n");
								if (getStringconEspacio(auxNombreCompleto, name_LEN,"Ingrese nuevo nombre de éste jugador\n", "No ingresó el nombre correctamente", 2) == 0)
								{
									if (jug_setNombreCompleto(pUnJugador,auxNombreCompleto) == 0)
									{
										controller_mostrarUnJugador(pUnJugador, pArrayListSeleccion);
										printf("El nombre fue modificado con exito\n\n");
										retorno = 0;
									}
								}
								break;
							case 'B':
								printf("MODIFICAR EDAD\n");
								if (utn_getNumero(&auxEdad,"Ingrese edad modificada\n","Error: No ingresó una edad válida\n", 18, 40, 3) == 0)
								{
									if (jug_setEdad(pUnJugador, auxEdad) == 0)
									{
										controller_mostrarUnJugador(pUnJugador, pArrayListSeleccion);
										printf("Edad modificada con exito\n");
										retorno = 0;
									}
								}
								break;
							case 'C':
								printf("MODIFICAR POSICION\n");
								if (get_Posicion(auxPosicion, char_LEN, "Ingrese nueva posicion del jugador:\n", "Error: Posicion no válidad entre las listadas\n", 3) == 0)
								{
									if (jug_setPosicion(pUnJugador,auxPosicion) == 0)
									{
										controller_mostrarUnJugador(pUnJugador, pArrayListSeleccion);
										printf("Posicion del jugador modificada con exito\n");
										retorno = 0;
									}
								}
								break;
							case 'D':
								printf("MODIFICAR NACIONALIDAD\n");
								if (get_Nacionalidad(auxNacionalidad, char_LEN, "Modifique la nacionalidad del jugador\n", "Error: no ingresó una palabra válida\n",	3) == 0)
								{
									if (jug_setNacionalidad(pUnJugador,auxNacionalidad) == 0)
									{
										controller_mostrarUnJugador(pUnJugador, pArrayListSeleccion);
										printf("Nueva nacionalidad modificada con éxito\n");
										retorno = 0;
									}
								}
								break;
							case 'E':
								printf("Volviendo al menú anterior\n");
								retorno = -1;
								break;
							}
					}
				}
				else
				{
					printf("El jugador no se encuentra listado o el ID es incorrecto. Reintente\n");
					retorno = -1;
				}
			}
		}
	}
	return retorno;
}


/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, LinkedList* pArrayListConvocados)
{
	int retorno = -1;
	Jugador* pUnJugador = NULL;
	Seleccion* pUnaSeleccion = NULL;
	int idABuscar;
	int index;
	int indexConvocado;
	char respuesta;
	int idSeleccion;
	int indexSeleccion;
	int auxConvocados;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL && !ll_isEmpty(pArrayListJugador))
	{
		if (controller_listarJugadores(pArrayListJugador, pArrayListSeleccion) == 0)
		{
			if (utn_getNumero(&idABuscar, "Ingrese el ID del jugador a dar de baja\n", "Error: Ingrese una opcion valida\n", 1, MAX, 3) == 0)
			{

				if ((index = controller_buscarJugadorPorId(pArrayListJugador, idABuscar)) != -1)
				{
					pUnJugador = (Jugador*)ll_get(pArrayListJugador, index);
					controller_mostrarUnJugador(pUnJugador, pArrayListSeleccion);
					indexConvocado = controller_buscarJugadorPorId(pArrayListConvocados, idABuscar);
					if (getRespuesta (&respuesta, "Desea dar de baja a éste jugador? Confirme 'S/N'\n", "Error: No ingreso respuesta válida. Debe ser 'S o N'\n", 'S', 'N' , 3, "Volviendo al menu principal") == 0)
					{
						if (respuesta == 'S')
						{
							jug_delete(pUnJugador);
							ll_remove(pArrayListJugador, index);
							retorno = 0;

							if (indexConvocado != -1)
							{
								if (jug_getIdSeleccion(pUnJugador, &idSeleccion) == 0 && (indexSeleccion = controller_buscarSeleccionPorId(pArrayListSeleccion, idSeleccion))!= -1)
								{
									pUnaSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, indexSeleccion);
									if (selec_getConvocados(pUnaSeleccion,&auxConvocados) == 0 && auxConvocados > 0)
									{
										auxConvocados --;
										selec_setConvocados(pUnaSeleccion, auxConvocados);
										ll_remove(pArrayListConvocados, indexConvocado);
									}
								}
							}
						}
						else
						{
							printf("Volviendo al menu\n");
							retorno = -1;
						}
					}
				}
				else
				{
					printf("El ID que busca, no corresponde a un jugador listado\n");
					retorno = -1;
				}
			}
		}
	}
    return retorno;
}

int controller_menuListados(LinkedList* pArrayListJugadores, LinkedList* pArrayListSelecciones, LinkedList* pArrayListConvocados)
{
	int retorno = -1;
	char opcionLista;

	if (pArrayListJugadores != NULL && pArrayListSelecciones != NULL && pArrayListConvocados != NULL)
	{
		mostrarMenuListado();

		if (getChar(&opcionLista, "Elija una opcion para listar\n", "No es una opcion válida\n", 'A', 'C', 2, "Volviendo al menu principal\n") == 0)
		{
			switch(opcionLista)
			{
				case 'A':
					if (controller_ordenarJugadores(pArrayListJugadores) == 0 && controller_listarJugadores(pArrayListJugadores, pArrayListSelecciones) == 0)
					{
						retorno = 0;
					}
					else
					{
						printf("Fallo carga de lista de jugadores\n");

					}
					break;
				case 'B':
					if (controller_ordenarSelecciones(pArrayListSelecciones) == 0 && controller_listarSelecciones(pArrayListSelecciones) == 0)
					{
						retorno = 0;
					}
					else
					{
						printf("Fallo carga de lista de selecciones\n");

					}
					break;
				case 'C':
					if (!ll_isEmpty(pArrayListConvocados))
					{
					 if (controller_ordenarJugadores(pArrayListConvocados)== 0 && controller_listarConvocados(pArrayListConvocados,pArrayListSelecciones) == 0)
					 {
						 retorno = 0;

					 }
					 else
					 {
						 printf("Fallo carga de lista de jugadores convocados\n");
					 }
					}
					else
					{
						printf("Aun no hay jugadores convocados para mostrar\n");
					}
					break;
			}
		}
	}
	return retorno;
}
/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	Jugador* pUnJugador = NULL;
	int id;
	char nombreCompleto[name_LEN];
	int edad;
	char posicion[char_LEN];
	char nacionalidad[char_LEN];
	int idSeleccion;
	char seleccionPais[char_LEN];

	int llLen;

	if (pArrayListJugador != NULL && !ll_isEmpty(pArrayListJugador))
	{
		llLen = ll_len(pArrayListJugador);

		if (llLen > 0)
		{
			printf("+------+----------------------------------------+------+--------------------+--------------------+--------------------+\n");
			printf("|  ID  |                 NOMBRE                 | EDAD |      POSICION      |    NACIONALIDAD    |      SELECCION     |\n");
			printf("+------+----------------------------------------+------+--------------------+--------------------+--------------------+\n");
			for (int i = 0; i <llLen; i++)
			{
				pUnJugador = (Jugador*)ll_get(pArrayListJugador, i);

				if(jug_getId(pUnJugador, &id) == 0 && jug_getNombreCompleto(pUnJugador, nombreCompleto) == 0 &&	jug_getEdad(pUnJugador, &edad) == 0 &&
				   jug_getPosicion(pUnJugador, posicion) == 0 && jug_getNacionalidad(pUnJugador, nacionalidad) == 0 &&
				   jug_getIdSeleccion(pUnJugador,&idSeleccion) == 0)
				{
					if (jug_deIdASeleccion (pUnJugador, pArrayListSeleccion, seleccionPais) != 0)
					{
						printf("No se pudo cargar el nombre de la seleccion\n");
					}
					printf("|%6d|%-40s|%6d|%-20s|%-20s|%-20s|\n", id, nombreCompleto, edad, posicion, nacionalidad, seleccionPais);
					retorno = 0;
				}
			}
				printf("+------+----------------------------------------+------+--------------------+--------------------+--------------------+\n");
		}
	}
	return retorno;
}


/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int(*ordena)(void*, void*);

	if (pArrayListJugador != NULL)
	{
		ordena = jug_ordenarPorId;
		if(ll_sort(pArrayListJugador,ordena,1) != 0)
		{
			printf("La lista no se pudo ordenar\n");
		}
		retorno = 0;
	}
	return retorno;
}


/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int i;
	int len;
	FILE *pFile;
	Jugador *pUnJugador = NULL;
	int auxId;
	char auxNombreCompleto[name_LEN];
	int auxEdad;
	char auxPosicion[char_LEN];
	char auxNacionalidad[char_LEN];
	int auxIdSeleccion;

	if (path != NULL && pArrayListJugador != NULL)
	{
		len = ll_len(pArrayListJugador);
		pFile = fopen(path, "w");

		if (pFile != NULL)
		{
			for (i = 0; i < len; i++)
			{
					pUnJugador = (Jugador*)ll_get(pArrayListJugador, i);
					if (jug_getId(pUnJugador, &auxId) == 0 && jug_getNombreCompleto(pUnJugador, auxNombreCompleto) == 0 && jug_getEdad(pUnJugador, &auxEdad) == 0 &&
						jug_getPosicion(pUnJugador, auxPosicion) == 0 && jug_getNacionalidad(pUnJugador, auxNacionalidad) == 0 && jug_getIdSeleccion(pUnJugador, &auxIdSeleccion) == 0)

					{
						fprintf(pFile,"%d,%s,%d,%s,%s,%d\n", auxId, auxNombreCompleto, auxEdad, auxPosicion, auxNacionalidad, auxIdSeleccion);
						retorno = 0;
					}
			}
		}
		fclose(pFile);
	}
	return retorno;
}


/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	Jugador* pUnJugador;
	FILE* pFileBin = NULL;
	int len;
	int i;

	if(path != NULL && pArrayListJugador != NULL)
	{
		len = ll_len(pArrayListJugador);
		pFileBin = fopen(path, "wb");

		if (pFileBin != NULL)
		{
			for(i=0; i <len; i++)
			{
				if((pUnJugador = (Jugador*)ll_get(pArrayListJugador, i)) != NULL)
				{
						fwrite(pUnJugador, sizeof(Jugador), 1, pFileBin);
						retorno = 0;
				}
			}
		 fclose(pFileBin);
		}
	}
    return retorno;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	FILE* pFile;

	if (path != NULL && pArrayListSeleccion != NULL)
	{
		pFile = fopen(path, "r");
		if (pFile != NULL)
		{
			if (parser_SeleccionFromText(pFile , pArrayListSeleccion) == 0)
			{
				retorno = 0;
			}
		}
		fclose(pFile);
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 0;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	Seleccion* pSeleccion = NULL;

	int id;
	char pais[char_LEN];
	char confederacion[char_LEN];
	int convocados;

	int llLen;

		if (pArrayListSeleccion != NULL && !ll_isEmpty(pArrayListSeleccion))
		{
			llLen = ll_len(pArrayListSeleccion);

			if (llLen > 0)
			{
				printf("+------+-----------------------------------+------------------------------+------------+\n");
				printf("|  ID  |               PAIS                |         CONFEDERACION        | CONVOCADOS |\n");
				printf("+------+-----------------------------------+------------------------------+------------+\n");
				for (int i = 0; i <llLen; i++)
				{
					pSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);
					if (selec_getId(pSeleccion, &id) == 0 && selec_getPais(pSeleccion, pais) == 0 &&
						selec_getConfederacion(pSeleccion, confederacion) == 0 && selec_getConvocados(pSeleccion,&convocados) == 0)
					{
						printf("|%6d|%-35s|%-30s|%12d|\n", id, pais, confederacion, convocados);
						retorno = 0;
					}
				}
				printf("+------+-----------------------------------+------------------------------+------------+\n");
			}
		}
		return retorno;
}

int controller_listarConvocados(LinkedList* pArrayListConvocados, LinkedList* pArraySelecciones)
{
	int retorno = -1;
	Jugador* pUnConvocado = NULL;

	int id;
	char nombreCompleto[name_LEN];
	int edad;
	char posicion[char_LEN];
	char nacionalidad[char_LEN];
	int idSeleccion;
	char seleccionPais[char_LEN];

	int llLen;

	if (pArrayListConvocados != NULL && !ll_isEmpty(pArrayListConvocados))
	{
		llLen = ll_len(pArrayListConvocados);

		if (llLen > 0)
		{
			printf("+------+----------------------------------------+------+--------------------+--------------------+--------------------+\n");
			printf("|  ID  |                 NOMBRE                 | EDAD |      POSICION      |    NACIONALIDAD    |      SELECCION     |\n");
			printf("+------+----------------------------------------+------+--------------------+--------------------+--------------------+\n");
			for (int i = 0; i <llLen; i++)
			{
				pUnConvocado = (Jugador*)ll_get(pArrayListConvocados, i);
				if (jug_getIdSeleccion(pUnConvocado,&idSeleccion) == 0 && idSeleccion != 0)
				{
					jug_getId(pUnConvocado, &id);
					jug_getNombreCompleto(pUnConvocado, nombreCompleto);
					jug_getEdad(pUnConvocado, &edad);
					jug_getPosicion(pUnConvocado, posicion);
					jug_getNacionalidad(pUnConvocado, nacionalidad);
					jug_getIdSeleccion(pUnConvocado,&idSeleccion);
					if (jug_deIdASeleccion (pUnConvocado, pArraySelecciones, seleccionPais) != 0)
					{
						printf("No se pudo cargar el nombre de la seleccion\n");
					}

					printf("|%6d|%-40s|%6d|%-20s|%-20s|%-20s|\n", id, nombreCompleto, edad, posicion, nacionalidad, seleccionPais);
					retorno = 0;
				}
			}
				printf("+------+----------------------------------------+------+--------------------+--------------------+--------------+\n");
		}
	}
	return retorno;
}


/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int(*ordenaS)(void*, void*);

	if (pArrayListSeleccion != NULL)
	{
		ordenaS = Selec_ordenarPorId;
		if(ll_sort(pArrayListSeleccion,ordenaS,1) != 0)
		{
			printf("La lista no se pudo ordenar\n");
		}
		retorno = 0;
	}
    return retorno;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int i;
	int len;
	FILE *pFile;
	Seleccion *pUnaSeleccion = NULL;
	int auxId;
	char auxPais[char_LEN];
	char auxConfederacion[char_LEN];
	int auxConvocados;

	if (path != NULL && pArrayListSeleccion != NULL)
	{
		len = ll_len(pArrayListSeleccion);
		pFile = fopen(path, "w");

		if (pFile != NULL)
		{
			for (i = 0; i < len; i++)
			{
				pUnaSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);
				if (selec_getId(pUnaSeleccion, &auxId) == 0 && selec_getPais(pUnaSeleccion, auxPais) == 0 && selec_getConfederacion(pUnaSeleccion, auxConfederacion) == 0 &&
					selec_getConvocados(pUnaSeleccion, &auxConvocados) == 0)
				{
					fprintf(pFile, "%d,%s,%s,%d\n", auxId, auxPais, auxConfederacion, auxConvocados);
					retorno = 0;
				}
			}
		}

		fclose(pFile);
	}
	return retorno;
}

int controller_buscarJugadorPorId (LinkedList *pArrayListJugador, int idIngresado)
{
	int index = -1;
	int llLen;
	int auxId;
	Jugador* pUnJugador = NULL;

	if (pArrayListJugador != NULL)
	{
		llLen = ll_len(pArrayListJugador);

		for (int i = 0; i < llLen; i++)
		{
			pUnJugador = (Jugador*)ll_get(pArrayListJugador, i);
			jug_getId(pUnJugador, &auxId);
			if (auxId == idIngresado)
			{
				index = ll_indexOf(pArrayListJugador, pUnJugador);
				break;
			}
		}
	}
	return index;
}

int controller_buscarSeleccionPorId (LinkedList *pArrayListSeleccion, int idIngresado)
{
	int index = -1;
	int llLen;
	int auxId;
	Seleccion* pUnaSeleccion = NULL;

	if (pArrayListSeleccion != NULL)
	{
		llLen = ll_len(pArrayListSeleccion);

		for (int i = 0; i < llLen; i++)
		{
			pUnaSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);
			selec_getId(pUnaSeleccion, &auxId);
			if (auxId == idIngresado)
			{
				index = ll_indexOf(pArrayListSeleccion, pUnaSeleccion);
				break;
			}
		}
	}
	return index;
}

void controller_mostrarUnJugador(Jugador* this, LinkedList* pArrayListSelecciones)
{
	int id;
	char nombreCompleto[name_LEN];
	int edad;
	char posicion[char_LEN];
	char nacionalidad[char_LEN];
	int idSeleccion;
	char seleccion[char_LEN];

	if (this != NULL && pArrayListSelecciones != NULL)
	{
		if (jug_getId(this, &id) == 0 && jug_getNombreCompleto(this, nombreCompleto) == 0 && jug_getEdad(this, &edad) == 0 &&
		    jug_getPosicion(this, posicion) == 0 && jug_getNacionalidad(this, nacionalidad) == 0 &&	jug_getIdSeleccion(this, &idSeleccion) == 0)
		{
			if (jug_deIdASeleccion (this, pArrayListSelecciones, seleccion) == 0)
			{
				printf("+------+----------------------------------------+------+--------------------+--------------------+--------------------+\n");
				printf("|  ID  |                 NOMBRE                 | EDAD |      POSICION      |    NACIONALIDAD    |      SELECCION     |\n");
				printf("+------+----------------------------------------+------+--------------------+--------------------+--------------------+\n");
				printf("|%6d|%-40s|%6d|%-20s|%-20s|%-20s|\n", id, nombreCompleto, edad, posicion, nacionalidad, seleccion);
				printf("+------+----------------------------------------+------+--------------------+--------------------+--------------+\n");
			}
		}
	}
}

void controller_mostrarUnaSeleccion(Seleccion* this)
{
	int id;
	char pais[char_LEN];
	char confederacion[char_LEN];
	int convocados;

	if (this != NULL)
	{
		if (selec_getId(this, &id) == 0 && selec_getPais(this, pais) == 0 && selec_getConfederacion(this, confederacion) &&
			selec_getConvocados(this,&convocados) == 0)
		{
			printf("+------+-----------------------------------+------------------------------+------------+\n");
			printf("|  ID  |               PAIS                |         CONFEDERACION        | CONVOCADOS |\n");
			printf("+------+-----------------------------------+------------------------------+------------+\n");
			printf("|%6d|%-35s|%-30s|%12d|\n", id, pais, confederacion, convocados);
			printf("+------+-----------------------------------+------------------------------+------------+\n");
		}
	}
}


int controller_convocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, LinkedList* pArrayListConvocados)
{
	int retorno = -1;
	int idJugador;
	int idSeleccion;
	int indexJugador;
	int indexSeleccion;
	char confirma;
	int auxIdSeleccion;
	int auxConvocados;
	Jugador* pJugador = NULL;
	Seleccion* pSeleccion = NULL;
	Jugador* pJugadorConvocado = NULL;

	if (pArrayListJugador!= NULL && !ll_isEmpty(pArrayListJugador) && pArrayListSeleccion!= NULL && !ll_isEmpty(pArrayListJugador) && pArrayListConvocados!= NULL)
	{
		if (controller_listarJugadores(pArrayListJugador, pArrayListSeleccion) == 0 && utn_getNumero(&idJugador, "Ingrese el ID del jugador a convocar\n","ID no válido\n", 1, MAX, 3) == 0)
		{
			if ((indexJugador = controller_buscarJugadorPorId (pArrayListJugador, idJugador)) != -1)
			{
				pJugador = (Jugador*)ll_get(pArrayListJugador, indexJugador);
				controller_mostrarUnJugador(pJugador, pArrayListSeleccion);
				if (controller_listarSelecciones(pArrayListSeleccion) == 0 && utn_getNumero(&idSeleccion, "Ingrese el ID de la seleccion convocante\n","ID no válido\n", 1, MAX, 3) == 0)
				{
					if ((indexSeleccion = controller_buscarSeleccionPorId(pArrayListSeleccion, idSeleccion)) != -1)
					{
						pSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, indexSeleccion);
						controller_mostrarUnaSeleccion(pSeleccion);
						if (getRespuesta (&confirma, "El jugador elegido será convocado por ésta selección? 'S/N'\n", "Error: opcion no valida", 'S', 'N', 3, "Volviendo...\n") == 0)
						{
							if (confirma == 'S' && jug_getIdSeleccion(pJugador,&auxIdSeleccion) == 0 && auxIdSeleccion == 0)
							{
								if (selec_getConvocados(pSeleccion,&auxConvocados) == 0 && auxConvocados < 22)
								{
									if(jug_setIdSeleccion(pJugador, idSeleccion) == 0)
									{
										auxConvocados ++;
										selec_setConvocados(pSeleccion, auxConvocados);
										if ((pJugadorConvocado = jug_new()) != NULL)
										{
											pJugadorConvocado = pJugador;
											ll_add(pArrayListConvocados, pJugadorConvocado);
											retorno = 0;
										}
									}
								}
							}
						}
					}
					else
					{
						printf("No hay una seleccion con ese ID\n");
					}
				}
			}
			else
			{
				printf ("No hay un jugador listado con ese numero de ID\n");
			}
		}
	}
	return retorno;
}

int controller_quitarSeleccion(LinkedList*pArrayListJugador, LinkedList*pArrayListSeleccion, LinkedList*pArrayListConvocados)
{
	int retorno = -1;
	int idJugador;
	int indexJugadorConvocado;
	int indexJugador;
	int indexSeleccion;
	char confirma;
	int auxIdSeleccion;
	int auxConvocados;
	Jugador* pJugador = NULL;
	Seleccion* pSeleccion = NULL;
	Jugador* pJugadorConvocado = NULL;

	if (pArrayListJugador!= NULL && !ll_isEmpty(pArrayListJugador) && pArrayListSeleccion!= NULL && !ll_isEmpty(pArrayListJugador) && pArrayListConvocados!=NULL && !ll_isEmpty(pArrayListConvocados))
	{
		if (controller_listarConvocados(pArrayListJugador,pArrayListSeleccion) == 0 && utn_getNumero(&idJugador, "Ingrese el ID del jugador a remover de 'convocados'\n","ID no válido\n", 1, MAX, 3) == 0)
		{
			if ((indexJugadorConvocado = controller_buscarJugadorPorId (pArrayListConvocados, idJugador)) != -1 && (indexJugador= controller_buscarJugadorPorId (pArrayListJugador, idJugador)) != -1)
			{
				pJugadorConvocado = (Jugador*)ll_get(pArrayListConvocados, indexJugadorConvocado);
				pJugador = (Jugador*)ll_get(pArrayListJugador, indexJugador);
				controller_mostrarUnJugador(pJugadorConvocado, pArrayListSeleccion);
				if (jug_getIdSeleccion(pJugadorConvocado,&auxIdSeleccion) == 0 && (indexSeleccion = controller_buscarSeleccionPorId(pArrayListSeleccion, auxIdSeleccion)) != -1)
				{
					pSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, indexSeleccion);
					if (getRespuesta (&confirma, "Desea remover el jugador de su seleccion? 'S/N'\n", "Error: opcion no valida", 'S', 'N', 3, "Volviendo...\n") == 0)
						{
							if (confirma == 'S')
							{
								if (selec_getConvocados(pSeleccion,&auxConvocados) == 0 && auxConvocados > 0)
								{
									auxConvocados --;
									selec_setConvocados(pSeleccion, auxConvocados);
									if (jug_setIdSeleccion(pJugador, 0) == 0)
									{
										jug_delete(pJugadorConvocado);
										ll_remove(pArrayListConvocados, indexJugadorConvocado);
										retorno = 0;
									}
								}
							}
						}
				}
			}
			else
			{
				printf ("No hay un jugador listado con ese numero de ID\n");
			}
		}
	}
	return retorno;
}



int controller_convocatoria(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, LinkedList* pArrayListConvocados)
{
	int retorno = -1;
	char opcion;
	Jugador* pJugador = NULL;
	int idSeleccion;
	mostrarMenuConvocar();

	if (getChar(&opcion, "Seleccione una opción del Menu\n", "Error: No seleccionó una opción válida\n", 'A', 'B', 3, "Volviendo a Menu Principal") == 0)
	{	if (ll_len(pArrayListConvocados) == 0)
		{
			for(int i=0; i<ll_len(pArrayListJugador);i++)
			{
				pJugador = (Jugador*)ll_get(pArrayListJugador, i);
				if (jug_getIdSeleccion(pJugador,&idSeleccion) == 0 && idSeleccion != 0)
				{
					ll_add(pArrayListConvocados, pJugador);
				}
			}
		 }
		if (opcion == 'A')
		{
			if (controller_convocar(pArrayListJugador, pArrayListSeleccion, pArrayListConvocados) == 0)
			{
				printf("El jugador fue convocado exitosamente\n");
				retorno = 0;
			}
		}
		else if (opcion == 'B')
		{
			 if (controller_quitarSeleccion(pArrayListJugador, pArrayListSeleccion, pArrayListConvocados) == 0)
			 {
				 printf("Se ha quitado el jugador de la lista de convocados\n");
				 retorno = 0;
			 }
		}

	}
	return retorno;
}

int controller_ordenarLista(LinkedList* pArrayListJugador, LinkedList* pArraySeleccion)
{
	int retorno = -1;
	char opcionOrdenar;
	int ordenamiento;
	int(*ordenar)(void*, void*);

	if (pArrayListJugador!=NULL && pArraySeleccion != NULL && !ll_isEmpty(pArrayListJugador) && !ll_isEmpty(pArraySeleccion))
	{
		mostrarMenuOrdenarListar();
		getChar(&opcionOrdenar, "Elija una opcion del menu\n", "Error: No es una opción listada\n", 'A', 'D', 3, "No tiene más reintentos\n");
		switch(opcionOrdenar)
		{
			case 'A':
				if (utn_getNumero(&ordenamiento, "Ingrese [1] si desea ordenar de manera ascendente, [2] de manera descendente\n", "No ingreso opcion válida\n", 1, 2, 3) == 0)
				{
					ordenar = jug_ordenarPorNacionalidad;
					if (ordenamiento == 1)
					{
						if  (ll_sort(pArrayListJugador, ordenar, 1) == 0 && controller_listarJugadores(pArrayListJugador, pArraySeleccion) == 0)
						{
							retorno = 0;
						}
					}
					else if (ordenamiento == 2)
					{
						if  (ll_sort(pArrayListJugador, ordenar, 0) == 0 && controller_listarJugadores(pArrayListJugador, pArraySeleccion) == 0)
						{
							retorno = 0;
						}
					}
					ordenar = jug_ordenarPorId;
					if (ll_sort(pArrayListJugador, ordenar, 1) != 0)
					{
						printf("No se pudo reordenar la lista\n");
					}
				}
				break;
			case 'B':
				if (utn_getNumero(&ordenamiento, "Ingrese [1] si desea ordenar de manera ascendente, [2] de manera descendente\n", "No ingreso opcion válida\n", 1, 2, 3) == 0)
				{
					ordenar = Selec_ordenarPorConfederacion;
					if(ordenamiento == 1)
					{
						if  (ll_sort(pArraySeleccion, ordenar, 1) == 0 && controller_listarSelecciones(pArraySeleccion) == 0)
						{
							retorno = 0;
						}
					}
					else if (ordenamiento == 2)
					{
						if  (ll_sort(pArraySeleccion, ordenar, 0) == 0 && controller_listarSelecciones(pArraySeleccion) == 0)
						{
							retorno = 0;
						}
					}
					ordenar = Selec_ordenarPorId;
					if (ll_sort(pArraySeleccion, ordenar, 1) != 0)
					{
						printf("No se pudo reordenar la lista\n");
					}
				}
				break;
			case 'C':
				if (utn_getNumero(&ordenamiento, "Ingrese [1] si desea ordenar de manera ascendente, [2] de manera descendente\n", "No ingreso opcion válida\n", 1, 2, 3) == 0)
				{
					if (ordenamiento == 1)
					{
						ordenar = jug_ordenarPorEdadAscendente;
						if  (ll_sort(pArrayListJugador, ordenar, 1) == 0 && controller_listarJugadores(pArrayListJugador, pArraySeleccion) == 0)
						{
							retorno = 0;
						}
					}
					else if (ordenamiento == 2)
					{
						ordenar = jug_ordenarPorEdadDescendente;
						if  (ll_sort(pArrayListJugador, ordenar, 1) == 0 && controller_listarJugadores(pArrayListJugador, pArraySeleccion) == 0)
						{
							retorno = 0;
						}
					}
					ordenar = jug_ordenarPorId;
					if (ll_sort(pArrayListJugador, ordenar, 1) != 0)
					{
						printf("No se pudo reordenar la lista\n");
					}
				}
				break;
			case 'D':
				if (utn_getNumero(&ordenamiento, "Ingrese [1] si desea ordenar de manera ascendente, [2] de manera descendente\n", "No ingreso opcion válida\n", 1, 2, 3) == 0)
				{
					ordenar = jug_ordenarPorNombre;
					if (ordenamiento == 1)
					{
						if  (ll_sort(pArrayListJugador, ordenar, 1) == 0 && controller_listarJugadores(pArrayListJugador, pArraySeleccion) == 0)
						{
							retorno = 0;
						}
					}
					else if (ordenamiento == 2)
					{
						if  (ll_sort(pArrayListJugador, ordenar, 0) == 0 && controller_listarJugadores(pArrayListJugador, pArraySeleccion) == 0)
						{
							retorno = 0;
						}
					}
					ordenar = jug_ordenarPorId;
					if (ll_sort(pArrayListJugador, ordenar, 1) != 0)
					{
						printf("No se pudo reordenar la lista\n");
					}
				}
				break;
			}
		}
	return retorno;
}

int controller_generarListaConvocadoPorConfederacion(LinkedList* pArrayListSeleccion, LinkedList* pArrayListConvocados, LinkedList* pArrayListBinario)
{
	int retorno = -1;
	char confederacionConvocada[char_LEN];
	int i;
	int j;
	int llLenSelecciones;
	int llLenConvocados;
	Seleccion* pSeleccion = NULL;
	Jugador* pUnJugador = NULL;
	char auxConfederacion[char_LEN];
	int idABuscar;
	int idSeleccion;

	if (pArrayListSeleccion != NULL && pArrayListConvocados != NULL)
	{
		printf("Se guardará un archivo que contendrá la lista de convocados de una confederacion\n\n");
		if (controller_listarSelecciones(pArrayListSeleccion) == 0 && controller_listarJugadores(pArrayListConvocados, pArrayListSeleccion) == 0 &&
			getStringconEspacio(confederacionConvocada, 30, "\nIngrese la confederacion a listar\n","Eror: No ingreso un dato valido\n", 3) == 0)
		{
			retorno = 0;
			llLenSelecciones = ll_len(pArrayListSeleccion);
			llLenConvocados = ll_len(pArrayListConvocados);
			for (i= 0; i< llLenSelecciones; i++)
			{
				pSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);
				if (selec_getConfederacion(pSeleccion, auxConfederacion)==0 && (stricmp(confederacionConvocada,auxConfederacion) == 0))
				{
					if (selec_getId(pSeleccion, &idABuscar)==0)
					{
						for (j= 0; j<llLenConvocados; j++)
						{
							pUnJugador = (Jugador*)ll_get(pArrayListConvocados, j);
							if (jug_getIdSeleccion(pUnJugador, &idSeleccion) == 0 && idSeleccion == idABuscar)
							{
								ll_add(pArrayListBinario, pUnJugador);
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}
