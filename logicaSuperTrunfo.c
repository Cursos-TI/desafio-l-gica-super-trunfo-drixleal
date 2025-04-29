#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Declaração das variáveis
    char pais1[3], pais2[3], codigo1[3], codigo2[3];
    char nomePais1[30], nomePais2[30];
    unsigned int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    float pibcapita1, pibcapita2, denspopulacional1, denspopulacional2;
    int pontosTur1, pontosTur2;
    int opcao1, opcao2;
    float valor1_atrib1 = 0, valor2_atrib1 = 0;
    float valor1_atrib2 = 0, valor2_atrib2 = 0;
    float soma1 = 0, soma2 = 0;

    printf("\n\n ==== Bem-vindo ao Super Trunfo - Países! ====\n");
    printf("Powered by Drix\n");



    // Entrada das cartas
    printf("\nInicie digitando uma letra de 'A' a 'H': ");
    scanf("%s", pais1);
    printf("\nPerfeito! Digite um número de 01 a 04 que codificará a  primeira carta: ");
    scanf("%s", codigo1);
    printf("\nBacana! Escreva o nome do país: ");
    getchar(); scanf(" %[^\n]", nomePais1);
    printf("\nCerto! Insira a população do país: ");
    scanf("%d", &populacao1);
    printf("\nDigite a área em quilômetros quadrados: ");
    scanf("%f", &area1);
    printf("\nDigite o PIB do país: ");
    scanf("%f", &pib1);
    printf("\nFinalmente, digite a quantidade de pontos turísticos: ");
    scanf("%d", &pontosTur1);

    printf("\n\n==== Agora vamos cadastrar a segunda carta! ====\n\n");

    printf("Digite uma letra do segundo país de 'A' a 'H': ");
    scanf("%s", pais2);
    printf("\nPerfeito! Digite um número de 01 a 04 que codificará a  segunda carta: ");
    scanf("%s", codigo2);
    printf("\nBacana! Agora digite o nome do país: ");
    getchar(); scanf(" %[^\n]", nomePais2);
    printf("\nCerto! Insira a população do país: ");
    scanf("%d", &populacao2);
    printf("\nDigite a área em quilômetros quadrados: ");
    scanf("%f", &area2);
    printf("\nDigite o PIB do país: ");
    scanf("%f", &pib2);
    printf("\nFinalmente, digite a quantidade de pontos turísticos: ");
    scanf("%d", &pontosTur2);

    // Cálculos
    denspopulacional1 = populacao1 / area1;
    denspopulacional2 = populacao2 / area2;
    pibcapita1 = pib1 / populacao1;
    pibcapita2 = pib2 / populacao2;

    // Menu de seleção
    printf("\nSelecione o primeiro atributo para comparação:\n");
    printf("1. Populacao\n2. Area\n3. PIB\n4. Pontos Turisticos\n5. Densidade Populacional\n6. PIB per Capita\n");
    scanf("%d", &opcao1);

    do {
        printf("\nSelecione o segundo atributo (diferente do primeiro):\n");
        for (int i = 1; i <= 6; i++) {
            if (i != opcao1) {
                switch(i) {
                    case 1: printf("%d. Populacao\n", i); break;
                    case 2: printf("%d. Area\n", i); break;
                    case 3: printf("%d. PIB\n", i); break;
                    case 4: printf("%d. Pontos Turisticos\n", i); break;
                    case 5: printf("%d. Densidade Populacional\n", i); break;
                    case 6: printf("%d. PIB per Capita\n", i); break;
                }
            }
        }
        scanf("%d", &opcao2);
        if (opcao2 == opcao1) {
            printf("Você não pode escolher o mesmo atributo duas vezes!\n");
        }
    } while (opcao1 == opcao2);

    // Comparação dos dois atributos
    for (int i = 1; i <= 2; i++) {
        int escolha = (i == 1) ? opcao1 : opcao2;
        float v1 = 0, v2 = 0;
        char nomeAttr[30];

        switch(escolha) {
            case 1: v1 = populacao1; v2 = populacao2; strcpy(nomeAttr, "População"); break;
            case 2: v1 = area1; v2 = area2; strcpy(nomeAttr, "Área"); break;
            case 3: v1 = pib1; v2 = pib2; strcpy(nomeAttr, "PIB"); break;
            case 4: v1 = pontosTur1; v2 = pontosTur2; strcpy(nomeAttr, "Pontos Turísticos"); break;
            case 5: v1 = denspopulacional1; v2 = denspopulacional2; strcpy(nomeAttr, "Densidade Populacional"); break;
            case 6: v1 = pibcapita1; v2 = pibcapita2; strcpy(nomeAttr, "PIB per Capita"); break;
            default: printf("Atributo inválido.\n"); return 1;
        }

        printf("\nComparando %s:\n", nomeAttr);
        printf("%s: %.2f | %s: %.2f\n", nomePais1, v1, nomePais2, v2);

        // Regra especial para Densidade Populacional (menor vence)
        if (escolha == 5) {
            (v1 < v2) ? printf("Vencedor: %s\n", nomePais1) :
            (v2 < v1) ? printf("Vencedor: %s\n", nomePais2) :
            printf("Empate neste atributo!\n");
        } else {
            (v1 > v2) ? printf("Vencedor: %s\n", nomePais1) :
            (v2 > v1) ? printf("Vencedor: %s\n", nomePais2) :
            printf("Empate neste atributo!\n");
        }

        if (i == 1) { valor1_atrib1 = v1; valor2_atrib1 = v2; }
        else { valor1_atrib2 = v1; valor2_atrib2 = v2; }
    }

    // Soma dos dois atributos
    soma1 = valor1_atrib1 + valor1_atrib2;
    soma2 = valor2_atrib1 + valor2_atrib2;

    printf("\n==== RESULTADO FINAL ====\n");
    printf("Soma dos atributos:\n%s: %.2f\n%s: %.2f\n", nomePais1, soma1, nomePais2, soma2);

    if (soma1 > soma2)
        printf("VENCEDOR DA RODADA: %s\n", nomePais1);
    else if (soma2 > soma1)
        printf("VENCEDOR DA RODADA: %s\n", nomePais2);
    else
        printf("Empate!\n");



printf("\n\n=================================\n");
printf("\n Obrigado por usar o programa!\n");
printf("    Powered by Drix\n\n");
printf("=================================\n");




    return 0;
}
