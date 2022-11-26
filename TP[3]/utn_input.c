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
		if(stricmp(string, "portero")!=0 && stricmp(string, "defensa central")!=0  && stricmp(string, "lateral izquierdo")!=0 &&
		   stricmp(string,"lateral derecho")!= 0 && stricmp(string, "pivote")!= 0 && stricmp(string, "mediocentro")!= 0 &&
		   stricmp(string, "mediocentro ofensivo")!= 0 && stricmp(string, "extremo izquierdo")!= 0 && stricmp(string, "extremo derecho")!=0 &&
		   stricmp(string,"mediapunta")!= 0 && stricmp(string, "delantero centro") != 0)
		{
			retorno = -1;
		}
	}
	return retorno;
}

int get_Nacionalidad (char *string, int length, char *mensaje, char *mensajeError, int reintentos)
{
	int retorno = -1;
	char auxString[length];

	if (string != NULL && length > 0)
	{
		printf("%s", mensaje);
		do
		{
			if (getString(auxString, sizeof(auxString)) == 0 && isLetrayEspacio(auxString, sizeof(auxString)) == 0 && isNacionalidad(auxString, sizeof(auxString)) == 0)
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
int isNacionalidad (char* string, int length)
{

	int retorno = 0;
	if(string != NULL && length > 0)
	{
		if(stricmp(string, "argentino")!=0 && stricmp(string, "brasilero")!=0  && stricmp(string, "uruguayo")!=0 &&
		   stricmp(string,"portugues")!= 0 && stricmp(string, "ingles")!= 0 && stricmp(string, "aleman")!= 0 &&
		   stricmp(string, "mexicano")!= 0 && stricmp(string, "estado unidense")!= 0 && stricmp(string, "camerunes")!=0 &&
		   stricmp(string,"senegales")!= 0 && stricmp(string, "australiano") != 0 && stricmp(string,"qatari")!= 0 &&
		   stricmp(string, "frances")!= 0 && stricmp(string, "español")!= 0 &&
		   stricmp(string, "neerlandes")!= 0 && stricmp(string, "polaco")!= 0 && stricmp(string, "gales")!=0 &&
		   stricmp(string,"croata")!= 0 && stricmp(string, "belga") != 0 && stricmp(string, "dinamarques")!=0 &&
		   stricmp(string, "serbio")!=0  && stricmp(string, "suizo")!=0 &&
		   stricmp(string,"cortarricense")!= 0 && stricmp(string, "canadiense")!= 0 && stricmp(string, "ecuatoriano")!= 0 &&
		   stricmp(string, "irani")!= 0 && stricmp(string, "coreano")!= 0 && stricmp(string, "japones")!=0 &&
		   stricmp(string,"arabe")!= 0 && stricmp(string,"marroqui")!= 0 && stricmp(string,"tunecino")!= 0)
		{
			retorno = -1;
		}
	}
	return retorno;
}
