/*
 ============================================================================
 Name        : TP[2].c
 Author      : BARO CARLA
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "confederaciones.h"
#include "jugadores.h"
#include "utn_input.h"
#include "output.h"


#define LEN 10 // deben ser max 3000
#define TAM 6

eConfederacion confederaciones[]=
{
		{100,"CONMEBOL","SUDAMERICA",1916},
		{101,"UEFA","EUROPA",1954},
		{102,"AFC","ASIA",1954},
		{103,"CAF","AFRICA",1957},
		{104,"CONCACAF","NORTE Y CENTRO AMERICA",1961},
		{105,"OFC","OCEANIA",1966}
};

int main(void) {
	setbuf(stdout, NULL);

	eJugador listaJugadores[LEN];
	int menu;
	char salir;
	int posicionArrayVacia;
	eJugador unJugador;
	int flagAlta = 0;
	int contadorJugadores = 0;
	int posicionJugador;
	char opcionSubMenu;
	int opcionInformes;

	unJugador.id = 0;

	if (iniciaArrayJugadores(listaJugadores, LEN) == 0)
	{
		printf ("MENU:\n");
	}

	do
	{
		mostrarMenu();
		if (utn_getNumero(&menu, "Elija una opci�n del menu\n", "Error: no es una opci�n de men� v�lida\n", 1, 5, 3)==0)
		{
			switch (menu)
			{
				case 1:
					if (arrayIsEmpty(listaJugadores, LEN, &posicionArrayVacia) == 0)
					{
						if (ingresaJugador(&unJugador, confederaciones, TAM, &unJugador.id) == 0)
						{
						  (*(listaJugadores+posicionArrayVacia)) = unJugador;
						  printf("El ID del jugador ser�: %d\n\n",(*(listaJugadores+posicionArrayVacia)).id);
						  flagAlta = 1;
						  contadorJugadores++;
						}
					}
					else
					{
						printf("No hay espacio en el sistema para cargar otro jugador\n");
					}
					break;
				case 2:
					if (flagAlta == 1 && contadorJugadores>0)
					{
						mostrarJugadores(listaJugadores, LEN, confederaciones);
						if (buscarPorID (listaJugadores, LEN, &posicionJugador) == 0)
						{
							if (darBaja(listaJugadores, posicionJugador) == 0)
							{
								contadorJugadores--;
								printf("Baja dada con �xito\n");
							}
						}
						else
						{
							printf("No se encontr� ese ID listado\n");
						}

					}
					break;
				case 3:
					if (flagAlta == 1 && contadorJugadores>0)
					{
						mostrarJugadores(listaJugadores, LEN, confederaciones);
						if (buscarPorID (listaJugadores, LEN, &posicionJugador) == 0)
						{
							subMenu();
							if (getChar (&opcionSubMenu, "Por favor, seleccione un elemento a modificar\n", "No es una opci�n v�lida de menu\n", 'A', 'F', 3, "Error. Saliendo.\n") == 0)
							{
								switch (opcionSubMenu)
								{
									case 'A':
										if (modificaNombre (listaJugadores, posicionJugador) == 0)
										{
											printf("Modific� el nombre con �xito\n");
										}
										break;
									case 'B':
									 	if (modificaPosicion (listaJugadores, posicionJugador) == 0)
									 	{
									 		printf("Modific� la posici�n con �xito\n");
									 	}
									break;
									case 'C':
										if (modificaCamiseta (listaJugadores, posicionJugador) == 0)
										{
											printf("Modific� el n�mero de la camiseta con �xito\n");
										}
										break;
									case 'D':
										if (modificaConfederacion (listaJugadores, posicionJugador, confederaciones, TAM) == 0)
										{
											printf("Modific� la confederacion con �xito\n");
										}
										break;
									case 'E':
										if (modificaSalario (listaJugadores, posicionJugador) == 0)
										{
											printf("Modific� el salario con �xito\n");
										}
										break;
									case 'F':
										if (modificaContrato (listaJugadores, posicionJugador) == 0)
										{
											printf("Modific� la duraci�n del contrato con �xito\n");
										}
										break;
								}
							}
						}
						else
						{
						  printf("El ID que est� ingresando no se encuentra entre los jugadores listados\n");
						}
					}
					else
					{
						printf("No hay jugadores listados.\n");
					}
					break;
				case 4:
					if (flagAlta == 1 && contadorJugadores >0)
					{
						menuInformes();
						if (utn_getNumero(&opcionInformes, "Ingrese una opci�n del menu\n","Error: No indic� una opci�n listada\n", 1, 6, 3) == 0)
						{
							switch (opcionInformes)
							{
								case 1:
									if (printInformeUno (listaJugadores, LEN, confederaciones) == 0)
									{
										printf("Volviendo al menu;\n");
									}
									break;
								case 2:
									if (printInformeDos (listaJugadores, LEN) == 0)
									{
										printf("Volviendo al menu...\n");
									}
									break;
								case 3:
									if (printInformeTres (listaJugadores, LEN) == 0)
									{
										printf("Volviendo al menu...\n");
									}
									break;
								case 4:
									if (printInformeCuatro (listaJugadores, LEN) == 0)
									{
										printf("Volviendo al menu...\n");
									}
									break;
								case 5:
									if (printInformeQuinto (listaJugadores, LEN,&contadorJugadores) == 0)
									{
										printf("Volviendo al menu...\n");
									}
									break;
								case 6:
									if (printInformeSeis (listaJugadores, LEN) == 0)
									{
										printf("Volviendo al menu...\n");
										//FALTA CHEQUEAR CUANDO TIENEN MISMA CANTIDAD DE JUG E IMPRIMIR LOS JUGADORES

									}
									break;
							}
						}
					}
					break;
				case 5:
					if (getRespuesta (&salir, "Est� seguro que desea salir? (S/N)\n", "No ingres� una respuesta v�lida\n", 'S', 'N' , 3, "Volviendo al Menu Principal") == 0 && salir == 'S')
					{
						printf("Saliendo...");
					}
					break;
			}
		}
	} while (salir != 's' && salir != 'S');

	return EXIT_SUCCESS;
}
