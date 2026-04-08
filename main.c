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

// Estrutura que representa uma carta do jogo SuperTrunfo
typedef struct
{
    char nome[50];         // Nome da cidade ou entidade
    int populacao;         // População
    float area;            // Área em km²
    float pib;             // PIB em bilhões
    float densidade;       // Densidade populacional
    float pib_per_capita;  // PIB per capita
    int pontos_turisticos; // Número de pontos turísticos
} Carta;

// Array global para armazenar as cartas
Carta cartas[MAX_CARTAS];
// Contador global do número de cartas carregadas
int carta_count = 0;

// Declarações das funções
void carregar_cartas(const char *filename);                // Carrega cartas de um arquivo
void salvar_cartas(const char *filename);                  // Salva cartas em um arquivo
int ler_int(const char *prompt, int min, int max);         // Lê um inteiro com validação
float ler_float(const char *prompt, float min, float max); // Lê um float com validação
void mostrar_cartas();                                     // Exibe todas as cartas
void registrar_carta();                                    // Registra uma nova carta
void compare_cartas(int carta1, int carta2);               // Compara duas cartas
void remover_carta();                                      // Remove uma carta
void inicializar_cartas_amostra();                         // Inicializa cartas de exemplo

void mostrar_menu(); // Mostra o menu principal
void compare_menu(); // Menu para comparação de cartas

// Função principal com loop do menu
int main()
{
    system("chcp 65001 > nul"); // Define o console para UTF-8
    setlocale(LC_ALL, "");      // habilita acentuação local no console
    int escolha;
    carregar_cartas("cartas.txt"); // Carrega cartas do arquivo
    if (carta_count == 0)          // Se não há cartas, inicializa com exemplos
    {
        inicializar_cartas_amostra();
    }
    do
    {
        mostrar_menu();                               // Exibe o menu
        escolha = ler_int("Escolha a opcao: ", 0, 4); // Lê a escolha do usuário
        switch (escolha)
        {
        case 1:
            mostrar_cartas(); // Exibe todas as cartas
            break;
        case 2:
            registrar_carta(); // Registra uma nova carta
            break;
        case 3:
            compare_menu(); // Menu de comparação
            break;
        case 4:
            remover_carta(); // Remove uma carta
            break;
        case 0:
            printf("Saindo...\n"); // Sai do programa
            break;
        default:
            printf("Opcao invalida!\n"); // Opção inválida
        }
    } while (escolha != 0); // Loop até escolher sair
    return 0;
}

void carregar_cartas(const char *filename)
{
    // Carrega as cartas de um arquivo e popula o vetor global
    // Cada linha do arquivo deve conter: nome populacao area pib densidade pib_per_capita pontos_turisticos
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Nao foi possivel abrir o arquivo %s\n", filename);
        return;
    }
    while (carta_count < MAX_CARTAS && fscanf(file, "%49s %d %f %f %f %f %d", cartas[carta_count].nome, &cartas[carta_count].populacao, &cartas[carta_count].area, &cartas[carta_count].pib, &cartas[carta_count].densidade, &cartas[carta_count].pib_per_capita, &cartas[carta_count].pontos_turisticos) == 7)
    {
        carta_count++; // Incrementa o contador de cartas
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
            continue; // Se falhar, tenta novamente
        }

        if (sscanf(buffer, "%d", &valor) != 1)
        {
            printf("Entrada invalida. Digite um numero inteiro.\n");
            continue; // Entrada inválida, tenta novamente
        }

        if (valor < min || valor > max)
        {
            printf("Valor deve estar entre %d e %d.\n", min, max);
            continue; // Fora do intervalo, tenta novamente
        }

        return valor; // Retorna o valor válido
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
            continue; // Se falhar, tenta novamente
        }

        if (sscanf(buffer, "%f", &valor) != 1)
        {
            printf("Entrada invalida. Digite um numero valido.\n");
            continue; // Entrada inválida, tenta novamente
        }

        if (valor < min || valor > max)
        {
            printf("Valor deve estar entre %.2f e %.2f.\n", min, max);
            continue; // Fora do intervalo, tenta novamente
        }

        return valor; // Retorna o valor válido
    }
}

void salvar_cartas(const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        printf("Nao foi possivel salvar no arquivo %s\n", filename);
        return;
    }
    for (int i = 0; i < carta_count; i++)
    {
        // Salva cada carta no formato: nome populacao area pib densidade pib_per_capita pontos_turisticos
        fprintf(file, "%s %d %.2f %.2f %.2f %.2f %d\n", cartas[i].nome, cartas[i].populacao, cartas[i].area, cartas[i].pib, cartas[i].densidade, cartas[i].pib_per_capita, cartas[i].pontos_turisticos);
    }
    fclose(file);
    printf("Cartas salvas com sucesso em %s\n", filename);
}

