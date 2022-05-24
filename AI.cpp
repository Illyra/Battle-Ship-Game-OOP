#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "AI.h"

AI::AI()
{
    //default constructor
}

void AI::getShipID()
{
    int x = randomNumberGen();
    int y = randomNumberGen();

    Ship sub(generateRandomOrient(), x, y, 3, 3);
    submarine = sub;
    setShips(sub, 3);

    x = randomNumberGen();
    y = randomNumberGen();

    Ship cruise(generateRandomOrient(), x, y, 3, 4);
    cruiser = cruise;
    setShips(cruise, 4);

    x = randomNumberGen();
    y = randomNumberGen();
    
    Ship destr(generateRandomOrient(),x, y, 2, 5);
    destroyer = destr;
    setShips(destr, 5);

    x = randomNumberGen();
    y = randomNumberGen();

    Ship car(generateRandomOrient(), x, y, 5, 6);
    carrier = car;
    setShips(car, 6);

    x = randomNumberGen();
    y = randomNumberGen();

    Ship bat(generateRandomOrient(), x, y, 4, 7);
    battleship = bat;
    setShips(bat, 7);

    std::cout << "The AI has completely placed their ships!" << std::endl << std::endl;

}

void AI::setShips(Ship& Vehicle, int number)
{
    if (!vec.setShipPos(Vehicle, number, Vehicle.printNameShip(number)))
    {
        isPlaceable(Vehicle, number);
    }
}
void AI::attackingShips(Grid& user)
{
    int shipNum = 0;
    int randomRow = rand() % 10;
    int randomCol = rand() % 10;
    if (user.hitMark(randomRow, randomCol))
    {
        user.getVector() [randomRow][randomCol] = 1;
        std::cout << "Your ";
        int n = user.typeShip(randomRow, randomCol);
        hit(user, n);
    }
    else
    {
        user.getVector() [randomRow] [randomCol] = 2;
    }
    user.printGrid();
}

int AI:: randomNumberGen() 
{
    return rand() % 10 + 1;
}

char AI::generateRandomOrient()
{
    int randomOrientation = rand() % 2;
    char orient;

    if (randomOrientation == 0)
        orient = 'h';
    else 
        orient = 'v';
    return orient;
}
void AI::isPlaceable(Ship& vehicle, int shipNum)
{
    vehicle.setX(randomNumberGen());
    vehicle.setY(randomNumberGen());
    if(!vec.setShipPos(vehicle, shipNum, vehicle.printNameShip(shipNum)))
    {
        isPlaceable(vehicle, shipNum);
    }
}
void AI::setVec(int x, int y , int hit)
{
    Grid vector = this ->getGrid();
    vector.getVector()[x][y] = hit;
}
