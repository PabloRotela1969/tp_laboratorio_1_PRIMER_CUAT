#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h";

int main()
{
    // para recoger los numeros
    int numero1 = 0;
    int numero2 = 0;

    // operaciones matematicas
    int suma;
    int resta;
    int multiplicacion;
    float division;
    int factor1;
    int factor2;

    // para el menu
    int opcion;

    // menú
    do
    {
        printf("\n1 - Ingresar 1er operando\n");
        printf("2 - Ingresar 2do operando\n");
        printf("3 - Calcular todas las operaciones\n");
        printf("4 - Informar resultados\n");
        printf("5 - Salir\n");
        printf(" Ingrese una opcion :");
        scanf(" %d", &opcion);

        switch(opcion)
        {
        case 1:
                // ingreso del primer numero
                printf("Favor de ingresar el primer numero : ");
                scanf(" %d",&numero1);
                fflush(stdin);
            break;
        case 2:
                // ingreso del segundo numero
                printf("Favor de ingresar el SEGUNDO numero : ");
                scanf(" %d",&numero2);
                fflush(stdin);
            break;
        case 3:
                // calculo de todas las operaciones matematicas solicitadas con los numeros disponibles
                suma = sumar(numero1,numero2);
                resta = restar(numero1,numero2);
                multiplicacion = multiplicar(numero1,numero2);
                division = dividir(numero1,numero2);
                factor1 = factorial(numero1);
                factor2 = factorial(numero2);
            break;
        case 4:
                // muestra de todos los resultados de las operaciones matematicas con los numeros disponibles
                printf("El resultado de %d + %d es: %d \n", numero1,numero2,suma);
                printf("El resultado de %d - %d es: %d \n", numero1,numero2,resta);

                if(numero2 != 0)
                {
                    printf("El resultado de %d / %d es: %f \n", numero1,numero2,division);
                }
                else
                {
                    printf("\nNo es posible dividir por cero\n");
                }
                printf("El resultado de %d * %d es: %d \n", numero1,numero2,multiplicacion);

                if(numero1 >= 0)
                {
                    printf("El resultado de %d! es: %d \n", numero1,factor1);
                }
                else
                {
                    printf("\nNo se puede extraer el factorial a un numero negativo\n");
                }

                if(numero2 >= 0)
                {
                    printf("El resultado de %d! es: %d \n", numero2,factor2);
                }
                else
                {
                    printf("\nNo se puede extraer el factorial a un numero negativo\n");
                }
            break;
        case 5:
            // salida
            break;
        default:
            // validacion del menu
            printf("\nFavor de elegir un numero entre 1 y 5, gracias\n");
            break;
        }
    }
    while(opcion != 5);

    return 0;
}
