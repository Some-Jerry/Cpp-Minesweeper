#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Tilemap.h"

class GameManager {
private:
    Tilemap map;
    bool game_over;
    bool game_won;

public:
    GameManager(int height, int width, int num_mines);

    void start_game();
    bool open_tile(int x, int y);
    void flag_tile(int x, int y);
    bool is_game_over() const;
    bool is_game_won() const;
    void reveal_all_tiles();
    int get_adjacent_mines(int x, int y) const;

private:
    void check_win_condition();
    void propagate_open(int x, int y);
};

#endif // GAMEMANAGER_H