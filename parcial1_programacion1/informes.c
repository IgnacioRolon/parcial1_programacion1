#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Musico.h"
#include "Instrumentos.h"
#include "informes.h"

#define TEXT_SIZE 20

int informes_orquestasPorLugar(Orquesta array[], int sizeArray)
{
    int i;
    int retorno = -1;
    char bufferText[TEXT_SIZE];
    char bufferTipo[TEXT_SIZE];
    if(array != NULL && sizeArray >= 0)
    {
        if(utn_getTexto("\nIngrese el lugar de origen: ","\nError",1,TEXT_SIZE,1,bufferText))
        {
            printf("\nLugar de Origen invalido.\n");
            return retorno;
        }
        for(i=0;i<sizeArray;i++)
        {
            if(strcmp(array[i].lugar, bufferText) == 0)
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
                       array[i].idUnico,bufferTipo,array[i].nombre,array[i].lugar);
                retorno = 0;
            }
        }
        if(retorno)
        {
            printf("No se ha encontrado ninguna orquesta de dicho lugar.");
        }
    }
    return retorno;
}

int informes_musicosMenoresA25(Musico arrayMusicos[], Instrumento arrayInstrumentos[], Orquesta arrayOrquestas[], int sizeArray, int sizeOrquestas, int sizeInstrumentos)
{
    int i,j;
    int retorno = -1;
    char bufferOrquesta[TEXT_SIZE];
    char bufferInstrumento[TEXT_SIZE];
    if(arrayMusicos != NULL && arrayInstrumentos != NULL && arrayOrquestas != NULL && sizeArray >= 0 && sizeInstrumentos >= 0 && sizeOrquestas >= 0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(arrayMusicos[i].isEmpty)
            {
                continue;
            }
            if(arrayMusicos[i].edad < 25)
            {
                for(j=0;j<sizeOrquestas;j++)
                {
                    if(arrayMusicos[i].idOrquesta == arrayOrquestas[j].idUnico)
                    {
                        strcpy(bufferOrquesta, arrayOrquestas[j].nombre);
                        break;
                    }
                }
                for(j=0;j<sizeInstrumentos;j++)
                {
                    if(arrayMusicos[i].idInstrumento == arrayInstrumentos[j].idUnico)
                    {
                        strcpy(bufferInstrumento, arrayInstrumentos[j].nombre);
                        break;
                    }
                }
                printf("\nID: %d\nNombre: %s\nApellido: %s\nEdad: %d\nInstrumento: %s\nOrquesta: %s\n",
                        arrayMusicos[i].idUnico, arrayMusicos[i].nombre, arrayMusicos[i].apellido, arrayMusicos[i].edad, bufferInstrumento, bufferOrquesta);
                retorno = 0;
            }
        }
        if(retorno)
        {
            printf("No se ha encontrado ningun musico menor de 25.");
        }
    }
    return retorno;
}

int informes_listarOrquestasMenosDe6(Orquesta array[], Musico arrayMusicos[], int size, int sizeMusicos)                      //cambiar orquesta
{
    int retorno=-1;
    char bufferTipo[TEXT_SIZE];
    int i,j;
    int contadorOrquestas = 0;
    if(array!=NULL && arrayMusicos != NULL && size>=0 && sizeMusicos >=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            {
                for(j=0;j<sizeMusicos;j++)
                {
                    if(arrayMusicos[j].isEmpty)
                    {
                        continue;
                    }
                    if(array[i].idUnico == arrayMusicos[j].idOrquesta)
                    {
                        contadorOrquestas++;
                    }
                }
                if(contadorOrquestas < 6)
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
                           array[i].idUnico,bufferTipo,array[i].nombre,array[i].lugar);
                }
                contadorOrquestas = 0;
            }
        }
        retorno=0;
    }
    return retorno;
}

int informes_instrumentosDeUnaOrquesta(Musico arrayMusicos[], Instrumento arrayInstrumentos[], int sizeMusicos, int sizeInstrumentos)
{
    int i,j;
    int id;
    int retorno = -1;
    char bufferTipo[TEXT_SIZE];
    if(arrayMusicos!=NULL && arrayInstrumentos != NULL && sizeInstrumentos>=0 && sizeMusicos >=0)
    {
        utn_getUnsignedInt("\nID de la Orquesta: ","\nError",1,sizeof(int),1,50,1,&id);
        for(i=0;i<sizeMusicos;i++)
        {
            if(arrayMusicos[i].isEmpty)
            {
                continue;
            }
            if(arrayMusicos[i].idOrquesta == id)
            {
                for(j=0;j<sizeInstrumentos;j++)
                {
                    if(arrayMusicos[i].idInstrumento == arrayInstrumentos[j].idUnico)
                    {
                        switch(arrayInstrumentos[j].tipo)
                        {
                            case 1:
                                strcpy(bufferTipo, "Cuerdas");
                                break;
                            case 2:
                                strcpy(bufferTipo, "Viento-madera");
                                break;
                            case 3:
                                strcpy(bufferTipo, "Viento-metal");
                                break;
                            case 4:
                                strcpy(bufferTipo, "Percusion");
                                break;
                        }
                        printf("\nInstrumento: %s\nTipo: %s\nMusico: %s\n", arrayInstrumentos[j].nombre, bufferTipo, arrayMusicos[i].nombre);
                        retorno = 0;
                        break;
                    }
                }
            }
        }
        if(retorno)
        {
            printf("No se encontro ningun instrumento y/o musico para dicha orquesta.");
        }
    }
    return retorno;
}

