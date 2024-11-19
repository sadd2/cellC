// grid.h
#ifndef GRID_H
#define GRID_H

#include "cell.h"

class Grid {
private:
    int rows;
    int cols;
    Cell** cells;

public:
    Grid(int rows, int cols);
    ~Grid();
    void initialize();
    void display() const;
    void update();
};

#endif // GRID_H
