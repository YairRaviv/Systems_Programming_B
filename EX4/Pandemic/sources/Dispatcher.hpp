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
    class Dispatcher : public pandemic::Player
    {
        private:
        public:
            Dispatcher(Board& board , City city);
            virtual Dispatcher& fly_direct(const City& city);
    };
}