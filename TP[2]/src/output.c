#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

int mostrarJugadores(eJugador* listaJugadores, int length, eConfederacion* confederaciones)
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
				if (deIDaDescripcion(listaJugadores, i, confederaciones, confederacion)==0)
				printf("%-15s|%18hi|\n", confederacion, (*(listaJugadores+i)).aniosContrato);
			}
		}
		printf("+================================================================================================================+\n\n");
		retorno = 0;
	}
	return retorno;
}


int printInformeUno (eJugador* listaJugadores, int length, eConfederacion* confederaciones)

{
	int retorno = -1;
	int i;
	char descripcion[51];

	if (listaJugadores != NULL && length >0)
	{
		if (ordenarConfederacionyJugadores (listaJugadores, length, confederaciones) == 0)
		{
			printf("+=========================+===============================+==================+=============+============+================+============+\n");
			printf("|      CONFEDERACION      |             NOMBRE            |     POSICION     | N° CAMISETA |   SUELDO   | ANIOS CONTRATO | ID JUGADOR |\n");
			printf("+-------------------------+-------------------------------+------------------+-------------+------------+----------------+------------+\n");
			for (i=0;i<length;i++)
			{
				if ((*(listaJugadores+i)).isEmpty == 0)
				{
					if (deIDaDescripcion(listaJugadores, i, confederaciones,descripcion) == 0)
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

int printInformeDos (eJugador* listaJugadores, int length)
{
	int retorno = -1;
	int i;

	if (listaJugadores != NULL && length > 0)
	{
		printf("+===============================+\n");
		printf("|            CONMEBOL           |\n");
		printf("+-------------------------------+\n");
		for (i=0;i<length;i++)
		{
			if ((*(listaJugadores+i)).isEmpty == 0 && (*(listaJugadores+i)).idConfederacion == 100)
			{
				{
					printf("|%-31s|\n",(*(listaJugadores+i)).nombre);
				}
			}
		}
		printf("+===============================+\n");
		printf("|              UEFA             |\n");
		printf("+-------------------------------+\n");
		for (i=0;i<length;i++)
		{
			if ((*(listaJugadores+i)).isEmpty == 0 && (*(listaJugadores+i)).idConfederacion == 101)
			{
				{
					printf("|%-31s|\n",(*(listaJugadores+i)).nombre);
				}
			}
		}
		printf("+===============================+\n");
		printf("|              AFC              |\n");
		printf("+-------------------------------+\n");
		for (i=0;i<length;i++)
		{
			if ((*(listaJugadores+i)).isEmpty == 0 && (*(listaJugadores+i)).idConfederacion == 102)
			{
				{
					printf("|%-31s|\n",(*(listaJugadores+i)).nombre);
				}
			}
		}
		printf("+===============================+\n");
		printf("|              CAF              |\n");
		printf("+-------------------------------+\n");
		for (i=0;i<length;i++)
		{
			if ((*(listaJugadores+i)).isEmpty == 0 && (*(listaJugadores+i)).idConfederacion == 103)
			{
				{
					printf("|%-31s|\n",(*(listaJugadores+i)).nombre);
				}
			}
		}
		printf("+===============================+\n");
		printf("|           CONCACAF            |\n");
		printf("+-------------------------------+\n");
		for (i=0;i<length;i++)
		{
			if ((*(listaJugadores+i)).isEmpty == 0 && (*(listaJugadores+i)).idConfederacion == 104)
			{
				{
					printf("|%-31s|\n",(*(listaJugadores+i)).nombre);
				}
			}
		}
		printf("+===============================+\n");
		printf("|              OFC              |\n");
		printf("+-------------------------------+\n");
		for (i=0;i<length;i++)
		{
			if ((*(listaJugadores+i)).isEmpty == 0 && (*(listaJugadores+i)).idConfederacion == 105)
			{
				{
					printf("|%-31s|\n",(*(listaJugadores+i)).nombre);
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

int printInformeCuatro (eJugador* listaJugadores, int length)
{
	int retorno = -1;
	int arrayContadorConfederaciones [6];
	int numeroMaximoContratos = 0;
	int posicionMaximo = 0;
	if (listaJugadores != NULL && length > 0)
	{
		if (iniciaArray (arrayContadorConfederaciones, 6) == 0)
		{
			if (contarDuracionContratosPorConfederacion(listaJugadores,length,arrayContadorConfederaciones)== 0)
			{
				if (buscarMax (arrayContadorConfederaciones,6,&numeroMaximoContratos, &posicionMaximo) == 0)
				{
					if (posicionMaximo == 0)
					{
						printf("+==========================================================================================+==========+\n");
						printf("| Confederacion con mayor duracion en los contratos: CONMEBOL  Total años de contrato:|%10d|\n",numeroMaximoContratos);
						printf("+------------------------------------------------------------------------------------------+----------+\n");
					}
					if (posicionMaximo == 1)
					{
						printf("+==========================================================================================+==========+\n");
						printf("| Confederacion con mayor duracion en los contratos: UEFA      Total años de contrato:|%10d|\n",numeroMaximoContratos);
						printf("+------------------------------------------------------------------------------------------+----------+\n");
					}
					if (posicionMaximo == 2)
					{
						printf("+==========================================================================================+==========+\n");
						printf("| Confederacion con mayor duracion en los contratos: AFC       Total años de contrato:|%10d|\n",numeroMaximoContratos);
						printf("+------------------------------------------------------------------------------------------+----------+\n");
					}
					if (posicionMaximo == 3)
					{
						printf("+==========================================================================================+==========+\n");
						printf("| Confederacion con mayor duracion en los contratos: CAF       Total años de contrato:|%10d|\n",numeroMaximoContratos);
						printf("+------------------------------------------------------------------------------------------+----------+\n");
					}
					if (posicionMaximo == 4)
					{
						printf("+==========================================================================================+==========+\n");
						printf("| Confederacion con mayor duracion en los contratos: CONCACAF  Total años de contrato:|%10d|\n",numeroMaximoContratos);
						printf("+------------------------------------------------------------------------------------------+----------+\n");
					}
					if (posicionMaximo == 5)
					{
						printf("+==========================================================================================+==========+\n");
						printf("| Confederacion con mayor duracion en los contratos: OFC       Total años de contrato:|%10d|\n",numeroMaximoContratos);
						printf("+------------------------------------------------------------------------------------------+----------+\n");
					}
					retorno = 0;
				}
			}
		}
	}
return retorno;
}

int printInformeQuinto (eJugador* listaJugadores, int length, int* contadorJugadores)
{
	int retorno = -1;
	int arrayContadorJugadoresConfederaciones [6];
	int i;
	if (listaJugadores != NULL && length > 0)
	{
		if (iniciaArray (arrayContadorJugadoresConfederaciones, 6) == 0)
		{
			if (contarJugadoresPorConfederacion(listaJugadores,length,arrayContadorJugadoresConfederaciones)== 0)
			{
				printf("+=================================+==============================+\n");
				printf("|         CONFEDERACION           |   PORCENTAJE DE JUGADORES    |\n");
				printf("+---------------------------------+------------------------------+\n");
				for (i=0;i<6;i++)
				{
					if (*(arrayContadorJugadoresConfederaciones+i) >= 0)
					{
						if (i == 0)
						{
							printf("|            CONMEBOL             |%%%29.2f|\n", (float)(*(arrayContadorJugadoresConfederaciones+i)*100)/(*contadorJugadores));
						}
						if (i == 1)
						{
							printf("|              UEFA               |%%%29.2f|\n",(float)(*(arrayContadorJugadoresConfederaciones+i)*100)/(*contadorJugadores));
						}
						if (i == 2)
						{
							printf("|              AFC                |%%%29.2f|\n",(float)(*(arrayContadorJugadoresConfederaciones+i)*100)/(*contadorJugadores));
						}
						if (i == 3)
						{
							printf("|              CAF                |%%%29.2f|\n",(float)(*(arrayContadorJugadoresConfederaciones+i)*100)/(*contadorJugadores));
						}
						if (i == 4)
						{
							printf("|            CONCACAF             |%%%29.2f|\n",(float)(*(arrayContadorJugadoresConfederaciones+i)*100)/(*contadorJugadores));
						}
						if (i == 5)
						{
							printf("|              OFC                |%%%29.2f|\n",(float)(*(arrayContadorJugadoresConfederaciones+i)*100)/(*contadorJugadores));
						}
					}
				}
				printf("+=================================+==============================+\n");
				retorno = 0;
			}
		}
	}
	return retorno;
}

int printInformeSeis (eJugador* listaJugadores, int length)
{
	int retorno = -1;
	int i;
	int idMostrar = 0;
	int arrayContadorJugadoresConfederaciones [6];
	int numeroMaximoJugadores = 0;
	int posicionMaximo = 0;

	if (listaJugadores != NULL && length > 0)
		{
			if (iniciaArray (arrayContadorJugadoresConfederaciones, 6) == 0)
			{
				if (contarJugadoresPorConfederacion(listaJugadores,length,arrayContadorJugadoresConfederaciones)== 0)
				{
					if (buscarMax (arrayContadorJugadoresConfederaciones,6,&numeroMaximoJugadores, &posicionMaximo) == 0)
					{
						if (posicionMaximo == 0)
						{
							printf("+==========================================================================================+==========+\n");
							printf("| REGION MAYORITARIA : SUDAMERICA  -              TOTAL DE JUGADORES:                      |%10d|\n",numeroMaximoJugadores);
							printf("+------------------------------------------------------------------------------------------+----------+\n");
							idMostrar = 100;
						}
						if (posicionMaximo == 1)
						{
							printf("+==========================================================================================+==========+\n");
							printf("| REGION MAYORITARIA : EUROPA  -                  TOTAL DE JUGADORES:                      |%10d|\n",numeroMaximoJugadores);
							printf("+------------------------------------------------------------------------------------------+----------+\n");
							idMostrar = 101;
						}
						if (posicionMaximo == 2)
						{
							printf("+==========================================================================================+==========+\n");
							printf("| REGION MAYORITARIA : ASIA -                          TOTAL DE JUGADORES:                 |%10d|\n",numeroMaximoJugadores);
							printf("+------------------------------------------------------------------------------------------+----------+\n");
							idMostrar = 102;
						}
						if (posicionMaximo == 3)
						{
							printf("+==========================================================================================+==========+\n");
							printf("| REGION MAYORITARIA : AFRICA -                   TOTAL DE JUGADORES:                      |%10d|\n",numeroMaximoJugadores);
							printf("+------------------------------------------------------------------------------------------+----------+\n");
							idMostrar = 103;
						}
						if (posicionMaximo == 4)
						{
							printf("+==========================================================================================+==========+\n");
							printf("| REGION MAYORITARIA : NORTE Y CENTRO AMERICA -   TOTAL DE JUGADORES:                      |%10d|\n",numeroMaximoJugadores);
							printf("+------------------------------------------------------------------------------------------+----------+\n");
							idMostrar = 104;
						}
						if (posicionMaximo == 5)
						{
							printf("+==========================================================================================+==========+\n");
							printf("| REGION MAYORITARIA : OCEANIA -                  TOTAL DE JUGADORES:                      |%10d|\n",numeroMaximoJugadores);
							printf("+------------------------------------------------------------------------------------------+----------+\n");
							idMostrar = 105;
						}
						/*if (posicionMaximo == -1)
						{
							printf("Hay dos o mas regiones con la misma cantidad de jugadores (%d en total)\n", numeroMaximoJugadores);
						}*/
						printf("+=====================================================================================================+\n");
						printf("|  ID  |             NOMBRE            |     POSICION     | N° CAMISETA |   SUELDO   | ANIOS CONTRATO |\n");
						printf("+------+-------------------------------+------------------+-------------+------------+----------------+\n");
						for (i=0;i<length;i++)
						{
							if ((*(listaJugadores+i)).isEmpty == 0 && (*(listaJugadores+i)).idConfederacion == idMostrar)
							{
								printf("|%6d|%-31s|%-18s|%13hi|%12.2f|%16hi|\n",(*(listaJugadores+i)).id, (*(listaJugadores+i)).nombre, (*(listaJugadores+i)).posicion, (*(listaJugadores+i)).numeroCamiseta, (*(listaJugadores+i)).salario, (*(listaJugadores+i)).aniosContrato);
							}

						}
						printf("+======+===============================+==================+=============+============+================+\n");

						retorno = 0;
					}
				}
			}
		}

	return retorno;
}
