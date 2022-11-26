#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"

int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);

int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador);

int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);

int parser_getId(char* path, int* id);

int parser_guardarId(char* path, int id);

#endif /* PARSER_H_ */
