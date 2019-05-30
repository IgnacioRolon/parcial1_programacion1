#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Musico.h"
#include "Orquesta.h"


/** \brief  To indicate that all position in the array are empty,
*           this function put the flag (isEmpty) in TRUE in all
*           position of the array.
* \param1 Array de tipo Orquesta
* \param2 size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int orquesta_Inicializar(Orquesta array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array de orquestas
* \param1 Orquesta array[] Array de orquesta
* \param2 size int Tamaño del array
* \param3 posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param1 array orquesta Array de orquesta
* \param2 size int Tamaño del array
* \param3 posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    if(retorno == -1)
    {
        printf("No se ha encontrado una Orquesta con dicha ID.");
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param1 Orquesta array[] Array de orquesta
* \param2 size int Tamaño del array
* \param3 posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarInt(Orquesta array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].tipo==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param1 Orquesta array[] Array de orquesta
* \param2 size int Tamaño del array
* \param3 posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarString(Orquesta array[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param1 array orquesta Array de orquesta
* \param2 size int Tamaño del array
* \param3 contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int orquesta_alta(Orquesta array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    int bufferInt;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(orquesta_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            if(utn_getUnsignedInt("\nIngrese el tipo de Orquesta: \n1- Sinfonica\n2- Filarmonica\n3- Camara\n","\nTipo de Orquesta No Valido.",1,sizeof(int),1,10,1,&bufferInt))
            {
                printf("Tipo de Orquesta No Valido.");
                return retorno;
            }
            if(bufferInt > 3 || bufferInt < 1)
            {
                printf("Tipo de Orquesta No Valido.");
                return retorno;
            }else
            {
                array[posicion].tipo = bufferInt;
            }
            if(utn_getName("\nIngrese el nombre de la Orquesta: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre))
            {
                printf("\nNombre de Orquesta invalido.\n");
                return retorno;
            }
            if(utn_getTexto("\nIngrese el lugar de origen: ","\nError",1,TEXT_SIZE,1,array[posicion].lugar))
            {
                printf("\nLugar de Origen invalido.\n");
                return retorno;
            }
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;
            printf("\n ID: %d\n Tipo: %d\n Nombre: %s\n Lugar: %s\n",
                  array[posicion].idUnico,array[posicion].tipo,array[posicion].nombre,array[posicion].lugar);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param1 array orquesta Array de orquesta
* \param2 size int Tamaño del array
* \param3 int* idBajada Puntero que indica cual ID fue bajada
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_baja(Orquesta array[], int sizeArray, int* idBajada)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(orquesta_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            *idBajada = id;
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;
            array[posicion].tipo=0;
            strcpy(array[posicion].nombre,"");
            strcpy(array[posicion].lugar,"");
            retorno=0;
            printf("\nBaja realizada con exito.\n");
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param1 array orquesta Array de orquesta
* \param2 size int Tamaño del array
* \param3 valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_bajaValorRepetidoInt(Orquesta array[], int sizeArray, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;
                array[i].tipo=0;
                strcpy(array[i].nombre,"");
                strcpy(array[i].lugar,"");
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param1 array orquesta Array de orquesta
* \param2 size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int orquesta_modificar(Orquesta array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(orquesta_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                printf("\n Posicion: %d\n ID: %d\n tipo: %d\n nombre: %s\n lugar: %s",
                       posicion, array[posicion].idUnico,array[posicion].tipo,array[posicion].nombre,array[posicion].lugar);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].tipo);
                        break;
                    case 'B':

                        break;
                    case 'C':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
                        break;
                    case 'D':
                        utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].lugar);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//Listar
/** \brief Lista los elementos de un array de Orquestas
* \param1 array orquesta Array de orquesta
* \param2 size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int orquesta_listar(Orquesta array[], int size)                      //cambiar orquesta
{
    int retorno=-1;
    char bufferTipo[15];
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            {
                switch(array[i].tipo)
                {
                    case 1:
                        strcpy(bufferTipo, "Sinfonica");
                        break;
                    case 2:
                        strcpy(bufferTipo, "Filarmonica");
                        break;
                    case 3:
                        strcpy(bufferTipo, "Camara");
                        break;
                }
                printf("\n ID: %d\n Tipo: %s\n Nombre: %s\n Lugar: %s\n",
                       array[i].idUnico,bufferTipo,array[i].nombre,array[i].lugar);      //cambiar todos
            }
        }
        retorno=0;
    }
    return retorno;
}