int informes_orquestasCompletas(Orquesta arrayOrquestas[], Musico arrayMusicos[], Instrumento arrayInstrumentos[], int sizeOrquestas, int sizeMusicos, int sizeInstrumentos)
{
    int i,j,z;
    int retorno = -1;
    int contadorCuerdas = 0;
    int contadorViento = 0;
    int contadorPercusion = 0;
    int bufferTipo;
    if(arrayMusicos != NULL && arrayInstrumentos != NULL && arrayOrquestas != NULL && sizeMusicos >= 0 && sizeInstrumentos >= 0 && sizeOrquestas >= 0)
    {
        for(i=0;i<sizeOrquestas;i++)
        {
            if(arrayOrquestas[i].isEmpty)
            {
                continue;
            }
            for(j=0;j<sizeMusicos;j++)
            {
                if(arrayMusicos[j].isEmpty)
                {
                    continue;
                }
                if(arrayMusicos[j].idOrquesta == arrayOrquestas[i].idUnico)
                {
                    for(z=0;z<sizeInstrumentos;z++)
                    {
                        if(arrayMusicos[j].idInstrumento == arrayInstrumentos[z].idUnico)
                        {
                            bufferTipo = arrayInstrumentos[z].tipo;
                            break;
                        }
                    }
                    switch(bufferTipo)
                    {
                        case 1:
                            contadorCuerdas++;
                            break;
                        case 2:
                            contadorViento++;
                            break;
                        case 3:
                            contadorViento++;
                            break;
                        case 4:
                            contadorPercusion++;
                            break;
                    }
                }
                if(contadorCuerdas >= 4 && contadorViento >= 4 && contadorPercusion >= 1)
                {
                    printf("\nNombre: %s\nLugar: %s\n", arrayOrquestas[i].nombre, arrayOrquestas[i].lugar);
                    retorno = 0;
                }
            }
        }
        if(retorno)
        {
            printf("No se ha encontrado ninguna orquesta completa.");
        }
    }
    return retorno;
}

int informes_ordenarMusicos(MusicoAuxiliar array[],int size)                              //cambiar musico
{
    int retorno=-1;
    int i;
    MusicoAuxiliar buffer;
    int flagSwap;
    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for(i = 1; i < size-1; i++)
            {
                if(array[i].idOrquesta < array[i+1].idOrquesta)
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

int informes_initMusicoAuxiliar(MusicoAuxiliar arrayAux[], int sizeArray)
{
    int i;
    for(i=0;i<sizeArray;i++)
    {
        arrayAux[i].isEmpty = 1;
        arrayAux[i].idOrquesta = -1;
    }
    return 0;
}

int informes_orquestaConMenosMusicos(Musico arrayMusicos[], Orquesta arrayOrquestas[], MusicoAuxiliar arrayAux[], int sizeMusicos, int sizeOrquestas)
{
    int i;
    int retorno = -1;
    int posicionAux = 0;
    int orquestaRepetida;
    int orquestaMenor;
    int contadorSeguidos = 1001;
    int contadorAuxiliar = 0;
    char bufferTipo[TEXT_SIZE];
    if(arrayMusicos != NULL && arrayOrquestas != NULL && sizeMusicos >= 0 && sizeOrquestas >= 0)
    {
        informes_initMusicoAuxiliar(arrayAux, sizeMusicos);
        for(i=0;i<sizeMusicos;i++)
        {
            if(arrayMusicos[i].isEmpty)
            {
                continue;
            }
            arrayAux[posicionAux].idOrquesta = arrayMusicos[i].idOrquesta;
            posicionAux++;
        }
        informes_ordenarMusicos(arrayAux, sizeMusicos);
        for(i=0;i<sizeMusicos;i++)
        {
            if(i==0)
            {
                orquestaRepetida = arrayAux[i].idOrquesta;
                contadorAuxiliar = 1;
                continue;
            }
            if(arrayAux[i].idOrquesta == orquestaRepetida)
            {
                contadorAuxiliar++;
            }else{
                if(contadorAuxiliar<contadorSeguidos)
                {
                    contadorSeguidos = contadorAuxiliar;
                    orquestaMenor = arrayAux[i-1].idOrquesta;
                    retorno = 0;
                }
                contadorAuxiliar = 0;
                orquestaRepetida = arrayAux[i].idOrquesta;
            }
            if(arrayAux[i].isEmpty == 1)
            {
                break; //Se hace break porque se sabe que todos estarán llenos hasta llegar a un isEmpty.
            }
        }
        //orquestaMenor contiene la Orquesta menos frecuente (la ID)
        for(i=0;i<sizeOrquestas;i++)
        {
            if(arrayOrquestas[i].isEmpty)
            {
                continue;
            }
            if(arrayOrquestas[i].idUnico == orquestaMenor)
            {
                switch(arrayOrquestas[i].tipo)
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
                printf("\nOrquesta: %s\nLugar: %s\nTipo %s\nCantidad de Musicos: %d",
                        arrayOrquestas[i].nombre, arrayOrquestas[i].lugar, bufferTipo, contadorSeguidos);
                retorno = 0;
            }
        }
        if(retorno)
        {
            printf("No se encontro ninguna orquesta.");
        }
    }
    return retorno;
}
