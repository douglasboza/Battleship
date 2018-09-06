
g++ -Wall -std=c++11 src/main.cpp include/functions.h src/functions.cpp -o a



Cada barco é numerado em decimal, sendo levado em consideração o sentido do barco e as casas dele.

----- 5 / no sentido vertical é o 51

---- 4 / no sentido vertical é o 41

---  3 / no sentido vertical é o 31

--   2 / no sentido vertical é o 21

-    1 / no sentido vertical é o 11

Temos o seguintes barcos: 4, 41, 3, 31, 2, 21, 1, 11


Função principal;
    Chama GERAR_MATRIZ
    Enquanto houver barco disponível:
        Chama CRIAR_BARCO


Função GERAR_MATRIZ(linhas, colunas):
    Cria uma matriz linhasxcolunas com todos os elementos iguais a 0.
    return matriz

Funcao VERIFICA_BARCO(linha, coluna, matriz):
    Verifica quais barcos podem ser colocados na linha x coluna
    Retorna a lista dos barcos que podem ser colocados, leva em consideração o limite de barcos do tabuleiro.
    

Função CRIAR_BARCO():
    Percorre cada posição igual a 0 e verifica se ela pode ser preenchida com algum barco chamando VERIFICA_BARCO
    Guarda a posição e qual barco pode ser colocado nela
    Sorteia uma posição que pode ter barcos
    Sorteia um barco para essa posição
    Chama PREENCHER_ESPACOS(linha, coluna, nome_barco)
    Após isso preenche como 1 os espaços do barco



Função PREENCHER_ESPACOS(linha, coluna, nome_barco){
    Preenche como 2 os espaços ao lado de linha x coluna   
    Deve levar em consideração o tipo de barco
    ex: PREENCHER_ESPACOS(0, 2, matriz)
        PREENCHER_ESPACOS(4, 4, matriz)

            0  1  2  3  4  5  6

        0    0, 2, 1, 2, 0, 0, 0
        1    2, 2, 2, 2, 0, 0, 0
        2    0, 0, 0, 0, 0, 0, 0
        3    0, 0, 0, 0, 2, 0, 0
        4    0, 0, 0, 2, 1, 2, 0
        5    0, 0, 0, 0, 2, 0, 0
        6    0, 0, 0, 0, 0, 0, 0



