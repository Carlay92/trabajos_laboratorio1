#ifndef JUGADORES_H_
#define JUGADORES_H_

typedef struct
{
	int id;
	char nombre[51];
	char posicion[51];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
} eJugador;


int iniciaArrayJugadores (eJugador* array, int length);

int arrayIsEmpty (eJugador* listaJugadores, int length, int* posicionVacia);
;
int ingresaJugador(eJugador* jugadorUnico, eConfederacion* confederaciones, int length, int* idJugador);

int buscarPorID (eJugador* listaJugadores, int length, int * posicionJugador);

int darBaja(eJugador* listaJugadores, int posicionJugador);

int modificaNombre (eJugador* listaJugadores, int posicionJugador);

int modificaPosicion (eJugador* listaJugadores, int posicionJugadorenArray);

int modificaCamiseta (eJugador* listaJugadores, int posicionJugadorenArray);

int modificaConfederacion (eJugador* listaJugadores, int posicionJugadorenArray, eConfederacion* confederaciones, int length);

int modificaSalario (eJugador* listaJugadores, int posicionJugadorenArray);

int modificaContrato (eJugador* listaJugadores, int posicionJugadorenArray);

int ordenarConfederacionyJugadores (eJugador* listaJugadores, int length, eConfederacion* confederaciones);

int deIDaDescripcion(eJugador* jugador, int i, eConfederacion* confederaciones, char* descripcion);

int salarioTotalJugadores(eJugador* listaJugadores,int length,float* salarioTotal);

int salarioPromedioJugadores(eJugador* listaJugadores,int length,float* salarioPromedio,float salarioTotal);

int contarDuracionContratosPorConfederacion(eJugador* listaJugadores,int length,int * arrayContadorConfederaciones);

int buscarMax (int array[], int length, int * numMaximo, int * posicionMaximo);

int contarJugadoresPorConfederacion(eJugador* listaJugadores,int length,int* arrayContadorJugadoresConfederaciones);

#endif /* JUGADORES_H_ */
