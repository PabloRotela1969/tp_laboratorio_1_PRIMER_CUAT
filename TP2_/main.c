#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

#define T 1000

//el harcodeo de empleados est� en la funci�n MENU para activarlo
// o desactivarlo favor de comentarlo o descomentarlo alternativamente

int main()
{
    Employee listaEmpleados[T];
    Menu(listaEmpleados,T);

    return 0;
}
