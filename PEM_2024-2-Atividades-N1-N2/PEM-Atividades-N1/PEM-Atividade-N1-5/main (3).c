/*-------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                *
*          Prof. Carlos Veríssimo                              *
*--------------------------------------------------------------*
* Objetivo do Programa: MODULARIZAÇÃO DO PROGRAMA XEQUE-PASTOR *
*                                                              *
* Data: 08/09/2024                                             * 
* Autor: Letícia Sudan Gauy e Fernando Palmieri                *
*--------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

// DEFININDO OS VETORES DE STRINGS
char linhaPecasPretas[8][4] = {"PT1", "PC1", "PB1", "PD1", "PR1", "PB2", "PC2", "PT2"};
char linhaPretaPeao[8][4] = {"PP1", "PP2", "PP3", "PP4", "PP5", "PP6", "PP7", "PP8"};
char linhaTabuleiro3[8][4] = {"", "", "", "", "", "", "", ""};
char linhaTabuleiro4[8][4] = {"", "", "", "", "", "", "", ""};
char linhaTabuleiro5[8][4] = {"", "", "", "", "", "", "", ""};
char linhaTabuleiro6[8][4] = {"", "", "", "", "", "", "", ""};
char linhaBrancaPeao[8][4] = {"BP1", "BP2", "BP3", "BP4", "BP5", "BP6", "BP7", "BP8"};
char linhaPecasBrancas[8][4] = {"BT1", "BC1", "BB1", "BD1", "BR1", "BB2", "BC2", "BT2"};

// DEFININDO AS FUNÇÕES
void exibirTabuleiro();
void jogadaBranca(char* peca, int origem, int destino);
void jogadaPreta(char* peca, int origem, int destino);
void atualizarTabuleiro(char* peca, int linha, int coluna, char* vetorOrigem, char* vetorDestino);

// CRIAÇÃO DAS FUNÇÕES
void exibirTabuleiro() {
    printf("     a   b   c   d   e   f   g   h\n");  
    printf("    --------------------------------\n");
    for (int i = 0; i < 8; i++) {
        printf("%d | ", 8 - i);
        for (int j = 0; j < 8; j++) {
            printf("%-4s", (i == 0 ? linhaPecasPretas[j] :
                            i == 1 ? linhaPretaPeao[j] :
                            i == 2 ? linhaTabuleiro6[j] :
                            i == 3 ? linhaTabuleiro5[j] :
                            i == 4 ? linhaTabuleiro4[j] :
                            i == 5 ? linhaTabuleiro3[j] :
                            i == 6 ? linhaBrancaPeao[j] :
                                     linhaPecasBrancas[j]));
        }
        printf("\n");
    }
    printf("\n");
}

void jogadaBranca(char* peca, int origem, int destino) {
    atualizarTabuleiro(peca, origem, destino, linhaBrancaPeao[origem], linhaTabuleiro4[destino]);
}

void jogadaPreta(char* peca, int origem, int destino) {
    atualizarTabuleiro(peca, origem, destino, linhaPretaPeao[origem], linhaTabuleiro5[destino]);
}

void atualizarTabuleiro(char* peca, int linha, int coluna, char* vetorOrigem, char* vetorDestino) {
    strcpy(vetorDestino, peca);
    strcpy(vetorOrigem, "...");
}

// EXIBIÇÃO DE CADA JOGADA NO CONSOLE
int main() {
    printf("    --------------------------------\n");
    printf("          TABULEIRO INICIAL\n");
    exibirTabuleiro();

    printf("\n          JOGADA 1 - BRANCO JOGA\n");
    jogadaBranca("BP5", 4, 4);  
    exibirTabuleiro();

    printf("\n          JOGADA 2 - PRETO JOGA\n");
    jogadaPreta("PP5", 4, 4);  
    exibirTabuleiro();

    printf("\n          JOGADA 3 - BRANCO JOGA\n");
    atualizarTabuleiro("BB2", 5, 2, linhaPecasBrancas[5], linhaTabuleiro4[2]);
    exibirTabuleiro();

    printf("\n          JOGADA 4 - PRETO JOGA\n");
    atualizarTabuleiro("PC1", 1, 2, linhaPecasPretas[1], linhaTabuleiro6[2]);
    exibirTabuleiro();

    printf("\n          JOGADA 5 - BRANCO JOGA\n");
    atualizarTabuleiro("BD1", 3, 7, linhaPecasBrancas[3], linhaTabuleiro5[7]);
    exibirTabuleiro();

    printf("\n          JOGADA 6 - PRETO JOGA\n");
    atualizarTabuleiro("PC2", 6, 5, linhaPecasPretas[6], linhaTabuleiro6[5]);
    exibirTabuleiro();

    printf("\n          JOGADA 7 - BRANCO JOGA\n");
    atualizarTabuleiro("BD1", 7, 7, linhaTabuleiro5[7], linhaPretaPeao[5]);
    exibirTabuleiro();

    return 0;
}
