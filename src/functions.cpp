
#include "../include/functions.h"
#include <iostream> // cout, endl
#include <fstream> // incluir 

namespace ir{
	//total disponível para cada barco
	int total5(1);
	int total4(2);
	int total3(3);
	int total2(3);
	int total1(1);

	int linhas = 10; // linhas do tabuleiro
	int colunas = 10; // colunas do tabuleiro
	int **matriz; //matriz do tabuleiro

	int total_barcos = total5 + total4 + total3 + total2 + total1;
	int total_barcos_fixo = total_barcos;
	int m_barcos[10][2]; // matriz com os barcos do tabuleiro

	void inicializa_matriz(int l, int c){  // Aloca memória para a matriz do tabuleiro
		linhas = l; // seta linhas do tabuleiro na variável global
    	colunas = c; // seta colunas do tabuleiro na variável global

		matriz = (int**)malloc(linhas * sizeof(int*)); // alocação de meória
		for (int i = 0; i < linhas; i++){	
		    matriz[i] = (int*)malloc(colunas * sizeof(int)); // alocação de meória
		}
	}



	void liberar(){ // aloca memória para a matriz do tabuleiro
	    for(int i = 0; i < linhas; i++)
	        free(matriz[i]);

	    free(matriz);
	}

	void zera_matriz(){ // //reinicia o tabuleiro zerando as posições
		for (int i = 0; i < linhas; i++) {
	        for (int j = 0; j < colunas; j++) {
	            matriz[i][j] = 0; 
	        }
	    }

	    for (int i = 0; i < 10; i++) {
	        for (int j = 0; j < 2; j++) {
	            m_barcos[i][j] = 0; 
	        }
	    }

	    total5 = 1;
		total4 = 2;
		total3 = 3;
		total2 = 3;
		total1 = 1;
		total_barcos = total5 + total4 + total3 + total2 + total1;
		total_barcos_fixo = total_barcos;

	}

	void salvar_barco(){ // Salva o array de barcos no arquivo	
		std::ofstream out;
		out.open("tabuleiros", std::ios::out | std::ios::app ); 

		for (int i = 0; i < total_barcos_fixo; ++i){
	        out << m_barcos[i][0] << " " << m_barcos[i][1] << " " << m_barcos[i][2] << std::endl;
	    }
	    out << " 9999 " << std::endl; //indica o final de um tabuleiro
		out.close();
		  
	}




