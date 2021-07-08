#include "FieldDoctor.hpp"
namespace pandemic
{
    FieldDoctor::FieldDoctor(Board& b , City c):Player(b , c)
    {
        _role = "FieldDoctor";
    }

    FieldDoctor& FieldDoctor::treat(const City& city)
    {
        if(board[city]==0){throw std::invalid_argument("disease level is already 0!!");}
        //if the city are different from the current location
        if(city!=location)
        {
            //check if the cities are connected
            if(connection(location,city))
            {
                board[city]--;
                if(cure_exist_city(city)){board[city]=0;}
                return *this;
            }
            throw std::invalid_argument("there is no path between the cities!!");
        }
        //same city , using default method.
        Player::treat(city);
        return *this;
    }
};