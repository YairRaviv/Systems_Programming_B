#include "Scientist.hpp"
namespace pandemic
{
    const unsigned int cities_num = 49;
    Scientist::Scientist(Board& b , City c , int k):Player(b , c)
    {
        _role = "Scientist";
        n = k;
    }
    Scientist& Scientist::discover_cure(const Color& color)
    {
        //cure already exist
        if(cure_exist(color)){return *this;}

        if(n_cards(color)&&research_station_exist(location))
        {
            int card=n;
            for(unsigned int i=1;i<cities_num;i++)
            {
                //remove n cards
                if(cards.at(i)!=0&&get_color(i)==color)
                {
                    cards.at(i)=0;
                    card--;
                    if(card==0){break;}
                }
            }
            //update cure existance
            cure_found(color);
            return *this;
        }
        throw std::invalid_argument("ileigal operation!!");
    }
    bool Scientist::n_cards(const Color& color)
    {
        //check if there is enough cards
        int card=0;
        for(unsigned int i=1;i<cities_num;i++)
        {
            if(cards.at(i)!=0&&get_color(i)==color)
            {
                card++;
            }
            if(card==n){return true;}
        }
        return false;
    }
};