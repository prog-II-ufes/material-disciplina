#ifndef _PARTIDA_H
#define _PARTIDA_H

typedef struct partida Partida;

Partida *partida_construir();
void partida_ler(Partida *partida);
int partida_vencedor(Partida *partida);
int partida_jogou(Partida *partida, int id_time);
void partida_destruir(Partida *partida);

#endif