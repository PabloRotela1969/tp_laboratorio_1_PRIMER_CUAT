
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int IsEmpty;

} Employee;

//=========================================PROTOTIPOS PEDIDOS====================================================
int initEmployees(Employee list[], int len);
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee list[], int len,int id);
int removeEmployee(Employee list[], int len, int id);
int sortEmployees(Employee list[], int len, int order);
int printEmployees(Employee list[], int length);
//=========================================MIS PROTOTIPOS========================================================

/** \brief permite ingresar un entero mostrando un mensaje indicativo
 *
 * \param mensaje[] char mensaje que orienta al usuario
 * \return float obtiene un valor decimal
 *
 */
float inputFloat(char mensaje[]);


/** \brief permite obtener un entero mostrando un mensaje indicativo
 *
 * \param mensaje[] char mensaje orientativo al usuario
 * \return int entero
 *
 */
int inputInt(char mensaje[]);

/** \brief permite el igreso de alfanumericos mostrando cartel indicativo al usuario
 *
 * \param mensaje[] char para orientar al usuario
 * \param salida[] char array de char con lo ingresado por el usuario
 * \param tam int tamaño que debe tener el array de caracteres
 * \return void
 *
 */
void inputString(char mensaje[], char salida[], int tam);


int ObtenerEleccionDeMenu(char menu[],int desde,int hasta);
void CargarNuevoEmpleado(Employee lista[],int tam);
void HarcodeoDeEmpleados(Employee lista[],int tam);
void ModificarEmpleado(Employee lista[],int tam);
void BorrarEmpleado(Employee lista[],int tam);
void OrdenarPorSectorYporApellido(Employee lista[],int tam);
void TotalPromedioSalariosYcantidadSuperanPromedio(Employee lista[],int tam);
int ContarEmpleados(Employee lista[],int tam);
void Menu(Employee lista[],int tam);
int buscarLibre(Employee lista[],int tam);
int proxIdEmpleado(Employee lista[],int tam);
