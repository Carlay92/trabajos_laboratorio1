/*
 ============================================================================
 Name    	    : TP_[1].c
 Author     	: Baro, Carla
 Version 		:
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "calculos.h"
#include "output.h"

int main(void)
{
	setbuf(stdout, NULL);
	int variableDeControl;
	int opcionMenu;
	int subMenuCostos;
	float hospedaje;
	float comida;
	float transporte;
	float costoHospedaje = 0;
	float costoComida = 0;
	float costoTransporte = 0;
	char respuestaMonto;
		int subMenuPosicion;
	int arqueros =0;
	int defensores = 0;
	int mediocampistas = 0;
	int delanteros = 0;
	char respuestaJugadores;
	int afc = 0;
	int caf = 0;
	int concacaf = 0;
	int conmebol = 0;
	int uefa = 0;
	int ofc = 0;
	int totalJugadores = 0;
	int flagCostos = 0;
	int flagJugadores = 0;
	int flagCalculos = 0;
	int flagAumento = 0;
	float presupuestoMantenimiento = 0;
	float promAfc = 0;
	float promCaf = 0;
	float promConca = 0;
	float promConme = 0;
	float promUefa = 0;
	float promOfc = 0;
	int contadorArqueros = 0;
	int contadorDefensores = 0;
	int contadorMediocampistas = 0;
	int contadorDelanteros = 0;
	float costoConRecargo = 0 ;
	float recargo ;

	do
	{
		mostrarMenu (costoHospedaje, costoComida, costoTransporte, arqueros, defensores, mediocampistas, delanteros);
		variableDeControl = utn_getNumero(&opcionMenu, "Elija opción de menu a ingresar (1-5)\n", "No ingresó una opción de menu válida\n", 1, 5, 3);
		if (variableDeControl == 0)
		{
			switch (opcionMenu)
			{
				case 1:
					do
					{
						printf("Ingreso de los costos de mantenimiento\n 1.Costo de hospedaje -> $%.2f\n 2.Costo de comida ->$%.2f\n 3.Costo de transporte -> $%.2f\n", costoHospedaje, costoComida, costoTransporte);
						variableDeControl = utn_getNumero(&subMenuCostos, "Elija qué tipo de costo quiere ingresar (1-3)\n", "No es una opción válida.\n", 1, 3, 3);
						if (variableDeControl == 0)
						{
							switch (subMenuCostos)
							{
								case 1:
									variableDeControl = utn_getFloat (&hospedaje, "Ingrese monto de hospedaje\n", "Ingrese un precio válido. Entre $0 y $1.000.000\n", 0, 1000000, 3);
									if (variableDeControl == 0)
									{
										costoHospedaje = hospedaje;
									}
									break;
								case 2:
									variableDeControl = utn_getFloat (&comida, "Ingrese monto de la comida\n", "Ingrese un precio válido. Entre $0 y $1.000.000\n", 0, 1000000, 3);
									if (variableDeControl == 0)
									{
										 costoComida = comida;
									}
									break;
								case 3:
									variableDeControl = utn_getFloat (&transporte, "Ingrese monto de transporte\n", "Ingrese un precio válido. Entre $0 y $1.000.000\n", 0, 1000000, 3);
									if (variableDeControl == 0)
									{
										costoTransporte = transporte;
									}
									break;
							}
						}
						printf ("Desea agregar otro costo de mantenimiento? 's/n'\n");
						fflush(stdin);
						scanf("%c", &respuestaMonto); //se debe hacer una funcion para validar el Char
						if (costoHospedaje > 0 && costoComida > 0 && costoTransporte > 0)
						{
							 flagCostos = 1;
						}
							} while (respuestaMonto == 's');
						break;
					case 2:
						do
						{
							printf("Ingreso de jugadores\n 1. Arqueros -> %d\n 2.Defensores -> %d\n 3.Mediocampistas -> %d\n 4.Delanteros -> %d\n", arqueros, defensores, mediocampistas, delanteros);
							variableDeControl = utn_getNumero(&subMenuPosicion, "Ingrese qué posición de jugador desea modificar (1-4)\n", "No ingresó una posición listada\n", 1, 4, 3);
							switch (subMenuPosicion)
							{
								case 1:
									if (contadorArqueros < 2)
									{
										variableDeControl = cargaJugador (&afc, &caf, &concacaf, &conmebol, &uefa, &ofc);
										if (variableDeControl == 0)
										{
											contadorArqueros ++;
											arqueros = contadorArqueros;
										}
									}
									else
									{
										printf("No se puede agregar más arqueros en esta oportunidad\n");
									}
									break;
								case 2:
									if (contadorDefensores < 8)
									{
										variableDeControl = cargaJugador ( &afc, &caf, &concacaf, &conmebol, &uefa, &ofc);
										if (variableDeControl == 0)
										{
											contadorDefensores ++;
											defensores = contadorDefensores;
										}
									}
									else
									{
										printf("No se puede agregar más defensores en esta oportunidad\n");
									}
									break;
								case 3:
									if (contadorMediocampistas < 8)
									{
										variableDeControl = cargaJugador ( &afc, &caf, &concacaf, &conmebol, &uefa, &ofc);
										if (variableDeControl == 0)
										{
										contadorMediocampistas ++;
										mediocampistas = contadorMediocampistas;
										}
									}
									else
									{
										printf("No se puede agregar más mediocampistas en esta oportunidad\n");
									}
									break;
								case 4:
									if (contadorDelanteros < 4)
									{
										variableDeControl = cargaJugador ( &afc, &caf, &concacaf, &conmebol, &uefa, &ofc);
										if (variableDeControl == 0)
										{
											contadorDelanteros ++;
											delanteros = contadorDelanteros;
										}
									}
									else
									{
										printf("No se puede agregar más delanteros en esta oportunidad\n");
									}
									break;
							}
							printf("¿Desea seguir agregando jugadores? 's/n'\n");
							fflush(stdin);
							scanf("%c", &respuestaJugadores);
							if (arqueros > 0 || defensores > 0 || mediocampistas >0 || delanteros > 0)
							{
								totalJugadores = arqueros + defensores + mediocampistas + delanteros;
								flagJugadores = 1;
							}
						} while (respuestaJugadores == 's');
						break;
					case 3:
						if (flagCostos == 1 && flagJugadores == 1)
						{
							if (calcularPromedio ( &promAfc, afc, totalJugadores) == 1 &&  calcularPromedio ( &promCaf,  caf, totalJugadores) == 1  && calcularPromedio ( &promConca, concacaf, totalJugadores) == 1 &&  calcularPromedio ( &promConme, conmebol, totalJugadores) == 1 &&  calcularPromedio ( &promUefa, uefa, totalJugadores) == 1 &&  calcularPromedio ( &promOfc, ofc, totalJugadores) == 1)
							{
								printf("CALCULAR PROMEDIO: OK\n");
							}
							if (suma3 (&presupuestoMantenimiento, costoHospedaje, costoComida, costoTransporte) == 1)
							{
								printf("CALCULAR COSTOS DE MANTENIMIENTO: OK\n");
							}
							if (promUefa>promAfc &&  promUefa>promCaf && promUefa>promConca && promUefa>promConme && promUefa>promOfc)
							{
								if (addPercent(&costoConRecargo, 35, &recargo, presupuestoMantenimiento) == 1)
								{
									flagAumento = 1;
									printf("CALCULAR RECARGO: OK\n");
								}
							} flagCalculos = 1;
						}
						else
						{
							printf("ERROR: Debe ingresar el total de costos de mantenimiento y  jugadores para poder calcular.\n");
						}
						break;
					case 4:
						if (flagCalculos == 1 && flagCostos ==1 && flagJugadores == 1)
						{
							mostrarPromedio (promAfc, promCaf, promConca, promConme, promUefa, promOfc);
							mostrarCosto (presupuestoMantenimiento);

							if (flagAumento == 1)
							{
								mostrarAumento (recargo, costoConRecargo);
							}
						}
						else
						{
							printf ("Debe primero calcular los gastos en el punto 3\n");
						}
						break;
					case 5:
						printf ("Saliendo...");
						break;
					 }
		}

	} while (opcionMenu != 5);

	return EXIT_SUCCESS;
}
