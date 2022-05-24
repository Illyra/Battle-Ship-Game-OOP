#include "player.h"
#include "grid.h"
#include <iostream>

Grid& player::getGrid()
{
    return vec;
}
void player::hit(Grid& grid, int n)
{
    if (n == 3)
    {
        std::cout << "Submarine" << std::endl;
        submarine.incHit();
    }
    else if (n == 4)
    {
        std::cout << "Cruiser" << std::endl; 
        cruiser.incHit();
    }
    else if (n == 5) 
    {
        std::cout << "Destroyer" << std::endl;
        destroyer.incHit();
    }
    else if (n == 6)
    {
        std::cout << "Carrier" << std::endl;
        carrier.incHit();
    }
    else if (n == 7)
    {
        std::cout << "BattleShip" << std::endl;
        battleship.incHit();
    }
    else
    {
        std::cout << "One of your ships ";
    }
        std::cout << "Has been hit!" << std::endl;
}
bool player::Won()
{
    if (submarine.getHit() == submarine.getShipLength() && cruiser.getHit() == cruiser.getShipLength() 
    && destroyer.getHit() == destroyer.getShipLength() && carrier.getHit() == carrier.getShipLength() 
    && battleship.getHit() == battleship.getShipLength())
    {
        return true;
    }   
    else
    {
        return false;
    }
}
void player::setVector(int x, int y, int hit)
{
    Grid vector = this->getGrid();
    vector.getVector()[x][y] = hit;
}