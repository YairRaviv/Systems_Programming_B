#include "GeneSplicer.hpp"
namespace pandemic
{
    const unsigned int cities_num = 49;
    const unsigned int cards_num = 5;
    GeneSplicer::GeneSplicer(Board& b , City c):Player(b , c)
    {
        _role = "GeneSplicer";
    }
    GeneSplicer& GeneSplicer::discover_cure(const Color& color)
    {
        //cure already exist
        if(cure_exist(color)){return *this;}
        //there is no research station
        if(!research_station_exist(location)){throw std::invalid_argument("there is no research station!!");}
        //check if there is 5 cards
        int card = 0;
        for(unsigned int i=1;i<cities_num;i++)
        {
            if(cards.at(i)==1){card++;}
            if(card==cards_num){break;}
        }
        if(card<cards_num){throw std::invalid_argument("there is no 5 cards!!");}
        //remove 5 cards
        for(unsigned int i=1;i<cities_num;i++)
        {
            if(cards.at(i)==1)
            {
                cards.at(i)=0;
                card--;
            }
            if(card==0){break;}
        }
        cure_found(color);
        return *this;
    }
};