#include "tile.h"

// Constructors

Tile::Tile() : mine(false), open (false), score(0) {};

Tile::Tile(bool isMine, bool isOpen, int startingScore) : mine(isMine), open(isOpen), score(startingScore) {}

// Member functions
bool Tile::get_is_Open() const {
    return open;
}

bool Tile::get_is_Mine() const {
    return mine;
}

void Tile::set_is_Open(bool isOpen) {
    open = isOpen;
}

void Tile::set_is_Mine(bool isMine) {
    mine = isMine;
}

int Tile::get_score() const {
    return score;
}

void Tile::set_score(int newScore) {
    score = newScore;
}