	// função principal que gera o tabuleiro
	// retorna true, se conseguir gerar um tabuleiro
    bool principal(){
    	int posicoes_livres[linhas * colunas][2]; // matriz que guarda cada coordenada coluna x linha
   		int cont_posicao(0); // Contador para preencher a matriz posições livres
	   	int posicao_aleatoria_casa(0); // Posição aleatória da coordenada da casa
	   	int barco_aleatorio(0); // Posição o barco aleatório
	   	int linha_vez(0); // linha sorteada
	   	int coluna_vez(0); // coluna sorteada
	   	int limite_aleatorio = (linhas * colunas) - 1 ; // Limite de coordenadas possíveis linha x coluna
  		bool teste_posicao_livre(false); // teste para verificar se a coordenada está livre para um barco

  		int barcos[10]; // array com os possíveis barcos
  		int barco_limite(0); // até onde foi preenchido o array barcos
  		


   		for (int i = 0; i < linhas; i++){ // preenche as corrdenadas na matriz posições livres
	        for (int j = 0; j < colunas; j++) {
	            posicoes_livres[cont_posicao][0] = i; // linha
	            posicoes_livres[cont_posicao][1] = j; // coluna
	            cont_posicao++; // próxima posição
	        }
	    }

        
        while(total_barcos > 0){ // enquanto houver barcos isponíveis
			
    
		    while(teste_posicao_livre == false){ // até encontrar uma posicao que seja possível colocar barco
	    		// srand(time(NULL));
		    	if(limite_aleatorio == 0 ){ // Caso 0, significa que todas as posições estão indisponíveis
		    		std::cout << "\n Erro! não conseguiu achar uma solução";
		    		return false;
		    	}

			    posicao_aleatoria_casa = (rand() % (limite_aleatorio)); // gera um número aleatório até a posição limite de corrdenadas
			   	linha_vez = posicoes_livres[posicao_aleatoria_casa][0]; // linha aleatória
			   	coluna_vez = posicoes_livres[posicao_aleatoria_casa][1]; // coluna aleatória
			    
			     // std::cout << "\n linha vez = " << matriz[linha_vez][coluna_vez];

			    if(total5 > 0){ // se ainda há barco com 5 casas
				    if(ir::verifica_barco(linha_vez, coluna_vez, 51) == true){ 
				    	// verifica se o barco 51 pode ser colocado na linha x coluna sorteada
						teste_posicao_livre = true; // encontrou um barco disponível para a posição linha x coluna
						barcos[barco_limite] = 51; // adiciona o barco no array barcos
					 	barco_limite++; // próxima posição dos barcos
				    }

				    if(ir::verifica_barco(linha_vez, coluna_vez, 5) == true){
						teste_posicao_livre = true;
						barcos[barco_limite] = 5;
						barco_limite++;
				    }
				}

			    if(total4 > 0){// se ainda há barco com 4 casas
				    if(ir::verifica_barco(linha_vez, coluna_vez, 41) == true){
						teste_posicao_livre = true;
						barcos[barco_limite] = 41;
						barco_limite++;
				    }

				    if(ir::verifica_barco(linha_vez, coluna_vez, 4) == true){
						teste_posicao_livre = true;
						barcos[barco_limite] = 4;
						barco_limite++;
				    }
				}


			    if(total3 > 0){// se ainda há barco com 3 casas
				    if(ir::verifica_barco(linha_vez, coluna_vez, 31) == true){
						teste_posicao_livre = true;
						barcos[barco_limite] = 31;
						barco_limite++;
				    }
				
				    if(ir::verifica_barco(linha_vez, coluna_vez, 3) == true){
						teste_posicao_livre = true;
						barcos[barco_limite] = 3;
						barco_limite++;
				    }
				}


			    if(total2 > 0){// se ainda há barco com 2 casas
				    if(ir::verifica_barco(linha_vez, coluna_vez, 21) == true){
						teste_posicao_livre = true;
						barcos[barco_limite] = 21;
						barco_limite += 1;
				    }
				
				    if(ir::verifica_barco(linha_vez, coluna_vez, 2) == true){
						teste_posicao_livre = true;
						barcos[barco_limite] = 2;
						barco_limite += 1;
				    }
				}


			    if(total1 > 0){// se ainda há barco com 1 casa
				    if(ir::verifica_barco(linha_vez, coluna_vez, 1) == true){
						teste_posicao_livre = true;
						barcos[barco_limite] = 1;
						barco_limite += 1;
				    }
			    }


			    if(teste_posicao_livre == true){ // Se econtrou pelo menos um barco para linha x coluna
			    	// std::cout << "\n aqui111 = "<< barco_limite << std::endl;

			    	barco_aleatorio = (rand() % (barco_limite)); // Sorteia um número entre 0 e o total de barcos para a posição

			    	// Verifica qual barco foi sorteado para a posição e diminui 1 no total do tipo de barco
			    	if(barcos[barco_aleatorio] == 1)  total1 -= 1;
			    	if(barcos[barco_aleatorio] == 2)  total2 -= 1;
			    	if(barcos[barco_aleatorio] == 21) total2 -= 1;
			    	if(barcos[barco_aleatorio] == 3)  total3 -= 1;
			    	if(barcos[barco_aleatorio] == 31) total3 -= 1;
			    	if(barcos[barco_aleatorio] == 4)  total4 -= 1;
			    	if(barcos[barco_aleatorio] == 41) total4 -= 1;
			    	if(barcos[barco_aleatorio] == 5)  total5 -= 1;
			    	if(barcos[barco_aleatorio] == 51) total5 -= 1;


				   	// std::cout << "\n coluna vez = " << coluna_vez << std::endl;
				    // std::cout << "\n linha vez = " << linha_vez << std::endl;
			    	// std::cout << "\n barco da vez = "<< barcos[barco_aleatorio] << std::endl;

			    	// Preenche na matriz m_matriz cada barco preenchido, para salvar no arquivo, no final
			    	m_barcos[total_barcos][0] = linha_vez; 	
			    	m_barcos[total_barcos][1] = coluna_vez;
			    	m_barcos[total_barcos][2] = barcos[barco_aleatorio];

			    				    		std::cout << "\n aqio" << barco_aleatorio << std::endl;


			    	// preenche a matriz de barcos com o barco encontrado e a posição
			    	preencher_barco(linha_vez, coluna_vez, barcos[barco_aleatorio]); 

			    	total_barcos -= 1; // Menos um barco disponível
			    	
			    	// std::cout << "\n barco1 " << total1<< std::endl;;
			    	// std::cout << "\n barco2 " << total2<< std::endl;;
			    	// std::cout << "\n barco3 " << total3<< std::endl;;
			    	// std::cout << "\n barco4 " << total4<< std::endl;;

			    	// std::cout << "\n linha_vez " << linha_vez;
			    	// std::cout << "\n coluna_vez " << coluna_vez;
			    	// std::cout << "\n total de barcos " << total_barcos;
			    	// std::cout << "\n barco vez " << barcos[barco_aleatorio];
			    	// std::cout << "\n" << std::endl;
			    }else{
			    	// Caso não encontre barco para a linha x coluna do sorteio
			    	// A corrdenada linha x coluna é jogada para o final do array de posições livres
			    	// É retirado 1 de limite_aleatorio para que essa coordenada não entre mais no sorteio

			    	std::swap(* posicoes_livres[posicao_aleatoria_casa], * posicoes_livres[limite_aleatorio]);
			    	limite_aleatorio -= 1;
			    	
			    }
			    barco_limite = 0; // Zera até onde foi preenchido o array de barcos para uma posição qualquer.
		    }

		    teste_posicao_livre = false; // Para iniciar um novo teste
		
		}

        std::cout << "\n" << std::endl;
        for (int i = 0; i < linhas; ++i){
	        for (int j = 0; j < colunas; ++j){
	        	if(matriz[i][j] == 1){
	        		 std::cout << "- ";
	        		}else{
	        			 std::cout << matriz[i][j] << " ";
	        	}
	        }
	        std::cout << "\n" << std::endl;
	    }

	    salvar_barco(); 
	    return true;

    }



