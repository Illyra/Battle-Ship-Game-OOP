#include <iostream>
#include <string>
#include <vector>
#include "Ship.h"

Ship::Ship()
{
    //default constructor
}
Ship::Ship(char Orient, int _x, int _y, int _shipLength, int shipNum)
{
    x = _x;
    y = _y;
    Orientation = Orient;
    shipLength = _shipLength;
    shipNumber = shipNum;
    hit = 0;
}
void Ship::setOrientation(char input) //sets orientation if it's h for horizontal v for vertical
{
    if (input == 'H' || input == 'h')
        Orientation = 'h';
    else if (input == 'V' || input == 'v')
        Orientation = 'v';
    else
        Orientation = 'h';
}

char Ship::getOrientation() const
{
    return Orientation;
}
void Ship::incHit()
{
    hit++;
}

bool Ship::sunken()
{
    if (hit == shipLength)
        return true;
    else
        return false;
}

int Ship::getShipLength() const
{
    return shipLength;
}

std::string Ship::printNameShip(int shipNum)
{
    if (shipNum == 3)
        return "Submarine";
    if (shipNum == 4)
        return "Cruiser";
    if (shipNum == 5)
        return "Destroyer";
    if (shipNum == 6)
        return "Carrier";
    if (shipNum == 7)
        return "BattleShip";
return 0;
}
int Ship::getX()
{
    return x;
}
int Ship::getY()
{
    return y;
}
void Ship::setX(int _x)
{
    x = _x;
}
void Ship::setY(int _y)
{
    y = _y;
}

