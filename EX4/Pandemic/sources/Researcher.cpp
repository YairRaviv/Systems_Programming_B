#include "Researcher.hpp"
namespace pandemic
{
    const unsigned int five = 5;
    Researcher::Researcher(Board& b , City c):Player(b , c)
    {
        _role = "Researcher";
    }
    Researcher& Researcher::discover_cure(const Color& color)
    {
        //if already exist cure
        if(cure_exist(color))
        {  
            return *this;
        }
        if(five_cards(color))
        {
            //remove 5 cards
            unsigned int cards_5 = five;
            unsigned int i = 1;
            while(cards_5!=0)
            {
                if(cards.at(i)==1&&get_color(i)==color){cards_5--;}
                i++;
            }
            //update cure existance
            cure_found(color);
            return *this;
        }
        throw std::invalid_argument("there is no 5 cards!!");
    }
};