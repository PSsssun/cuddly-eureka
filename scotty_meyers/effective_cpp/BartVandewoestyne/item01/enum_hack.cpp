/**
 * Note:
 *
 *   Unless you're dealing with compilers of primarily historical interest
 *   (i.e., those written before 1995), you shouldn't have to use the enum
 *   hack.
 */
#include <iostream>
class GamePlayer {
public:
    enum {NUM_TURNS = 5};

    int scores[NUM_TURNS];
};

int main(){
    GamePlayer* p = new GamePlayer();
    std::cout << p->NUM_TURNS <<std::endl;
    std::cout << &(p->scores) << std::endl;
    // can not do &(p->NUM_TURNS)
    return 0;
}