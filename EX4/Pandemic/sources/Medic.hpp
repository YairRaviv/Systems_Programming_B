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
    class Medic : public Player
    {
        private:
        public:
            Medic(Board& board , City city);
            virtual Medic& drive(const City& city);
            virtual Medic& fly_direct(const City& city);
            virtual Medic& fly_charter(const City& city);
            virtual Medic& fly_shuttle(const City& city);
            virtual Medic& treat(const City& city);
    };
}