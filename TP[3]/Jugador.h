#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

#define nombre_LEN 100
#define char_LEN 30


typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

void jug_delete(Jugador* this);

int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getIdSeleccion(Jugador* this,int* idSeleccion);

int jug_setIsEmpty(Jugador* this,int isEmpty);
int jug_getIsEmpty(Jugador* this,int* isEmpty);

int jug_ordenarPorId (void* this, void *this2);
int jug_ordenarPorEdadAscendente (void* this, void *this2);
int jug_ordenarPorEdadDescendente (void* this, void *this2);
int jug_ordenarPorNacionalidad (void* this, void *this2);
int jug_ordenarPorNombre (void* this, void *this2);

int jug_deIdASeleccion (Jugador* unJugador, LinkedList* selecciones, char* seleccionPais);
#endif // jug_H_INCLUDED
