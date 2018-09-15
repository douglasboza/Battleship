#include <iostream> // cout, endl
#include <iterator> // begin, end
#include <sstream>  // ostringstream
#include <algorithm> // for_each
#include "../include/functions.h"


int main (int argc, char* const argv[]){
    int opcao;
    int linhas(0);
    int colunas(0);
    int tabuleiros(0);
    // int tabuleiro_jogar(0);

    std::cout << "Gerar tabuleiros: 1" << std::endl;
    std::cout << "Jogar: 2" << std::endl;
    std::cin >> opcao;

    if(opcao == 1){
        std::cout << "Número de linhas? digite pelo menos 10" << std::endl;
        while(linhas < 10){
            std::cin >> linhas;
        }

        std::cout << "Número de colunas? digite pelo menos 10" << std::endl;
        while(colunas < 10){
            std::cin >> colunas;
        }


        std::cout << "Número de tabuleiros? digite pelo menos 1" << std::endl;
        while(tabuleiros == 0){
            std::cin >> tabuleiros;
        }

        bool teste_gerou(true);
        ir::inicializa_matriz(linhas, colunas);

        while(tabuleiros > 0){
            ir::zera_matriz();
            teste_gerou = ir::principal();
            if(teste_gerou == false){
                tabuleiros += 1;
            }else{
                tabuleiros -= 1;
            }
        }
        ir::liberar();
    }else{
        if(opcao == 2){
            std::cout << "Qual o tabuleiro que você deseja jogar?" << std::endl;
            while(tabuleiros == 0){
                std::cin >> tabuleiros;
            }      

            if(ir::carrega_tabuleiro(tabuleiros)){
                ir::iniciar_jogo();
            }

        }
    }






    return EXIT_SUCCESS;
}
