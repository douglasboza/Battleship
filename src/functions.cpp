
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

	int linhas = 10;
	int colunas = 10;
	int matriz[10][10];

	int total_barcos = total5 + total4 + total3 + total2 + total1;
	
	void inicializa_matriz(){
	    for (int i = 0; i < linhas; i++) {
	        for (int j = 0; j < colunas; j++) {
	            matriz[i][j] = 0;
	            // std::cout << matriz[i * colunas + j] << std::endl;
	        }
	    }
	}




    void principal(){
    	int posicoes_livres[linhas * colunas][2];
    	int limite_posicao_livre(0);
   		int cont_posicao(0);
	   	int posicao_aleatoria_casa(0);
	   	int barco_aleatorio(0);
	   	int linha_vez(0);
	   	int limite_aleatorio = linhas * colunas;
	   	int coluna_vez(0);
  		bool teste_posicao_livre(false);

  		int barcos[10];
  		int barco_limite(0);

		srand(time(NULL));
   		
   		// int cont_posicao_barco(0);
   		// int barcos_livres[8];


   		for (int i = 0; i < linhas; i++){
	        for (int j = 0; j < colunas; j++) {
	            posicoes_livres[cont_posicao][0] = i;
	            posicoes_livres[cont_posicao][1] = j;
	            cont_posicao++;
	        }
	    }

	    posicoes_livres[0][0] = 4;
	    posicoes_livres[0][1] = 5;
	    posicoes_livres[1][0] = 6;
	    posicoes_livres[1][1] = 7;

        while(total_barcos > 0){ // enquanto houver barcos
    
		    while(teste_posicao_livre == false){ // até encontrar uma posicao que seja possível colocar barco
			    posicao_aleatoria_casa = (rand() % (limite_aleatorio));
			   	linha_vez = posicoes_livres[posicao_aleatoria_casa][0];
			   	coluna_vez = posicoes_livres[posicao_aleatoria_casa][1];
			    
			  //   if(ir::verifica_barco(linha_vez, coluna_vez, 51) == true){
					// teste_posicao_livre = true;
					// barcos[barco_limite] = 51;
				 // 	barco_limite++;
			  //   }

			  //   if(ir::verifica_barco(linha_vez, coluna_vez, 5) == true){
					// teste_posicao_livre = true;
					// barcos[barco_limite] = 5;
					// barco_limite++;
			  //   }

			  //   if(ir::verifica_barco(linha_vez, coluna_vez, 41) == true){
					// teste_posicao_livre = true;
					// barcos[barco_limite] = 41;
					// barco_limite++;
			  //   }

			  //   if(ir::verifica_barco(linha_vez, coluna_vez, 4) == true){
					// teste_posicao_livre = true;
					// barcos[barco_limite] = 4;
					// barco_limite++;
			  //   }

			  //   if(ir::verifica_barco(linha_vez, coluna_vez, 31) == true){
					// teste_posicao_livre = true;
					// barcos[barco_limite] = 31;
					// barco_limite++;
			  //   }

			  //   if(ir::verifica_barco(linha_vez, coluna_vez, 3) == true){
					// teste_posicao_livre = true;
					// barcos[barco_limite] = 3;
					// barco_limite++;
			  //   }

			    if(ir::verifica_barco(linha_vez, coluna_vez, 21) == true){
					teste_posicao_livre = true;
					barcos[barco_limite] = 21;
					barco_limite++;
			    }

			    if(ir::verifica_barco(linha_vez, coluna_vez, 2) == true){
					teste_posicao_livre = true;
					barcos[barco_limite] = 2;
					barco_limite++;
			    }

			    if(ir::verifica_barco(linha_vez, coluna_vez, 1) == true){
					teste_posicao_livre = true;
					barcos[barco_limite] = 1;
					barco_limite++;
			    }


			    if(teste_posicao_livre == true){
			    	barco_aleatorio = (rand() % (barco_limite));			    	
			    	preencher_barco(linha_vez, coluna_vez, barcos[barco_aleatorio]);
			    	total_barcos-=1;
			    }else{
			    	std::swap(* posicoes_livres[posicao_aleatoria_casa], * posicoes_livres[limite_aleatorio]);
			    	limite_aleatorio -= 1;
			    }
			    barco_limite = 0;


			    for (int i = 0; i < 10; ++i){
			        for (int j = 0; j < 10; ++j){
			            std::cout << matriz[i][j] << " ";
			        }
			        std::cout << "\n" << std::endl;
			    }
			        std::cout << "\n\n" << std::endl;

		    }

		    teste_posicao_livre = false;

		    

       		// ir::criar_barco(matriz, linhas, colunas, posicoes_livres);
        }


        for (int i = 0; i < 10; ++i){
	        for (int j = 0; j < 10; ++j){
	            std::cout << matriz[i][j] << " ";
	        }
	        std::cout << "\n" << std::endl;
	    }



    }



	bool verifica_barco(int linha, int coluna, int tipo_barco){
		bool verifica_proxima(true);
		bool verifica_anterior(true);

		if(matriz[linha][coluna] == 1){
			return false; // caso base para estar ocupado a casa
		}

		if(tipo_barco == 1){
			if(verifica_proxima_casa(linha, coluna, 1)){
				return false;
			}
			if(verifica_anterior_casa(linha, coluna, 1)){
				return false;
			}
			if(verifica_topo_casa(linha, coluna, 1)){
				return false;
			}
			if(verifica_inferior_casa(linha, coluna, 1)){
				return false;
			}
		
		}

		if(tipo_barco == 2){
			// std::cout << "\n\n\n\n" << std::endl;
			// std::cout << linha << std::endl;
			// std::cout << coluna << std::endl;
			if(verifica_proxima_casa(linha, coluna, 2)){ // final da linha
				return false;
			}
			if(verifica_anterior_casa(linha, coluna, 2)){
				return false;
			}
			if(verifica_topo_casa(linha, coluna, 2)){
				return false;
			}
			if(verifica_inferior_casa(linha, coluna, 2)){
				return false;
			}
		}

		return true;
	}
	
	bool verifica_anterior_casa(int linha, int coluna, int casas){ // retorna true se a próxima casa estiver ocupada
		if(coluna == 0 ){
			return false;
		}else{
			for (int j = 0; j < casas; ++j){
				if(matriz[linha + j][coluna - 1] == 1){
					return true;
				}
			}
		}

		return false;
		
	}

	bool verifica_proxima_casa(int linha, int coluna, int casas){ // retorna true se a próxima casa estiver ocupada
		if((coluna + casas) < colunas){
			for(int j = 0; j <= casas; ++j){
				
				
				std::cout << matriz[linha][coluna + j] << " verificado " << std::endl;
				std::cout << linha << " linha " << std::endl;
				std::cout << coluna << " coluna \n " << std::endl;

				if(matriz[linha][coluna + j] == 1){
					return true;
				}
			}
		}else{
			return true;
		}
		return false;
	}

	bool verifica_topo_casa(int linha, int coluna, int casas){ // retorna true se a próxima casa estiver ocupada
		if(linha != 0){
			for (int j = 0; j <= casas; ++j){
				if(matriz[linha - 1][coluna + j] == 1){
					return true;
				}
			}
		}
		return false;
	}

	bool verifica_inferior_casa(int linha, int coluna, int casas){ // retorna true se a próxima casa estiver ocupada
		if(coluna != colunas){
			for (int j = 0; j <= casas; ++j){
				if(matriz[linha + 1][coluna + j] == 1){
					return true;
				}
			}
		}
		return false;
	}

	bool verifica_superior_casa(int linha, int coluna, int casas){ // retorna true se a próxima casa estiver ocupada
		if(coluna != 0){
			for (int j = 0; j <= casas; ++j){
				if(matriz[linha - 1][coluna + j] == 1){
					return true;
				}
			}
		}
		return false;
	}


	void preencher_barco(int linha, int coluna, int tipo_barco){
		if(tipo_barco == 1){
			matriz[linha][coluna] = 1;
		}

		if(tipo_barco == 2){
			matriz[linha][coluna] = 1;
			matriz[linha][coluna + 1]  = 1;
		}

		if(tipo_barco == 21){
			matriz[linha][coluna] = 1;
			matriz[linha + 1][coluna] = 1;
		}

		// if(tipo_barco == 21){
		// 	matriz[linha][coluna] = 1;
		// 	matriz[linha + 1][coluna] = 1;
		// }

	}

// Função PREENCHER_ESPACOS(linha, coluna, nome_barco){
//     Preenche como 2 os espaços ao lado de linha x coluna   
//     Deve levar em consideração o tipo de barco
//     ex: PREENCHER_ESPACOS(0, 2, matriz)
//         PREENCHER_ESPACOS(4, 4, matriz)

//             0  1  2  3  4  5  6

//         0    0, 2, 1, 2, 0, 0, 0
//         1    2, 2, 2, 2, 0, 0, 0
//         2    0, 0, 0, 0, 0, 0, 0
//         3    0, 0, 0, 0, 2, 0, 0
//         4    0, 0, 0, 2, 1, 2, 0
//         5    0, 0, 0, 0, 2, 0, 0
//         6    0, 0, 0, 0, 0, 0, 0

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
