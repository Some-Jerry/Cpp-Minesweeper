#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Tilemap.h"

class GameManager {
private:
    Tilemap map;
    bool game_over;
    bool game_won;
    int total_score;
    int tiles_remaining;

public:
    GameManager();
    GameManager(int height, int width, int num_mines, int totalScore);

    void start_game();
    bool open_tile(int x, int y);
    void flag_tile(int x, int y);
    bool is_game_over() const;
    void set_game_over(bool isGameOver);
    bool is_game_won() const;
    void set_game_won(bool isGameWon);
    void add_score(int additionalScore);

private:
    void propagate_open(int x, int y);
};

#endif // GAMEMANAGER_H