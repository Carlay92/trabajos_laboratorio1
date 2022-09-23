/*
 * Calculos.h
 *
 *  Created on: 19 sep. 2022
 *      Author: adminbf
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/// \brief Funcion para calcular un promedio.
/// \param pResultado Devuelve el resultado por referencia.
/// \param sumatoria Es el total del grupo de numeros sumados.
/// \param total Es la cantidad de numeros, por el que se dividirá.
/// \return Devuelve "0" si no hubo errores al realizar la división. Devuelve "-1" en caso contrario.
int calcularPromedio (float * pResultado, int  sumatoria, int total);

/// \brief  Suma tres numeros flotantes por referencia.
/// \param pResultado Devuelve el resultado de la funcion por referencia.
/// \param a Primer parámetro a ser sumado.
/// \param b Segundo numero decimal a ser sumado
/// \param c Tercer numero decimal a ser sumado
/// \return Devuelve "0" si no hubo errores al realizar la suma. Devuelve "-1" en caso contrario.
int suma3 (float * pResultado, float a, float b, float c);

/// \brief Calcula el porcentaje de un total y se lo suma a ese total.
///
/// \param pResultado Devuelve el resultado de la operacion
/// \param a Es el porcentaje a calcular.
/// \param b Es el aumento que se realizara.
/// \param c Es el valor al que se le aplicará el aumento.
/// \return Devuelve "0" si no hubo errores al realizar la suma. Devuelve "-1" en caso contrario.
int addPercent (float *pResultado, int a, float *recargo, float c);
#endif /* CALCULOS_H_ */
