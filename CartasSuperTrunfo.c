#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

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

    // ===== PRIMEIRO ESTADO =====
    printf("Digite a primeira letra do primeiro estado: ");
    scanf(" %c", &carta1);

    printf("Digite o codigo do primeiro estado: ");
    scanf("%s", estado1);

    printf("Digite o nome da cidade do primeiro estado: ");
    scanf("%s", nomeCity1);  // não aceita espaço

    printf("Digite a populacao do primeiro estado: ");
    scanf("%f", &populacao1);

    printf("Digite a area do primeiro estado: ");
    scanf("%f", &area1);

    printf("Digite o PIB do primeiro estado: ");
    scanf("%f", &pib1);

    printf("Digite os pontos turisticos do primeiro estado: ");
    scanf("%d", &pontosTuristicos1);

    // ===== SEGUNDO ESTADO =====
    printf("\nDigite a primeira letra do segundo estado: ");
    scanf(" %c", &carta2);

    printf("Digite o codigo do segundo estado: ");
    scanf("%s", estado2);

    printf("Digite o nome da cidade do segundo estado: ");
    scanf("%s", nomeCity2);

    printf("Digite a populacao do segundo estado: ");
    scanf("%f", &populacao2);

    printf("Digite a area do segundo estado: ");
    scanf("%f", &area2);

    printf("Digite o PIB do segundo estado: ");
    scanf("%f", &pib2);

    printf("Digite os pontos turisticos do segundo estado: ");
    scanf("%d", &pontosTuristicos2);

    printf("\nCadastro realizado com sucesso!\n");

    return 0;
}