#include "Virologist.hpp"
namespace pandemic
{
    Virologist::Virologist(Board& b , City c):Player(b , c)
    {
        _role = "Virologist";
    }
    Virologist& Virologist::treat(const City& city)
    {
        if(board[city]==0){throw std::invalid_argument("same city");}
        //if the viriligist treat in current location - default operation.
        if(city==location)
        {
           Player::treat(city);
           return *this;
        }
        //check if there is card
        if(cards.at(city)==0){throw std::invalid_argument("there is no card!!");}
        cards.at(city)=0;
        if(cure_exist_city(city))
        {
            board[city]=0;
        }
        else
        {
            board[city]--;
        }
        return *this;
    }
};