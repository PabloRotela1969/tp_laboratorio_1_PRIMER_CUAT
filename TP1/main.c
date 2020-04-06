#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Funciones.h" /* librer�a de funciones matem�ticas */

int main()
{
    // n�meros que ingresa el usuario
    int numero1;
    int numero2;
    // car�cter que representa la operaci�n ingresada por el usuario
    char operacion;
    // variable bandera usada para validar ingreso de operaci�n
    bool mal = true;


    printf(" Ingrese el primer numero : ");
    scanf("%d", &numero1);

    printf("\n Ingrese el segundo numero : ");
    scanf("%d", &numero2);

    // validaci�n de ingreso de funci�n y c�lculo de funci�n
    do
    {
        mal = false;
        fflush(stdin);
        printf("\n Elija una operacion entre las siguientes : +, - , * , / , ! : ");
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
            // valido que el denominador sea distinto de cero
            if (numero2 > 0)
            {
                printf(" %d %c %d = %f \n" , numero1,operacion,numero2,division(numero1,numero2));
            }
            else
            {
                printf("No se puede dividir por cero \n");
            }
            break;
        case '!':
            printf(" %c%d = %d y el " , operacion,numero1,factorial(numero1));
            printf(" %c%d = %d \n" , operacion,numero2,factorial(numero2));
            break;
        default:
            mal = true;
            // no se ingres� ning�n caracter de funci�n contemplado, muestro error
            printf("Tenga en bien ingresar los signos de operacion requeridos");
            break;
        }
    // si no se ingres� ninguno de los caracteres, vuelvo a iterar y pido volver a ingresar
    }while(mal);


    system("Pause");

    return 0;
}
