// Enhanced version of CartasSuperTrunfo.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARDS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int power;
} Card;

Card cards[MAX_CARDS];
int cardCount = 0;

void compareCards(Card a, Card b) {
    if (a.power > b.power) {
        printf("%s has more power than %s.\n", a.name, b.name);
    } else if (a.power < b.power) {
        printf("%s has more power than %s.\n", b.name, a.name);
    } else {
        printf("%s and %s have equal power.\n", a.name, b.name);
    }
}

void displayMenu() {
    printf("Menu:\n");
    printf("1. Compare two cards\n");
    printf("2. Exit\n");
}

int main() {
    // Sample card data
    strcpy(cards[0].name, "Card A");
    cards[0].power = 50;
    strcpy(cards[1].name, "Card B");
    cards[1].power = 75;
    cardCount = 2;

    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            int cardIndex1, cardIndex2;
            printf("Enter index of first card (0 to %d): ", cardCount - 1);
            scanf("%d", &cardIndex1);
            printf("Enter index of second card (0 to %d): ", cardCount - 1);
            scanf("%d", &cardIndex2);
            if (cardIndex1 >= 0 && cardIndex1 < cardCount && cardIndex2 >= 0 && cardIndex2 < cardCount) {
                compareCards(cards[cardIndex1], cards[cardIndex2]);
            } else {
                printf("Invalid card indices.\n");
            }
        } else if (choice == 2) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}