void inicializar_cartas_amostra()
{
    // Inicializa 10 cartas de exemplo com dados aproximados de cidades brasileiras
    strcpy(cartas[0].nome, "Sao Paulo");
    cartas[0].populacao = 12400000;
    cartas[0].area = 1521.0f;
    cartas[0].pib = 700.0f;
    cartas[0].densidade = 8150.0f;
    cartas[0].pib_per_capita = 56000.0f;
    cartas[0].pontos_turisticos = 100;

    strcpy(cartas[1].nome, "Rio de Janeiro");
    cartas[1].populacao = 6700000;
    cartas[1].area = 1200.0f;
    cartas[1].pib = 300.0f;
    cartas[1].densidade = 5583.0f;
    cartas[1].pib_per_capita = 44776.0f;
    cartas[1].pontos_turisticos = 80;

    strcpy(cartas[2].nome, "Salvador");
    cartas[2].populacao = 2900000;
    cartas[2].area = 693.0f;
    cartas[2].pib = 60.0f;
    cartas[2].densidade = 4185.0f;
    cartas[2].pib_per_capita = 20690.0f;
    cartas[2].pontos_turisticos = 60;

    strcpy(cartas[3].nome, "Brasilia");
    cartas[3].populacao = 3100000;
    cartas[3].area = 5802.0f;
    cartas[3].pib = 120.0f;
    cartas[3].densidade = 534.0f;
    cartas[3].pib_per_capita = 38710.0f;
    cartas[3].pontos_turisticos = 70;

    strcpy(cartas[4].nome, "Fortaleza");
    cartas[4].populacao = 2700000;
    cartas[4].area = 314.0f;
    cartas[4].pib = 40.0f;
    cartas[4].densidade = 8600.0f;
    cartas[4].pib_per_capita = 14815.0f;
    cartas[4].pontos_turisticos = 50;

    strcpy(cartas[5].nome, "Belo Horizonte");
    cartas[5].populacao = 2500000;
    cartas[5].area = 331.0f;
    cartas[5].pib = 80.0f;
    cartas[5].densidade = 7559.0f;
    cartas[5].pib_per_capita = 32000.0f;
    cartas[5].pontos_turisticos = 55;

    strcpy(cartas[6].nome, "Manaus");
    cartas[6].populacao = 2200000;
    cartas[6].area = 11401.0f;
    cartas[6].pib = 50.0f;
    cartas[6].densidade = 193.0f;
    cartas[6].pib_per_capita = 22727.0f;
    cartas[6].pontos_turisticos = 45;

    strcpy(cartas[7].nome, "Curitiba");
    cartas[7].populacao = 1900000;
    cartas[7].area = 435.0f;
    cartas[7].pib = 70.0f;
    cartas[7].densidade = 4368.0f;
    cartas[7].pib_per_capita = 36842.0f;
    cartas[7].pontos_turisticos = 65;

    strcpy(cartas[8].nome, "Recife");
    cartas[8].populacao = 1700000;
    cartas[8].area = 218.0f;
    cartas[8].pib = 50.0f;
    cartas[8].densidade = 7798.0f;
    cartas[8].pib_per_capita = 29412.0f;
    cartas[8].pontos_turisticos = 55;

    strcpy(cartas[9].nome, "Porto Alegre");
    cartas[9].populacao = 1500000;
    cartas[9].area = 496.0f;
    cartas[9].pib = 60.0f;
    cartas[9].densidade = 3024.0f;
    cartas[9].pib_per_capita = 40000.0f;
    cartas[9].pontos_turisticos = 50;

    carta_count = 10; // Define o número de cartas
}

void mostrar_cartas()
{
    for (int i = 0; i < carta_count; i++) // Loop para cada carta
    {
        printf("Cartao %d: %s\n", i + 1, cartas[i].nome);
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
        printf("Limite de cartoes atingido!\n");
        return;
    }
    printf("Digite o nome do cartao: ");
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) // Limpa o buffer de entrada
    {
    }
    if (fgets(cartas[carta_count].nome, sizeof(cartas[carta_count].nome), stdin))
    {
        size_t len = strlen(cartas[carta_count].nome);
        if (len > 0 && cartas[carta_count].nome[len - 1] == '\n')
        {
            cartas[carta_count].nome[len - 1] = '\0'; // Remove o \n
        }
    }
    // Lê os atributos da carta
    cartas[carta_count].populacao = ler_int("Digite a população: ", 0, INT_MAX);
    cartas[carta_count].area = ler_float("Digite a área: ", 0.0f, 1e12f);
    cartas[carta_count].pib = ler_float("Digite o PIB: ", 0.0f, 1e18f);
    cartas[carta_count].densidade = ler_float("Digite a densidade: ", 0.0f, 1e9f);
    cartas[carta_count].pib_per_capita = ler_float("Digite o PIB per capita: ", 0.0f, 1e12f);
    cartas[carta_count].pontos_turisticos = ler_int("Digite os pontos turísticos: ", 0, MAX_CARTAS);
    carta_count++; // Incrementa o contador
    printf("Cartao registrado!\n");
    salvar_cartas("cartas.txt"); // Salva no arquivo
}

