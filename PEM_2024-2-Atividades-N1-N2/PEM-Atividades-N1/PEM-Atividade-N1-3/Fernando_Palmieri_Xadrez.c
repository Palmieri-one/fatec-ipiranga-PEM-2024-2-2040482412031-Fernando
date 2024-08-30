/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: Aprendendo uso Vetores*
* Data - 30/08/2024                                               * 
* Autor: Fernando Palmieri*
*--------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

int main()
{    //Declaração das Variaveis
    char xadrezpreto[200];
    char xadrezpretopeao[200];
    char xadrezLinha3[200];
    char xadrezLinha4[200];
    char xadrezLinha5[200];
    char xadrezLinha6[200];
    char xadrezbrancopeao[200];
    char xadrezbranco[200];
    
    //Identificação das Variaveis
    strcpy(xadrezpreto, "8|PT1  PC1  PB1  PD1  PR1  PB2  PC2  PT2|8");
    strcpy(xadrezpretopeao,"7|PP1  PP2  PP3  PP4  PP5  PP6  PP7  PP8|7");
    strcpy(xadrezLinha6,"6| X    X    X    X    X    X    X    X |6");
    strcpy(xadrezLinha5,"5| X    X    X    X    X    X    X    X |5");
    strcpy(xadrezLinha4,"4| X    X    X    X    X    X    X    X |4");
    strcpy(xadrezLinha3,"3| X    X    X    X    X    X    X    X |3");
    strcpy(xadrezbrancopeao, "2|BP1  BP2  BP3  BP4  BP5  BP6  BP7  BP8|2");
    strcpy(xadrezbranco,"1|BT1  BC1  BB1  BR1  BD1  BB2  BC2  BT2|1");
    
    //Exibição das Variaveis
    printf("   A    B    C    D    E    F    G    H\n");
    printf("  --------------------------------------\n");
    printf("%s",xadrezpreto);
    printf("\n%s",xadrezpretopeao);
    printf("\n%s",xadrezLinha6);
    printf("\n%s",xadrezLinha5);
    printf("\n%s",xadrezLinha4);
    printf("\n%s",xadrezLinha3);
    printf("\n%s",xadrezbrancopeao);
    printf("\n%s",xadrezbranco);
    printf("\n  --------------------------------------");
    printf("\n   A    B    C    D    E    F    G    H");
    

    return 0;
}
