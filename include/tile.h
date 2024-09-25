#ifndef TILE_H
#define TILE_H

class Tile {
private:
    bool mine;
    bool open;
    int score;

public:
    // Constructor
    Tile(bool is_mine);

    // Member functions
    bool get_is_Open() const;
    bool set_is_Open() const;
    bool get_is_Mine() const;
    bool set_is_Mine() const;
    int get_score() const;
    void set_score(int newScore);
    
};

#endif // TILE_H