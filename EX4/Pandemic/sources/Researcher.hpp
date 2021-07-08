#include "City.hpp"
#include "Color.hpp"
#include <unordered_map>
#include "Board.hpp"
#include "Player.hpp"
#include<iostream>
#include<string>

using namespace std;
namespace pandemic
{
        
    class Researcher : public pandemic::Player
    {
        private:
        public:
            Researcher(Board& board , City city);
            virtual Researcher& discover_cure(const Color& color);
    };
}