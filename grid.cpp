// grid.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "grid.h"

Grid::Grid(int rows, int cols) : rows(rows), cols(cols) {
    cells = new Cell*[rows];
    for (int i = 0; i < rows; ++i) {
        cells[i] = new Cell[cols];
    }
}

Grid::~Grid() {
    for (int i = 0; i < rows; ++i) {
        delete[] cells[i];
    }
    delete[] cells;
}

void Grid::initialize() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cells[i][j].setAlive(std::rand() % 2); // Randomly set cells to alive or dead
        }
    }
}

void Grid::display() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << (cells[i][j].isAlive() ? "O" : ".") << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::update() {
    // Create a temporary grid to store the next state
    Cell** newCells = new Cell*[rows];
    for (int i = 0; i < rows; ++i) {
        newCells[i] = new Cell[cols];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int aliveNeighbors = 0;

            // Count alive neighbors
            for (int x = -1; x <= 1; ++x) {
                for (int y = -1; y <= 1; ++y) {
                    if (x == 0 && y == 0) continue; // Skip the cell itself
                   int newRow = i + x;
                    int newCol = j + y;
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                        aliveNeighbors += cells[newRow][newCol].isAlive();
                    }
                }
            }

            // Apply the rules of the Game of Life
            if (cells[i][j].isAlive()) {
                newCells[i][j].setAlive(aliveNeighbors == 2 || aliveNeighbors == 3);
            } else {
                newCells[i][j].setAlive(aliveNeighbors == 3);
            }
        }
    }

    // Update the cells to the new state
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cells[i][j] = newCells[i][j];
        }
        delete[] newCells[i];
    }
    delete[] newCells;
}
