#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <limits.h>

// Define o número máximo de cartas que podem ser armazenadas
#define MAX_CARTAS 100

/*
  SuperTrunfo: cadastro e comparação de cartas.
  Funcionalidades suportadas:
    - carregar cartas de arquivo (cartas.txt)
    - exibir cartas
    - registrar nova carta
    - comparar duas cartas
    - remover carta
    - salvar em arquivo após alteração
*/

typedef struct
{
    char nome[50];
    int populacao;
    float area;
    float pib;
    float densidade;
    float pib_per_capita;
    int pontos_turisticos;
} Carta;

Carta cartas[MAX_CARTAS];
int carta_count = 0;

void carregar_cartas(const char *filename);
void salvar_cartas(const char *filename);
int ler_int(const char *prompt, int min, int max);
float ler_float(const char *prompt, float min, float max);
void mostrar_cartas();
void registrar_carta();
void compare_cartas(int carta1, int carta2);
void remover_carta();

void mostrar_menu();
void compare_menu();

// Função principal com loop do menu
int main()
{
    setlocale(LC_ALL, ""); // habilita acentuação local no console
    int escolha;
    carregar_cartas("cartas.txt"); // Load cartas from a file
    do
    {
        mostrar_menu();
        escolha = ler_int("Escolha a opção: ", 0, 4);
        switch (escolha)
        {
        case 1:
            mostrar_cartas();
            break;
        case 2:
            registrar_carta();
            break;
        case 3:
            compare_menu();
            break;
        case 4:
            remover_carta();
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (escolha != 0);
    return 0;
}

void carregar_cartas(const char *filename)
{
    // Carrega as cartas de um arquivo e popula o vetor global
    // Cada linha do arquivo deve conter: nome populacao area pib densidade pib_per_capita pontos_turisticos
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Não foi possível abrir o arquivo %s\n", filename);
        return;
    }
    while (carta_count < MAX_CARTAS && fscanf(file, "%49s %d %f %f %f %f %d", cartas[carta_count].nome, &cartas[carta_count].populacao, &cartas[carta_count].area, &cartas[carta_count].pib, &cartas[carta_count].densidade, &cartas[carta_count].pib_per_capita, &cartas[carta_count].pontos_turisticos) == 7)
    {
        carta_count++;
    }
    if (carta_count == MAX_CARTAS)
    {
        printf("Aviso: limite de %d cartas atingido, algumas entradas podem ter sido ignoradas\n", MAX_CARTAS);
    }
    fclose(file);
}

// Lê um número inteiro do usuário com validação de intervalo
int ler_int(const char *prompt, int min, int max)
{
    char buffer[128];
    int valor;

    while (1)
    {
        printf("%s", prompt);
        if (!fgets(buffer, sizeof(buffer), stdin))
        {
            continue;
        }

        if (sscanf(buffer, "%d", &valor) != 1)
        {
            printf("Entrada inválida. Digite um número inteiro.\n");
            continue;
        }

        if (valor < min || valor > max)
        {
            printf("Valor deve estar entre %d e %d.\n", min, max);
            continue;
        }

        return valor;
    }
}

// Lê um número de ponto flutuante do usuário com validação de intervalo
float ler_float(const char *prompt, float min, float max)
{
    char buffer[128];
    float valor;

    while (1)
    {
        printf("%s", prompt);
        if (!fgets(buffer, sizeof(buffer), stdin))
        {
            continue;
        }

        if (sscanf(buffer, "%f", &valor) != 1)
        {
            printf("Entrada inválida. Digite um número válido.\n");
            continue;
        }

        if (valor < min || valor > max)
        {
            printf("Valor deve estar entre %.2f e %.2f.\n", min, max);
            continue;
        }

        return valor;
    }
}

void salvar_cartas(const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        printf("Não foi possível salvar no arquivo %s\n", filename);
        return;
    }
    for (int i = 0; i < carta_count; i++)
    {
        fprintf(file, "%s %d %.2f %.2f %.2f %.2f %d\n", cartas[i].nome, cartas[i].populacao, cartas[i].area, cartas[i].pib, cartas[i].densidade, cartas[i].pib_per_capita, cartas[i].pontos_turisticos);
    }
    fclose(file);
    printf("Cartas salvas com sucesso em %s\n", filename);
}

