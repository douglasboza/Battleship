
Comando paracompilar.
g++ -Wall -std=c++11 src/main.cpp include/functions.h src/functions.cpp -o run
./run


Cada barco é numerado em decimal, sendo levado em consideração o sentido do barco e as casas dele.

barco ----- representado por 5 | no sentido vertical é o 51

barco ---- representado por 4 | no sentido vertical é o 41

barco --- representado por 3 | no sentido vertical é o 31

barco -- representado por 2 | no sentido vertical é o 21

barco - representado por 1 | no sentido vertical é o 11

Temos o seguintes possíveis barcos para um tabuleiro: 5, 51, 4, 41, 3, 31, 2, 21, 1, 11

Obrigatoriamente cada tabuleiro tem:
Com 5 casas deve ter 1 barco
Com 4 casas deve ter 2 barcos
Com 3 casas deve ter 3 barcos
Com 2 casas deve ter 3 barcos
Com 1 casas deve ter 1 barco



O método para gerar o tabuleiro utiliza duas matrizes, uma delas representa o tabuleiro, onde cada casa é preenchida com 0
Após prencher um barco, a casa é preenchida com 1.

A outra matriz é utilizada para guardar todas as coordenadas da matriz do tabuleiro
Ex:
m[0][0] = linha da coordenada 0
m[0][1] = coluna da coordenada 0

m[1][0] = linha da coordenada 1
m[1][1] = coluna da coordenada 1

m[2][0] = linha da coordenada 2
m[2][1] = coluna da coordenada 2

O sorteio é realizado nessa matriz, caso não seja possível preencher barco algum na coordenada sorteada, ela é posicionada
no final da matriz e não entrará no próxima sorteio.
Caso a posição sorteada tenha algum barco disponível para preencher, então é realizado um sorteio entre esses barcos.

Dessa forma, o algorítmo possui uma alta possibilidade de encontrar uma solução e gerar um tabuleiro, pois ele não considera
as posições ocupadas para realizar o sorteio.

Porém, dependendo da quantidade de linhas e colunas, pode haver combinações que impossibilitem o preenchimento de todos os barcos. Quando isso ocorre, o algoritmo tenta gerar novamente um outro tabuleiro
