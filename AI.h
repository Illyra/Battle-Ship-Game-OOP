#ifndef AI_FUNCTIONS_H
#define AI_FUNCTIONS_H
#include <vector>
#include <string>
#include "grid.h"
#include "player.h"

class AI : public player
{
    public:
        AI();
        void getShipID();
        void setShips(Ship&, int);
        void attackingShips(Grid&);
        int randomNumberGen();
        char generateRandomOrient();
        void isPlaceable(Ship&, int);
        void setVec(int x, int y, int hit);
};


#endif