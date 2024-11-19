// game.cpp
#include <iostream>
#include "game.h"
#include "grid.h"

Game::Game() {}

void Game::run() {
    Grid grid(10, 10); // Create a 10x10 grid
    grid.initialize(); // Initialize the grid with a random state

    char choice;
    do {
        grid.display(); // Display the current state of the grid
        grid.update();  // Update the grid based on the rules
        std::cout << "Press 'q' to quit or any other key to continue: ";
        std::cin >> choice;
    } while (choice != 'q');
}
