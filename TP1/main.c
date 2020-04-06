#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Funciones.h"

float resulta;
int main()
{
    int numero1;
    int numero2;
    char operacion;

    bool mal = true;


    printf(" Ingrese el primer numero : ");
    scanf("%d", &numero1);

    printf("\n Ingrese el segundo numero : ");
    scanf("%d", &numero2);

    do
    {
        mal = false;
        fflush(stdin);
        printf("\n Elija una operacion entre las siguientes : +, - , * y / ");
        scanf("%c", &operacion);

        switch(operacion)
        {
        case '+':

            printf(" %d %c %d = %d \n" , numero1,operacion,numero2,suma(numero1,numero2));
            break;
        case '-':
            printf(" %d %c %d = %d \n" , numero1,operacion,numero2,resta(numero1,numero2));
            break;
        case '*':
            printf(" %d %c %d = %d \n" , numero1,operacion,numero2,multiplicacion(numero1,numero2));
            break;
        case '/':
            if (numero2 > 0)
            {
                printf(" %d %c %d = %f \n" , numero1,operacion,numero2,division(numero1,numero2));
            }
            else
            {
                printf("No se puede dividir por cero \n");
            }


            break;
        default:
            mal = true;
            printf("Tenga en bien ingresar los signos de operacion requeridos");
            break;
        }
    }while(mal);


    system("Pause");

    return 0;
}
