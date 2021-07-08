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
    class OperationsExpert : public Player
    {
        private:
        public:
            OperationsExpert(Board& board ,City city);
            virtual OperationsExpert& build();
    };
}