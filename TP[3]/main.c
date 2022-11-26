/*
 ============================================================================
 Name        : TP[3].c
 Author      : Baro Carla
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "Controller.h"
#include "output.h"
#include "utn_input.h"


int main()
{
	setbuf(stdout,NULL);
    int menu;
    int flagCargaArchivo = 0;
    int flagGuardarBin = 0;
    int flagGuardado = 0;
    int guardar;
    int salir;

    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();
    LinkedList* listaConvocados = ll_newLinkedList();
    LinkedList* listaConvocadosConfBin = ll_newLinkedList();

    do
    {
    	mostrarMenu();
    	if (utn_getNumero(&menu, "Elija una opción del menu\n", "Error: no es una opción de menú válida\n", 1, 11, 3)==0)
    	{
    		switch (menu)
    		{
				case 1:
					if(flagCargaArchivo == 0)
					{
						if(controller_cargarJugadoresDesdeTexto("jugadores.csv", listaJugadores) == 0 &&
						   controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones) == 0)
						{
							flagCargaArchivo = 1;

							printf("Archivos 'jugadores.csv' y 'selecciones.csv' cargados con exito.\n\n");
						}
						else
						{
							printf("Error: el o los archivos no pudieron cargarse.\n\n");
						}
					}
					else
					{
						printf("Error: la carga de los archivos ya se realizó con anterioridad\n\n");
					}
					break;
				case 2:
					if (flagCargaArchivo == 1)
					{
						if (controller_agregarJugador(listaJugadores) == 0)
						{
							printf("El jugador ha sido cargado con exito\n\n");
						}
						else
						{
							printf("Error: No se pudo cargar el jugador\n\n");
						}
					}
					else
					{
						printf("Cargue primero el archivo de jugadores\n");
					}
					break;
				case 3:
					if (flagCargaArchivo == 1 && !ll_isEmpty(listaJugadores))
					{
						if (controller_editarJugador(listaJugadores, listaSelecciones) != 0)
						{
							printf("No se han podido realizar modificaciones\n\n");
						}
					}
					else
					{
						printf("No hay elementos cargados para realizar una modificacion.\n\n");
					}
					break;
				case 4:
					if (flagCargaArchivo == 1 && !ll_isEmpty(listaJugadores))
					{
						if (controller_removerJugador(listaJugadores, listaSelecciones, listaConvocados) == 0)
						{
							printf("Jugador dado de baja correctamente\n\n");
						}
					}
					else
					{
						printf("No hay elementos cargados para realizar una modificacion.\n");
					}
					break;
				case 5:
					if (flagCargaArchivo == 1 && !ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSelecciones))
					{
						if (controller_menuListados(listaJugadores, listaSelecciones, listaConvocados) != 0)
						{
							printf("No se puede acceder al menu de los listados\n");
						}
					}
					else
					{
						printf("No hay elementos para listar. No puede ingresar en esta opcion del Menú\n");
					}
					break;
				case 6:
					if (flagCargaArchivo == 1 && !ll_isEmpty(listaJugadores))
					{
						if (controller_convocatoria(listaJugadores, listaSelecciones, listaConvocados) != 0)
						{
							printf("Algo salió mal, intente nuevamente\n");
						}
					}
					else
					{
						printf("Debe cargar el archivo antes de ingresar a esta opcion\n");
					}
					break;
				case 7:
					if (flagCargaArchivo == 1 && !ll_isEmpty(listaJugadores))
					{
						if (controller_ordenarLista(listaJugadores, listaSelecciones) !=0)
						{
							printf("No se pudo acceder al menú\n");
						}
					}
					else
					{
						printf("No hay elementos en las listas para ser ordenados. Ingrese algo primero\n");
					}
					break;
				case 8:
					if (flagCargaArchivo == 1 && !ll_isEmpty(listaConvocados))
					{
						if (controller_generarListaConvocadoPorConfederacion(listaSelecciones, listaConvocados, listaConvocadosConfBin) == 0)
						{
							if (controller_guardarJugadoresModoBinario("convocadosporconfederacion.bin", listaConvocadosConfBin) == 0)
							{
								printf("Se guardó la lista de 'Convocados' en un archivo BIN.\n");
								flagGuardarBin = 1;
							}
						}
					}
					else
					{
						printf("No hay jugadores convocados\n");
					}
					break;
				case 9:
					if (flagCargaArchivo == 1 && flagGuardarBin == 1)
					{
						LinkedList* listaArchivoBin= ll_newLinkedList();
						if(controller_cargarJugadoresDesdeBinario("convocadosporconfederacion.bin", listaArchivoBin) == 0)
						{
							if (controller_ordenarJugadores(listaArchivoBin) == 0 && controller_listarJugadores(listaArchivoBin, listaSelecciones) != 0)
							{
								printf("No se pudo abrir archivo BIN\n");
							}
							ll_deleteLinkedList(listaArchivoBin);
						}

					}
					else
					{
						printf("Debe cargar el archivo y crear un archivo .BIN antes de guardar.\n");
					}
					break;
				case 10:
					if (flagCargaArchivo == 1)
					{
						if(utn_getNumero(&guardar, "Desea guardar las listas modificadas? (1- SI, 2- NO)\n", "Error; no ingresó una opción válida\n", 1, 2, 2) == 0)
						{
							if (guardar == 1)
							{
								if (controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores) == 0 &&
									controller_guardarSeleccionesModoTexto("selecciones.csv", listaSelecciones) == 0)
								{
									printf("La listas se han sido guardada con éxito en los archivos 'jugadores.csv' y 'selecciones.csv'\n\n");
									flagGuardado = 1;
								}
							}
							else
							{
								printf("No guardo las listas! Se recomienda guardar antes de salir\n\n");
							}
						}
					}
					else
					{
						printf("Debe cargar el archivo antes de ingresar a esta opcion\n");
					}
					break;
				case 11:
					if (flagGuardado == 0)
					{
						if (utn_getNumero(&salir,"No se realizó el guardado de datos. Se perderá el trabajo-\n  Desea Finalizar? (1- SI, 2- NO)\n","\n-Ingrese una opción valida-", 1, 2, 5) ==0)
						{
							if (salir == 1 && ll_deleteLinkedList(listaJugadores) && ll_deleteLinkedList(listaSelecciones) && ll_deleteLinkedList(listaConvocados) && ll_deleteLinkedList(listaConvocadosConfBin))
							{
								printf("Saliendo del programa. Los datos no han sido guardados.\n\n");
							}
						}
					}
					else
					{
						if (utn_getNumero(&salir,"Los cambios han sido guardados. Desea Finalizar? (1- SI, 2- NO)\n","\n-Ingrese una opción valida-", 1, 2, 5) == 0)
						{
							if (salir == 1 && ll_deleteLinkedList(listaJugadores) && ll_deleteLinkedList(listaSelecciones) && ll_deleteLinkedList(listaConvocados) && ll_deleteLinkedList(listaConvocadosConfBin))
							{
								printf("Saliendo del programa. Los datos se encuentran guardados.\n\n");
							}
						}
					}
					break;
				}
			}
    }while(menu != 11 || (menu == 11 && salir == 2));

    return 0;
}
