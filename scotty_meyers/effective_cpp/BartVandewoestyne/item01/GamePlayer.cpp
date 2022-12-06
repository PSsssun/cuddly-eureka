#include "GamePlayer.h"
#include <iostream>


// The above is however a *declaration*, not a *definition*, so you must still
// define static class members in an implementation fie:
const int GamePlayer::NUM_TURNS; // mandatory definition;
                                 // goes in class impl. file

int main()
{
    GamePlayer* p = new GamePlayer();
    std::cout << &(p->NUM_TURNS) << std::endl; // this works only with above definition
    return 0;
}