#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <unordered_map>
#include "Board.hpp"
#include "OperationsExpert.hpp"
#include<iostream>
#include<string>
using namespace std;
//using namespace pandemic;
namespace pandemic
{
    OperationsExpert::OperationsExpert(Board& b , City c):Player(b , c)
    {
        _role = "OperationsExpert";
    }
    OperationsExpert& OperationsExpert::build()
    {
        unsigned int card = cards.at(location);
        cards.at(location)=1;
        Player::build();
        //make sure that the player keep the card (if he had if at the first place)
        cards.at(location)=card;
        return *this;
    }
};