	bool verifica_barco(int linha, int coluna, int tipo_barco){ // retorna true se pode colocar o barco
		if(tipo_barco == 1){ // se barco for do tipo 1
			// verifica se a casa está disponível para preenchder o barco
			if(verifica_casa_existe(linha, coluna) == 1) return false; 

			// Verifica se as casas perto não existem ou estão vazias
			if(verifica_casa_vazia(linha + 1, coluna) == 1) return false; // inferior
			if(verifica_casa_vazia(linha - 1, coluna) == 1) return false; // superior
			if(verifica_casa_vazia(linha, coluna + 1) == 1) return false; // direita
			if(verifica_casa_vazia(linha, coluna - 1) == 1) return false; // esquerda

			if(verifica_casa_vazia(linha + 1, coluna + 1) == 1) return false; // diagonal direita inferior
			if(verifica_casa_vazia(linha - 1, coluna + 1) == 1) return false; // diagonal direita superior
			if(verifica_casa_vazia(linha + 1, coluna - 1) == 1) return false; // diagonal esquerda inferior
			if(verifica_casa_vazia(linha - 1, coluna - 1) == 1) return false; // diagonal esquerda superior
		}

		if(tipo_barco == 2){
			if(verifica_casa_existe(linha, coluna) == 1) return false;
			if(verifica_casa_existe(linha, coluna + 1) == 1) return false;

			if(verifica_casa_vazia(linha + 1, coluna) == 1) return false; // casa 1 inferior
			if(verifica_casa_vazia(linha + 1, coluna + 1) == 1) return false; // casa 2 inferior

			if(verifica_casa_vazia(linha - 1, coluna) == 1) return false; // casa 1 supeior
			if(verifica_casa_vazia(linha - 1, coluna + 1) == 1) return false; // casa 2 superior
			

			if(verifica_casa_vazia(linha, coluna - 1) == 1) return false; // esquerda da casa 1
			if(verifica_casa_vazia(linha, coluna + 2) == 1) return false; // direita da casa 2

			if(verifica_casa_vazia(linha + 1, coluna + 2) == 1) return false; // diagonal direita inferior
			if(verifica_casa_vazia(linha - 1, coluna + 2) == 1) return false; // diagonal direita superior
			if(verifica_casa_vazia(linha + 1, coluna - 1) == 1) return false; // diagonal esquerda inferior
			if(verifica_casa_vazia(linha - 1, coluna - 1) == 1) return false; // diagonal esquerda superior
		}

		
		if(tipo_barco == 21){
			if(verifica_casa_existe(linha, coluna) == 1) return false;
			if(verifica_casa_existe(linha + 1, coluna) == 1) return false;

			if(verifica_casa_vazia(linha - 1, coluna) == 1) return false; // casa 1 supeior
			if(verifica_casa_vazia(linha + 2, coluna) == 1) return false; // casa 2 inferior

			if(verifica_casa_vazia(linha, coluna - 1) == 1) return false; // esquerda da casa 1
			if(verifica_casa_vazia(linha + 1, coluna - 1) == 1) return false; // esquerda da casa 2

			if(verifica_casa_vazia(linha, coluna + 1) == 1) return false; // direita da casa 1
			if(verifica_casa_vazia(linha + 1, coluna + 1) == 1) return false; // direita da casa 2

			if(verifica_casa_vazia(linha + 2, coluna + 1) == 1) return false; // diagonal direita inferior
			if(verifica_casa_vazia(linha - 1, coluna + 1) == 1) return false; // diagonal direita superior
			if(verifica_casa_vazia(linha + 2, coluna - 1) == 1) return false; // diagonal esquerda inferior
			if(verifica_casa_vazia(linha - 1, coluna - 1) == 1) return false; // diagonal esquerda superior
		}

		if(tipo_barco == 3){
			if(verifica_casa_existe(linha, coluna) == 1) return false;
			if(verifica_casa_existe(linha, coluna + 1) == 1) return false;
			if(verifica_casa_existe(linha, coluna + 2) == 1) return false;

			if(verifica_casa_vazia(linha + 1, coluna) == 1) return false; // casa 1 inferior
			if(verifica_casa_vazia(linha + 1, coluna + 1) == 1) return false; // casa 2 inferior
			if(verifica_casa_vazia(linha + 1, coluna + 2) == 1) return false; // casa 3 inferior


			if(verifica_casa_vazia(linha - 1, coluna) == 1) return false; // casa 1 superior
			if(verifica_casa_vazia(linha - 1, coluna + 1) == 1) return false; // casa 2 superior
			if(verifica_casa_vazia(linha - 1, coluna + 2) == 1) return false; // casa 3 superior
			

			if(verifica_casa_vazia(linha, coluna - 1) == 1) return false; // esquerda da casa 1
			if(verifica_casa_vazia(linha, coluna + 3) == 1) return false; // direita da casa 2
			


			if(verifica_casa_vazia(linha + 1, coluna + 3) == 1) return false; // diagonal direita inferior
			if(verifica_casa_vazia(linha - 1, coluna + 3) == 1) return false; // diagonal direita superior
			if(verifica_casa_vazia(linha + 1, coluna - 1) == 1) return false; // diagonal esquerda inferior
			if(verifica_casa_vazia(linha - 1, coluna - 1) == 1) return false; // diagonal esquerda superior

		}

		if(tipo_barco == 31){
			if(verifica_casa_existe(linha, coluna) == 1) return false;
			if(verifica_casa_existe(linha + 1, coluna) == 1) return false;
			if(verifica_casa_existe(linha + 2, coluna) == 1) return false;

			if(verifica_casa_vazia(linha - 1, coluna) == 1) return false; // casa 1 supeior
			if(verifica_casa_vazia(linha + 3, coluna) == 1) return false; // casa 3 inferior

			if(verifica_casa_vazia(linha, coluna - 1) == 1) return false; // esquerda da casa 1
			if(verifica_casa_vazia(linha + 1, coluna - 1) == 1) return false; // esquerda da casa 2
			if(verifica_casa_vazia(linha + 2, coluna - 1) == 1) return false; // esquerda da casa 3

			if(verifica_casa_vazia(linha, coluna + 1) == 1) return false; // direita da casa 1
			if(verifica_casa_vazia(linha + 1, coluna + 1) == 1) return false; // direita da casa 2
			if(verifica_casa_vazia(linha + 2, coluna + 1) == 1) return false; // direita da casa 3
			
			if(verifica_casa_vazia(linha + 3, coluna + 1) == 1) return false; // diagonal direita inferior
			if(verifica_casa_vazia(linha - 1, coluna + 1) == 1) return false; // diagonal direita superior
			if(verifica_casa_vazia(linha + 3, coluna - 1) == 1) return false; // diagonal esquerda inferior
			if(verifica_casa_vazia(linha - 1, coluna - 1) == 1) return false; // diagonal esquerda superior
		}


		if(tipo_barco == 4){
			if(verifica_casa_existe(linha, coluna) == 1) return false;
			if(verifica_casa_existe(linha, coluna + 1) == 1) return false;
			if(verifica_casa_existe(linha, coluna + 2) == 1) return false;
			if(verifica_casa_existe(linha, coluna + 3) == 1) return false;

			if(verifica_casa_vazia(linha + 1, coluna) == 1) return false; // casa 1 inferior
			if(verifica_casa_vazia(linha + 1, coluna + 1) == 1) return false; // casa 2 inferior
			if(verifica_casa_vazia(linha + 1, coluna + 2) == 1) return false; // casa 3 inferior
			if(verifica_casa_vazia(linha + 1, coluna + 3) == 1) return false; // casa 4 inferior


			if(verifica_casa_vazia(linha - 1, coluna) == 1) return false; // casa 1 superior
			if(verifica_casa_vazia(linha - 1, coluna + 1) == 1) return false; // casa 2 superior
			if(verifica_casa_vazia(linha - 1, coluna + 2) == 1) return false; // casa 3 superior
			if(verifica_casa_vazia(linha - 1, coluna + 3) == 1) return false; // casa 3 superior
			

			if(verifica_casa_vazia(linha, coluna - 1) == 1) return false; // esquerda da casa 1
			if(verifica_casa_vazia(linha, coluna + 4) == 1) return false; // direita da casa 4
			


			if(verifica_casa_vazia(linha + 1, coluna + 4) == 1) return false; // diagonal direita inferior
			if(verifica_casa_vazia(linha - 1, coluna + 4) == 1) return false; // diagonal direita superior
			if(verifica_casa_vazia(linha + 1, coluna - 1) == 1) return false; // diagonal esquerda inferior
			if(verifica_casa_vazia(linha - 1, coluna - 1) == 1) return false; // diagonal esquerda superior

		}

		if(tipo_barco == 41){
			if(verifica_casa_existe(linha, coluna) == 1) return false;
			if(verifica_casa_existe(linha + 1, coluna) == 1) return false;
			if(verifica_casa_existe(linha + 2, coluna) == 1) return false;
			if(verifica_casa_existe(linha + 3, coluna) == 1) return false;

			if(verifica_casa_vazia(linha - 1, coluna) == 1) return false; // casa 1 supeior
			if(verifica_casa_vazia(linha + 4, coluna) == 1) return false; // casa 3 inferior

			if(verifica_casa_vazia(linha, coluna - 1) == 1) return false; // esquerda da casa 1
			if(verifica_casa_vazia(linha + 1, coluna - 1) == 1) return false; // esquerda da casa 2
			if(verifica_casa_vazia(linha + 2, coluna - 1) == 1) return false; // esquerda da casa 3
			if(verifica_casa_vazia(linha + 3, coluna - 1) == 1) return false; // esquerda da casa 4

			if(verifica_casa_vazia(linha, coluna + 1) == 1) return false; // direita da casa 1
			if(verifica_casa_vazia(linha + 1, coluna + 1) == 1) return false; // direita da casa 2
			if(verifica_casa_vazia(linha + 2, coluna + 1) == 1) return false; // direita da casa 3
			if(verifica_casa_vazia(linha + 3, coluna + 1) == 1) return false; // direita da casa 4
			
			if(verifica_casa_vazia(linha + 4, coluna + 1) == 1) return false; // diagonal direita inferior
			if(verifica_casa_vazia(linha - 1, coluna + 1) == 1) return false; // diagonal direita superior
			if(verifica_casa_vazia(linha + 4, coluna - 1) == 1) return false; // diagonal esquerda inferior
			if(verifica_casa_vazia(linha - 1, coluna - 1) == 1) return false; // diagonal esquerda superior
		}

		if(tipo_barco == 51){
			if(verifica_casa_existe(linha, coluna) == 1) return false;
			if(verifica_casa_existe(linha + 1, coluna) == 1) return false;
			if(verifica_casa_existe(linha + 2, coluna) == 1) return false;
			if(verifica_casa_existe(linha + 3, coluna) == 1) return false;
			if(verifica_casa_existe(linha + 4, coluna) == 1) return false;

			if(verifica_casa_vazia(linha - 1, coluna) == 1) return false; // casa 1 supeior
			if(verifica_casa_vazia(linha + 5, coluna) == 1) return false; // casa 5 inferior

			if(verifica_casa_vazia(linha, coluna - 1) == 1) return false; // esquerda da casa 1
			if(verifica_casa_vazia(linha + 1, coluna - 1) == 1) return false; // esquerda da casa 2
			if(verifica_casa_vazia(linha + 2, coluna - 1) == 1) return false; // esquerda da casa 3
			if(verifica_casa_vazia(linha + 3, coluna - 1) == 1) return false; // esquerda da casa 4
			if(verifica_casa_vazia(linha + 4, coluna - 1) == 1) return false; // esquerda da casa 5

			if(verifica_casa_vazia(linha, coluna + 1) == 1) return false; // direita da casa 1
			if(verifica_casa_vazia(linha + 1, coluna + 1) == 1) return false; // direita da casa 2
			if(verifica_casa_vazia(linha + 2, coluna + 1) == 1) return false; // direita da casa 3
			if(verifica_casa_vazia(linha + 3, coluna + 1) == 1) return false; // direita da casa 4
			if(verifica_casa_vazia(linha + 4, coluna + 1) == 1) return false; // direita da casa 5
			
			if(verifica_casa_vazia(linha + 5, coluna + 1) == 1) return false; // diagonal direita inferior
			if(verifica_casa_vazia(linha - 1, coluna + 1) == 1) return false; // diagonal direita superior
			if(verifica_casa_vazia(linha + 5, coluna - 1) == 1) return false; // diagonal esquerda inferior
			if(verifica_casa_vazia(linha - 1, coluna - 1) == 1) return false; // diagonal esquerda superior
		}

		

		if(tipo_barco == 5){
			if(verifica_casa_existe(linha, coluna) == 1) return false;
			if(verifica_casa_existe(linha, coluna + 1) == 1) return false;
			if(verifica_casa_existe(linha, coluna + 2) == 1) return false;
			if(verifica_casa_existe(linha, coluna + 3) == 1) return false;
			if(verifica_casa_existe(linha, coluna + 4) == 1) return false;

			if(verifica_casa_vazia(linha + 1, coluna) == 1) return false; // casa 1 inferior
			if(verifica_casa_vazia(linha + 1, coluna + 1) == 1) return false; // casa 2 inferior
			if(verifica_casa_vazia(linha + 1, coluna + 2) == 1) return false; // casa 3 inferior
			if(verifica_casa_vazia(linha + 1, coluna + 3) == 1) return false; // casa 4 inferior
			if(verifica_casa_vazia(linha + 1, coluna + 4) == 1) return false; // casa 5 inferior


			if(verifica_casa_vazia(linha - 1, coluna) == 1) return false; // casa 1 superior
			if(verifica_casa_vazia(linha - 1, coluna + 1) == 1) return false; // casa 2 superior
			if(verifica_casa_vazia(linha - 1, coluna + 2) == 1) return false; // casa 3 superior
			if(verifica_casa_vazia(linha - 1, coluna + 3) == 1) return false; // casa 3 superior
			if(verifica_casa_vazia(linha - 1, coluna + 4) == 1) return false; // casa 3 superior	

			if(verifica_casa_vazia(linha, coluna - 1) == 1) return false; // esquerda da casa 1
			if(verifica_casa_vazia(linha, coluna + 5) == 1) return false; // direita da casa 5
			


			if(verifica_casa_vazia(linha + 1, coluna + 5) == 1) return false; // diagonal direita inferior
			if(verifica_casa_vazia(linha - 1, coluna + 5) == 1) return false; // diagonal direita superior
			if(verifica_casa_vazia(linha + 1, coluna - 1) == 1) return false; // diagonal esquerda inferior
			if(verifica_casa_vazia(linha - 1, coluna - 1) == 1) return false; // diagonal esquerda superior

		}

		return true; // O barco está disponível, pois passou em todos os testes
	}

