/*
 * Biblioteca.h
 *
 *  Created by Carla Baro.
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_

/// \brief Muestra el menu principal para que el usuario pueda acceder.
/// \param costoHospedaje Variable actualizable segun interacción del usuario.
/// \param costoComida Variable actualizable segun interacción del usuario.
/// \param costoTransporte Variable actualizable segun interacción del usuario.
/// \param arqueros Variable actualizable segun interacción del usuario.
/// \param defensores Variable actualizable segun interacción del usuario.
/// \param mediocampistas Variable actualizable segun interacción del usuario.
/// \param delanteros Variable actualizable segun interacción del usuario.
void mostrarMenu (float costoHospedaje, float costoComida, float costoTransporte, int arqueros, int defensores, int mediocampistas, int delanteros);

/// \brief Muestra por pantalla los resultados de porcentajes, solicitados por el punto 4.
///
/// \param afc porcentaje correspondiente a la liga asiatica
/// \param caf porcentaje correspondiente a la liga africana
/// \param conca porcentaje correspondiente a la liga de zona norte
/// \param conme porcentaje correspondiente a la liga sudamericana
/// \param uefa porcentaje correspondiente a la liga europea
/// \param ofc porcentaje correspondiente a la liga de oceania
void mostrarPromedio (float afc, float caf, float conca, float conme, float uefa, float ofc);

/// \brief Muestra el costo total del mantenimiento
///
/// \param presupuestoMantenimiento Variable que carga el costo total ya calculado
void mostrarCosto (float presupuestoMantenimiento);


/// \brief  Muestra por pantalla el recargo a aplicarse y luego el costo total con el aumento
///
/// \param recargo valor individual a aumentar
/// \param costoConRecargo costo con el aumento aplicado
void mostrarAumento (float  recargo, float costoConRecargo);
#endif /* OUTPUT_H_ */
