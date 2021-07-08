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
    class Scientist : public pandemic::Player
    {
        private:
        bool n_cards(const Color& color);
        public:
            virtual Scientist& discover_cure(const Color& color);
            int n;
            Scientist(Board& board , City city , int k);
    };
}