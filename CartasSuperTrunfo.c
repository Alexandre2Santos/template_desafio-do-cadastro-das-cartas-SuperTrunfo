// Code to load card data and handle comparisons of multiple attributes

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Structure to represent a card
struct Card {
    std::string name;
    int population;
    double area;
    double PIB;
};

// Load card data from a blob
std::vector<Card> loadData() {
    std::vector<Card> cards;
    // Simulate loading data from a blob (replace with actual loading logic)
    // Example data
    cards.push_back({"Card1", 5000000, 2000.5, 30000});
    cards.push_back({"Card2", 3000000, 1500.0, 25000});
    return cards;
}

// Function to compare two cards based on selected attribute
int compareCards(const Card &a, const Card &b, int attribute) {
    switch(attribute) {
        case 1: // Compare by population
            return a.population < b.population;
        case 2: // Compare by area
            return a.area < b.area;
        case 3: // Compare by PIB
            return a.PIB < b.PIB;
        default:
            return false;
    }
}

// Main function
int main() {
    std::vector<Card> cards = loadData();
    int choice;

    std::cout << "Select a comparison attribute:\n1. Population\n2. Area\n3. PIB\nChoice: ";
    std::cin >> choice;

    // Sort cards based on the chosen attribute
    std::sort(cards.begin(), cards.end(), [choice](const Card &a, const Card &b) {
        return compareCards(a, b, choice);
    });

    // Display sorted cards
    for (const auto &card : cards) {
        std::cout << card.name << ": Population: " << card.population << ", Area: " << card.area << ", PIB: " << card.PIB << '\n';
    }

    return 0;
}