#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "confederaciones.h"
#include "jugadores.h"
#include "utn_input.h"
#include "output.h"

void mostrarMenu(void)
{
	printf("1. ALTA DE JUGADOR\n");
	printf("2. BAJA DE JUGADOR\n");
	printf("3. MODIFICACIÓN DE JUGADOR\n");
	printf("4. INFORMES\n");
	printf("5. SALIR\n");
}

void subMenu(void)
{
	printf("A. Nombre\n");
	printf("B. Posición\n");
	printf("C. N° de camiseta\n");
	printf("D. Confederación\n");
	printf("E. Salario\n");
	printf("F. Años de contrato\n");
}

void menuInformes(void)
{
	printf("1. Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador.\n");
	printf("2. Listado de confederaciones con sus jugadores.\n");
	printf("3. Informe: Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio.\n");
	printf("4. Informe: Confederación con mayor cantidad de años de contratos total.\n");
	printf("5. Informe: Porcentaje de jugadores por cada confederación.\n");
	printf("6. Informe: Región con más jugadores y el listado de los mismos.\n");
}

void mostrarConfederaciones(eConfederacion* confederaciones, int length)
{
	int i;
	printf("+===========================================================+\n");
	printf("|  ID |   NOMBRE   |          REGION         | AÑO CREACION |\n");
	printf("|-----------------------------------------------------------|\n");
	for (i=0; i<length; i++)
	{
		printf("|%5d|%-12s|%-25s|%14d|\n",(*(confederaciones+i)).id, (*(confederaciones+i)).nombre, (*(confederaciones+i)).region, (*(confederaciones+i)).anioCreacion);
	}
	printf("+===========================================================+\n");
}

int mostrarJugadores(eJugador* listaJugadores, int length, eConfederacion* confederaciones, int tam)
{
	int retorno = -1;
	char confederacion[51];
	int i;
	int j;
	eJugador jugadorAux;

	if (listaJugadores != NULL && length > 0)
	{
		for (i=0; i<length -1; i++)
		{
			for (j=i+1; j<length; j++)
			{
				if ((*(listaJugadores+j)).id<(*(listaJugadores+i)).id)
				{
					jugadorAux = (*(listaJugadores+j));
					(*(listaJugadores+j)) = (*(listaJugadores+i));
					(*(listaJugadores+i))= jugadorAux;
				}
			}
		}

		printf("+================================================================================================================+\n");
		printf("|  ID  |            NOMBRE            |  POSICION  | N° CAMISETA |   SUELDO   | CONFEDERACION | AÑOS DE CONTRATO |\n");
		printf("|----------------------------------------------------------------------------------------------------------------|\n");
		for (i=0; i<length;i++)
		{
			if ((*(listaJugadores+i)).isEmpty == 0)
			{
				printf("|%6d|%-30s|%-12s|%13hi|%12.2f|", (*(listaJugadores+i)).id, (*(listaJugadores+i)).nombre, (*(listaJugadores+i)).posicion,(*(listaJugadores+i)).numeroCamiseta, (*(listaJugadores+i)).salario);
				if (deIDaDescripcion(listaJugadores, i, confederaciones, tam, confederacion)==0)
				printf("%-15s|%18hi|\n", confederacion, (*(listaJugadores+i)).aniosContrato);
			}
		}
		printf("+================================================================================================================+\n\n");
		retorno = 0;
	}
	return retorno;
}


int printInformeUno (eJugador* listaJugadores, int length, eConfederacion* confederaciones, int tam)
{
	int retorno = -1;
	int i;
	char descripcion[51];

	if (listaJugadores != NULL && length >0)
	{
		if (ordenarConfederacionyJugadores (listaJugadores, length, confederaciones, tam) == 0)
		{
			printf("+=========================+===============================+==================+=============+============+================+============+\n");
			printf("|      CONFEDERACION      |             NOMBRE            |     POSICION     | N° CAMISETA |   SUELDO   | ANIOS CONTRATO | ID JUGADOR |\n");
			printf("+-------------------------+-------------------------------+------------------+-------------+------------+----------------+------------+\n");
			for (i=0;i<length;i++)
			{
				if ((*(listaJugadores+i)).isEmpty == 0)
				{
					if (deIDaDescripcion(listaJugadores, i, confederaciones, tam, descripcion) == 0)
					{
						printf("|%-25s|%-31s|%-18s|%13hi|%12.2f|%16hi|%12d|\n", descripcion, (*(listaJugadores+i)).nombre,(*(listaJugadores+i)).posicion,(*(listaJugadores+i)).numeroCamiseta,(*(listaJugadores+i)).salario,(*(listaJugadores+i)).aniosContrato,(*(listaJugadores+i)).id);
					}

					retorno = 0;
				}
			}
			printf("+=========================+===============================+==================+=============+============+================+============+\n\n");
		}
	}
	return retorno;
}

