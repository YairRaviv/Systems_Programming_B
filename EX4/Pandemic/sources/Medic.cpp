#include "Medic.hpp"
namespace pandemic
{
    //all drive/fly methods using player implementation but check if there is cure at dest city , and if so update the 
    //disease level to 0
    Medic::Medic(Board& b , City c):Player(b , c)
    {
        _role = "Medic";
    }
    Medic& Medic::drive(const City& city)
    {
        Player::drive(city);
        if(cure_exist_city(city))
        {
            board[city] = 0;
        }
        return *this;
    }
    Medic& Medic::fly_direct(const City& city)
    {
        Player::fly_direct(city);
        if(cure_exist_city(city))
        {
            board[city] = 0;
        }
        return *this;
    }
    Medic& Medic::fly_charter(const City& city)
    {
        Player::fly_charter(city);
        if(cure_exist_city(city))
        {
            board[city] = 0;
        }
        return *this;
    }
    Medic& Medic::fly_shuttle(const City& city)
    {
        Player::fly_shuttle(city);
        if(cure_exist_city(city))
        {
            board[city] = 0;
        }
        return *this;
    }
    Medic& Medic::treat(const City& city)
    {
        if(board[city]==0){throw std::invalid_argument("disease level is already 0!!");}
        board[city] = 0;
        return *this;
    }
};