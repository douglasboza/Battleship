
#include "../include/functions.h"
#include <iostream> // cout, endl
#include <fstream> // incluir 

namespace ir{

	// int barco5(1);
	// int barco51(1);
	// int barco4(2);
	// int barco41(2);
	// int barco3(3);
	// int barco31(3);
	// int barco2(3);
	// int barco21(3);
	// int barco1(1);

	int total5(1);
	int total4(2);
	int total3(3);
	int total2(3);
	int total1(1);

	int linhas = 10;
	int colunas = 10;
	int **matriz;

	int total_barcos = total5 + total4 + total3 + total2 + total1;
	int total_barcos_fixo = total_barcos;
	int m_barcos[10][2]; // matriz com os barcos do tabuleiro

	void liberar(){
	    for(int i = 0; i < linhas; i++)
	        free(matriz[i]);

	    free(matriz);
	}

	void zera_matriz(){
		for (int i = 0; i < linhas; i++) {
	        for (int j = 0; j < colunas; j++) {
	            matriz[i][j] = 0;
	        }
	    }
	}

	void salvar_barco(){		
		std::ofstream out;
		out.open("tabuleiros", std::ios::out | std::ios::app ); 

		for (int i = 0; i < total_barcos_fixo; ++i){
	        out << m_barcos[i][0] << " " << m_barcos[i][1] << " " << m_barcos[i][2] << std::endl;
	    }
	    out << " 9999 " << std::endl;
		out.close();
		  
	}

	void inicializa_matriz(){
		matriz = (int**)malloc(linhas * sizeof(int*));
		for (int i = 0; i < linhas; i++){	
		    matriz[i] = (int*)malloc(colunas * sizeof(int));
		}
	}




