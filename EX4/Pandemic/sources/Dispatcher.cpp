#include "Dispatcher.hpp"
namespace pandemic
{
    Dispatcher::Dispatcher(Board& b , City c):Player(b , c)
    {
        _role = "Dispatcher";
    }
    Dispatcher& Dispatcher::fly_direct(const City& city)
    {
        if(location == city){throw std::invalid_argument("same city");}
        if(research_station_exist(location))
        {
            location = city;
            return *this;
        }
        //if there is no research station , the dispatcher using regular "fly_direct" opertaion.
        if(cards.at(city)!=0)
        {
            cards.at(city)=0;
            location = city;
            return *this;
        }
        throw std::invalid_argument("there is no card!!");
    }
};