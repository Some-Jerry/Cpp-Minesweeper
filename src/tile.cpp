#include <utility>

class Tile {
private:
    bool mine;
    bool open;
    int score;

public:
    // Constructors
    Tile() : mine(false), open(false), score(0) {}
    Tile(bool isMine, bool isOpen, int startingScore) : mine(isMine), open(isOpen), score(startingScore) {}

    // Member functions
    bool get_is_Open() const {
        return open;
    }

    bool get_is_Mine() const {
        return mine;
    }
    
    void set_is_Open(bool isOpen) {
        open = isOpen;
    }

    void set_is_Mine(bool isMine) {
        mine = isMine;
    }

    int get_score() const {
        return score;
    }

    void set_score(int newScore) {
        score = newScore;
    }

};