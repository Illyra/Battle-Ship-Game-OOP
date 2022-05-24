#include "grid.h"
#include "Ship.h"
#include "User.h"
#include "AI.h"
#include <iostream>
#include <ctime>

int main()
{
    Grid Make;
    std::cout << "Lets play Battleship!" << std::endl;
    std::cout << "Press 1 to quit!" << std:: endl;
    std::cout << "TO continue playing press 2!" << std::endl;
    std::cout << "The board: " << std::endl;
    Make.printGrid();

    srand(time(NULL));
    int input = 1;

    User use;
    AI compute;
    std::cout <<"Enter a file name to open the ships to begin playing: " << std::endl;
    use.getShipID();
    std::cout << std::endl;
    use.getGrid().printGrid();
    std::cout << "The A.I's grid: ";
    std::cout << std::endl;
    compute.getShipID();
    std::cout << std::endl;
    Grid computerGrid = compute.getGrid();
    Grid userGrid = use.getGrid();
    do 
    {
        std::cout << "Its your turn" << std::endl;
        use.attackingShips(compute.getGrid());
        compute.getGrid().printHit(compute.getGrid());
        std::cout << "The AI has shot a torpedo" << std::endl;
        compute.attackingShips(use.getGrid());
        compute.getGrid().printGrid();
        if (compute.Won())
        {
            std::cout << "The AI has won the game" << std::endl;
            input = 2;
        }
        else
        if (use.Won())
        {
            std::cout << "You... WIN" << std::endl;
            input = 2;
        }
        std::cout << "Do you wish to continue...? Press 1 for yes, 2 for no" << std::endl;
        //std::cin.ignore();
        std::cin >> input;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cout << "please enter a number between 1 - 2...." << std::endl;
        }
        else if (input != 1 && input != 2)
        {
            std::cout <<"The number you entered was invalid..." << std::endl;
        }
    }
    while (input == 1);

    return 0;
}