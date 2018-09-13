#ifndef RANGE_LIB_H
#define RANGE_LIB_H

#include <iterator> // distance
#include <algorithm> // swap

namespace ir {

    // Aloca memória para a matriz do tabuleiro
    void inicializa_matriz(int linhas, int colunas);

    //libera a memória da matriz do tabuleiro
    void liberar();

    //verifica se um barco pode ser colocado em uma casa
    bool verifica_barco(int linha, int coluna, int tipo_barco);
 	
 	//função principal que gera o tabuleiro
 	bool principal();

 	//preenche o barco no tabuleiro
 	void preencher_barco(int linha, int coluna, int tipo_barco);
 	
 	//verifica se linha x coluna existe no tabuleiro
 	int verifica_casa_existe(int linha, int coluna);
 	
 	//verifica se as casas perto do linha x coluna estão vazias
 	int verifica_casa_vazia(int linha, int coluna);

 	//reinicia o tabuleiro
 	void zera_matriz();

 	//salva o tabuleiro no arquivo
 	void salvar_barco();

}

#endif
