#include "GameManager.h"

    // Constructors
    // GameManager(int height, int width, int mines) {};

    void start_game();

    bool GameManager::open_tile(int x, int y) {
        int index = (y * map.get_height()) + x;
        bool mineFound = map.get_tile_at_index(index).get_is_Mine();
    }

    void flag_tile(int x, int y);
    bool is_game_over() const;
    bool is_game_won() const;
    void reveal_all_tiles();
    int get_adjacent_mines(int x, int y) const;

    void check_win_condition();
    void propagate_open(int x, int y);


