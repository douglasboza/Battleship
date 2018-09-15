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





    // std::cout << matriz.end() << std::endl;


    // ir::compact( std::begin(A), std::end(A));

    // ir::partition( std::begin(A), std::end(A), std::begin(A) + 3);

    // ir::rotate(std::begin(A), std::begin(A) + 1, std::end(A));
    // ir::rotate(std::begin(A), std::begin(A) + 2 , std::end(A) - 2);
    // ir::rotate(std::begin(A), std::begin(A) + 2 , std::end(A) - 4);
            // rotate(first, n_first, last - 2);

    // for (auto i(std::begin(A)); i != std::end(A); ++i){
    //       std::cout << * a << " "; 
    // }
    // [ −5, 3, −2, 1, 7, 7, 7, 9, 8, 10 ]

    // int A[]{ 1, 2, 3, 4, 5 };
    // // ir::value_type A_E[]{ 1, 4, 3, 2, 5};
    //     ir::reverse(std::begin(A), std::end(A) );
    // // ASSERT_EQ( std::distance( std::begin(A), std::end(A) ), std::distance( std::begin(A_E), std::end(A_E) ) );
    // // ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );

    // for (auto i(std::begin(A)); i != std::end(A); ++i){
    //       // std::cout << * i << " "; 
    // }


    return EXIT_SUCCESS;
}
