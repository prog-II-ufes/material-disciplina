#include <stdio.h>
#include <stdlib.h>
#include "time.h"

struct time {
    char nome[33];
    char estado[3];
};

Time* time_construir() {
    Time *t = (Time *)malloc(sizeof(Time));
    if (t == NULL) {
        printf("Falta memoria para alocar um time!");
        exit(1);
    }
    return t;
}

void time_ler(Time *time) {
    scanf("%s %s\n", time->nome, time->estado);
}

void time_mostrar(Time *time) {
    printf("%s [%s]", time->nome, time->estado);
}

void time_destruir(Time *time) {
    free(time);
}
