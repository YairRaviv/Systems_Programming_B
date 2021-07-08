#pragma once
#include<iostream>
#include<string>
#include<unordered_map>
#include "City.hpp"
#include "Color.hpp"
using namespace std;

namespace pandemic
 {
    class Board
    {
        private:
            //tables used to covert city number <-> city name
            //unordered_map<string,unsigned int> table;
            //unordered_map<unsigned int,string> table_to_string;

            //all the information of the cities : color, cure existance , disease level , research station existance 
            unordered_map<unsigned int,unordered_map<string,int>> cities_info;

            //all the connections between the cities
            unordered_map<unsigned int,unordered_map<unsigned int,unsigned int>> neighbors;
            
            void init();
            void cure_found(const Color& color);
            bool cure_exist(const Color& color);
        public:

             //tables used to covert city number <-> city name
            unordered_map<string,unsigned int> table;
            unordered_map<unsigned int,string> table_to_string;

            //                     /\      \
            //public only for main ||

        
            Board();
            ~Board();
            void remove_cures();
            void remove_stations();
            int& operator[](City city);
            bool is_clean();
            friend ostream& operator<<(ostream &os ,const Board& board);
            friend class Player;
    };
}







