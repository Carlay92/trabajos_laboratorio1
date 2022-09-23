/*
 * Biblioteca.c
 *
 *  Created by: Carla Baro
 */

#include "output.h"

#include "input.h"
#include "calculos.h"
#include <stdio.h>
#include <stdlib.h>

void mostrarMenu (float costoHospedaje, float costoComida, float costoTransporte, int arqueros, int defensores, int mediocampistas, int delanteros)
{
	printf("MENU PRINCIPAL:\n\n"
			"1.Ingreso de los costos de mantenimiento\n"
			" Costo de hospedaje -> $%.2f\n"
			" Costo de comida ->$%.2f\n"
			" Costo de transporte -> $%.2f\n"
			"2.Carga de jugadores\n Arqueros -> %d\n"
			" Defensores -> %d\n"
			" Mediocampistas -> %d\n"
			" Delanteros -> %d\n"
			"3.Realizar todos los calculos\n"
			"4.Informar todos los calculos\n"
			"5.Salir\n\n", costoHospedaje, costoComida, costoTransporte, arqueros, defensores, mediocampistas, delanteros);
}

void mostrarPromedio (float afc, float caf, float conca, float conme, float uefa, float ofc)
{
	printf("Promedio de jugadores AFC (Asia) -> %.2f\n", afc);
	printf("Promedio de jugadores CAF (Africa) -> %.2f\n", caf);
	printf("Promedio de jugadores CONCACAF (Zona Norte) ->%.2f\n", conca);
	printf("Promedio de jugadores  CONMEBOL (Sudamerica) -> %.2f \n", conme);
	printf("Promedio de jugadores  UEFA (Europa) -> %.2f\n", uefa);
	printf("Promedio de jugadores  OFC (Oceanía) -> %.2f\n\n", ofc);
}
void mostrarCosto (float presupuestoMantenimiento)
{
printf ("El costo de mantenimiento del plantel es de $ %.2f \n", presupuestoMantenimiento);
}

void mostrarAumento  (float recargo, float costoConRecargo)
{
	printf("Dado que el promedio arroja un mayor número de jugadores de la UEFA, el costo se verá elevado en $ %.2f, es decir, el valor total será de $ %.2f \n", recargo, costoConRecargo);
}
