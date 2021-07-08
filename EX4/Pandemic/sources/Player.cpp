#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <unordered_map>
#include "Board.hpp"
#include<iostream>
#include<string>
using namespace std;

namespace pandemic
{
    const unsigned int cities_num = 49;
    const unsigned int cards_num = 5;
    //update the cards list
    Player& Player::take_card(const City& city)
    {
        cards[city]=1;
        return *this;
    }
    
    string Player::role(){return _role;}
    Player& Player::build()
    {
        //there is already research station
        if(research_station_exist(location)){return *this;}
        //if there is no card of the current city   
        if(cards.at(location)==0)
        {  
            throw std::invalid_argument("there is no card");
        }
        //remove the card of the city , and update the research station existance of the city in the board
        cards.at(location)=0;
        board.cities_info.at(location).at("Research_station")=1;
        return *this;
    }
    Player& Player::drive(const City& city)
    {  
        //src and dest are the same city.
        if(location == city){throw std::invalid_argument("same city");}
        
        //check if the cities are connected
        if(connection(location , city))
        {
            location = city;
            return *this;
        }
        throw std::invalid_argument("there is no path between the cities!!");
    }
    Player& Player::fly_direct(const City& city)
    {
        //src and dest are the same city.
        if(location == city){throw std::invalid_argument("same city");}
        //check if there is card of dest city
        if(cards.at(city)!=0)
        {
            cards.at(city)=0;
            location = city;
            return *this;
        }
        throw std::invalid_argument("there is no card!!");
    }
    Player& Player::fly_charter(const City& city)
    {
        if(location == city){throw std::invalid_argument("same city!!");}
        if(cards.at(location)!=1)
        {
            throw std::invalid_argument("there is no card!!");
        }
        cards.at(location)=0;
        location = city;

        return *this;
    }
    Player& Player::fly_shuttle(const City& city)
    {
        if(location == city){throw std::invalid_argument("same city!!");}
        //check if there is research station in src and dest cities.
        if(!research_station_exist(location)||!research_station_exist(city))
        {
            throw std::invalid_argument("there is no research station");
        }
        location = city;
        return *this;
    }
    Player& Player::discover_cure(const Color& color)
    {
        //if there is already cure.
        if(board.cure_exist(color)){return *this;}
        if(five_cards(color)&&research_station_exist(location))
        {
            //update the board that cure exist forthis color
            board.cure_found(color);
            return *this;
        }
        throw std::invalid_argument("ileigal operation!!");
    }
    Player& Player::treat(const City& city)
    {
        if(board[city]==0){throw std::invalid_argument("disease level is already 0!!");}
        if(city!=location){throw std::invalid_argument("ileigal operation!!");}
        board[city]--;
        //if there is cure for this city
        if(cure_exist_city(city)){board[city]=0;}
        return *this;
    }

    //check if the player has 5 cards of this color
    bool Player::five_cards(const Color& c)
    {
        int card=0;
        for(unsigned int i=1;i<cities_num;i++)
        {
            if(cards.at(i)!=0&&board.cities_info.at(i).at("color")==c)
            {
                card++;
            }
            if(card==cards_num){return true;}
        }
        return false;
    }
    void Player::remove_cards()
    {
        for(unsigned int i =1;i<cities_num;i++)
        {
            cards.at(i)=0;
        }
    }
    //call cure_found of the board. this function using by inheritors
    void Player::cure_found(const Color& color){board.cure_found(color);}
    bool Player::cure_exist(const Color& color){return board.cure_exist(color);}
    bool Player::cure_exist_city(const City& city){return (board.cities_info.at(city).at("cure")!=0);}
    bool Player::research_station_exist(const City& city){return (board.cities_info.at(city).at("Research_station")!=0);}
   
    //check if two cities are connected
    bool Player::connection(const City& city_a , const City& city_b)
    {
        try
        {
            return (board.neighbors.at(city_a).at(city_b)!=0);
        }
        catch(std::out_of_range)
        {
            return false;
        }
    }
    //get color of specific city
    int Player::get_color(const unsigned int& city)
    {
        return board.cities_info.at(city).at("color");
    }
};