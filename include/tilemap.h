#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include "Tile.h"

class Tilemap {
private:
    std::vector<Tile> tiles;
    int height;
    int width;
    int num_of_mines;

public:
    // Constructor
    Tilemap(int h, int w, int mines);

    // Getters and setters
    int get_height() const;
    void set_height(int h);
    int get_width() const;
    void set_width(int w);
    int get_num_of_mines() const;
    void set_num_of_mines(int mines);

    // Other member functions
    void populate();
};

#endif // TILEMAP_H