/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Name of Author: Yair Raviv
 * 
 * Date: 2021-02
 */
#include<iostream>
#include "doctest.h"
#include "snowman.hpp"
#include "snowman.cpp"
using namespace ariel;
#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	input.erase(remove(input.begin(),input.end(),' '),input.end());
    input.erase(remove(input.begin(),input.end(),'\n'),input.end());
    input.erase(remove(input.begin(),input.end(),'\r'),input.end());
    input.erase(remove(input.begin(),input.end(),'\t'),input.end());
	return input;
}



TEST_CASE("Good snowman code") {
    //check random snowmans

    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(12341234)) == nospaces("_===_\n(O.-)/\n<(> <)\n(   )"));
    CHECK(nospaces(snowman(21314123)) == nospaces("___.....\n(O,.)\n(] [)>\n(___)"));
    CHECK(nospaces(snowman(43214321)) == nospaces("___\n(_*_)\n(o_.)\n(] [)\\n( : )"));
    CHECK(nospaces(snowman(31422134)) == nospaces("_\n/_\\n\(-,.)\n(> <)>\n(   )"));
    CHECK(nospaces(snowman(44132331)) == nospaces("___\n(_*_)\n\(. O)\n(> <)\\n( : )"));
    CHECK(nospaces(snowman(21443221)) == nospaces("___.....\n(-,-)/\n/(] [)\n( : )"));
    CHECK(nospaces(snowman(31422423)) == nospaces("_\n/_\\n\(-,o)\n(] [)\n(___)"));
    CHECK(nospaces(snowman(14342314)) == nospaces("_===_\n\(O .)\n( : )\\n(   )"));
    CHECK(nospaces(snowman(33232124)) == nospaces("_\n/_\\n\(o_O)\n(] [)>\n(   )"));

    //cover all presets!

    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
    CHECK(nospaces(snowman(22222222)) == nospaces("___.....\n\(o.o)/\n(] [)\n(" ")"));
    CHECK(nospaces(snowman(33333333)) == nospaces("_\n/_\\n(O_O)\n/(> <)\\n(___)"));
    CHECK(nospaces(snowman(44444444)) == nospaces("___\n(_*_)\n(- -)\n(   )\n(   )"));
    /* Add more checks here */
}

TEST_CASE("Bad snowman code") 
{
    CHECK_THROWS(snowman(555));
    CHECK_THROWS(snowman(0));
    CHECK_THROWS(snowman(-1));
    CHECK_THROWS(snowman(-11114411));
    CHECK_THROWS(snowman(44444445));
    CHECK_THROWS(snowman(11111110));
    
}


/* Add more test cases here */
