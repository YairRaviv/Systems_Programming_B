#include<iostream>
#include<string>
#include<unordered_map>
#include "Direction.hpp"
using namespace std;

namespace ariel
 {
    class Board
    {
        private:
            unordered_map<unsigned int,unordered_map<unsigned int,char>> table;
            unsigned int max_row;
            unsigned int max_column;
            unsigned int min_row;
            unsigned int min_column;
        
        public:
            Board();
            void post(unsigned int row,unsigned int column,Direction d,string massage);
            string read(unsigned int r,unsigned int c,Direction d,unsigned int len);
            void show();
    };
}








