#include <stdio.h>
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[10][10]) {
    printf("\n   A B C D E F G H I J\n");
    for (int i = 0; i < 10; i++) {
        //esse printf faz mostrar os numeros na lateral do tabuleiro, usei o %2d para nao fica desalinhado e comecei com o 1 para mostrar do 1 ao 10.
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se pode posicionar um navio
int podePosicionar(int tabuleiro[10][10], int linha, int coluna, int tamanho, char direcao) {
    if (direcao == 'H'||direcao == 'h') {
        if (coluna + tamanho > 10) {
            return 0;
        }
        for (int j = coluna; j < coluna + tamanho; j++) {
            if (tabuleiro[linha][j] != 0){
                return 0;
            } 
        }
    } else {
        if (linha + tamanho > 10){
            return 0;
        }
        for (int i = linha; i < linha + tamanho; i++) {
            if (tabuleiro[i][coluna] != 0) {
                return 0;
            }
        }
    }
    return 1;
}

// Função para posicionar um navio fixo se possível
void posicionarNavio(int tabuleiro[10][10], int linha, int coluna, int tamanho, char direcao) {
    if (podePosicionar(tabuleiro, linha, coluna, tamanho, direcao)) {
        if (direcao == 'H') {
            for (int j = coluna; j < coluna + tamanho; j++) {
                tabuleiro[linha][j] = 3;
            }
        } else {
            for (int i = linha; i < linha + tamanho; i++) {
                tabuleiro[i][coluna] = 3;
            }
        }
        printf("Navio posicionado na linha %d, coluna %d, tamanho %d, direção %c.\n", linha + 1, coluna + 1, tamanho, direcao);
    } else {
        printf("Erro: Sobreposição ou fora do tabuleiro na posição linha %d, coluna %d, tamanho %d, direção %c.\n", linha + 1, coluna + 1, tamanho, direcao);
    }
}

// Função para posicionar os navios fixos
void posicionarNaviosFixos(int tabuleiro[10][10]) {
    // Navio horizontal: na linha 2(1), coluna 3(2),tamanho 4(navio), direção H(Horizontal)
    posicionarNavio(tabuleiro, 1, 2, 4, 'H');
    // Navio vertical: na linha 5, coluna 7, tamanho 3 , direção V(Vertical)
    posicionarNavio(tabuleiro, 4, 6, 3, 'V');
}

int main() {
   
    int tabuleiro[10][10] = {0}; // Inicializa o tabuleiro com agua (0) 

    posicionarNaviosFixos(tabuleiro);
    //Os navios sao representados pelo numero 3
    printf("\n****************************\n");
    printf("*      Batalha Naval       *\n");
    printf("****************************\n");
    exibirTabuleiro(tabuleiro);
    printf("\n");
}

    
// Nível Novato - Posicionamento dos Navios
// Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
// Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
// Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

// Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
// Sugestão: Expanda o tabuleiro para uma matriz 10x10.
// Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
// Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

// Nível Mestre - Habilidades Especiais com Matrizes
// Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
// Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
// Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

// Exemplos de exibição das habilidades:
// Exemplo para habilidade em cone:
// 0 0 1 0 0
// 0 1 1 1 0
// 1 1 1 1 1
    
// Exemplo para habilidade em octaedro:
// 0 0 1 0 0
// 0 1 1 1 0
// 0 0 1 0 0

// Exemplo para habilidade em cruz:
// 0 0 1 0 0
// 1 1 1 1 1
// 0 0 1 0 0