// Remove uma carta escolhida pelo usuário, deslocando restantes para manter vetor contínuo
void remover_carta()
{
    if (carta_count == 0)
    {
        printf("Nenhum cartao para remover.\n");
        return;
    }

    int idx = ler_int("Digite o indice do cartao a remover: ", 1, carta_count) - 1;

    // Move os cartões seguintes uma posição para trás, mantendo ordem
    for (int i = idx; i < carta_count - 1; i++)
    {
        cartas[i] = cartas[i + 1];
    }

    carta_count--; // Decrementa o contador
    printf("Cartao removido com sucesso.\n");
    salvar_cartas("cartas.txt"); // Salva no arquivo
}

void compare_cartas(int carta1, int carta2)
{
    printf("Comparando %s e %s:\n", cartas[carta1].nome, cartas[carta2].nome);

    // Compara cada atributo e determina o vencedor (maior valor ganha)
    // Comparar população
    printf("População: %s (%d) vs %s (%d) - %s vence\n",
           cartas[carta1].nome, cartas[carta1].populacao,
           cartas[carta2].nome, cartas[carta2].populacao,
           (cartas[carta1].populacao > cartas[carta2].populacao ? cartas[carta1].nome : cartas[carta2].nome));

    // Comparar área
    printf("Área: %s (%.2f) vs %s (%.2f) - %s vence\n",
           cartas[carta1].nome, cartas[carta1].area,
           cartas[carta2].nome, cartas[carta2].area,
           (cartas[carta1].area > cartas[carta2].area ? cartas[carta1].nome : cartas[carta2].nome));

    // Comparar PIB
    printf("PIB: %s (%.2f) vs %s (%.2f) - %s vence\n",
           cartas[carta1].nome, cartas[carta1].pib,
           cartas[carta2].nome, cartas[carta2].pib,
           (cartas[carta1].pib > cartas[carta2].pib ? cartas[carta1].nome : cartas[carta2].nome));

    // Comparar densidade (nota: menor densidade pode ser melhor, mas aqui comparamos maior)
    printf("Densidade: %s (%.2f) vs %s (%.2f) - %s vence\n",
           cartas[carta1].nome, cartas[carta1].densidade,
           cartas[carta2].nome, cartas[carta2].densidade,
           (cartas[carta1].densidade > cartas[carta2].densidade ? cartas[carta1].nome : cartas[carta2].nome));

    // Comparar PIB per capita
    printf("PIB per capita: %s (%.2f) vs %s (%.2f) - %s vence\n",
           cartas[carta1].nome, cartas[carta1].pib_per_capita,
           cartas[carta2].nome, cartas[carta2].pib_per_capita,
           (cartas[carta1].pib_per_capita > cartas[carta2].pib_per_capita ? cartas[carta1].nome : cartas[carta2].nome));

    // Comparar pontos turísticos
    printf("Pontos turísticos: %s (%d) vs %s (%d) - %s vence\n",
           cartas[carta1].nome, cartas[carta1].pontos_turisticos,
           cartas[carta2].nome, cartas[carta2].pontos_turisticos,
           (cartas[carta1].pontos_turisticos > cartas[carta2].pontos_turisticos ? cartas[carta1].nome : cartas[carta2].nome));
}

void mostrar_menu()
{
    printf("\nMenu Principal:\n");
    printf("1. Exibir cartoes\n");
    printf("2. Registrar cartao\n");
    printf("3. Comparar cartoes\n");
    printf("4. Remover cartao\n");
    printf("0. Sair\n");
}

void compare_menu()
{
    if (carta_count == 0)
    {
        printf("Nenhum cartao disponivel para comparar.\n");
        return;
    }

    int carta1 = ler_int("Entre com o indice do primeiro cartao a comparar: ", 1, carta_count);
    int carta2 = ler_int("Entre com o indice do segundo cartao a comparar: ", 1, carta_count);

    compare_cartas(carta1 - 1, carta2 - 1); // Chama a função de comparação (índices baseados em 0)
}