#ifndef OUTPUT_H_
#define OUTPUT_H_

void mostrarMenu(void);

void subMenu(void);

void menuInformes(void);

void mostrarConfederaciones(eConfederacion* confederaciones, int length);

int mostrarJugadores(eJugador* listaJugadores, int length, eConfederacion* confederaciones);

int printInformeUno (eJugador* listaJugadores, int length, eConfederacion* confederaciones);

int printInformeDos (eJugador* listaJugadores, int length);

int printInformeTres (eJugador* listaJugadores, int length);

int printInformeCuatro (eJugador* listaJugadores, int length);

int printInformeQuinto (eJugador* listaJugadores, int length, int* contadorJugadores);

int printInformeSeis (eJugador* listaJugadores, int length);

#endif /* OUTPUT_H_ */
