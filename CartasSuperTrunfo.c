#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARDS 100

typedef struct {
    char name[50];
    int population;
    float area;
    float pib;
    float density;
    float pib_per_capita;
    int tourist_points;
} Card;

Card cards[MAX_CARDS];
int card_count = 0;

void load_cards(const char *filename);
void display_cards();
void register_card();
void compare_cards(int card1, int card2);

void display_menu();
void comparison_menu();

int main() {
    int choice;
    load_cards("cards.txt"); // Load cards from a file
    do {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: display_cards(); break;
            case 2: register_card(); break;
            case 3: comparison_menu(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 0);
    return 0;
}

void load_cards(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return;
    }
    while (fscanf(file, "%49s %d %f %f %f %f %d", cards[card_count].name, &cards[card_count].population, &cards[card_count].area, &cards[card_count].pib, &cards[card_count].density, &cards[card_count].pib_per_capita, &cards[card_count].tourist_points) == 7) {
        card_count++;
    }
    fclose(file);
}

void display_cards() {
    for (int i = 0; i < card_count; i++) {
        printf("Card %d: %s\n", i + 1, cards[i].name);
        printf(" Population: %d\n", cards[i].population);
        printf(" Area: %.2f\n", cards[i].area);
        printf(" PIB: %.2f\n", cards[i].pib);
        printf(" Density: %.2f\n", cards[i].density);
        printf(" PIB per capita: %.2f\n", cards[i].pib_per_capita);
        printf(" Tourist Points: %d\n\n", cards[i].tourist_points);
    }
}

void register_card() {
    if (card_count >= MAX_CARDS) {
        printf("Card limit reached!\n");
        return;
    }
    printf("Enter card name: ");
    scanf("%49s", cards[card_count].name);
    printf("Enter population: ");
    scanf("%d", &cards[card_count].population);
    printf("Enter area: ");
    scanf("%f", &cards[card_count].area);
    printf("Enter PIB: ");
    scanf("%f", &cards[card_count].pib);
    printf("Enter density: ");
    scanf("%f", &cards[card_count].density);
    printf("Enter PIB per capita: ");
    scanf("%f", &cards[card_count].pib_per_capita);
    printf("Enter tourist points: ");
    scanf("%d", &cards[card_count].tourist_points);
    card_count++;
    printf("Card registered!\n");
}

void compare_cards(int card1, int card2) {
    printf("Comparing %s and %s:\n", cards[card1].name, cards[card2].name);
    // Example comparison
    printf("Population: %d vs %d\n", cards[card1].population, cards[card2].population);
    // ... More comparisons for other attributes ... 
}

void display_menu() {
    printf("\nMain Menu:\n");
    printf("1. Display Cards\n");
    printf("2. Register Card\n");
    printf("3. Compare Cards\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
}

void comparison_menu() {
    int card1, card2;
    printf("Enter the index of the first card to compare: ");
    scanf("%d", &card1);
    printf("Enter the index of the second card to compare: ");
    scanf("%d", &card2);
    compare_cards(card1-1, card2-1);
}