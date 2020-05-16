#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"



//======================================================================================================================
//==========================================FUNCIONES PEDIDAS===========================================================


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee list[], int len)
{
    int i;
    Employee vacio;
    int resultado = -1;
    vacio.id = 0;
    vacio.IsEmpty = 1;
    strcpy(vacio.name, "");
    strcpy(vacio.lastName, "");
    vacio.salary = 0.0;
    vacio.sector = 0;
    for(i=0;i<len;i++)
    {
        list[i] = vacio;
        resultado = 0;
    }
    return resultado;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
  */
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector)
{


    int indiceLibre = buscarLibre(list,len);
    Employee nuevo;
    int resultado = -1;


    if( indiceLibre != -1)
    {
        nuevo.id = id;
        strcpy(nuevo.name, name);
        strcpy(nuevo.lastName, lastName);
        nuevo.salary = salary;
        nuevo.sector = sector;
        nuevo.IsEmpty = 0;

        list[indiceLibre] = nuevo;
        resultado = 0;
    }
    return resultado;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int findEmployeeById(Employee list[], int len,int id)
{
    int i;
    int posicion = -1;
    for(i = 0; i<len;i++)
    {
        if( list[i].id == id && list[i].IsEmpty == 0)
        {
            posicion = i;
            break;
        }

    }
    return posicion;
}


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee list[], int len, int id)
{
    int i;
    int encontrado = -1;
    for(i=0;i<len;i++)
    {
        list[i].IsEmpty = 1;
        encontrado = 0;
    }

    return encontrado;
}


/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee list[], int len, int order)
{
    int i;
    int j;
    Employee aux;
    int resultado = -1;
    for(i=0;i<len-1;i++)
    {
        for(j=(i+1);j<len;j++)
        {
            resultado = 0;
            if(order == 1)
            {
                if(list[i].IsEmpty != 1 && list[j].IsEmpty != 1)
                {

                    if( strcmp( list[i].lastName , list[j].lastName ) > 0 )
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                    else
                    {
                        if( strcmp( list[i].lastName , list[j].lastName ) == 0 )
                        {
                            if(list[i].sector > list[j].sector )
                            {
                                aux = list[i];
                                list[i] = list[j];
                                list[j] = aux;
                            }
                        }

                    }


                }


            }
            else
            {
                if(list[i].IsEmpty != 1 && list[j].IsEmpty != 1)
                {

                    if(strcmp( list[i].lastName , list[j].lastName ) < 0 )
                    {
                        aux = list[j];
                        list[j] = list[i];
                        list[i] = aux;
                    }
                    else
                    {
                        if(strcmp( list[i].lastName , list[j].lastName ) == 0 )
                        {
                            if(list[i].sector < list[j].sector )
                            {
                                aux = list[j];
                                list[j] = list[i];
                                list[i] = aux;
                            }
                        }

                    }
                }
            }

        }
    }
    return resultado;
}




/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee list[], int length)
{
    int i;
    int resultado = -1;
    printf("|%5s|%30s|%30s|%15s|%6s|\n","ID","NAME","LASTNAME","SALARY","SECTOR");
    printf("--------------------------------------------------------------------------------------------\n");
    for(i=0;i<length;i++)
    {
        if(list[i].IsEmpty == 0)
        {
            resultado = 0;
            printf("|%5d|%30s|%30s|%-15f|%6d|\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
        }

    }
    printf("--------------------------------------------------------------------------------------------\n");

    return resultado;
}


//======================================================================================================================
//==========================================FUNCIONES PROPIAS===========================================================
//======================================================================================================================


int ContarEmpleados(Employee lista[],int tam)
{
    int i;
    int cantidad = 0;
    for(i = 0;i<tam;i++)
    {
        if(lista[i].IsEmpty == 0)
        {
            cantidad++;
        }
    }
    return cantidad;
}

int ObtenerEleccionDeMenu(char menu[],int desde,int hasta)
{
    int opcion;
    int mal;
    do
    {
        mal = 0;
        printf("Elija numero del %d al %d", desde,hasta);
        printf("%s",menu);

        opcion = inputInt("Teclee el numero: ");
        if(opcion < desde || opcion > hasta)
        {
            mal = 1;
            printf("Preste atención a los numeros, vuelva a intentarlo \n");
        }
    }while(mal);

    return opcion;
}

void inputString(char mensaje[], char salida[], int tam)
{
    printf("%s",mensaje);
    fflush(stdin);
    fgets(salida,tam,stdin);
    salida[strlen(salida)-1]='\0';
    fflush(stdin);
}

int inputInt(char mensaje[])
{
    int i;
    int largo;
    int mal;
    int tam = 60;
    char salida[tam];

    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        fgets(salida,tam,stdin);
        largo = strlen(salida) - 1;
        salida[largo]='\0';
        for(i=0;i<largo;i++)
        {
            switch(salida[i])
            {
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '0':
                case '-':
                    mal = 0;
                break;
                default:
                    mal = 1;
                break;

            }
            if(mal)
            {
                printf("\n Debe ser numerica la entrada, intente nuevamente \n");
                break;
            }
        }

    }while(mal);

    return atoi(salida);

}