    bool principal(int l, int c){
    	linhas = l;
    	colunas = c;

    	int posicoes_livres[linhas * colunas][2];
    	int limite_posicao_livre(0);
   		int cont_posicao(0);
	   	int posicao_aleatoria_casa(0);
	   	int barco_aleatorio(0);
	   	int linha_vez(0);
	   	int limite_aleatorio = (linhas * colunas) - 1 ;
	   	int coluna_vez(0);
  		bool teste_posicao_livre(false);

  		int barcos[10];
  		int barco_limite(0);

		
   		
   		// int cont_posicao_barco(0);
   		// int barcos_livres[8];


   		for (int i = 0; i < linhas; i++){
	        for (int j = 0; j < colunas; j++) {
	            posicoes_livres[cont_posicao][0] = i;
	            posicoes_livres[cont_posicao][1] = j;
	            cont_posicao++;
	        }
	    }

		srand(time(NULL));
        
        while(total_barcos > 0){ // enquanto houver barcos
    
				std::cout << "\n aqui --- = " << linha_vez;

		    while(teste_posicao_livre == false){ // até encontrar uma posicao que seja possível colocar barco
		    	
		    	if(limite_aleatorio == 0 ){
		    		std::cout << "\n Erro! não conseguiu achar uma solução";
		    		return false;
		    		// exit(0);
		    	}

		    	std::cout << "\n limite aleatorio = " << limite_aleatorio;
		    	std::cout << "\n  total_barcos = " << total_barcos;

			    posicao_aleatoria_casa = (rand() % (limite_aleatorio));
			   	linha_vez = posicoes_livres[posicao_aleatoria_casa][0];
			   	coluna_vez = posicoes_livres[posicao_aleatoria_casa][1];
			    
			     // std::cout << "\n linha vez = " << matriz[linha_vez][coluna_vez];

			    if(total5 > 0){
				    if(ir::verifica_barco(linha_vez, coluna_vez, 51) == true){
						teste_posicao_livre = true;
						barcos[barco_limite] = 51;
					 	barco_limite++;
				    }

				    if(ir::verifica_barco(linha_vez, coluna_vez, 5) == true){
						teste_posicao_livre = true;
						barcos[barco_limite] = 5;
						barco_limite++;
				    }
				}

			    if(total4 > 0){
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


			    if(total3 > 0){
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


			    if(total2 > 0){
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

				std::cout << "\n aqui222 = " << linha_vez;

			    if(total1 > 0){
				    if(ir::verifica_barco(linha_vez, coluna_vez, 1) == true){
						teste_posicao_livre = true;
						barcos[barco_limite] = 1;
						barco_limite += 1;
				    }
			    }


			     
				std::cout << "\n aqui9999 = " << std::endl;

			    	std::cout << "\n aquierror = " << std::endl;

			    if(teste_posicao_livre == true){
			    	std::cout << "\n aqui111 = "<< barco_limite << std::endl;

			    	barco_aleatorio = (rand() % (barco_limite));	


			    	if(barcos[barco_aleatorio] == 1)  total1 -= 1;
			    	if(barcos[barco_aleatorio] == 2)  total2 -= 1;
			    	if(barcos[barco_aleatorio] == 21) total2 -= 1;
			    	if(barcos[barco_aleatorio] == 3)  total3 -= 1;
			    	if(barcos[barco_aleatorio] == 31) total3 -= 1;
			    	if(barcos[barco_aleatorio] == 4)  total4 -= 1;
			    	if(barcos[barco_aleatorio] == 41) total4 -= 1;
			    	if(barcos[barco_aleatorio] == 5)  total5 -= 1;
			    	if(barcos[barco_aleatorio] == 51) total5 -= 1;


				   	std::cout << "\n coluna vez = " << coluna_vez << std::endl;
				    std::cout << "\n linha vez = " << linha_vez << std::endl;
			    	std::cout << "\n barco da vez = "<< barcos[barco_aleatorio] << std::endl;

			    	
			    	m_barcos[total_barcos][0] = linha_vez;
			    	m_barcos[total_barcos][1] = coluna_vez;
			    	m_barcos[total_barcos][2] = barcos[barco_aleatorio];

			    	preencher_barco(linha_vez, coluna_vez, barcos[barco_aleatorio]);

			    	total_barcos -= 1;
			    	
			    	std::cout << "\n barco1 " << total1<< std::endl;;
			    	std::cout << "\n barco2 " << total2<< std::endl;;
			    	std::cout << "\n barco3 " << total3<< std::endl;;
			    	std::cout << "\n barco4 " << total4<< std::endl;;

			    	// std::cout << "\n linha_vez " << linha_vez;
			    	// std::cout << "\n coluna_vez " << coluna_vez;
			    	// std::cout << "\n total de barcos " << total_barcos;
			    	// std::cout << "\n barco vez " << barcos[barco_aleatorio];
			    	std::cout << "\n" << std::endl;
			    }else{

			    	std::cout << "\n aquierroasdr = " << std::endl;;

			    	std::swap(* posicoes_livres[posicao_aleatoria_casa], * posicoes_livres[limite_aleatorio]);
			    	limite_aleatorio -= 1;
			    	std::cout << "\n aquierror = " << linha_vez << std::endl;;

			    }
			    barco_limite = 0;


			    for (int i = 0; i < 10; ++i){
			        for (int j = 0; j < 10; ++j){
			            if(matriz[i][j] == 1){
			        			std::cout << "- ";
			        		}else{
			        			std::cout << matriz[i][j] << " ";
			        	}
			        }
			        std::cout << "\n" << std::endl;
			    }
			        std::cout << "\n\n" << std::endl;

		    }

		    teste_posicao_livre = false;

		    

       		// ir::criar_barco(matriz, linhas, colunas, posicoes_livres);
        }

        std::cout << "\n" << std::endl;
        for (int i = 0; i < 10; ++i){
	        for (int j = 0; j < 10; ++j){
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
		bool verifica_proxima(true);
		bool verifica_anterior(true);


    	 std::cout << " nova verificação de barco \n\n\n\n\n" << std::endl;

		if(tipo_barco == 1){
			if(verifica_casa_existe(linha, coluna) == 1) return false;

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
			std::cout << "teste inicio" << std::endl;
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

			std::cout << "teste fim" << std::endl;
		}

		
		if(tipo_barco == 21){
			std::cout << "teste inicio" << std::endl;
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
			std::cout << "teste fim" << std::endl; 	
		}

		if(tipo_barco == 3){
			std::cout << "teste inicio" << std::endl;
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


			std::cout << "teste fim" << std::endl;

		}

		if(tipo_barco == 31){
			std::cout << "teste inicio" << std::endl;
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

			std::cout << "teste fim" << std::endl; 	
		}


		if(tipo_barco == 4){
			std::cout << "teste inicio" << std::endl;
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


			std::cout << "teste fim" << std::endl;

		}

		if(tipo_barco == 41){
			std::cout << "teste inicio" << std::endl;
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

			std::cout << "teste fim" << std::endl; 	
		}

		if(tipo_barco == 51){
			std::cout << "teste inicio" << std::endl;
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

			std::cout << "teste fim" << std::endl; 	
		}

		

		if(tipo_barco == 5){
			std::cout << "teste inicio" << std::endl;
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


			std::cout << "teste fim" << std::endl;

		}

		// std::cout << " fim da nova verificação de barco \n\n\n\n\n" << std::endl;

		// if(tipo_barco == 3){
		// 	if(verifica_proxima_casa(linha, coluna, 3) == false){ // final da linha
		// 		return false;
		// 	}
		// 	if(verifica_anterior_casa(linha, coluna, 3) == false){
		// 		return false;
		// 	}
		// 	if(verifica_topo_casa(linha, coluna, 3) == false){
		// 		return false;
		// 	}

		// 	if(verifica_inferior_casa(linha + 1, coluna, 3) == false) return false;

		// 	if(verifica_inferior_casa(linha, coluna, 3) == false) return false;

		// }
		

		// if(tipo_barco == 31){
		// 	if(verifica_proxima_casa(linha, coluna, 1) == false) return false;
			
		// 	if(verifica_proxima_casa(linha + 1, coluna, 1) == false) return false;

		// 	if(verifica_proxima_casa(linha + 2, coluna, 1) == false) return false;
			
		// 	if(verifica_anterior_casa(linha, coluna, 1) == false) return false;
			
		// 	if(verifica_anterior_casa(linha + 1, coluna, 1) == false) return false;

		// 	if(verifica_anterior_casa(linha + 2, coluna, 1) == false) return false;
			
		// 	if(verifica_topo_casa(linha, coluna, 1) == false) return false;
			
		// 	if(verifica_inferior_casa(linha + 3, coluna, 1) == false) return false;
			
		// }




		return true;
	}

	int verifica_casa_vazia(int linha, int coluna){
		std::cout << coluna << " verifica casa vazia \n " << std::endl;
		std::cout << linha << " linha " << std::endl;
		std::cout << coluna << " coluna \n " << std::endl;

		if((linha < linhas) && (coluna < colunas) && (linha >= 0) && (coluna >= 0)){ 
			if(matriz[linha][coluna] == 1){
				return 1; // 1 se está preenchida
			}
		}
		return 0; // 0 se tá livre 
	}

	int verifica_casa_existe(int linha, int coluna){
		std::cout << coluna << " verifica casa exite \n " << std::endl;
		std::cout << linha << " verifica casa exite \n " << std::endl;

		if((linha < linhas) && (coluna < colunas) && (linha >= 0) && (coluna >= 0)){ 
			if(matriz[linha][coluna] == 1){
				return 1;
			}else{
				return 0;
			}
		}
		return 1; // 1 se não existe
	}
	
	// bool verifica_anterior_casa(int linha, int coluna, int casas){ // retorna true se a próxima casa estiver ocupada
	// 	if(coluna == 0 ){
	// 		return true;
	// 	}else{
	// 		for (int j = 0; j < casas; ++j){
	// 			if(matriz[linha + j][coluna] == 1){
	// 				return false;
	// 			}
	// 		}
	// 	}
	// 	return true;
	// }

	// bool verifica_proxima_casa(int linha, int coluna, int casas){ // retorna true se a próxima casa estiver ocupada
	// 	if((coluna + casas) < colunas){
	// 		for(int j = 0; j <= casas; ++j){
				
				
	// 			// std::cout << matriz[linha][coluna + j] << " verificado " << std::endl;
	// 			// std::cout << linha << " linha " << std::endl;
	// 			// std::cout << coluna+j << " coluna \n " << std::endl;

	// 			if(matriz[linha][coluna + j] == 1){
	// 				return false;
	// 			}
	// 		}
	// 	}else{
	// 		return false;
	// 	}
	// 	return true;
	// }

	// bool verifica_topo_casa(int linha, int coluna, int casas){ // retorna true se a próxima casa estiver ocupada
	// 	if(linha != 0){
	// 		for (int j = 0; j <= casas; ++j){
	// 			if(matriz[linha - 1][coluna + j] == 1){
	// 				return false;
	// 			}
	// 		}
	// 	}
	// 	return true;
	// }

	// bool verifica_inferior_casa(int linha, int coluna, int casas){ // retorna true se a próxima casa estiver ocupada
	// 	if(linha != linhas){
	// 		for (int j = 0; j <= casas; ++j){
				

	// 			std::cout << matriz[linha][coluna + j] << " verificado " << std::endl;
	// 			std::cout << linha << " linha " << std::endl;
	// 			std::cout << coluna+j << " coluna \n " << std::endl;

	// 			if(matriz[linha][coluna + j] == 1){
	// 				return false;
	// 			}
	// 		}
	// 	}
	// 	return true;
	// }

	// bool verifica_superior_casa(int linha, int coluna, int casas){ // retorna true se a próxima casa estiver ocupada
	// 	if(coluna != 0){
	// 		for (int j = 0; j <= casas; ++j){
	// 			if(matriz[linha - 1][coluna + j] == 1){
	// 				return false;
	// 			}
	// 		}
	// 	}
	// 	return true;
	// }


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


		// if(tipo_barco == 31){
		// 	matriz[linha][coluna] = 1;
		// 	matriz[linha + 1][coluna] = 1;
		// 	matriz[linha + 2][coluna] = 1;
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
