// To limit the scope of a constant to a class
// 1. you must make it a member
// 2. you must make it a static member to ensure there's at most one copy
class GamePlayer {
    public:
    static const int NUM_TURNS = 5; // const declaration
    int scores[NUM_TURNS]; // use of constant
};