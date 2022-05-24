#ifndef PLAYER_FUNCTIONS_H
#define PLAYER_FUNCTIONS_H
#include "grid.h"
#include "Ship.h"

class player
{
    protected:
        Grid vec;
        Ship submarine;
        Ship cruiser;
        Ship destroyer;
        Ship carrier;
        Ship battleship;
   
    public:
        Grid& getGrid();
        void hit(Grid& grid, int n);
        bool Won();
        void getShipID();
        void setShips(Ship, int);
        void attackingShips(Grid&);
        void setVector(int x, int y, int hit);
};




#endif