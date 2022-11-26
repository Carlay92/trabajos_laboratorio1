#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "jugador.h"
#include "seleccion.h"
#include "LinkedList.h"


int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);
int controller_agregarJugador(LinkedList* pArrayListJugador);
int controller_editarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, LinkedList* pArrayListConvocados);
int controller_menuListados(LinkedList* pArrayListJugadores, LinkedList* pArrayListSelecciones, LinkedList* pArrayListConvocados);
int controller_listarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_ordenarJugadores(LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);
int controller_generarListaConvocadoPorConfederacion(LinkedList* pArrayListSeleccion, LinkedList* pArrayListConvocados, LinkedList* pArrayListBinario);
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
int controller_listarConvocados(LinkedList* pArrayListConvocados, LinkedList* pArraySelecciones);
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_buscarJugadorPorId (LinkedList *pArrayListJugador, int idIngresado);
int controller_buscarSeleccionPorId (LinkedList *pArrayListSeleccion, int idIngresado);
void controller_mostrarUnJugador(Jugador* this, LinkedList* pArrayListSelecciones);
void controller_mostrarUnaSeleccion(Seleccion* this);
int controller_convocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, LinkedList* pArrayListConvocados);
int controller_quitarSeleccion(LinkedList*pArrayListJugador, LinkedList*pArrayListSeleccion, LinkedList*pArrayListConvocados);
int controller_convocatoria(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, LinkedList* pArrayListConvocados);
int controller_ordenarLista(LinkedList* pArrayListJugador, LinkedList* pArraySeleccion);
#endif /* CONTROLLER_H_*/
