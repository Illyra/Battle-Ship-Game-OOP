#include <iostream>
#include <vector>
#include <string>
#include "grid.h"

const int MAX_SIZE = 10;

Grid::Grid()
{
    //default constructor
    vec.resize(MAX_SIZE, std::vector <int>(MAX_SIZE, 0)); //setting the maximum size of the grid
}

bool Grid::hitMark(int x, int y)
{
    if (vec[x][y] != 0 && vec[x][y] != 1 && vec[x][y] !=2)
    {
        return true;
    }
    else 
    {
        vec[x][y] = 2;
        return false;
    }
}
int Grid::typeShip(int x, int y)
{
    int shipNum = 0;
    shipNum = vec[x][y];
    vec[x][y] = 1;
    return shipNum;

}
void Grid::printGrid()
{
    std::cout << "----------------------------------" << std::endl;
    std::cout << "|   A  B  C  D  E  F  G  H  I  J |" << std::endl;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (i + 1 == 10)
            std::cout << i + 1 << " ";
        else 
            std::cout << i + 1 << "  ";
        for (int j = 0; j < MAX_SIZE; j++) 
        {
            if (vec[i][j] == 0)
                std::cout << " " << "  ";
            if (vec[i][j] == 1)
                std::cout << "X" << "  ";
            if (vec[i][j] == 2)
                std::cout << "O" << "  ";
            if (vec[i][j] == 3)
                std::cout << "S" << "  ";
            if (vec[i][j] == 4)
                std::cout << "C" << "  ";
            if (vec[i][j] == 5)
                std::cout << "D" << "  ";
            if (vec[i][j] == 6)
                std::cout << "K" << "  ";
            if (vec[i][j] == 7)
                std::cout << "B" << "  ";
        }
        std::cout <<"|" << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
}
bool Grid::setShipPos(Ship& vehicle, int shipNum, std::string name)
{
    bool isPlaced = false;
    bool enter = false;
    int shipLength = vehicle.getShipLength();
    int x = vehicle.getX() - 1;
    int y = vehicle.getY() -1;
    int endofX = x + shipLength;
    int endofY = y + shipLength;
    if (endofX <= 10 && endofY <= 10)
    {
        if (vehicle.getOrientation() == 'h' || vehicle.getOrientation() == 'H')
        {
            if (isPlaceable(vehicle, x, y, shipNum))
            {
                while (shipLength > 0)
                {
                    vec[x][y] = shipNum;
                    y++;
                    shipLength--;
                }
                isPlaced = true;
            }
        }
        else if (vehicle.getOrientation() == 'v' || vehicle.getOrientation() == 'V')
            {
                if (isPlaceable(vehicle,x,y, shipNum))
                {
                    while (shipLength > 0)
                        {
                            vec[x][y] = shipNum;
                            x++;
                            shipLength--;
                        }
                    isPlaced = true;
                }
            }
        return isPlaced;
    }
    else 
    {
        return false;
    }
}
bool Grid::isPlaceable(Ship& anotherVehicle, int x, int y, int shipNum)
{
    bool abletoPlace = false;
    if (anotherVehicle.getOrientation() == 'h' || anotherVehicle.getOrientation() == 'H')
    {
        for (int i = 0; i < anotherVehicle.getShipLength(); i++)
        {
            if (x >= 0 && x < 10 && y >=0 && y < 10) 
            {
                if (vec[x][y] != 0)
                {
                    abletoPlace = false;
                    return abletoPlace;
                }
                else 
                {
                    abletoPlace = true;
                    y++;
                }
            }
        }
    }
    else if (anotherVehicle.getOrientation() == 'v' || anotherVehicle.getOrientation() == 'V')
    {
        for (int i = 0; i < anotherVehicle.getShipLength(); i++)
        {
            if ( x>= 0 && x <= 9 && y >= 0 && y <= 9) 
            {
                if (vec[x][y] != 0)
                {
                    abletoPlace = false;
                    return abletoPlace;
                }
                else
                {
                    abletoPlace = true;
                    x++;
                }
            }
        }
    }
    return abletoPlace;
}
void Grid::printHit(Grid& AI)
{
    std::vector<std::vector<int>> printVec = AI.getVector();
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "| A B C D E F G H I J |" << std::endl;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (i + 1 == 10)
            std::cout << i + 1 << " ";
        else 
            std::cout << i + 1 << "  ";
        for (int j = 0; j < MAX_SIZE; j++) 
        {
            if (printVec[i][j] == 0)
                std::cout << " " << "  ";
            if (printVec[i][j] == 1)
                std::cout << "X" << "  ";
            if (printVec[i][j] == 2)
                std::cout << "O" << "  ";
            if (printVec[i][j] == 3)
                std::cout << "S" << "  ";
            if (printVec[i][j] == 4)
                std::cout << "C" << "  ";
            if (printVec[i][j] == 5)
                std::cout << "D" << "  ";
            if (printVec[i][j] == 6)
                std::cout << "K" << "  ";
            if (printVec[i][j] == 7)
                std::cout << "B" << "  ";
        }
        std::cout <<"|" << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
}
