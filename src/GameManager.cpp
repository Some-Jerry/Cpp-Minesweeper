#include "GameManager.h"

    // Constructors
    GameManager::GameManager() {
        // difficulty = DIFFICULTY_EASY;
        total_score = 0;
    }

    GameManager::GameManager(int height, int width, int mines, int totalScore) {
        // specify difficulty in GM that will tell the Tilemap what size map and how many mines
        total_score = totalScore;
    }
    
    void start_game();

    bool GameManager::open_tile(int x, int y) {

        int index = (y * map.get_width()) + x;
        Tile currentTile = map.get_tile_at_index(index);
        bool mineFound = currentTile.get_is_Mine();
        bool openedMine = false;

        currentTile.set_is_Open(true);

        if (currentTile.get_score() == 0) 
        {
            propagate_open(x, y);
        }
        else if (currentTile.get_is_Mine())
        {
            set_game_over(true);
            set_game_won(false);
            openedMine = true;
        } else {
            add_score(currentTile.get_score());
        }
    }   

    void GameManager::flag_tile(int x, int y) {
        map.get_tile_at_index( y * map.get_height() + x).set_is_Flagged(true);
     }

    bool GameManager::is_game_over() const {
        return game_over;
    }

    void GameManager::set_game_over(bool isGameOver) {
        game_over = isGameOver;
    }

    bool GameManager::is_game_won() const {
        return game_won;
    }

    void GameManager::set_game_won(bool isGameWon) {
        game_won = isGameWon;
    }

    void GameManager::add_score(int scoreIncrease) {
        total_score += scoreIncrease;
    }
    
    void GameManager::propagate_open(int x, int y) {
        // Called when a zero tile is opened
        // Open all neighbors. If a zero is opened, call recursively
        
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;  // Skip the tile itself
                int nx = x + dx; 
                int ny = y + dy;
                if (nx >= 0 && nx < map.get_width() && ny >= 0 && ny < map.get_height()) {
                if (!map.get_tile_at_index(ny * map.get_width() + nx).get_is_Open())
                {
                    open_tile(nx, ny);
                };
                }
            }
        }
    }


