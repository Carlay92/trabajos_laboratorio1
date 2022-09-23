/*
 * Input.c
 *      Author: adminbf
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "calculos.h"
#include "output.h"

int utn_getNumero(int * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >0)
	{
		while(reintentos>0)
		{
			printf(mensaje);
			fflush(stdin);
			if(scanf("%d",&buffer)!=0)
			{
				if(buffer<=maximo && buffer>=minimo)
				break;
			}
			reintentos--;
			printf(mensajeError);
		}
			if(reintentos==0)
			{
				retorno = -1;
			}
			else
			{
				retorno = 0;
				*pResultado = buffer;
			}
	}
	return retorno;
}

int utn_getFloat(float * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	float buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >0)
	{
		while(reintentos>0)
		{
			printf("%s", mensaje);
			fflush(stdin);
			if(scanf("%f", &buffer )!=0)
			{
				if(buffer<=maximo && buffer>=minimo)
				break;
			}
			reintentos--;
			printf("%s", mensajeError);
		}
			if(reintentos==0)
			{
				retorno = -1;
			}
			else
			{
				retorno = 0;
				*pResultado = buffer;
			}
	}
	return retorno;
}

int cargaJugador (int * afc, int * caf, int * concacaf, int * conmebol, int * uefa, int * ofc)
{
	int retorno = -1;
	int camiseta;
	int asociacion;
	int aux1;
	int aux2;
	aux1 = utn_getNumero(&camiseta,"Indique el numero de camiseta del jugador\n", "No indicó un número válido\n", 1, 22, 2);
	if (aux1 == 0)
		{
			aux2= utn_getNumero(&asociacion,"Indique a qué asociacion pertenece dicho jugador:\n"
										"1. AFC en Asia\n"
										"2.CAF en África\n"
										"3.CONCACAF en zona del Norte\n"
										"4.CONMEBOL en Sudamérica\n"
										"5.UEFA en Europa\n"
										"6.OFC en Oceanía\n", "Lo ingresado no corresponde a una asociación listada\n", 1, 6, 3);
			if (aux2 == 0)
			{
				switch (asociacion)
					{
						case 1:
							*afc = *afc +1;
							retorno = 0;
							break;
						case 2:
							*caf = *caf +1;
							retorno = 0;
							break;
						case 3:
							*concacaf = *concacaf +1;
							retorno = 0;
							break;
						case 4:
							*conmebol = *conmebol +1;
							retorno = 0;
							break;
						case 5:
							*uefa = *uefa +1;
							retorno = 0;
							break;
						case 6:
							*ofc = *ofc +1;
							retorno = 0;
							break;
					}
			}

		}
	return retorno;
}
