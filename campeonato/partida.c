#include <stdio.h>
#include <stdlib.h>
#include "partida.h"

struct partida {
    int id_time_1;
    int id_time_2;
    int gols_time_1;
    int gols_time_2;
};

Partida* partida_construir() {
    Partida *p = (Partida *)malloc(sizeof(Partida));
    if (p == NULL) {
        printf("Falta memoria para alocar uma partida!");
        exit(1);
    }
    return p;
}

void partida_ler(Partida *partida) {
    scanf("%d %d %d %d", &partida->id_time_1, &partida->id_time_2, 
                         &partida->gols_time_1, &partida->gols_time_2);
}

int partida_vencedor(Partida *partida) {
    if (partida->gols_time_1 > partida->gols_time_2)
        return partida->id_time_1;
    else if (partida->gols_time_1 < partida->gols_time_2)
        return partida->id_time_2;    
    return -1;
}

void partida_destruir(Partida *partida) {
    free(partida);
}

int partida_jogou(Partida *partida, int id_time) {
    if (partida->id_time_1 == id_time || partida->id_time_2 == id_time) 
        return 1;
    return 0;
}