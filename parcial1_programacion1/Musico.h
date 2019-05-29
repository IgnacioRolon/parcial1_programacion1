#include "Orquesta.h"
#include "Instrumentos.h"
#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int idOrquesta;
    int idInstrumento;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE]; //ex lugar
    int edad; //ex tipo
}Musico;


#endif // MUSICO_H_INCLUDED

int musico_Inicializar(Musico array[], int size);
int musico_buscarEmpty(Musico array[], int size, int* posicion);
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion);
int musico_buscarInt(Musico array[], int size, int valorBuscado, int* posicion);
int musico_buscarString(Musico array[], int size, char* valorBuscado, int* indice);
int musico_alta(Musico array[], Orquesta arrayOrquesta[], Instrumento arrayInstrumento[], int size, int* contadorID);
int musico_baja(Musico array[], int sizeArray);
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado);
int musico_modificar(Musico array[], Orquesta arrayOrquesta[], int sizeArray);
int musico_listar(Musico array[], Instrumento arrayInstrumento[], int size);
int musico_bajaPorOrquesta(Musico array[], int sizeArray, int idAEliminar);
int musico_ordenarPorUnCriterio(Musico array[],int size, int orderFirst);
