#include <stdio.h>

int main()
{
    int pontosTuristicos1, pontosTuristicos2;
    char carta1, carta2;
    char estado1[20], estado2[20];
    char nomeCity1[20], nomeCity2[20];
    float populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;

    // ===== PRIMEIRO ESTADO =====
    printf("===== CARTA 1 =====\n");

    printf("Digite o estado: ");
    scanf("%s", estado1);

    printf("Digite o codigo da carta (uma letra): ");
    scanf(" %c", &carta1);

    printf("Digite o nome da cidade: ");
    scanf("%s", nomeCity1);

    printf("Digite a populacao: ");
    scanf("%f", &populacao1);

    printf("Digite a area (km2): ");
    scanf("%f", &area1);

    printf("Digite o PIB: ");
    scanf("%f", &pib1);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos1);

    // ===== SEGUNDO ESTADO =====
    printf("\n===== CARTA 2 =====\n");

    printf("Digite o estado: ");
    scanf("%s", estado2);

    printf("Digite o codigo da carta (uma letra): ");
    scanf(" %c", &carta2);

    printf("Digite o nome da cidade: ");
    scanf("%s", nomeCity2);

    printf("Digite a populacao: ");
    scanf("%f", &populacao2);

    printf("Digite a area (km2): ");
    scanf("%f", &area2);

    printf("Digite o PIB: ");
    scanf("%f", &pib2);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // ===== CÁLCULOS =====
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;

    pibPerCapita1 = pib1 / populacao1;
    pibPerCapita2 = pib2 / populacao2;

    printf("\nCadastro realizado com sucesso!\n");

    // ===== EXIBIÇÃO DOS RESULTADOS =====
    printf("\n\n===== DADOS DAS CARTAS =====\n");

    printf("\n--- CARTA 1 ---\n");
    printf("Estado: %s\n", estado1);
    printf("Codigo: %c\n", carta1);
    printf("Cidade: %s\n", nomeCity1);
    printf("Populacao: %.2f\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f\n", pib1);
    printf("Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade1);
    printf("PIB per Capita: %.2f\n", pibPerCapita1);

    printf("\n--- CARTA 2 ---\n");
    printf("Estado: %s\n", estado2);
    printf("Codigo: %c\n", carta2);
    printf("Cidade: %s\n", nomeCity2);
    printf("Populacao: %.2f\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f\n", pib2);
    printf("Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade2);
    printf("PIB per Capita: %.2f\n", pibPerCapita2);

    return 0;
}