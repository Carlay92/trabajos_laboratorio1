#include <stdlib.h>
#include <stdio.h>
#include "output.h"

void mostrarMenu(void)
{
	printf("1. CARGA DE ARCHIVOS\n");
	printf("2. ALTA DE JUGADOR\n");
	printf("3. MODIFICACION DE JUGADOR\n");
	printf("4. BAJA DE JUGADOR\n");
	printf("5. LISTADOS\n");
	printf("6. CONVOCAR JUGADORES\n");
	printf("7. ORDENAR Y LISTAR\n");
	printf("8. GENERAR ARCHIVO BINARIO\n");
	printf("9. CARGAR ARCHIVO BINARIO\n");
	printf("10. GUARDAR ARCHIVOS .CSV\n");
	printf("11. SALIR\n");
}

void mostrarMenuListado(void)
{
	printf("A) TODOS LOS JUGADORES\n");
	printf("B) TODAS LAS SELECCIONES.\n");
	printf("C) JUGADORES CONVOCADOS.\n");
}

void mostrarMenuModificaciones(void)
{
	printf("OPCIONES PARA APLICAR MODIFICACION:\n");
	printf("A) NOMBRE\n");
	printf("B) EDAD\n");
	printf("C) POSICION\n");
	printf("D) NACIONALIDAD\n");
	printf("E) VOLVER SIN MODIFICAR\n");
}

void mostrarMenuConvocar(void)
{
	printf("A) CONVOCAR:\n");
	printf("B) QUITAR DE LA SELECCIÓN:\n");
}

void mostrarMenuOrdenarListar(void)
{
	printf("A) JUGADORES POR NACIONALIDAD.\n");
	printf("B) SELECCIONES POR CONFEDERACIÓN.\n");
	printf("C) JUGADORES POR EDAD.\n");
	printf("D) JUGADORES POR NOMBRE.\n");
}
