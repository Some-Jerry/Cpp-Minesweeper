#include "Tilemap.h"

Tilemap::Tilemap(int h, int w, int mines) : height(h), width(w), num_of_mines(mines) {
    tiles.resize(h * w, Tile(false));  // Initialize all tiles as non-mines
}

int Tilemap::get_height() const {
    return height;
}

void Tilemap::set_height(int h) {
    height = h;
    tiles.resize(height * width, Tile(false));
}

int Tilemap::get_width() const {
    return width;
}

void Tilemap::set_width(int w) {
    width = w;
    tiles.resize(height * width, Tile(false));
}

int Tilemap::get_num_of_mines() const {
    return num_of_mines;
}

void Tilemap::set_num_of_mines(int mines) {
    num_of_mines = mines;
}

void Tilemap::populate() {
    // Implementation remains empty for now
}