// cell.h
#ifndef CELL_H
#define CELL_H

class Cell {
private:
    bool alive;

public:
    Cell();
    void setAlive(bool state);
    bool isAlive() const;
};

#endif // CELL_H
