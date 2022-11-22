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
		if (getStringconEspacio((*(jugadorUnico)).nombre, 51, "Ingrese APELLIDO y luego NOMBRE del jugador (max 50 caracteres)\n", "ERROR: Intente nuevamente con caracteres válidos y respetando el max.\n", 3) == 0 &&
			get_Posicion((*(jugadorUnico)).posicion, 51, "Nombre de la posición en la que juega: (arquero, delantero, defensor o mediocampista)\n", "Posición no válida\n", 3) == 0 &&
			utn_getShort(&(*(jugadorUnico)).numeroCamiseta, "Ingrese el numero de camiseta correspondiente (1-99)\n", "No ingresó un número válido\n", 1, 99, 3) == 0)
		{
			mostrarConfederaciones(confederaciones, length);
		}
		if (utn_getNumero(&(*(jugadorUnico)).idConfederacion, "Ingrese el ID de la federacion correspondiente\n", "No es un ID listado\n", 100, 105, 3) == 0 &&
			utn_getFloat(&(*(jugadorUnico)).salario, "Ingrese el salario en pesos -sin signo '$'- (Min 1000)\n", "Salario no válido\n", 1000, 1000000, 3) == 0 &&
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
		if (get_Posicion(auxPosicion, 51, "Indique la posición en la que juega: \n", "Posición no válida\n", 3) == 0)
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
		if (utn_getFloat(&(*(listaJugadores+posicionJugadorenArray)).salario, "Ingrese el salario en pesos -sin signo '$'- (Min 1000)'\n", "Salario no válido\n", 1000, 1000000, 3) == 0)
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

int ordenarConfederacionyJugadores (eJugador* listaJugadores, int length, eConfederacion* confederaciones, int tam)
{
	int retorno = -1;
	int i;
	int j;
	char descripcion1[51];
	char descripcion2[51];
	eJugador jugadorAux;

	if (listaJugadores != NULL && length > 0)
	{
		for (i=0; i<length-1; i++)
		{
			for (j=i+1; j<length; j++)
			{
				if (deIDaDescripcion(listaJugadores, i, confederaciones, tam, descripcion1) == 0 && deIDaDescripcion(listaJugadores, j, confederaciones, tam, descripcion2) == 0 )
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

int deIDaDescripcion(eJugador* jugador, int i, eConfederacion* confederaciones, int tam, char* descripcion)
{
	int retorno = -1;
	int j;

	if (jugador != NULL && confederaciones != NULL && descripcion != NULL)
	{
		for (j=0; j<tam; j++)
		{
			if ((*(jugador+i)).idConfederacion == (*(confederaciones+j)).id)
			{
				strcpy(descripcion,(*(confederaciones+j)).nombre);
				retorno = 0;
				break;
			}
		}
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

int contarDuracionContratosPorConfederacion (eJugador* listaJugadores, int len, eConfederacion* confederaciones, int tam, int* arrayContadorConfederaciones)
{
	int retorno = -1;
	int i;
	int j;

	if (listaJugadores != NULL && confederaciones != NULL && len >0 && tam > 0)
	{
		for (i=0; i<tam; i++)
		{
			for (j=0; j<len; j++)
			{
				if ((*(confederaciones+i)).id == (*(listaJugadores+j)).idConfederacion && (*(listaJugadores+j)).isEmpty == 0)
				{
					(*(arrayContadorConfederaciones+i)) = (*(arrayContadorConfederaciones+i)) + (*(listaJugadores+j)).aniosContrato;
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

	if (array != NULL && length > 0 && numMaximo != NULL && posicionMaximo != NULL)
	{
		*numMaximo = 0;
		for (i=0; i<length; i++)
		{
			if ((*(array+i)) > *numMaximo)
			{
				*numMaximo = (*(array+i));
				*posicionMaximo = i;
			}
			else if((*(array+i)) == *numMaximo)
			{
				*posicionMaximo = -1;
			}
		}
		retorno = 0;
	}
	return retorno;
}

int contarJugadoresPorConfederacion(eJugador* listaJugadores, int length, eConfederacion* confederaciones, int tam, int* arrayContadorJugadoresConfederaciones)
{
	int retorno = -1;
	int i;
	int j;
	if (listaJugadores != NULL && length > 0 && confederaciones != NULL && tam > 0)
	{
		for (i=0;i<tam;i++)
		{
			for (j=0; j<length; j++)
			{
				if ((*(confederaciones+i)).id == (*(listaJugadores+j)).idConfederacion && (*(listaJugadores+j)).isEmpty == 0)
				{
					(*(arrayContadorJugadoresConfederaciones+i)) = (*(arrayContadorJugadoresConfederaciones+i)) + 1;
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}