void mostrar_cartas()
{
    for (int i = 0; i < carta_count; i++)
    {
        printf("Cartão %d: %s\n", i + 1, cartas[i].nome);
        printf(" População: %d\n", cartas[i].populacao);
        printf(" Área: %.2f\n", cartas[i].area);
        printf(" PIB: %.2f\n", cartas[i].pib);
        printf(" Densidade: %.2f\n", cartas[i].densidade);
        printf(" PIB per capita: %.2f\n", cartas[i].pib_per_capita);
        printf(" Pontos Turísticos: %d\n\n", cartas[i].pontos_turisticos);
    }
}

void registrar_carta()
{
    if (carta_count >= MAX_CARTAS)
    {
        printf("Limite de cartões atingido!\n");
        return;
    }
    printf("Digite o nome do cartão: ");
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }
    if (fgets(cartas[carta_count].nome, sizeof(cartas[carta_count].nome), stdin))
    {
        size_t len = strlen(cartas[carta_count].nome);
        if (len > 0 && cartas[carta_count].nome[len - 1] == '\n')
        {
            cartas[carta_count].nome[len - 1] = '\0';
        }
    }
    cartas[carta_count].populacao = ler_int("Digite a população: ", 0, INT_MAX);
    cartas[carta_count].area = ler_float("Digite a área: ", 0.0f, 1e12f);
    cartas[carta_count].pib = ler_float("Digite o PIB: ", 0.0f, 1e18f);
    cartas[carta_count].densidade = ler_float("Digite a densidade: ", 0.0f, 1e9f);
    cartas[carta_count].pib_per_capita = ler_float("Digite o PIB per capita: ", 0.0f, 1e12f);
    cartas[carta_count].pontos_turisticos = ler_int("Digite os pontos turísticos: ", 0, MAX_CARTAS);
    carta_count++;
    printf("Cartão registrado!\n");
    salvar_cartas("cartas.txt");
}

// Remove uma carta escolhida pelo usuário, deslocando restantes para manter vetor contínuo
void remover_carta()
{
    if (carta_count == 0)
    {
        printf("Nenhum cartão para remover.\n");
        return;
    }

    int idx = ler_int("Digite o índice do cartão a remover: ", 1, carta_count) - 1;

    // Move os cartões seguintes uma posição para trás, mantendo ordem
    for (int i = idx; i < carta_count - 1; i++)
    {
        cartas[i] = cartas[i + 1];
    }

    carta_count--;
    printf("Cartão removido com sucesso.\n");
    salvar_cartas("cartas.txt");
}

void compare_cartas(int carta1, int carta2)
{
    printf("Comparando %s and %s:\n", cartas[carta1].nome, cartas[carta2].nome);
    // Example comparison
    printf("Populacao: %d vs %d\n", cartas[carta1].populacao, cartas[carta2].populacao);
    // ... More comparisons for other attributes ...
}

void mostrar_menu()
{
    printf("\nMenu Principal:\n");
    printf("1. Exibir cartões\n");
    printf("2. Registrar cartão\n");
    printf("3. Comparar cartões\n");
    printf("4. Remover cartão\n");
    printf("0. Sair\n");
}

void compare_menu()
{
    if (carta_count == 0)
    {
        printf("Nenhum cartão disponível para comparar.\n");
        return;
    }

    int carta1 = ler_int("Entre com o índice do primeiro cartão a comparar: ", 1, carta_count);
    int carta2 = ler_int("Entre com o índice do segundo cartão a comparar: ", 1, carta_count);

    compare_cartas(carta1 - 1, carta2 - 1);
}