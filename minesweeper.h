#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <vector>
#include <iostream>
#include <random>
#include <time.h>
#include <string>
#include <sstream>
#include <utility>
#include <array>

using namespace std;

// Global constant for adjacent tile checking
constexpr array<pair<int, int>, 8> directions = {
    make_pair(-1, -1), make_pair(-1, 0), make_pair(-1, 1),
    make_pair(0, -1),                    make_pair(0, 1),
    make_pair(1, -1),  make_pair(1, 0),  make_pair(1, 1)
};

class Minesweeper {
private:
    int map_size;
    int mines;
    double score;
    bool gameover;
    vector<vector<char>> displaymap;
    vector<vector<int>> scoremap;
    

public:
    // Constructors
    Minesweeper(); 

    // Helper Functions
    void difficulty_request(); // easy - medium - hard? effects map_size + mines
    void display_map();
    void display_scoremap();
    void generate_scoremap(); 
    bool index_valid(int row, int col, int size);
    int tile_selection(); // 1 == game over
    void open_tile(int x, int y);
    pair<int,int> random_position(int map_size);

    // Getters + Setters
    int get_map_size();
    void set_map_size(int size);
    int get_mines();
    void set_mines(int mines);
    int get_score();
    void set_score(int score);
    

};

#endif