float inputFloat(char mensaje[])
{
    int i;
    int largo;
    int mal;
    int tam = 60;
    char salida[tam];
    float resultado = -1.1;

    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        fgets(salida,tam,stdin);
        largo = strlen(salida) - 1;
        salida[largo]='\0';
        for(i=0;i<largo;i++)
        {
            switch(salida[i])
            {
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '0':
                case '-':
                case '.':
                    mal = 0;
                break;
                default:
                    mal = 1;
                break;

            }
            if(mal)
            {
                printf("\n Debe ser numerica la entrada, intente nuevamente \n");
                break;
            }
        }

    }while(mal);
    resultado = atof(salida);

    return resultado;
}

void HarcodeoDeEmpleados(Employee lista[],int tam)
{

    lista[0].id = 1;
    strcpy(lista[0].name,"Ana");
    strcpy(lista[0].lastName,"Eleazar");
    lista[0].salary = 10.3;
    lista[0].sector = 1;
    lista[0].IsEmpty = 0;

    lista[1].id = 2;
    strcpy(lista[1].name, "Claudia");
    strcpy(lista[1].lastName , "Eleazar");
    lista[1].salary = 11.3;
    lista[1].sector = 2;
    lista[1].IsEmpty = 0;


    lista[2].id = 3;
    strcpy(lista[2].name, "Jesica");
    strcpy(lista[2].lastName , "Casares");
    lista[2].salary = 19.3;
    lista[2].sector = 1;
    lista[2].IsEmpty = 0;

    lista[3].id = 4;
    strcpy(lista[3].name, "Joana");
    strcpy(lista[3].lastName , "Bermudez");
    lista[3].salary = 15.3;
    lista[3].sector = 5;
    lista[3].IsEmpty = 0;

    lista[4].id = 5;
    strcpy(lista[4].name, "Adriana");
    strcpy(lista[4].lastName , "Alister");
    lista[4].salary = 17.3;
    lista[4].sector = 5;
    lista[4].IsEmpty = 0;

}

int buscarLibre(Employee lista[],int tam)
{
    int i;
    int indiceLibre = 1;

    for(i = 0;i<tam;i++)
    {
        if(lista[i].IsEmpty)
        {
            indiceLibre = i;
            break;
        }
    }
    return indiceLibre;
}


int proxIdEmpleado(Employee lista[],int tam)
{
    int i;
    int max = -2;
    int primerVez = 1;
    for(i=0;i<tam;i++)
    {
        if(!lista[i].IsEmpty)
        {
            if(lista[i].id > max || primerVez )
            {
                primerVez = 0;
                max = lista[i].id;
            }
        }
    }
    return max + 1;
}

void CargarNuevoEmpleado(Employee lista[],int tam)
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;

    int resultado;

    id = proxIdEmpleado(lista,tam);
    if(id == -1)
    {
        printf("\n Hubieron errores en la inicialización de array de empleados \n");
    }
    else
    {
        inputString("Ingrese el nombre : ",nombre,51);
        inputString("Ingrese el apellido : ",apellido,51);
        salario = inputFloat("Ingrese el salario :");
        sector = inputInt("Ingrese el sector :" );
        resultado = addEmployee(lista,tam,id,nombre,apellido,salario,sector);

    }

}