	int verifica_casa_vazia(int linha, int coluna){ // verifica se a coordenada linha x coluna está vazia e existe
		if((linha < linhas) && (coluna < colunas) && (linha >= 0) && (coluna >= 0)){ 
			if(matriz[linha][coluna] == 1){
				return 1; // 1 se está preenchida
			}
		}
		return 0; // 0 se tá livre ou não existe
	}

	int verifica_casa_existe(int linha, int coluna){  // verifica se a coordenada linha x coluna existe e se está livre
		if((linha < linhas) && (coluna < colunas) && (linha >= 0) && (coluna >= 0)){ 
			if(matriz[linha][coluna] == 1){
				return 1; // retorna 1 se está ocupada
			}else{
				return 0; // retorna 0 existe e está livre
			}
		}
		return 1; // 1 se não existe
	}
	

	// Preenche as casas do barco
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

		if(tipo_barco == 3){
			matriz[linha][coluna] = 1;
			matriz[linha][coluna + 1]  = 1;
			matriz[linha][coluna + 2]  = 1;
		}

		if(tipo_barco == 31){
			matriz[linha][coluna] = 1;
			matriz[linha + 1][coluna] = 1;
			matriz[linha + 2][coluna] = 1;
		}

		if(tipo_barco == 4){
			matriz[linha][coluna] = 1;
			matriz[linha][coluna + 1]  = 1;
			matriz[linha][coluna + 2]  = 1;
			matriz[linha][coluna + 3]  = 1;
		}

		if(tipo_barco == 41){
			matriz[linha][coluna] = 1;
			matriz[linha + 1][coluna] = 1;
			matriz[linha + 2][coluna] = 1;
			matriz[linha + 3][coluna] = 1;
		}

		if(tipo_barco == 5){
			matriz[linha][coluna] = 1;
			matriz[linha][coluna + 1]  = 1;
			matriz[linha][coluna + 2]  = 1;
			matriz[linha][coluna + 3]  = 1;
			matriz[linha][coluna + 4]  = 1;
		}

		if(tipo_barco == 51){
			matriz[linha][coluna] = 1;
			matriz[linha + 1][coluna] = 1;
			matriz[linha + 2][coluna] = 1;
			matriz[linha + 3][coluna] = 1;
			matriz[linha + 4][coluna] = 1;
		}


	
	}

}
