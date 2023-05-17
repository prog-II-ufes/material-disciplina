
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "partida.h"
#include "campeonato.h"

struct campeonato {
    Time **times;
    Partida **partidas;

    int n_times;
    int n_times_alocados;

    int n_partidas;
    int n_partidas_alocadas;
};

Campeonato *campeonato_construir() {
    Campeonato *c = (Campeonato *)calloc(1, sizeof(Campeonato));

    if (c == NULL) {
        printf("Falta memoria para alocar um campeonato!");
        exit(1);
    }

    c->n_partidas_alocadas = 2;
    c->n_times_alocados = 2;

    c->n_times = 0;    
    c->n_partidas = 0;

    c->times = (Time **)calloc(c->n_times_alocados, sizeof(Time *));
    c->partidas = (Partida **)calloc(c->n_partidas_alocadas, sizeof(Partida *));

    return c;
}

void campeonato_ler(Campeonato *c) {
    
    char tipo;
    
    while (1) {
        scanf("\n%c", &tipo);

        if (tipo == 'T') {
            Time *time = time_construir();
            time_ler(time);

            if (c->n_times == c->n_times_alocados) {
                c->n_times_alocados += 2;
                c->times = (Time **)realloc(c->times, c->n_times_alocados * sizeof(Time *));
                if (c->times == NULL){
                    printf("Realloc falhou alocar um novo time. Verifique se existe memoria disponivel");
                    exit(1);
                }
            }

            c->times[c->n_times] = time;
            c->n_times++;
        } else if (tipo == 'P') {
            Partida *partida = partida_construir();
            partida_ler(partida);

            if (c->n_partidas == c->n_partidas_alocadas) {
                c->n_partidas_alocadas += 2;
                c->partidas = (Partida **)realloc(c->partidas, c->n_partidas_alocadas * sizeof(Partida *));
                if (c->partidas == NULL){
                    printf("Realloc falhou ao alocar uma nova partida. Verifique se existe memoria disponivel");
                    exit(1);
                }
            }

            c->partidas[c->n_partidas] = partida;
            c->n_partidas++;
        }
        else
            break;
    }
}

void campeonato_destruir(Campeonato *c) {
    int i;

    for (i = 0; i < c->n_times; i++)
        time_destruir(c->times[i]);

    for (i = 0; i < c->n_partidas; i++)
        partida_destruir(c->partidas[i]);

    free(c->times);
    free(c->partidas);
    free(c);
}

void campeonato_mostrar_relatorio(Campeonato *c) {
    
    for (int i = 0; i < c->n_times; i++) {
        int pontos = 0;
        for (int j = 0; j < c->n_partidas; j++) {
            int v = partida_vencedor(c->partidas[j]);

            if (v == i)
                pontos += 3;
            else if (v == -1 && partida_jogou(c->partidas[j], i))
                pontos += 1;
        }

        time_mostrar(c->times[i]);
        printf(": %d\n", pontos);
    }
}
