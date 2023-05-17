
#include "campeonato.h"

int main() {
    Campeonato *c = campeonato_construir();

    campeonato_ler(c);
    campeonato_mostrar_relatorio(c);
    campeonato_destruir(c);

    return 0;
}