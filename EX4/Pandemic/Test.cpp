#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;

#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;


TEST_CASE("Basic player functionality")
{
    Board board;
    CHECK(board.is_clean()); // new board
    OperationsExpert player{board, City::Algiers};


    // player takes 5 cards (Color::Black):
    player.take_card(City::Algiers)
        .take_card(City::Baghdad)
        .take_card(City::Cairo)
        .take_card(City::Chennai)
        .take_card(City::Delhi);


    SUBCASE("Moving by rules")
    {

        // drive
        CHECK_NOTHROW(player.drive(City::Madrid);); // player drive to neighbor city
        CHECK_THROWS(player.drive(City::Lima);); // player can't move to distanced city
        CHECK_NOTHROW(player.drive(City::Algiers).drive(City::Madrid);); // player drive to neighbor city and back

        // fly_direct
        CHECK_THROWS(player.fly_direct(City::Lima);); // player doesn't hold that card
        CHECK_NOTHROW(player.fly_direct(City::Cairo);); // player holds that card
        CHECK_NOTHROW(player.fly_direct(City::Chennai).fly_direct(City::Delhi)); // player fly_direct twice
        CHECK_THROWS(player.fly_direct(City::Algiers).fly_direct(City::Delhi)); // player doesn't hold that 2nd card
        CHECK_THROWS(player.fly_direct(City::Baghdad).fly_direct(City::Baghdad)); // player doesn't hold that 2nd card

        // player takes 5 cards (Color::Black):
        player.take_card(City::Algiers)
            .take_card(City::Baghdad)
            .take_card(City::Cairo)
            .take_card(City::Chennai)
            .take_card(City::Delhi);

        // player fly back to Algiers:
        player.fly_direct(City::Algiers);

        // fly_charter
        CHECK_THROWS(player.fly_charter(City::Lima);); // player doesn't hold his place card
        CHECK_THROWS(player.fly_charter(City::Baghdad);); // player doesn't hold his place card
        CHECK_THROWS(player.fly_charter(City::Algiers);); // player doesn't hold his place card

        player.drive(City::Cairo); // player drive to neighbor city

        CHECK_NOTHROW(player.fly_charter(City::Algiers);); // player throws his place card

        player.take_card(City::Algiers)
              .take_card(City::Cairo); // player takes those cards back
        
        CHECK_THROWS(player.fly_charter(City::Algiers).fly_charter(City::Cairo)); // order is wrong here

        player.take_card(City::Algiers); // player takes back this card

        CHECK_NOTHROW(player.fly_charter(City::Cairo).fly_charter(City::Algiers)); // fly_charter and back

        // fly_shuttle
        CHECK_THROWS(player.fly_shuttle(City::Delhi);); // no station in this city
        player.take_card(City::Algiers); // player takes back this card
        player.build(); // throws Algiers card
        player.fly_direct(City::Delhi)
              .take_card(City::Delhi)
              .build(); // player builds in 2 citys (Algiers, Delhi)
        player.take_card(City::Algiers) // player takes back this card
              .take_card(City::Delhi); // player takes back this card
        
        CHECK_NOTHROW(player.fly_shuttle(City::Algiers);); // player fly_shuttle to Algiers
        player.take_card(City::Algiers); // player takes back this card
        
        
       
        CHECK_NOTHROW(player.fly_shuttle(City::Delhi).fly_shuttle(City::Algiers);); // player fly_shuttle to Delhi and back
    }
    }

