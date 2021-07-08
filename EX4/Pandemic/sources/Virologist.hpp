#include "City.hpp"
#include "Color.hpp"
#include <unordered_map>
#include "Player.hpp"
#include "Board.hpp"
#include<iostream>
#include<string>

using namespace std;
namespace pandemic
{
    class Virologist : public pandemic::Player
    {
        private:
        public:
            Virologist(Board& board , City city);
            virtual Virologist& treat(const City& city);
    };
}