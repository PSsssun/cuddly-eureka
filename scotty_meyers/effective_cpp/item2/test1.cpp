#include <iostream>

class GamePlayer {
private:
    static const int NumTurns = 5; //const declaration
    int scores[NumTurns]; // usage of this const

public:
    void printf() {std::cout << NumTurns << std::endl;}
};

class CostEstimate {
private:
   static const double FudgeFactor;

public:
   void printf() {std::cout << FudgeFactor << std::endl;}
};

class GamePlayer2 {
private:
    enum {NumTurns = 5};

    int scores[NumTurns];

public:
    void printf() {std::cout << NumTurns << std::endl;}
};

const double CostEstimate::FudgeFactor = 1.35;

int main()
{
    GamePlayer gp1;

    gp1.printf();
    
    CostEstimate ce1;
    ce1.printf();

    GamePlayer2 gp2;

    gp2.printf();
    return 0;
}
