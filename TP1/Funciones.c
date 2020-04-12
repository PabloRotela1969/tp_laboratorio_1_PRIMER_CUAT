#include <stdio.h>
#include <stdlib.h>

// biblioteca de implementación de prototipos de funciones matemáticas
// suma, resta, multiplicación, división y factorial

int sumar(int numero1,int numero2)
{
    int resulta;
    resulta = numero1 + numero2;
    return resulta;
}
int restar(int numero1,int numero2)
{
    int resulta;
    resulta = numero1 - numero2;
    return resulta;
}
int multiplicar(int numero1,int numero2)
{
    int resulta;
    resulta = numero1 * numero2;
    return resulta;
}
float dividir(int numero1,int numero2)
{
    float resulta;
    resulta = (float)numero1 / (float)numero2;
    return resulta;
}

int factorial(int numero1)
{
    int i;
    int resulta = 1;
    if ( numero1 >= 0)
    {
        for ( i = 1 ; i <= numero1 ; i++)
        {
            resulta *= i;
        }
    }

    return resulta;
}
