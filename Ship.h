#ifndef SHIP_FUNCTIONS_H
#define SHIP_FUNCTIONS_H

class Ship
{
    protected:
        int x;
        int y;
        char Orientation;
        int hit = 0;
        int shipLength;
        int shipNumber;
    public:
        Ship();
        Ship(char, int, int, int, int);
        void setOrientation(char);
        void setX(int);
        void setY(int);
        void setShipLength(int);
       
        int getShipLength() const;
        int getX();
        int getY();
        char getOrientation() const;
        int getNum() const 
        {return shipLength;}
        int getHit()    
        {return hit;}
        
        void incHit();
        bool sunken();
        std::string printNameShip(int);

};




#endif