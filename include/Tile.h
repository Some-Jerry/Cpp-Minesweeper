#ifndef TILE_H
#define TILE_H

class Tile {
private:
    bool mine;
    bool open;
    int score;

public:
    // Constructors
    Tile();
    Tile(bool isMine, bool isOpen, int startingScore);

    // Member functions
    bool get_is_Open() const;
    void set_is_Open(bool isOpen);
    bool get_is_Mine() const;
    void set_is_Mine(bool isMine) ;
    int get_score() const;
    void set_score(int newScore);
    
};

#endif // TILE_H