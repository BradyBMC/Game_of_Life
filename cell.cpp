#include "cell.hpp"

cell :: cell() {

}

cell :: cell (int x, int y,bool alive) {
    coord = {x,y};
    this->alive = alive;
}

bool cell :: isAlive() {
    return alive;
}

void cell :: kill() {
    alive = false;
}

void cell :: born() {
    alive = true;
}