#include <stdio.h>
#include <string.h>

// Com a adcição de direções na vertical achei melhor tratar as direções como strings e foi assim que resolvi da melhor forma
#define HORIZONTAL "HORIZONTAL"
#define VERTICAL "VERTICAL"
#define DIAGONAL_DIREITA "DIAGONAL_DIREITA"
#define DIAGONAL_ESQUERDA "DIAGONAL_ESQUERDA"

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
//Com as direções como strig as condições com elas em maiuscula e minuscula foram necessarios para evitar erros
int podePosicionar(int tabuleiro[10][10], int linha, int coluna, int tamanho, const char* direcao) {
    if (strcmp(direcao, "HORIZONTAL") == 0 || strcmp(direcao, "horizontal") == 0 ||strcmp(direcao, "Horizontal") == 0) {
        if (coluna + tamanho > 10){
            return 0;
        } 
        for (int j = coluna; j < coluna + tamanho; j++) {
            if (tabuleiro[linha][j] != 0){
                return 0;
            }
        }
    } else if (strcmp(direcao, "VERTICAL") == 0 ||strcmp(direcao, "vertical") == 0 ||strcmp(direcao, "Vertical") == 0) {
        if (linha + tamanho > 10){
            return 0;
        } 
        for (int i = linha; i < linha + tamanho; i++) {
            if (tabuleiro[i][coluna] != 0){
                return 0;
            } 
        }
    } else if (strcmp(direcao, "DIAGONAL_DIREITA") == 0 ||strcmp(direcao, "diagonal_direita") == 0 ||strcmp(direcao, "Diagonal_Direita") == 0) {
        if (linha + tamanho > 10 || coluna + tamanho > 10){
            return 0;
        } 
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna + i] != 0){
                return 0;
            } 
        }
    } else if (strcmp(direcao, "DIAGONAL_ESQUERDA") == 0 ||strcmp(direcao, "diagonal_esquerda") == 0 ||strcmp(direcao, "Diagonal_Esquerda") == 0) {
        if (linha + tamanho > 10 || coluna - tamanho + 1 < 0){
            return 0;
        } 
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna - i] != 0){
                return 0;
            } 
        }
    } else {
        return 0; // direção inválida
    }

    return 1;
}

// Função para posicionar um navio fixo se possível
void posicionarNavio(int tabuleiro[10][10], int linha, int coluna, int tamanho, const char* direcao) {
    if (podePosicionar(tabuleiro, linha, coluna, tamanho, direcao)) {
        if (strcmp(direcao, "HORIZONTAL") == 0 ||strcmp(direcao, "horizontal") == 0 ||strcmp(direcao, "Horizontal") == 0) {
            for (int j = coluna; j < coluna + tamanho; j++) {
                tabuleiro[linha][j] = 3;
            }
        } else if (strcmp(direcao, "VERTICAL") == 0 ||strcmp(direcao, "vertical") == 0 ||strcmp(direcao, "Vertical") == 0) {
            for (int i = linha; i < linha + tamanho; i++) {
                tabuleiro[i][coluna] = 3;
            }
        } else if (strcmp(direcao, "DIAGONAL_DIREITA") == 0 ||strcmp(direcao, "diagonal_direita") == 0 ||strcmp(direcao, "Diagonal_Direita") == 0) {
            for (int i = 0; i < tamanho; i++) {
                tabuleiro[linha + i][coluna + i] = 3;
            }
        } else if (strcmp(direcao, "DIAGONAL_ESQUERDA") == 0 ||strcmp(direcao, "diagonal_esquerda") == 0 ||strcmp(direcao, "Diagonal_Esquerda") == 0) {
            for (int i = 0; i < tamanho; i++) {
                tabuleiro[linha + i][coluna - i] = 3;
            }
        }

        printf("Navio posicionado na linha %d, coluna %d, tamanho %d, direção: %s.\n", linha + 1, coluna + 1, tamanho, direcao);
    } else {
        printf("Erro: Sobreposição ou fora do tabuleiro na posição linha %d, coluna %d, tamanho %d, direção: %s.\n", linha + 1, coluna + 1, tamanho, direcao);
    }
}

// So coloquei essa função para o Main ficar mais simples .
void posicionarNaviosFixos(int tabuleiro[10][10]) {
    // Navio horizontal: na linha 10(9), coluna 1(0),tamanho 4(navio)
    posicionarNavio(tabuleiro, 9, 0, 4, "horizontal");
    // Navio vertical: na linha 5(4), coluna 7(6), tamanho 3 
    posicionarNavio(tabuleiro, 4, 6, 3, "VERTICAL");
    //Navio Diagonal Direita(De cima para baixo): linha 1(0), coluna 1 (0), tamanho 3
    posicionarNavio(tabuleiro, 0, 0, 3, "Diagonal_Direita");
    //Navio Diagonal Esquerda(De cima para baixo): linha 1(0), coluna 1 (0), tamanho 3
    posicionarNavio(tabuleiro, 0, 7, 3, "diagonal_esquerda");
}

int main() {
   
    int tabuleiro[10][10] = {0}; // Inicializa o tabuleiro com agua (0) 
    //Posiciona todos os navios no tabuleiro 
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