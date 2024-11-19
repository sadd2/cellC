// rules.cpp
#include "rules.h"

bool Rules::applyRules(bool currentState, int aliveNeighbors) {
    if (currentState) {
        return (aliveNeighbors == 2 || aliveNeighbors == 3); // Survive
    } else {
        return (aliveNeighbors == 3); // Reproduce
    }
}
