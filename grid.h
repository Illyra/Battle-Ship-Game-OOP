#ifndef GRID_FUNCTIONS_H
#define GRID_FUNCTIONS_H
#include <vector>
#include <string>
#include "Ship.h"
class Grid
{
    private:
        std::vector<std::vector<int>> vec;

    public:
        Grid();
        void printGrid();
        int fireRandom(std::vector<std::vector<int>>&);
        bool setShipPos(Ship&, int, std::string);
        bool isPlaceable(Ship&, int, int, int);
        bool hitMark(int, int);
        int typeShip(int, int);
        void printHit(Grid&);
        std::vector<std::vector<int>> & getVector() {return vec;}
};








#endif