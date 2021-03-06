#include <iostream> // cout, endl
#include <iterator> // begin, end
#include <sstream>  // ostringstream
#include <algorithm> // for_each
#include "../include/functions.h"

// Componentes:
// Douglas Pinheiro Boza
// Marcos Antonio de Freitas Júnior
 
int main (int argc, char* const argv[]){
    int opcao;
    int linhas(0);
    int colunas(0);
    int tabuleiros(0);

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
        ir::inicializa_matriz(linhas, colunas); // matriz do tabuleiro
        ir::carrega_strings_tabuleiro(); // carrega os tabuleiros já geraos para verificação posterior

        while(tabuleiros > 0){
            ir::zera_matriz(); // cada elemento vira 0
            teste_gerou = ir::principal();
            if(teste_gerou == false){ // se não gerar uma matriz
                tabuleiros += 1; // gerou
            }else{
                tabuleiros -= 1; // não gerou
            }
        }
        ir::liberar();
    }else{
        if(opcao == 2){
            std::cout << "Qual o tabuleiro que você deseja jogar?" << std::endl;
            while(tabuleiros == 0){
                std::cin >> tabuleiros;
            }      

            if(ir::carrega_tabuleiro(tabuleiros)){ // se conseguir carregar o tabuleiro
                ir::iniciar_jogo();
            }
        }
    }






    return EXIT_SUCCESS;
}
