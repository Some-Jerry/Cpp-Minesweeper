#include "minesweeper.h"

using namespace std;

Minesweeper::Minesweeper() {
    // Easy difficulty default values
    map_size = 5;
    mines = 8;
    score = 0;
    gameover = false;

    // Size displaymap & scoremap based on map_size
    // displaymap is chars, initialized to quesiton marks (?)
    // scoremap is ints, initliazed to zeros (0)
    displaymap.resize(map_size, vector<char>(map_size, '?'));
    scoremap.resize(map_size, vector<int>(map_size, 0));
};

// Generate mines / score tiles on the scoremap
void Minesweeper::generate_scoremap() {

    // First, generate mines on map
    int mine_count = this->mines;
    // While we have mines to place
    while (mine_count != 0) {
        // Get a random position on the map
        pair<int,int> position = random_position(this->map_size);
        int x = position.first;
        int y = position.second;

        // If it's not already a mine (mines = -1, other tiles = how many mines are touching the tile)
        int tile = this->scoremap[x][y];
        if (tile != -1) {
            tile = -1;
            this->scoremap[x][y] = tile;
            mine_count--;
        }
        else {
            // find a new spot for this mine
        }
    }

    // Next, set score of each tile that isn't a mine
    // Check each tile and set its score
    for (int i = 0; i < this->map_size; i++) {

        for (int j = 0; j < this->map_size; j++) {
            int tilescore = 0;

            // Check to make sure it isn't a mine
            if (this->scoremap[i][j] != -1) {

            // Check all adjacent cells for mines
                for (const auto& dir : directions) {
                    int newi = i + dir.first;
                    int newj = j + dir.second;

                    // If the index is in the map
                    if (index_valid(newi,newj,this->map_size)) {

                        // and its a mine, increase tile score
                        if (this->scoremap[newi][newj] == -1) {
                            tilescore++;
                        }
                    }
                }
            // Set tile score on scoremap
            this->scoremap[i][j] = tilescore;
            tilescore = 0;
            }
        }
    }
}

// Checks if a given index is valid 
// (i.e., make sure we are within the bounds of the map)
bool Minesweeper::index_valid(int row, int col, int size) {
    return (row >= 0 && row < size && col >= 0 && col < size);
}

// Print a readable version of the gamemap to the console
void Minesweeper::display_map() {

    // Print spaces to line up top row of coords with displaymap
    cout <<"   ";

    // Print the first row as coordinates for user input
    for (int i = 0; i < this->map_size; i++) {
        cout << i << " ";
    }
    cout << endl;

    // Print spaces to line up separater (-) with top row coords
    cout << "   ";

    // Print line to separate coordinates from game tiles
        for (int i = 0; i < this->map_size; i++) {
        cout << "- ";
    }
    cout << endl;

    // Print coords before each row followed by pipe char
    int i = 0;
    for (const auto& row : this->displaymap) {
        cout << i << " |";
        i++;
        for (const auto& cell : row) {
             cout << cell << " ";
        }
        cout << endl;
    }
}

// Print a readable version of the scoremap to the console
void Minesweeper::display_scoremap() {


    for (const auto& row : this->scoremap) {
            for (const auto& cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    }

// Returns a random (x,y) position on the map
pair<int,int> Minesweeper::random_position(int map_size) {
    // Return pair var
    pair<int,int> ret;
    
    // Providing a seed value based on current time
	srand((unsigned)time(NULL));

	// Get a random numbers 0-4 inclusive, set them as the pair to return
	int first = rand() % map_size;
    int second = rand() % map_size;

    ret.first = first;
    ret.second = second;

    return ret;

}

// Takes in an index from the user for which tile they would like to open
int Minesweeper::tile_selection() {
    
    // Variables to store input and index
    string input;
    int x,y;
    bool valid_input = false;

    // Request input until a valid index is entered
    while(!valid_input) {
        
        // Get user input
        cout << "Select a tile (E.g., \"0 0\"): ";
        getline(cin, input);

        // Parse user input into index variables
        istringstream choice(input);
        if (choice >> x >> y) {
            if (x >= 0 && x < map_size && y >= 0 && y < map_size) {
                valid_input = true;
            }
        }
        else {
            cout << "Invalid input, please try again." << endl;
        }
    }

    // Open the tile (update score? and displaymap)
    open_tile(x, y);

    // Check if its a mine, and if so end the game
    if (this->displaymap[x][y] == -1) {
        cout << "YOU LOSE" << endl;
        this->gameover = true;
        return 1;
    } 
    // If we open a zero, open ALL adjacent tiles
    else if (this->displaymap[x][y] == 0) {
        for (const auto& dir : directions) {
            int newx = dir.first + x;
            int newy = dir.second + y;
            if (index_valid(newx,newy,this->map_size)) {
                open_tile(newx, newy);
            }
        }
    }

    

    return 0;
}

void Minesweeper::open_tile(int x, int y) {
    this->displaymap[x][y] = this->scoremap[x][y];
}

int main() {

    Minesweeper game1;

    game1.generate_scoremap();

    game1.display_map();

    game1. display_scoremap();

    // game1.tile_selection();


    return(0);
}