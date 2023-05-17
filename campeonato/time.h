
#ifndef _TIME_H
#define _TIME_H

typedef struct time Time;

Time* time_construir();
void time_ler(Time *time);
void time_mostrar(Time *time);
void time_destruir(Time *time);

#endif