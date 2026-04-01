#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARDS 100

typedef struct {
    char name[50];
    int attack;
    int defense;
    int speed;
} Card;

Card cards[MAX_CARDS];
int card_count = 0;

void register_card() {
    if (card_count >= MAX_CARDS) {
        printf("Card limit reached.\n");
        return;
    }
    printf("Enter card name: ");
    scanf("%s", cards[card_count].name);
    printf("Enter attack: ");
    scanf("%d", &cards[card_count].attack);
    printf("Enter defense: ");
    scanf("%d", &cards[card_count].defense);
    printf("Enter speed: ");
    scanf("%d", &cards[card_count].speed);
    card_count++;
    printf("Card registered successfully!\n");
}

void load_cards_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }
    while (fscanf(file, "%49s %d %d %d", cards[card_count].name, &cards[card_count].attack, &cards[card_count].defense, &cards[card_count].speed) == 4) {
        card_count++;
    }
    fclose(file);
    printf("Cards loaded from file successfully!\n");
}

void display_menu() {
    printf("1. Register Card\n");
    printf("2. Load Cards from File\n");
    printf("0. Exit\n");
}

int main() {
    int choice;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                register_card();
                break;
            case 2:
                load_cards_from_file("cards.txt");
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}