void ModificarEmpleado(Employee lista[],int tam)
{
    int id;
    int resultado;
    Employee unEmpleado[1];
    int campo;
    int nuevoId;
    char nuevoApellido[50];
    char nuevoNombre[50];
    float nuevoSalario;
    int nuevoSector;


    id = inputInt("Ingrese el ID del empleado a modificar : ");
    resultado = findEmployeeById(lista,tam,id);
    if(resultado == -1)
    {
        printf("\nError 404  ID = %d not found \n",id);
    }
    else
    {
        unEmpleado[0] = lista[resultado];
        printEmployees(unEmpleado,1);

        campo = ObtenerEleccionDeMenu("\n 1 - id\n 2 - nombre\n 3 - apellido \n 4 - salario \n 5 - sector \n 6 - salir sin cambios \n",1,6);
        switch(campo)
        {
        case 1:
                nuevoId = inputInt("Ingrese nuevo ID :");
                lista[resultado].id = nuevoId;
            break;
        case 2:
                inputString("Ingrese nuevo nombre :",nuevoNombre,50);
                strcpy(lista[resultado].name, nuevoNombre);
            break;
        case 3:
                inputString("Ingrese nuevo apellido :",nuevoApellido,50);
                strcpy(lista[resultado].lastName, nuevoApellido);
            break;
        case 4:
                nuevoSalario = inputFloat("Ingrese nuevo salario : ");
                lista[resultado].salary = nuevoSalario;
            break;
        case 5:
                nuevoSector = inputInt("Ingrese nuevo sector : ");
                lista[resultado].sector = nuevoSector;
            break;

        }
        unEmpleado[0] = lista[resultado];
        printEmployees(unEmpleado,1);

    }

}

void BorrarEmpleado(Employee lista[],int tam)
{
    int resultado;
    int id;

    id = inputInt("Ingrese el ID del empleado a modificar : ");
    resultado = findEmployeeById(lista,tam,id);
    if(resultado == -1)
    {
        printf("\nError 404  ID = %d not found \n",id);
    }
    else
    {
        lista[resultado].IsEmpty = 1;
    }
}

void OrdenarPorSectorYporApellido(Employee lista[],int tam)
{
    int opcion;
    opcion = ObtenerEleccionDeMenu("\n 1 - Descendente \n 2 - Ascendente \n",1,2);
    sortEmployees(lista,tam,opcion);

}

void TotalPromedioSalariosYcantidadSuperanPromedio(Employee lista[],int tam)
{
    int i;
    float total = 0.0;
    float promedio = 0.0;
    int cantidad = 0;
    int cantidadEmpleadosSuperanPromedio = 0;
    for(i=0;i<tam;i++)
    {
        if(lista[i].IsEmpty == 0)
        {
            total += lista[i].salary;
            cantidad ++;
        }
    }
    if(cantidad > 0)
    {
        promedio = total / cantidad;
        printf("\n El total de salarios es : %f\n",total);
        printf(" El promedio de salarios es : %f\n", promedio);
        for(i=0;i<tam;i++)
        {
            if(lista[i].IsEmpty == 0)
            {
                if(lista[i].salary > promedio)
                {
                    cantidadEmpleadosSuperanPromedio ++;
                }
            }
        }
        printf(" Hay %d empleados que superan ese promedio \n", cantidadEmpleadosSuperanPromedio);
    }

}




void Menu(Employee lista[],int tam)
{
    int errores;
    int opcion;
    int salir = 0;

    errores = initEmployees(lista,tam);
    if(errores == -1)
    {
        printf("\n Hubieron errores en la inicialización de array de empleados \n");
    }
    HarcodeoDeEmpleados(lista,tam);

    do
    {
       if(ContarEmpleados(lista,tam) > 0)
       {
           opcion = ObtenerEleccionDeMenu("\n 1 - ALTAS\n 2 - MODIFICAR\n 3 - BAJA\n 4 - ORDENAMIENTO (apellido luego sector)\n 5 - TOTAL ,PROMEDIO SALARIOS y CANTIDAD QUE SUPERA PROMEDIO\n 6 - MOSTRAR LISTA\n 7 - SALIR\n",1,7);

           switch(opcion)
            {
            case 1:
                CargarNuevoEmpleado(lista,tam);
                break;
            case 2:
                ModificarEmpleado(lista,tam);
                break;
            case 3:
                BorrarEmpleado(lista,tam);
                break;
            case 4:
                OrdenarPorSectorYporApellido(lista,tam);
                break;
            case 5:
                TotalPromedioSalariosYcantidadSuperanPromedio(lista,tam);
                break;
            case 6:
                printEmployees(lista,tam);
                break;
            case 7:
                salir = 1;
                break;
            }

       }
       else
       {
           opcion = ObtenerEleccionDeMenu("\n 1 - ALTAS\n 2 - SALIR\n",1,2);
            switch(opcion)
            {
            case 1:
                CargarNuevoEmpleado(lista,tam);
                break;
            case 2:
                salir = 1;
                break;
            }

       }

    }
    while(!salir);

}


