#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.c";

// biblioteca de prototipos de funciones matem�ticas
// suma, resta, multiplicaci�n, divisi�n y factorial

/** \brief Suma de dos numeros
 *
 * \param int primer numero
 * \param int segundo numero
 * \return int suma entre numero 1 y 2
 *
 */
int sumar( int , int );


/** \brief resta de dos n�meros
 *
 * \param int primer numero
 * \param int segundo numero
 * \return int diferencia entre el numero 1 y 2
 *
 */
int restar( int , int );


/** \brief producto entre dos numeros
 *
 * \param int primer numero
 * \param int segundo numero
 * \return int multiplicaci�n entre el numero 1 y 2
 *
 */
int multiplicar( int , int );


/** \brief cociente entre dos numeros
 *
 * \param int numerador
 * \param int denominador  ( que debe ser distinto de cero )
 * \return float divisi�n entre dos n�meros
 *
 */
float dividir( int , int );


/** \brief factorial de un numero
 *
 * \param int numero entero positivo
 * \return int factorial
 *
 */
int factorial(int);

#endif // FUNCIONES_H_INCLUDED
