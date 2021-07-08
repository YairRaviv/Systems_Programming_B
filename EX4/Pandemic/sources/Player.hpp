#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <unordered_map>
#include "Board.hpp"
#include<iostream>
#include<string>

using namespace std;
namespace pandemic
{
    class Player
    {
        private:
        protected:
            //this map represent the cards list of the player
            unordered_map<unsigned int,unsigned int> cards;
            City location;
            Board& board;
            string _role;

            //the player class has acsess to private members of the board , 
            //so this is some get&set functions that works on the board.
            bool five_cards(const Color& color);
            void cure_found(const Color& color);
            bool cure_exist(const Color& color);
            bool cure_exist_city(const City& city); 
            bool connection(const City& city_a , const City& city_b); 
            bool research_station_exist(const City& city);
            int get_color(const unsigned int& city);
            
            
            //the constructor is avialable only to inheritors of player , there is no instance of base class.
            Player(Board& b , City c):board(b),location(c)
            {
                for(unsigned int i = 1;i<49;i++)
                {
                    cards[i]=0;
                }        
            }
        public:
            string role();
            Player& take_card(const City& city);
            virtual Player& build();
            virtual Player& drive(const City& city);
            virtual Player& fly_direct(const City& city);
            virtual Player& fly_charter(const City& city);
            virtual Player& fly_shuttle(const City& city);
            virtual Player& discover_cure(const Color& color);
            virtual Player& treat(const City& city);
            void remove_cards();
    };
}