int printInformeDos (eJugador* listaJugadores, int length, eConfederacion* confederaciones, int tam)
{
	int retorno = -1;
	int i;
	int j;
	char auxDescripcion[30];

	if (listaJugadores != NULL && confederaciones != NULL && tam > 0 && length > 0)
	{
		for (i=0;i<tam;i++)
		{
			printf("+================================================================+\n");
			printf("|%-64s|\n", (*(confederaciones+i)).nombre);
			printf("+================================================================+\n");
			printf("|             NOMBRE            |     POSICION     | N° CAMISETA |\n");
			printf("+-------------------------------+------------------+-------------+\n");
			for (j=0;j<length;j++)
			{
				if ((*(listaJugadores+j)).isEmpty == 0 && deIDaDescripcion(listaJugadores, j, confederaciones, tam, auxDescripcion) == 0)
				{
					if (stricmp(auxDescripcion,(*(confederaciones+i)).nombre) == 0)
					{
						printf("|%-31s|%-18s|%13d|\n",(*(listaJugadores+j)).nombre, (*(listaJugadores+j)).posicion, (*(listaJugadores+j)).numeroCamiseta);
					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int printInformeTres (eJugador* listaJugadores, int length)
{	int retorno = -1;
	if (listaJugadores != NULL && length > 0)
	{	float salarioTotal= 0;
		float salarioPromedio = 0;
		int cantidadJugadores = 0;
		int i;
		if (salarioTotalJugadores(listaJugadores,length,&salarioTotal)== 0)
		{
			if (salarioPromedioJugadores(listaJugadores,length,&salarioPromedio,salarioTotal) == 0)
			{
				for(i=0; i<length; i++)
				{
					if ((*(listaJugadores+i)).isEmpty == 0 && (*(listaJugadores+i)).salario > salarioPromedio)
					{
						cantidadJugadores++;
					}
				}
				printf("+=============================+==================+=======================================+\n");
				printf("| TOTAL DE TODOS LOS SALARIOS | SALARIO PROMEDIO | JUGADORES QUE COBRAN MAS DEL PROMEDIO |\n");
				printf("+-----------------------------+------------------+---------------------------------------+\n");
				printf("|%29.2f|%18.2f|%39d|\n", salarioTotal, salarioPromedio, cantidadJugadores);
				printf("+=============================+==================+=======================================+\n");
				retorno = 0;
			}
		}
	}
	return retorno;
}

int printInformeCuatro (eJugador* listaJugadores, int len, eConfederacion* listaConfederaciones, int tam)
{
	int retorno = -1;
	int arrayContadorConfederaciones[tam];
	int numeroMaximoContratos = 0;
	int posicionMaximo = 0;
	if (listaJugadores != NULL && len > 0 && listaConfederaciones != NULL && tam > 0)
	{
		if (iniciaArray (arrayContadorConfederaciones, tam) == 0)
		{
			if (contarDuracionContratosPorConfederacion(listaJugadores, len, listaConfederaciones, tam, arrayContadorConfederaciones)== 0)
			{
				if (buscarMax (arrayContadorConfederaciones, tam, &numeroMaximoContratos, &posicionMaximo) == 0)
				{
					if (posicionMaximo == -1)
					{
						printf("+-----------------------------------------------------------------+\n");
						printf("| Hay mas de una confederación con %d años de contratos en total |\n", numeroMaximoContratos);
						printf("+-----------------------------------------------------------------+\n");
					}
					if (posicionMaximo >= 0)
					{
						printf("+===============================================+=============================================+==========+\n");
						printf("| Confederacion con mayor duracion en contratos:|%-20s| Total años de contrato:|%10d|\n",(*(listaConfederaciones+posicionMaximo)).nombre, numeroMaximoContratos);
						printf("+-----------------------------------------------+---------------------------------------------+----------+\n");

					}

					retorno = 0;
				}
			}
		}
	}
return retorno;
}

int printInformeQuinto (eJugador* listaJugadores, int length, eConfederacion* confederaciones, int  tam, int contadorJugadores)
{
	int retorno = -1;
	int arrayContadorJugadoresConfederaciones [6];
	int i;
	if (listaJugadores != NULL && length > 0)
	{
		if (iniciaArray (arrayContadorJugadoresConfederaciones, 6) == 0)
		{
			if (contarJugadoresPorConfederacion(listaJugadores,length, confederaciones, tam, arrayContadorJugadoresConfederaciones)== 0)
			{
				printf("+==============================+=========================+\n");
				printf("|        CONFEDERACION         | PORCENTAJE DE JUGADORES |\n");
				printf("+------------------------------+-------------------------+\n");
				for (i=0;i<tam;i++)
				{
					if (*(arrayContadorJugadoresConfederaciones+i) >= 0)
					{
						printf("|%-30s|%%%24.2f|\n", (*(confederaciones+i)).nombre, (float)(*(arrayContadorJugadoresConfederaciones+i)*100)/(contadorJugadores));
						printf("+------------------------------+-------------------------+\n");
					}
				}
				printf("+==============================+=========================+\n");
				retorno = 0;
			}
		}
	}
	return retorno;
}

int printInformeSeis (eJugador* listaJugadores, int length, eConfederacion* confederaciones, int tam)
{
	int retorno = -1;
	int i;
	int arrayContadorJugadoresConfederaciones [6];
	int numeroMaximoJugadores = 0;
	int posicionMaximo = 0;

	if (listaJugadores != NULL && length > 0)
		{
			if (iniciaArray (arrayContadorJugadoresConfederaciones, tam) == 0)
			{
				if (contarJugadoresPorConfederacion(listaJugadores,length, confederaciones, tam, arrayContadorJugadoresConfederaciones)== 0)
				{
					if (buscarMax (arrayContadorJugadoresConfederaciones, tam, &numeroMaximoJugadores, &posicionMaximo) == 0)
					{
						if (posicionMaximo >= 0)
						{
							printf("+=========================================+====================+==========+\n");
							printf("| REGION MAYORITARIA:|%-20s| Total de jugadores:|%10d|\n",(*(confederaciones+posicionMaximo)).region, numeroMaximoJugadores);
							printf("+-----------------------------------------+--------------------+----------+\n\n");

							printf("+=====================================================================================================+\n");
							printf("|  ID  |             NOMBRE            |     POSICION     | N° CAMISETA |   SUELDO   | ANIOS CONTRATO |\n");
							printf("+------+-------------------------------+------------------+-------------+------------+----------------+\n");
							for (i=0;i<length;i++)
							{
								if ((*(listaJugadores+i)).isEmpty == 0 && (*(listaJugadores+i)).idConfederacion == (*(confederaciones+posicionMaximo)).id)
								{
									printf("|%6d|%-31s|%-18s|%13hi|%12.2f|%16hi|\n",(*(listaJugadores+i)).id, (*(listaJugadores+i)).nombre, (*(listaJugadores+i)).posicion, (*(listaJugadores+i)).numeroCamiseta, (*(listaJugadores+i)).salario, (*(listaJugadores+i)).aniosContrato);
								}

							}
							printf("+======+===============================+==================+=============+============+================+\n");
						}


						if (posicionMaximo == -1)
						{
							printf("+------------------------.-------------------------------------+\n");
							printf("| Hay dos o mas regiones con un total de %d jugadores cada una |\n", numeroMaximoJugadores);
							printf("+--------------------------------------------------------------+\n");
						}
						retorno = 0;
					}
				}
			}
		}

	return retorno;
}
