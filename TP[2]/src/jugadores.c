#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "confederaciones.h"
#include "jugadores.h"
#include "utn_input.h"
#include "output.h"


int iniciaArrayJugadores (eJugador* array, int length)
{
	int retorno = -1;
	int i;
	if (array != NULL && length >0)
	{
		for (i=0; i<length; i++)
		{
			(*(array+i)).id = 0;
			strcpy((*(array+i)).nombre,"\0");
			(*(array+i)).numeroCamiseta = 0;
			(*(array+i)).idConfederacion = 0;
			(*(array+i)).salario = 0;
			(*(array+i)).aniosContrato = 0;
			(*(array+i)).isEmpty = 1;
		}
			retorno = 0;
	}
		return retorno;
}

int arrayIsEmpty (eJugador* listaJugadores, int length, int* posicionVacia)
{
	int retorno = -1;
	int i;
	if (listaJugadores != NULL && length >0 && posicionVacia !=NULL)
	{
		for (i=0; i<length; i++)
		{
			if ((*(listaJugadores+i)).isEmpty == 1)
			{
				*posicionVacia = i;
				retorno = 0;
				break;
			}
		}

	}
	return retorno;
}

int ingresaJugador(eJugador* jugadorUnico, eConfederacion* confederaciones, int length, int* idJugador)
{
	int retorno = -1;

	if (jugadorUnico!=NULL && idJugador !=NULL)
	{
		if (getStringconEspacio((*(jugadorUnico)).nombre, 51, "Ingrese APELLIDO y luego NOMBRE del jugador (max 50 caracteres)\n", "ERROR: intente nuevamente\n", 3) == 0 &&
			getStringconEspacio((*(jugadorUnico)).posicion, 51, "Nombre de la posición en la que juega: \n", "Posición no válida\n", 3) == 0 &&
			utn_getShort(&(*(jugadorUnico)).numeroCamiseta, "Ingrese el numero de camiseta correspondiente (1-99)\n", "No ingresó un número válido\n", 1, 99, 3) == 0)
		{
			mostrarConfederaciones(confederaciones, length);
		}
		if (utn_getNumero(&(*(jugadorUnico)).idConfederacion, "Ingrese el ID de la federacion correspondiente\n", "No es un ID listado\n", 100, 105, 3) == 0 &&
			utn_getFloat(&(*(jugadorUnico)).salario, "Ingrese el salario en pesos -sin signo '$'- Recuerde que el mínimo son 23.000'\n", "Salario no válido\n", 23000, 100000000, 3) == 0 &&
			utn_getShort(&(*(jugadorUnico)).aniosContrato, "Cantidad de años de contrato (min 1 - max 5)\n", "ERROR; intente nuevamente\n", 1, 5, 2) == 0)
		{
			(*(jugadorUnico)).isEmpty = 0;
			*idJugador = *idJugador + 1;
			retorno = 0;
		}
	}

	return retorno;
}

