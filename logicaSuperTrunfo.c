#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
        // Carta 1
        char estado1 = 'A';
        char codigo1[] = "A01";
        char nomeCidade1[] = "Paranaiba";
        unsigned long int populacao1 = 41363;
        float area1 = 5402.77;
        float pib1 = 71 * 1000000000; // PIB em reais
        int pontosTuristicos1 = 10;
        float densidade1 = populacao1 / area1;
        float pibPerCapita1 = pib1 / populacao1;
        float superPoder1 = populacao1 + area1 + pib1 + pontosTuristicos1 + pibPerCapita1 + (1 / densidade1);
        
        // Carta 2
        char estado2 = 'B';
        char codigo2[] = "B02";
        char nomeCidade2[] = "Sena Madureira";
        unsigned long int populacao2 = 45177;
        float area2 = 25296.70;
        float pib2 = 40 * 1000000000; // PIB em reais
        int pontosTuristicos2 = 15;
        float densidade2 = populacao2 / area2;
        float pibPerCapita2 = pib2 / populacao2;
        float superPoder2 = populacao2 + area2 + pib2 + pontosTuristicos2 + pibPerCapita2 + (1 / densidade2);
        
        // Comparação de Atributos
        printf("\nComparacao de Cartas:\n\n");
        printf("Populacao: Carta %d venceu (%lu)\n", populacao1 > populacao2 ? 1 : 2, populacao1 > populacao2 ? populacao1 : populacao2);
        printf("Area: Carta %d venceu (%.2f km²)\n", area1 > area2 ? 1 : 2, area1 > area2 ? area1 : area2);
        printf("PIB: Carta %d venceu (%.2f reais)\n", pib1 > pib2 ? 1 : 2, pib1 > pib2 ? pib1 : pib2);
        printf("Pontos Turisticos: Carta %d venceu (%d)\n", pontosTuristicos1 > pontosTuristicos2 ? 1 : 2, pontosTuristicos1 > pontosTuristicos2 ? pontosTuristicos1 : pontosTuristicos2);
        printf("Densidade Populacional: Carta %d venceu (%.2f hab/km²)\n", densidade1 < densidade2 ? 1 : 2, densidade1 < densidade2 ? densidade1 : densidade2);
        printf("PIB per Capita: Carta %d venceu (%.2f reais)\n", pibPerCapita1 > pibPerCapita2 ? 1 : 2, pibPerCapita1 > pibPerCapita2 ? pibPerCapita1 : pibPerCapita2);
        printf("Super Poder: Carta %d venceu (%.2f)\n", superPoder1 > superPoder2 ? 1 : 2, superPoder1 > superPoder2 ? superPoder1 : superPoder2);
        
        // Carta Vencedora Geral
        int vitoriasCarta1 = (populacao1 > populacao2) + (area1 > area2) + (pib1 > pib2) + (pontosTuristicos1 > pontosTuristicos2) + (densidade1 < densidade2) + (pibPerCapita1 > pibPerCapita2) + (superPoder1 > superPoder2);
        int vitoriasCarta2 = 7 - vitoriasCarta1;
        
        printf("\nCarta Vencedora Geral:\n");
        if (vitoriasCarta1 > vitoriasCarta2) {
            printf("Carta 1 - %s venceu!\n", nomeCidade1);
        } else {
            printf("Carta 2 - %s venceu!\n", nomeCidade2);
        }

    return 0;
}
