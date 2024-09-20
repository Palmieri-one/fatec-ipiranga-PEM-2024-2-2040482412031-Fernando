/*-------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                *
*          Prof. Carlos Veríssimo                              *
*--------------------------------------------------------------*
* Objetivo do Programa: CALCULADORA RPN HP12C                  *
*                                                              *
* Data: 14/09/2024                                             * 
* Autor: Letícia Sudan Gauy e Fernando Palmieri                *
*--------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para usar fgets, strtok e atof

#define MAX 100

float *p; // Aponta para região de memória livre
float *tos; // Ponteiro para o topo da pilha
float *bos; // Ponteiro para a base da pilha

void push(float i);
float pop(void);

// Armazena um elemento na Pilha = empilha
void push(float i) {
    if (p > bos) {
        printf("Pilha Cheia\n");
        return;
    }
    *p = i;
    p++;
}

// Recupera um elemento da Pilha - desempilha
float pop(void) {
    p--;
    if (p < tos) {
        printf("Pilha Vazia\n");
        return 0.0;
    }
    return *p;
}

int main() {
    float a, b;
    char s[256]; // Buffer maior para suportar linhas mais longas
    p = (float *) malloc(MAX * sizeof(float)); // Aloca memória para a pilha

    if (!p) {
        printf("ERRO DE ALOCAÇÃO DE MEMÓRIA\n");
        exit(1);
    }

    tos = p;
    bos = p + MAX - 1;
    printf("Calculadora\n");
    printf("Digite os comandos separados por espaço (digite 'q' para sair):\n");

    while (1) {
        printf(": ");
        if (fgets(s, sizeof(s), stdin) == NULL) {
            printf("Erro na leitura da linha.\n");
            continue;
        }

        // Remove o caractere de nova linha se presente
        s[strcspn(s, "\n")] = 0;

        // Divide a linha em tokens
        char *token = strtok(s, " ");
        while (token != NULL) {
            if (strcmp(token, "q") == 0) {
                free(p); // Libere a memória alocada
                return 0;
            }
            
            switch (token[0]) {
                case '+':
                    a = pop();
                    b = pop();
                    printf("%.2f\n", b + a);
                    push(b + a);
                    break;
                
                case '-':
                    a = pop();
                    b = pop();
                    printf("%.2f\n", b - a);
                    push(b - a);
                    break;
                
                case '*':
                    a = pop();
                    b = pop();
                    printf("%.2f\n", b * a);
                    push(b * a);
                    break;
                
                case '/':
                    a = pop();
                    b = pop();
                    if (a == 0) {
                        printf("Divisão por 0\n");
                        push(b); // Retorna o valor de b para a pilha
                        break;
                    }
                    printf("%.2f\n", b / a);
                    push(b / a);
                    break;
                
                case '.': // Mostra conteúdo do topo da pilha
                    a = pop();
                    push(a);
                    printf("Valor corrente no topo da pilha: %.2f\n", a);
                    break;
                
                default:
                    push(atof(token));
            }

            // Obtem o próximo token
            token = strtok(NULL, " ");
        }
    }

    return 0;
}