int buscarPorID (eJugador* listaJugadores, int length, int * posicionJugador)
{
	int retorno = -1;
	int i;
	int idBuscar;

	if (listaJugadores != NULL && length > 0 && posicionJugador != NULL)
	{
		if (utn_getNumero(&idBuscar, "Ingrese el ID del jugador a buscar\n","No es un ID válido",1,300,3) == 0)
		{
			for (i=0; i<length;i++)
			{
				if ((*(listaJugadores+i)).id == idBuscar)
				{
					*posicionJugador = i;
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

int darBaja(eJugador* listaJugadores, int posicionJugador)
{
	int retorno = -1;

	if (listaJugadores != NULL && posicionJugador >=0)
	{
		(*(listaJugadores+posicionJugador)).id = -1;
		(*(listaJugadores+posicionJugador)).isEmpty = 1;
		retorno = 0;
	}
	return retorno;
}

int modificaNombre (eJugador* listaJugadores, int posicionJugador)
{
	int retorno = -1;
	char auxNombre[51];

	if (listaJugadores != NULL)
	{
		if (getStringconEspacio(auxNombre, 51, "Ingrese APELLIDO y luego NOMBRE del jugador, corregidos (max 50 caracteres)\n", "ERROR: intente nuevamente\n", 3) == 0)
		{
			strcpy((*(listaJugadores+posicionJugador)).nombre, auxNombre);
			retorno = 0;
		}
	}
	return retorno;
}

int modificaPosicion (eJugador* listaJugadores, int posicionJugadorenArray)
{
	int retorno = -1;
	char auxPosicion[51];

	if (listaJugadores != NULL)
	{
		if (getStringconEspacio(auxPosicion, 51, "Indique la posición en la que juega: \n", "Posición no válida\n", 3) == 0)
		{
			strcpy((*(listaJugadores+posicionJugadorenArray)).posicion, auxPosicion);
			retorno = 0;
		}
	}
	return retorno;
}

int modificaCamiseta (eJugador* listaJugadores, int posicionJugadorenArray)
{
	int retorno = -1;

	if (listaJugadores != NULL)
	{
		if (utn_getShort(&(*(listaJugadores+posicionJugadorenArray)).numeroCamiseta, "Ingrese el numero de camiseta correspondiente (1-99)\n", "No ingresó un número válido\n", 1, 99, 3) == 0)
		{
			retorno = 0;
		}
	}
	return retorno;
}

int modificaConfederacion (eJugador* listaJugadores, int posicionJugadorenArray, eConfederacion* confederaciones, int length)
{
	int retorno = -1;

	if (listaJugadores != NULL)
	{
		mostrarConfederaciones(confederaciones, length);
		if (utn_getNumero(&(*(listaJugadores+posicionJugadorenArray)).idConfederacion, "Ingrese el ID de la federacion correspondiente\n", "No es un ID listado\n", 100, 105, 3) == 0)
		{
			retorno = 0;
		}
	}
	return retorno;
}

int modificaSalario (eJugador* listaJugadores, int posicionJugadorenArray)
{
	int retorno = -1;

	if (listaJugadores != NULL)
	{
		if (utn_getFloat(&(*(listaJugadores+posicionJugadorenArray)).salario, "Ingrese el salario en pesos -sin signo '$'- Recuerde que el mínimo son 23.000'\n", "Salario no válido\n", 23000, 100000000, 3) == 0)
		{
			retorno = 0;
		}
	}
	return retorno;
}

int modificaContrato (eJugador* listaJugadores, int posicionJugadorenArray)
{
	int retorno = -1;

	if (listaJugadores != NULL)
	{
		if (utn_getShort(&(*(listaJugadores+posicionJugadorenArray)).aniosContrato, "Cantidad de años de contrato (min 1 - max 5)\n", "ERROR; intente nuevamente\n", 1, 5, 2) == 0)
		{
			retorno = 0;
		}
	}
	return retorno;
}

int ordenarConfederacionyJugadores (eJugador* listaJugadores, int length, eConfederacion* confederaciones)
{
	int retorno = -1;
	int i;
	int j;
	char descripcion1[51];
	char descripcion2[51];
	eJugador jugadorAux;

	if (listaJugadores != NULL && length > 0)
	{
		for (i=0; i<length -1; i++)
		{
			for (j=i+1; j<length; j++)
			{
				if (deIDaDescripcion(listaJugadores, i, confederaciones, descripcion1) == 0 && deIDaDescripcion(listaJugadores, j, confederaciones, descripcion2) == 0 )
				{
					if (stricmp(descripcion2, descripcion1)<0)
					{
						jugadorAux = (*(listaJugadores+j));
						(*(listaJugadores+j)) = (*(listaJugadores+i));
						(*(listaJugadores+i))= jugadorAux;
					}
					if ((*(listaJugadores+j)).idConfederacion == (*(listaJugadores+i)).idConfederacion)
					{
						if(stricmp((*(listaJugadores+j)).nombre, (*(listaJugadores+i)).nombre)<0)
						{
							jugadorAux = (*(listaJugadores+j));
							(*(listaJugadores+j)) = (*(listaJugadores+i));
							(*(listaJugadores+i))= jugadorAux;
						}
					}
				}
			}
		}
		retorno = 0;
	}
		return retorno;
}

int deIDaDescripcion(eJugador* jugador, int i, eConfederacion* confederaciones, char* descripcion)
{
	int retorno = -1;

	if (jugador != NULL && confederaciones != NULL && descripcion != NULL)
	{
		if ((*(jugador+i)).idConfederacion == 0)
		{
			strcpy(descripcion,"\0");
		}
		if ((*(jugador+i)).idConfederacion == 100)
		{
			strcpy(descripcion,(*(confederaciones)).nombre);
		}
		if ((*(jugador+i)).idConfederacion == 101)
		{
			strcpy(descripcion,(*(confederaciones+1)).nombre);
		}
		if ((*(jugador+i)).idConfederacion == 102)
		{
			strcpy(descripcion,(*(confederaciones+2)).nombre);
		}
		if ((*(jugador+i)).idConfederacion == 103)
		{
			strcpy(descripcion,(*(confederaciones+3)).nombre);
		}
		if ((*(jugador+i)).idConfederacion == 104)
		{
			strcpy(descripcion,(*(confederaciones+4)).nombre);
		}
		if ((*(jugador+i)).idConfederacion == 105)
		{
			strcpy(descripcion,(*(confederaciones+5)).nombre);
		}
		retorno = 0;
	}
	return retorno;
}

int salarioTotalJugadores(eJugador* listaJugadores,int length,float* salarioTotal)
{
	int retorno = -1;
	int i;
	if (listaJugadores != NULL && length > 0)
	{
		for(i=0; i<length; i++)
		{
			if ((*(listaJugadores+i)).isEmpty == 0)
			{
				*salarioTotal = *salarioTotal + (*(listaJugadores+i)).salario;
			}
		}
		retorno = 0;
	}
	return retorno;
}

int salarioPromedioJugadores(eJugador* listaJugadores,int length,float* salarioPromedio, float salarioTotal)
{
	int retorno = -1;
	int i;
	int contadorJugadores = 0;

	if (listaJugadores != NULL && length > 0)
	{
		for(i=0; i<length; i++)
		{
			if ((*(listaJugadores+i)).isEmpty == 0)
			{
				contadorJugadores++;
			}
		}
		if (contadorJugadores > 0)
		{
			*salarioPromedio = salarioTotal / contadorJugadores;
			retorno = 0;
		}
	}
	return retorno;
}

int contarDuracionContratosPorConfederacion(eJugador* listaJugadores,int length,int * arrayContadorConfederaciones)
{
	int retorno = -1;
	int i;
	if (listaJugadores != NULL && length > 0)
	{

		for (i=0;i<length;i++)
		{
			if ((*(listaJugadores+i)).isEmpty == 0)
			{
				if ((*(listaJugadores+i)).idConfederacion == 100)
				{
					(*(arrayContadorConfederaciones + 0)) = (*(arrayContadorConfederaciones + 0 )) + (*(listaJugadores+i)).aniosContrato ;
				}
				if ((*(listaJugadores+i)).idConfederacion == 101)
				{
					(*(arrayContadorConfederaciones+1)) = (*(arrayContadorConfederaciones+1)) + (*(listaJugadores+i)).aniosContrato;
				}
				if ((*(listaJugadores+i)).idConfederacion == 102)
				{
					(*(arrayContadorConfederaciones+2)) = (*(arrayContadorConfederaciones+2)) +(*(listaJugadores+i)).aniosContrato;
				}
				if ((*(listaJugadores+i)).idConfederacion == 103)
				{
					(*(arrayContadorConfederaciones+3)) = (*(arrayContadorConfederaciones+3)) + (*(listaJugadores+i)).aniosContrato;
				}
				if ((*(listaJugadores+i)).idConfederacion == 104)
				{
					(*(arrayContadorConfederaciones+4)) = (*(arrayContadorConfederaciones+4)) + (*(listaJugadores+i)).aniosContrato ;
				}
				if ((*(listaJugadores+i)).idConfederacion == 105)
				{
					(*(arrayContadorConfederaciones+5)) = (*(arrayContadorConfederaciones+5)) + (*(listaJugadores+i)).aniosContrato;
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int buscarMax (int* array, int length, int * numMaximo, int * posicionMaximo)
{
	int retorno = -1;
	int i;

	if (array != NULL && length > 0 && numMaximo != NULL)
	{
		*numMaximo = (*(array));
		for (i=0; i<length; i++)
		{
			if ((*(array+i)) > *numMaximo)
			{
				*numMaximo = (*(array+i));
				*posicionMaximo = i;
			}
			/*else if((*(array+i)) == *numMaximo)
			{
				*posicionMaximo = -1;
			}*/
		}
		retorno = 0;
	}
	return retorno;
}

int contarJugadoresPorConfederacion(eJugador* listaJugadores,int length,int* arrayContadorJugadoresConfederaciones)
{
	int retorno = -1;
	int i;
	if (listaJugadores != NULL && length > 0)
	{
		for (i=0;i<length;i++)
				{
					if ((*(listaJugadores+i)).isEmpty == 0)
					{
						if ((*(listaJugadores+i)).idConfederacion == 100)
						{
							(*(arrayContadorJugadoresConfederaciones + 0)) = (*(arrayContadorJugadoresConfederaciones + 0 )) + 1 ;
						}
						if ((*(listaJugadores+i)).idConfederacion == 101)
						{
							(*(arrayContadorJugadoresConfederaciones+1)) = (*(arrayContadorJugadoresConfederaciones+1)) + 1;
						}
						if ((*(listaJugadores+i)).idConfederacion == 102)
						{
							(*(arrayContadorJugadoresConfederaciones+2)) = (*(arrayContadorJugadoresConfederaciones+2)) + 1;
						}
						if ((*(listaJugadores+i)).idConfederacion == 103)
						{
							(*(arrayContadorJugadoresConfederaciones+3)) = (*(arrayContadorJugadoresConfederaciones+3)) + 1;
						}
						if ((*(listaJugadores+i)).idConfederacion == 104)
						{
							(*(arrayContadorJugadoresConfederaciones+4)) = (*(arrayContadorJugadoresConfederaciones+4)) + 1 ;
						}
						if ((*(listaJugadores+i)).idConfederacion == 105)
						{
							(*(arrayContadorJugadoresConfederaciones+5)) = (*(arrayContadorJugadoresConfederaciones+5)) + 1;
						}
					}
				}
				retorno = 0;
	}
	return retorno;
}
