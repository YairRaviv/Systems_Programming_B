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
    class GeneSplicer : public pandemic::Player
    {
        private:
        public:
            GeneSplicer(Board& board , City city);
            virtual GeneSplicer& discover_cure(const Color& color);
    };
}