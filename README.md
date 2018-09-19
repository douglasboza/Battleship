
Comando para compilar.
g++ -Wall -std=c++11 src/main.cpp include/functions.h src/functions.cpp -o run
./run


------------ Representação dos barcos ------------


Cada barco é numerado em decimal, sendo levado em consideração o sentido do barco e as casas dele.

barco ----- representado por 5 | no sentido vertical é o 51

barco ---- representado por 4 | no sentido vertical é o 41

barco --- representado por 3 | no sentido vertical é o 31

barco -- representado por 2 | no sentido vertical é o 21

barco - representado por 1

Temos o seguintes possíveis barcos para um tabuleiro: 5, 51, 4, 41, 3, 31, 2, 21, 1

Obrigatoriamente cada tabuleiro possui:
Com 5 casas 1 barco
Com 4 casas 2 barcos
Com 3 casas 3 barcos
Com 2 casas 3 barcos
Com 1 casa 1 barco

- Os barcos na horizontal são preenchidos para a direita.
- Os barcos na vertical são preenchidos para a parte inferior do tabuleiro.


Representação dos barcos na matriz, quando o barco teve a casa atingida por um tiro:
5   vira  52
51  vira  512
4   vira  42
41  vira  412
3   vira  32
31  vira  312
2   vira  22
21  vira  212
1   vira  12


Representação dos barcos no jogo no terminal:
A = 5
B = 51
C = 4
D = 41
E = 3
F = 31
G = 2
H = 21
i = 1


------------------------------------------------------------



------------ Método geral para criar o tabuleiro ------------

O método para gerar o tabuleiro utiliza duas matrizes, uma delas representa o tabuleiro, onde cada casa é preenchida com 0
Após prencher um barco, a casa é preenchida com 1.

A outra matriz é utilizada para guardar todas as coordenadas da matriz do tabuleiro
Ex:
Caso o tabuleiro possua 10 linhas e 10 colunas, a matriz m terá 100 posições.
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

Porém, dependendo da quantidade de linhas e colunas, pode haver combinações que impossibilitem o preenchimento de todos os barcos, pois ao lado de cada barco não pode haver outro barco. Quando isso ocorre, o algoritmo tenta gerar novamente um outro tabuleiro

Quando um tabuleiro é gerado, há uma verificação para ver se ele já foi gerado antes.

------------------------------------------------------------


------------ Forma com são salvos os tabuleiros ------------

Os tabuleiros são salvos em um arquivo chamado "tabuleiros"
Em cada tabuleiro(até chegar em 9999), o primeiro número é a quantidade de linhas do tabuleiro, o segundo a quantidade de colunas.
Em seguida estão os barcos na ordem linha, coluna e depois o número do barco.
O final de cada tabuleiro é representado por 9999

Ex:

10 10 (tabuleiro com 10 linhas e 10 colunas)
9 1 3 (linha 9 coluna 1 com o barco 3)
4 3 21
1 1 1
0 4 5
8 5 4
5 0 31
5 5 4
2 3 3
7 2 2
2 8 2
9999  (fim do tabuleiro)
15 15 (novo tabuleiro com 15 linhas por 15 colunas)
2 2 1
...



------------------------------------------------------------