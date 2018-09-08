#ifndef RANGE_LIB_H
#define RANGE_LIB_H

#include <iterator> // distance
#include <algorithm> // swap

namespace ir {

    /// Negate all integer values in [first;last).
    void inicializa_matriz();
    void liberar();

    // void criar_barco(int * matriz, int linhas, int colunas, int * posicoes_livres);

    bool verifica_barco(int linha, int coluna, int tipo_barco);
 	
 	bool principal();

 	void preencher_barco(int linha, int coluna, int tipo_barco);
 	
 	bool verifica_proxima_casa(int linha, int coluna, int casas);

 	bool verifica_anterior_casa(int linha, int coluna, int casas);
 	
 	bool verifica_topo_casa(int linha, int coluna, int casas);

 	bool verifica_inferior_casa(int linha, int coluna, int casas);

 	int verifica_casa_existe(int linha, int coluna);
 	
 	int verifica_casa_vazia(int linha, int coluna);

 	void zera_matriz();


}

#endif
