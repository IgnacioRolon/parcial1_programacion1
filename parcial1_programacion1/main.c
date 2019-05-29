#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include "Orquesta.h"
#include "Instrumentos.h"
#include "Musico.h"
#include "informes.h"
#define ORQUESTAS_MAX 50
#define INSTRUMENTOS_MAX 20
#define MUSICOS_MAX 1000

int main()
{
    MusicoAuxiliar arrayAuxiliar[MUSICOS_MAX];

    Orquesta arrayOrquestas[50];
    int idOrquestas = 0;
    orquesta_Inicializar(arrayOrquestas, ORQUESTAS_MAX);

    Instrumento arrayInstrumentos[20];
    int idInstrumentos = 0;
    instrumento_Inicializar(arrayInstrumentos, INSTRUMENTOS_MAX);

    Musico arrayMusicos[1000];
    int idMusicos = 0;
    musico_Inicializar(arrayMusicos, MUSICOS_MAX);

    int aux;
    int respuesta = -2;
    int respuestaSubmenu = -2;

    //Hardcode Instrumentos
    arrayInstrumentos[0].idUnico = 1;
    arrayInstrumentos[0].isEmpty = 0;
    strcpy(arrayInstrumentos[0].nombre,"Inst1");
    arrayInstrumentos[0].tipo = 1;

    arrayInstrumentos[1].idUnico = 2;
    arrayInstrumentos[1].isEmpty = 0;
    strcpy(arrayInstrumentos[1].nombre,"Inst2");
    arrayInstrumentos[1].tipo = 2;

    arrayInstrumentos[2].idUnico = 3;
    arrayInstrumentos[2].isEmpty = 0;
    strcpy(arrayInstrumentos[2].nombre,"Inst3");
    arrayInstrumentos[2].tipo = 2;

    arrayInstrumentos[3].idUnico = 4;
    arrayInstrumentos[3].isEmpty = 0;
    strcpy(arrayInstrumentos[3].nombre,"Inst4");
    arrayInstrumentos[3].tipo = 3;

    arrayInstrumentos[4].idUnico = 5;
    arrayInstrumentos[4].isEmpty = 0;
    strcpy(arrayInstrumentos[4].nombre,"Inst5");
    arrayInstrumentos[4].tipo = 4;

    //Hardcode Orquesta

    arrayOrquestas[0].idUnico = 1;
    arrayOrquestas[0].isEmpty = 0;
    strcpy(arrayOrquestas[0].nombre,"Orquesta1");
    strcpy(arrayOrquestas[0].lugar,"Lugar1");
    arrayOrquestas[0].tipo = 1;

    arrayOrquestas[1].idUnico = 2;
    arrayOrquestas[1].isEmpty = 0;
    strcpy(arrayOrquestas[1].nombre,"Orquesta2");
    strcpy(arrayOrquestas[1].lugar,"Lugar2");
    arrayOrquestas[1].tipo = 2;

    arrayOrquestas[2].idUnico = 3;
    arrayOrquestas[2].isEmpty = 0;
    strcpy(arrayOrquestas[2].nombre,"Orquesta3");
    strcpy(arrayOrquestas[2].lugar,"Lugar3");
    arrayOrquestas[2].tipo = 3;

    arrayOrquestas[3].idUnico = 4;
    arrayOrquestas[3].isEmpty = 0;
    strcpy(arrayOrquestas[3].nombre,"Orquesta4");
    strcpy(arrayOrquestas[3].lugar,"Lugar4");
    arrayOrquestas[3].tipo = 2;

    //Hardcode Musico
    arrayMusicos[0].idUnico = 1;
    arrayMusicos[0].idOrquesta = 1;
    arrayMusicos[0].idInstrumento = 2;
    arrayMusicos[0].isEmpty = 0;
    strcpy(arrayMusicos[0].nombre,"Mus1");
    strcpy(arrayMusicos[0].apellido,"Amus1");
    arrayMusicos[0].edad = 30;

    arrayMusicos[1].idUnico = 2;
    arrayMusicos[1].idOrquesta = 2;
    arrayMusicos[1].idInstrumento = 5;
    arrayMusicos[1].isEmpty = 0;
    strcpy(arrayMusicos[1].nombre,"Mus2");
    strcpy(arrayMusicos[1].apellido,"Amus2");
    arrayMusicos[1].edad = 20;

    arrayMusicos[2].idUnico = 3;
    arrayMusicos[2].idOrquesta = 4;
    arrayMusicos[2].idInstrumento = 2;
    arrayMusicos[2].isEmpty = 0;
    strcpy(arrayMusicos[2].nombre,"Mus3");
    strcpy(arrayMusicos[2].apellido,"Amus3");
    arrayMusicos[2].edad = 25;

    arrayMusicos[3].idUnico = 4;
    arrayMusicos[3].idOrquesta = 4;
    arrayMusicos[3].idInstrumento = 1;
    arrayMusicos[3].isEmpty = 0;
    strcpy(arrayMusicos[3].nombre,"Mus4");
    strcpy(arrayMusicos[3].apellido,"Amus4");
    arrayMusicos[3].edad = 27;

    arrayMusicos[4].idUnico = 5;
    arrayMusicos[4].idOrquesta = 1;
    arrayMusicos[4].idInstrumento = 3;
    arrayMusicos[4].isEmpty = 0;
    strcpy(arrayMusicos[4].nombre,"Mus5");
    strcpy(arrayMusicos[4].apellido,"Amus5");
    arrayMusicos[4].edad = 22;

    arrayMusicos[5].idUnico = 6;
    arrayMusicos[5].idOrquesta = 3;
    arrayMusicos[5].idInstrumento = 4;
    arrayMusicos[5].isEmpty = 0;
    strcpy(arrayMusicos[5].nombre,"Mus6");
    strcpy(arrayMusicos[5].apellido,"Amus6");
    arrayMusicos[5].edad = 35;

    while(respuesta != 11)
    {
        utn_getUnsignedInt("\n1) Agregar Orquesta\n2) Eliminar Orquesta\n3) Imprimir Orquestas\n4) Agregar Musico\n5) Modificar Musico\n6) Eliminar Musico\n7) Imprimir Musicos\n8) Agregar Instrumento\n9) Imprimir Instrumentos\n10) Informes\n11) Salir\n", "ERROR: Ingrese un numero valido.", 0, 3, 0, 10, 1, &respuesta);
        //__fpurge(stdin);
        switch(respuesta)
        {
            case 1:
                orquesta_alta(arrayOrquestas, ORQUESTAS_MAX, &idOrquestas);
                break;
            case 2:
                if(!orquesta_baja(arrayOrquestas, ORQUESTAS_MAX, &aux))
                {
                    musico_bajaPorOrquesta(arrayMusicos, MUSICOS_MAX, aux);
                }
                break;
            case 3:
                orquesta_listar(arrayOrquestas, ORQUESTAS_MAX);
                break;
            case 4:
                musico_alta(arrayMusicos, arrayOrquestas, arrayInstrumentos, MUSICOS_MAX, &idMusicos);
                break;
            case 5:
                musico_listar(arrayMusicos, arrayInstrumentos, MUSICOS_MAX);
                musico_modificar(arrayMusicos, arrayOrquestas, MUSICOS_MAX);
                break;
            case 6:
                musico_listar(arrayMusicos, arrayInstrumentos, MUSICOS_MAX);
                musico_baja(arrayMusicos, MUSICOS_MAX);
                break;
            case 7:
                musico_listar(arrayMusicos, arrayInstrumentos, MUSICOS_MAX);
                break;
            case 8:
                instrumento_alta(arrayInstrumentos, INSTRUMENTOS_MAX, &idInstrumentos);
                break;
            case 9:
                instrumento_listar(arrayInstrumentos, INSTRUMENTOS_MAX);
                break;
            case 10:
            utn_getUnsignedInt("\n1) Listar Orquestas por lugar\n2) Listar Musicos menores de 25 años\n3) Listar Orquestas con menos de 6 musicos\n4) Listar instrumentos de una Orquesta determinada\n5) Listar Orquestas Completas\n6) Listar Orquesta con menos musicos\n7) Listar promedio de instrumentos\n8) Listar musicos que no toquen instrumentos de viento\n", "ERROR: Ingrese un numero valido.", 0, 3, 0, 10, 1, &respuestaSubmenu);
            //__fpurge(stdin);
            switch(respuestaSubmenu)
            {
                case 1:
                    informes_orquestasPorLugar(arrayOrquestas, ORQUESTAS_MAX);
                    break;
                case 2:
                    informes_musicosMenoresA25(arrayMusicos, arrayInstrumentos, arrayOrquestas, MUSICOS_MAX, ORQUESTAS_MAX, INSTRUMENTOS_MAX);
                    break;
                case 3:
                    informes_listarOrquestasMenosDe6(arrayOrquestas, arrayMusicos, ORQUESTAS_MAX, MUSICOS_MAX);
                    break;
                case 4:
                    informes_instrumentosDeUnaOrquesta(arrayMusicos, arrayInstrumentos, MUSICOS_MAX, INSTRUMENTOS_MAX);
                    break;
                case 5:
                    informes_orquestasCompletas(arrayOrquestas, arrayMusicos, arrayInstrumentos, ORQUESTAS_MAX, MUSICOS_MAX, INSTRUMENTOS_MAX);
                    break;
                case 6:
                    informes_orquestaConMenosMusicos(arrayMusicos, arrayOrquestas, arrayAuxiliar, MUSICOS_MAX, ORQUESTAS_MAX);
                    break;
                case 7:
                    informes_promedioDeInstrumentos(arrayMusicos, arrayOrquestas, MUSICOS_MAX, ORQUESTAS_MAX);
                    break;
                case 8:
                    informes_sinInstrumentosViento(arrayMusicos, arrayInstrumentos, MUSICOS_MAX, INSTRUMENTOS_MAX);
                    break;
            }
        }
    }
}
