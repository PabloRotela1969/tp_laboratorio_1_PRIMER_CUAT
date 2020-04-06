#include <stdio.h>
#include <stdlib.h>
/* biblioteca de funciones matematicas */



//recibe dos enteros y entrega uno como suma
int suma(int primero,int segundo)
{
    return primero + segundo;
}
//recibe dos enteros y entrega uno como resta
int resta(int primero,int segundo)
{
    return primero - segundo;
}
//recibe dos enteros y entrega uno como producto
int multiplicacion(int primero, int segundo)
{
    return primero * segundo;
}
//recibe dos enteros y entrega un flotante como cociente
float division(int primero, int segundo)
{
   return (float)primero / segundo;

}

//recibe un entero y acumula los sucesivos productos desde el 1 al numero
//entregando el acumulado como entero
int factorial(int primero)
{
    int i;
    int acumulado = 1;
    for(i = 1; i <= primero ; i++)
    {
        acumulado *= i;
    }
    return acumulado;
}
