#ifndef RANGE_LIB_H
#define RANGE_LIB_H

#include <iterator> // distance
#include <algorithm> // swap

namespace ir {

    /// Negate all integer values in [first;last).
    void inicializa_matriz(int * matriz, int linhas, int colunas);

    void criar_barco(int * matriz, int linhas, int colunas);

    bool verifica_barco(int * matriz, int linha, int coluna, int tipo_barco);
 

}
#endif
