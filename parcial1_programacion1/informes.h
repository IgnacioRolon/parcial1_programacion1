#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED


typedef struct
{
    int idOrquesta;
    int isEmpty;
}MusicoAuxiliar;

int informes_orquestasPorLugar(Orquesta array[], int sizeArray);
int informes_musicosMenoresA25(Musico arrayMusicos[], Instrumento arrayInstrumentos[], Orquesta arrayOrquestas[], int sizeArray, int sizeOrquestas, int sizeInstrumentos);
int informes_listarOrquestasMenosDe6(Orquesta array[], Musico arrayMusicos[], int size, int sizeMusicos);
int informes_instrumentosDeUnaOrquesta(Musico arrayMusicos[], Instrumento arrayInstrumentos[], int sizeMusicos, int sizeInstrumentos);
int informes_orquestasCompletas(Orquesta arrayOrquestas[], Musico arrayMusicos[], Instrumento arrayInstrumentos[], int sizeOrquestas, int sizeMusicos, int sizeInstrumentos);
int informes_ordenarMusicos(MusicoAuxiliar array[],int size);
int informes_initMusicoAuxiliar(MusicoAuxiliar arrayAux[], int sizeArray);
int informes_orquestaConMenosMusicos(Musico arrayMusicos[], Orquesta arrayOrquestas[], MusicoAuxiliar arrayAux[], int sizeMusicos, int sizeOrquestas);

#endif // INFORMES_H_INCLUDED
