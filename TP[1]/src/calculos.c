/*
 * Calculos.c
 *      Author: adminbf
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "input.h"
#include "output.h"

int calcularPromedio (float * pResultado, int sumatoria, int total)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
	*pResultado = (float)sumatoria / total;
	retorno = 1;
	}
	return retorno;
}

int suma3 (float * pResultado, float a, float b, float c)
{
	int retorno = -1;
	if (pResultado != NULL)
	{
		*pResultado = a+b+c;
		retorno = 1;
	}
	return retorno;
}

int addPercent (float *pResultado, int a, float*recargo, float c)
{
	int retorno = -1;
	if (pResultado != NULL && recargo!= NULL)
	{
		*recargo= c * a/100;
		*pResultado = c + *recargo ;
		retorno = 1;
	}
	return retorno;
}
