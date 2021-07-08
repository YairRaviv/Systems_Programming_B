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
    class FieldDoctor : public pandemic::Player
    {
        private:
        public:
            FieldDoctor(Board& board , City city);
            virtual FieldDoctor& treat(const City& city);
    };
}