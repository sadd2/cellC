// cell.cpp
#include "cell.h"

Cell::Cell() : alive(false) {}

void Cell::setAlive(bool state) {
    alive = state;
}

bool Cell::isAlive() const {
    return alive;
}
