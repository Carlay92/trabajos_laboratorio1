#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_input.h"

int getRespuesta (char* letra, char* mensaje, char * mensajeError, char opcionUno, char opcionDos , int reintentos, char* mensajeSalida)
{
	int retorno = -1;
	char auxLetra;

	if (letra != NULL && mensaje != NULL && mensajeError != NULL && opcionUno!=opcionDos)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &auxLetra);
			auxLetra = toupper(auxLetra);
			if (auxLetra == opcionUno || auxLetra == opcionDos)
			{
				*letra = auxLetra;
				retorno = 0;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		} while (reintentos > 0);
		if (reintentos == 0)
		{
			printf("%s", mensajeSalida);
		}
	}

	return retorno;
}

int getChar (char* letra, char* mensaje, char * mensajeError, char min, char max, int reintentos, char* mensajeSalida)
{
	int retorno = -1;
	char auxLetra;

	if (letra != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &auxLetra);
			auxLetra = toupper(auxLetra);
			if (auxLetra <= max && auxLetra >= min)
			{
				*letra = auxLetra;
				retorno = 0;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		} while (reintentos > 0);
		if (reintentos == 0)
		{
			printf("%s", mensajeSalida);
		}
	}

	return retorno;
}

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int min, int max, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0 && bufferInt >= min	&& bufferInt <= max)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s", mensajeError);
		reintentos--;
	} while (reintentos >= 0);
	return retorno;
}

int utn_getShort(short *pResultado, char *mensaje, char *mensajeError, int min, int max, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0 && bufferInt >= min	&& bufferInt <= max)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s", mensajeError);
		reintentos--;
	} while (reintentos >= 0);
	return retorno;
}


int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL)
		{
			if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer))
			{
				*pResultado = atoi(buffer);
				retorno = 0;
			}
		}
		return retorno;
	}

int utn_getFloat(float * pResultado, char*pMensaje, char*pMensajeError, int min, int max, int reintentos)
{
	int retorno = -1;
	float buffer;

	if (pResultado != NULL && pMensaje!=NULL && pMensajeError!=NULL && min<=max && reintentos>=0)
	{
		while(reintentos>0)
		{
			printf("%s", pMensaje);
			fflush(stdin);
			if(getFloat(&buffer)== 0)
			{
				if(buffer<=max && buffer>=min){
				break;
			}
		}
			fflush(stdin);
			reintentos--;
			printf(pMensajeError);
		}
		if(reintentos==0)
		{
			retorno=-1;
		}
		else
		{
		retorno=0;
		*pResultado = buffer;
		}
	}
return retorno;
}

int getFloat(float* pResultado)

{
	int retorno = -1;
	char buffer[64];

	if(pResultado != NULL)
	{
		if(myGets(buffer, sizeof(buffer))==0 && esNumericaDecimal(buffer)==0)
		{
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int myGets(char *cadena, int longitud)
{
	int retorno = -1;
	char bufferString[4096];

	if (cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if (bufferString[strnlen(bufferString, sizeof(bufferString)) -1] =='\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1]='\0';
			}
			if (strnlen(bufferString, sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena, bufferString, longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int esNumerica(char *cadena)
{
	int i = 0;
	int retorno = -1;
	if (cadena != NULL && strlen(cadena) > 0)
	{
		while (cadena[i] != '\0')
		{
			if (isalpha(cadena[i]) != 0)
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int esNumericaDecimal(char* cadena)
{
	int i = 0;
	int retorno = -1;

	if(cadena != NULL)
	{
		while(cadena[i]!='\0')
		{
			if((cadena[i] >= '0' && cadena[i] <= '9') || cadena[i] == ',' || cadena[i] == '.')
			{
				if(cadena[i] == ',')
				{
					cadena[i]= '.';
				}
				i++;
				retorno = 0;
			}
			else
			{
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}

int getString(char *cadena, int length)
{
	int retorno = -1;
	char auxString[length];
	if (cadena != NULL && length > 0) {
		fflush(stdin);
		if (fgets(auxString, sizeof(auxString), stdin) != NULL)
		{
			if (auxString[strnlen(auxString, sizeof(auxString)) - 1] == '\n')
				{
					auxString[strnlen(auxString, sizeof(auxString)) - 1] = '\0';
				}
				if (strnlen(auxString, sizeof(auxString)) <= length)
				{
					strncpy(cadena, auxString, length);
					retorno = 0;
				}
		}
	}
	return retorno;
}

int getStringconEspacio (char *string, int length, char *mensaje, char *mensajeError, int reintentos)
{
		int retorno = -1;
		char auxString[length];

		if (string != NULL && length > 0)
		{
			printf("%s", mensaje);
			do
			{
				if (getString(auxString, sizeof(auxString)) == 0 && isLetrayEspacio(auxString, sizeof(auxString)) == 0)
				{
					strncpy(string, auxString, sizeof(auxString));
					retorno = 0;
					break;

				}
				else
				{
					reintentos--;
					if (reintentos > 0) {
					printf("%s", mensajeError);
					}
					else
					{
						printf("\n-Se quedo sin reintentos-\n");
						retorno = -1;
					}
				}
			} while (reintentos > 0);
		}
		return retorno;
	}

int isLetrayEspacio(char* string, int lenght)
{
	int retorno = -1;
	if(string != NULL && lenght > 0)
	{
		retorno = 0;
		for(int i = 0; i < lenght && *(string +i) != '\0'; i++)
		{
			if((*(string +i) < 'A' || *(string +i) > 'Z') && (*(string +i) < 'a' || *(string +i) > 'z') && *(string +i) != ' ')
			{
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}


int iniciaArray (int array[], int cantElementos)
{
	int retorno = -1;
	int i;
	if (array != NULL && cantElementos > 0)
	{
		for (i=0; i<cantElementos; i++)
		{
			array[i] = 0;
		}
		retorno = 0;
	}
	return retorno;
}

int get_Posicion (char *string, int length, char *mensaje, char *mensajeError, int reintentos)
{
	int retorno = -1;
	char auxString[length];

	if (string != NULL && length > 0)
	{
		printf("%s", mensaje);
		do
		{
			if (getString(auxString, sizeof(auxString)) == 0 && isLetrayEspacio(auxString, sizeof(auxString)) == 0 && isPosicion(auxString, sizeof(auxString)) == 0)
			{
				strncpy(string, auxString, sizeof(auxString));
				retorno = 0;
				break;

			}
			else
			{
				reintentos--;
				if (reintentos > 0) {
				printf("%s", mensajeError);
				}
				else
				{
					printf("\n-Se quedo sin reintentos-\n");
					retorno = -1;
				}
			}
		} while (reintentos > 0);
	}
	return retorno;
}

int isPosicion (char* string, int length)
{
	int retorno = 0;
	if(string != NULL && length > 0)
	{
		if(stricmp(string, "arquero")!=0 && stricmp(string, "defensor")!=0  && stricmp(string, "delantero")!=0 && stricmp(string,"mediocampista")!= 0)
		{
			retorno = -1;
		}
	}
	return retorno;
}
