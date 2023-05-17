
#ifndef _CAMPEONATO_H
#define _CAMPEONATO_H

typedef struct campeonato Campeonato;

Campeonato *campeonato_construir();
void campeonato_ler(Campeonato *c);
void campeonato_destruir(Campeonato *c);
void campeonato_mostrar_relatorio(Campeonato *c);

#endif