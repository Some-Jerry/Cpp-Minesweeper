#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include "Tile.h"

class Tilemap {
private:
    std::vector<Tile> tiles;
    int height;
    int width;
    int mines;
    int nonMines;

public:
    // Constructor
    Tilemap(int h, int w, int mines);

    // Getters and setters
    int get_height() const;
    void set_height(int h);
    int get_width() const;
    void set_width(int w);
    int get_mines() const;
    void set_mines(int newMines);
    int get_non_mines() const;
    void set_non_mines(int newNonMines);

    // Other member functions
    void reset();
    void populate();
};

#endif // TILEMAP_H