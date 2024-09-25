#include "Tilemap.h"
#include <random>
#include <algorithm>
#include <utility>


Tilemap::Tilemap(int h, int w, int startingMines) : height(h), width(w), mines(startingMines) {
    tiles.resize(h * w, Tile());  // Initialize all tiles as non-mines
}

Tile& Tilemap::get_tile_at_index(int index) {
    return tiles[index];
}

int Tilemap::get_height() const {
    return height;
}

void Tilemap::set_height(int h) {
    height = h;
    tiles.resize(height * width, Tile());
}

int Tilemap::get_width() const {
    return width;
}

void Tilemap::set_width(int w) {
    width = w;
    tiles.resize(height * width, Tile());
}

int Tilemap::get_mines() const {
    return mines;
}

void Tilemap::set_mines(int newMines) {
    mines = newMines;
}

int Tilemap::get_non_mines() const {
    return nonMines;
}

void Tilemap::set_non_mines(int newNonMines) {
    nonMines = newNonMines;
}

void Tilemap::reset() {
    // Reset all tiles
    for (auto& tile : tiles) {
        tile = Tile();  // Reconstruct each tile as a new tile (non-mine, closed, 0 score)
    }
}

void Tilemap::populate() {
    // Reset tiles
    reset();
    // Randomly place mines
    std::vector<int> indices(width * height);
    std::iota(indices.begin(), indices.end(), 0);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(indices.begin(), indices.end(), g);

    // Place mines at each index
    for (int i = 0; i < mines; ++i) {
        int index = indices[i];
        tiles[index].set_is_Mine(true);  // Set as mine
    }


    // Loop through each tile
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // 2D array stored as 1D, take y * width to get row selection, + x to get to correct column. If its not a mine, score it.
            if (!tiles[y * width + x].get_is_Mine()) {
                int score = 0;
                // Checks the lower 3 neighbors, middle 3 neighbors, upper 3 neighbors in that order
                for (int dy = -1; dy <= 1; ++dy) {
                    for (int dx = -1; dx <= 1; ++dx) {
                        int nx = x + dx, ny = y + dy;
                        // Bounds check
                        if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                            if (tiles[ny * width + nx].get_is_Mine()) {
                                ++score;
                            }
                        }
                    }
                }
                // Assuming we add a set_Score method to Tile class
                tiles[y * width + x].set_score(score);
            }
        }
    }
}