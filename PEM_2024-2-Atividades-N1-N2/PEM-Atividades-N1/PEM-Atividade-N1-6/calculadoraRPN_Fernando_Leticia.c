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

#define TAMANHO_MAX_PILHA 4 // Limite máximo de 4 números na pilha

float *ponteiro_pilha;  // Aponta para a região de memória livre
float *topo_pilha;      // Ponteiro para o topo da pilha
float *base_pilha;      // Ponteiro para a base da pilha

void empilhar(float valor);
float desempilhar(void);
int tamanho_pilha(void);
int é_numero(char *token);
void limpar_pilha(void);

// Armazena um elemento na Pilha = empilha
void empilhar(float valor) {
    if (ponteiro_pilha > base_pilha) {
        printf("Erro: Pilha cheia\n");
        return;
    }
    *ponteiro_pilha = valor;
    ponteiro_pilha++;
}

// Recupera um elemento da Pilha - desempilha
float desempilhar(void) {
    if (ponteiro_pilha <= topo_pilha) {
        printf("Erro: Pilha vazia\n");
        return 0.0;
    }
    ponteiro_pilha--;
    return *ponteiro_pilha;
}

// Função para verificar o tamanho atual da pilha
int tamanho_pilha(void) {
    return ponteiro_pilha - topo_pilha;
}

// Função para verificar se o token é um número
int é_numero(char *token) {
    char *ponteiro_final;
    strtod(token, &ponteiro_final);
    return *ponteiro_final == '\0';
}

// Função para limpar a pilha
void limpar_pilha(void) {
    ponteiro_pilha = topo_pilha; // Reseta o ponteiro ao topo da pilha
}

int main() {
    float operando1, operando2;
    char linha_entrada[256]; // Buffer maior para suportar linhas mais longas
    ponteiro_pilha = (float *) malloc(TAMANHO_MAX_PILHA * sizeof(float)); // Aloca memória para a pilha

    if (!ponteiro_pilha) {
        printf("ERRO DE ALOCAÇÃO DE MEMÓRIA\n");
        exit(1);
    }

    topo_pilha = ponteiro_pilha;
    base_pilha = ponteiro_pilha + TAMANHO_MAX_PILHA - 1;
    printf("Calculadora RPN\n");
    printf("Digite os comandos separados por espaço (digite 'q' para sair):\n");

    while (1) {
        printf(": ");
        if (fgets(linha_entrada, sizeof(linha_entrada), stdin) == NULL) {
            printf("Erro na leitura da linha.\n");
            continue;
        }

        // Remove o caractere de nova linha se presente
        linha_entrada[strcspn(linha_entrada, "\n")] = 0;

        // Divide a linha em tokens
        char *token = strtok(linha_entrada, " ");
        int erro_ocorreu = 0; // Flag para controlar o erro de limite

        while (token != NULL) {
            if (strcmp(token, "q") == 0) {
                free(ponteiro_pilha); // Libere a memória alocada
                return 0;
            }

            if (é_numero(token)) {
                // Verifica se ainda há espaço para mais números na pilha
                if (tamanho_pilha() >= TAMANHO_MAX_PILHA) {
                    printf("Erro: Muitos números na memória\n");
                    erro_ocorreu = 1;  // Marca que houve erro de limite
                    limpar_pilha();  // Limpa a pilha após o erro
                    break;            // Sai do loop e solicita nova entrada
                } else {
                    empilhar(atof(token)); // Empilha apenas números
                }
            } else {
                // Verifica o operador e só realiza operações se houver elementos suficientes
                switch (token[0]) {
                    case '+':
                        if (tamanho_pilha() < 2) {
                            printf("Erro: Números insuficientes para a operação '+'.\n");
                            erro_ocorreu = 1;  // Sinaliza que ocorreu um erro
                            break;
                        }
                        operando1 = desempilhar();
                        operando2 = desempilhar();
                        empilhar(operando2 + operando1);
                        printf("Resultado: %.2f\n", operando2 + operando1);
                        break;

                    case '-':
                        if (tamanho_pilha() < 2) {
                            printf("Erro: Números insuficientes para a operação '-'.\n");
                            erro_ocorreu = 1;  
                            break;
                        }
                        operando1 = desempilhar();
                        operando2 = desempilhar();
                        empilhar(operando2 - operando1);
                        printf("Resultado: %.2f\n", operando2 - operando1);
                        break;

                    case '*':
                        if (tamanho_pilha() < 2) {
                            printf("Erro: Números insuficientes para a operação '*'.\n");
                            erro_ocorreu = 1;  
                            break;
                        }
                        operando1 = desempilhar();
                        operando2 = desempilhar();
                        empilhar(operando2 * operando1);
                        printf("Resultado: %.2f\n", operando2 * operando1);
                        break;

                    case '/':
                        if (tamanho_pilha() < 2) {
                            printf("Erro: Números insuficientes para a operação '/'.\n");
                            erro_ocorreu = 1;  
                            break;
                        }
                        operando1 = desempilhar();
                        operando2 = desempilhar();
                        if (operando1 == 0) {
                            printf("Erro: Divisão por zero\n");
                            empilhar(operando2); // Retorna o valor de operando2 para a pilha
                            break;
                        }
                        empilhar(operando2 / operando1);
                        printf("Resultado: %.2f\n", operando2 / operando1);
                        break;

                    case '.': // Mostra conteúdo do topo da pilha
                        if (tamanho_pilha() > 0) {
                            operando1 = desempilhar();
                            empilhar(operando1);
                            printf("Valor corrente no topo da pilha: %.2f\n", operando1);
                        } else {
                            printf("Pilha vazia\n");
                        }
                        break;

                    default:
                        printf("Comando inválido: %s\n", token);
                }
            }

            // Obtem o próximo token
            token = strtok(NULL, " ");
        }

        // Se houve um erro de limite, pede nova entrada
        if (erro_ocorreu) {
            printf("Por favor, insira uma nova expressão.\n");
            continue;
        }
        
        // Após processar todos os tokens, limpa a pilha para nova entrada
        limpar_pilha();
    }

    return 0;
}
