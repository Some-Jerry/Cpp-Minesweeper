#include "Tile.h"

// Constructors
Tile::Tile() : mine(false), open(false), flag(false), score(0) {};

Tile::Tile(bool isMine, bool isOpen, bool isFlagged, int startingScore) : mine(isMine), open(isOpen), flag(isFlagged), score(startingScore) {}

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

bool Tile::get_is_Flagged() const {
    return flag;
}

void Tile::set_is_Flagged(bool isFlagged) {
    flag = isFlagged;
}

int Tile::get_score() const {
    return score;
}

void Tile::set_score(int newScore) {
    score = newScore;
}