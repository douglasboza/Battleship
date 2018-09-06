
#include "../include/functions.h"
#include <iostream> // cout, endl

namespace ir{

	int barco5(1);
	int barco51(1);
	int barco4(2);
	int barco41(2);
	int barco3(3);
	int barco31(3);
	int barco2(3);
	int barco21(3);
	int barco1(1);

	int total5(1);
	int total4(2);
	int total3(3);
	int total2(3);
	int total1(1);

	int total_barcos = total5 + total4 + total3 + total2 + total1;
	
	void inicializa_matriz(int * matriz, int linhas, int colunas){
	    for (int i = 0; i < linhas; i++) {
	        for (int j = 0; j < colunas; j++) {
	            matriz[i * colunas + j] = 0;
	            // std::cout << matriz[i * colunas + j] << std::endl;
	        }
	    }
	}

    void principal(int * matriz, int linhas, int colunas){
       while(total_barcos > 0){
       		ir::criar_barco(matriz, linhas, colunas);
       }
    }


   	void criar_barco(int * matriz, int linhas, int colunas){
   			// [indice][linha, coluna, barcos,barcos,barcos ]
   		int barcos[]{5, 51, 4, 41, 3, 31, 2, 21, 1};
   		int posicoes_livres[linhas * colunas][10];
   		int cont_posicao(0);
   		int cont_posicao_barco(0);
   		int barcos_livres[8];

   		for (int i = 0; i < linhas; i++) {
	        for (int j = 0; j < colunas; j++) {
	            if( matriz[i * colunas + j] == 0){
	            	    for (auto b(std::begin(barcos)); b != std::end(barcos); ++b){
					    	 cont_posicao_barco = 0;     	
			            	if( ir::verifica_barco(matriz, i, j, barcos[cont_posicao_barco])){
			            		posicoes_livres[cont_posicao][0] = i;
			            		posicoes_livres[cont_posicao][1] = j;
			            		posicoes_livres[cont_posicao][3] = barcos[cont_posicao_barco]; 
			            		cont_posicao++;
			            		cont_posicao_barco++;
			            	}

					    }
					cont_posicao = 0;   
	            } 
	        }
	    }
	}

	bool verifica_barco(int * matriz, int linha, int coluna, int tipo_barco){
		std::cout << "linha "<< linha << " coluna " << coluna << " barco "<< tipo_barco << std::endl;
		return true;
	}

// Funcao VERIFICA_BARCO(linha, coluna, matriz):
//     Verifica quais barcos podem ser colocados na linha x coluna
//     Retorna a lista dos barcos que podem ser colocados, leva em consideração o limite de barcos do tabuleiro.
    

// Função CRIAR_BARCO():
//     Percorre cada posição igual a 0 e verifica se ela pode ser preenchida com algum barco chamando VERIFICA_BARCO
//     Guarda a posição e qual barco pode ser colocado nela
//     Sorteia uma posição que pode ter barcos
//     Sorteia um barco para essa posição
//     Chama PREENCHER_ESPACOS(linha, coluna, nome_barco)
//     Após isso preenche como 1 os espaços do barco


// ----- 5 / no sentido vertical é o 51

// ---- 4 / no sentido vertical é o 41

// ---  3 / no sentido vertical é o 31

// --   2 / no sentido vertical é o 21

// -    1 / no sentido vertical é o 11


}
