#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctype.h>
#include "User.h"


User::User()
{

}

void User::getShipID()
{
    std::string file;
    std::ifstream infile;
    std::string ship, position, orient;
    int row, column;
    char charOrientation;
    getline(std::cin, file);
    infile.open(file);
    if (!infile)
    {
        std::cout << "The file failed to open. Re-enter the file name: " << std::endl;
        getShipID();
    }
    else
    {
        getline(infile, ship, ',');
        getline(infile, ship, ',');
        getline(infile, ship);
        std::cout <<std::endl << std::endl;
        while(!infile.eof())
        {
            getline(infile, ship, ',');
            getline(infile, position, ',');
            getline(infile, orient);
            for(int i = 0; i < ship.length(); i++)
        {
            ship[i] = tolower(ship[i]);
        }
        if (ship == "submarine")
        {
        shipHelper(infile, position, orient, charOrientation, row, column);
            
        Ship sub(charOrientation, row, column + 1, 3, 3);
        submarine = sub;
        setShips(sub, 3);
        }
    if (ship == "cruiser")
    {
        shipHelper(infile, position, orient, charOrientation, row, column);
    
        Ship Cruise(charOrientation, row, column + 1, 3, 4);
            cruiser = Cruise;
            setShips(Cruise, 4);
    }
    if (ship == "destroyer")
    {
        shipHelper(infile, position, orient, charOrientation, row, column);
    
        Ship Destroy(charOrientation, row, column + 1, 2, 5);
        destroyer = Destroy;
        setShips(Destroy, 5);
    }
    if (ship == "carrier")
    {
        shipHelper(infile, position, orient, charOrientation, row, column);
        Ship Car(charOrientation, row, column + 1, 5, 6);
        carrier = Car;
        setShips(Car, 6);
    }
    if (ship == "battleship")
    {
        shipHelper(infile, position, orient, charOrientation, row, column);
        Ship Battle(charOrientation, row, column + 1, 4, 7);
        battleship = Battle;
        setShips(Battle, 7);
    }
    }
}
}

void User::setShips(Ship& vehicle, int shipNum)
{
    if (vec.setShipPos(vehicle, shipNum, vehicle.printNameShip(shipNum)))
    {
        std::cout << vehicle.printNameShip(shipNum) << " has been placed onto the grid" << std::endl;
    }
    else
    {
        std::cout << vehicle.printNameShip(shipNum) << " cannot be placed onto the grid" << std::endl;
    }
}

void User::attackingShips(Grid& AI)
{
    bool isValid = true;
    char col;
    int row;
    int column;
    std::cout <<"Enter the row you would like to attack: " << std::endl;
    std::cin >> col;

    std::cout << "Enter the column you would like to attack: " << std::endl;
    std::cin >> row;

    column = changefromChartoInt(col);
    try {
        while (row < 1 && row > 11)
        {
            isValid = false;
            std::cout << "The row you have entered doesn't exist" << std::endl;
            std::cin >> row;
        }
        while (column == 11)
        {
            isValid = false;
            std::cout << "The column you have entered doesn't exist" << std::endl;
            std::cin >> col;
            break;
        }
        if (std::cin.fail())
        {
            isValid = false;
            std::cin.clear();
            std::cout << "Enter a valid input....." << std::endl;
        }
        if(isValid)
        {
            std::cout << std::endl << std::endl;
            std::cout << "_________________________________" << std::endl << std::endl;
            std::cout << "An O will be printed if you missed a hit on the board" << std::endl;
            std::cout << "An X will be printed if you hit the enemy ship" << std::endl;
            if(AI.hitMark(row - 1, column - 1))
            {
                AI.getVector() [row - 1] [col - 1] = 1;
                std::cout << "AI's  ";
                int n = AI.typeShip(row - 1, column - 1);
                hit(AI, n);
            }
        }
        else{
        throw "Errror: you screwed up";
        }
    }
    
        catch (const std::string e)
        {
            std::cerr << e << std::endl;
        }
}

void User::shipHelper(std::ifstream& infile, std::string& position, std::string& orient, char& charOrient, int& row, int& column)
{
    std::stringstream ss;
    char letter = 'A';
    ss << position;
    ss >> letter;
    ss >> row;
    ss.clear();
    ss << position;
    column = letter - 'A';
    if (orient.size() != 0)
        charOrient = orient[0];
}

int User::changefromChartoInt(char letter)
{
    
    if (letter == 'A' || letter == 'a')
        return 1;
    if (letter == 'B' || letter == 'b')
        return 2;
    if (letter == 'C' || letter == 'c')
        return 3;
    if (letter == 'D' || letter == 'd')
        return 4;
    if (letter == 'E' || letter == 'e')
        return 5;
    if (letter == 'F' || letter == 'f')
        return 6;
    if (letter == 'G' || letter == 'g')
        return 7;
    if (letter == 'H' || letter == 'h')
        return 8;
    if (letter == 'I' || letter == 'i')
        return 9;
    if (letter == 'J' || letter == 'j')
        return 10;
    else
        return 11;
}