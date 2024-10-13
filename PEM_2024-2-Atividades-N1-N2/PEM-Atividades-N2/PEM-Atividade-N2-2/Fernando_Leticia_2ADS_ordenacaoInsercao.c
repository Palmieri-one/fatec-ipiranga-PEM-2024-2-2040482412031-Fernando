/*-------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                *
*          Prof. Carlos Veríssimo                              *
*--------------------------------------------------------------*
* Objetivo do Programa: ORDENAÇÃO POR INSERÇÃO                 *
*                                                              *
* Data: 04/10/2024                                             * 
* Autor: Letícia Sudan Gauy e Fernando Palmieri                *
*--------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>

// Ordena um array usando o algoritmo de ordenação por inserção
void ordenacaoInsercao(int numeros[], int quantidade) {
    int i, elemento, posicao;
    for (i = 1; i < quantidade; i++) {
        elemento = numeros[i]; // Elemento a ser inserido
        posicao = i - 1;

        // Move elementos maiores para a direita
        while (posicao >= 0 && numeros[posicao] > elemento) {
            numeros[posicao + 1] = numeros[posicao];
            posicao--;
        }
        numeros[posicao + 1] = elemento; // Insere o elemento na posição correta
    }
}

// Imprime o array
void imprimirArray(int numeros[], int quantidade) {
    for (int i = 0; i < quantidade; i++)
        printf("%d ", numeros[i]);
    printf("\n");
}

int main() {
    int quantidadeNumeros;

    // Solicita o número de elementos
    printf("Quantos números você deseja ordenar? ");
    scanf("%d", &quantidadeNumeros);

    // Aloca memória para o array
    int *numeros = (int *)malloc(quantidadeNumeros * sizeof(int));
    if (numeros == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Solicita os números
    printf("Insira os números:\n");
    for (int i = 0; i < quantidadeNumeros; i++) {
        scanf("%d", &numeros[i]);
    }

    printf("Array original: ");
    imprimirArray(numeros, quantidadeNumeros);

    ordenacaoInsercao(numeros, quantidadeNumeros); // Ordena o array

    printf("Array ordenado: ");
    imprimirArray(numeros, quantidadeNumeros);

    // Libera a memória alocada
    free(numeros);

    return 0;
}
