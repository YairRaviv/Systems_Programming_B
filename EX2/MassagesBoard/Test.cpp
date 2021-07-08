/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * 
 *
 * AUTHORS: Name of Author: Yair Raviv
 * 
 * Date: 2021-03
 */
#include<iostream>
#include<string>
#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;
#include <stdexcept>
using namespace std;





TEST_CASE("basic cases") 
{
    //check some basic post/read operations
    ariel::Board board_1;
    board_1.post(0,0,Direction::Horizontal,"hello world");
    CHECK(board_1.read(0,0,Direction::Horizontal,5)=="hello");
    CHECK(board_1.read(0,6,Direction::Horizontal,5)=="world");
    board_1.post(1,0,Direction::Vertical,"ello world");
    CHECK(board_1.read(0,0,Direction::Vertical,11)=="hello world");
    //"hello world" should be equal to "hello world"
    CHECK(board_1.read(0,0,Direction::Vertical,11)==board_1.read(0,0,Direction::Horizontal,11));

    //check 7x10 board
    ariel::Board board;

    board.post(0,0,Direction::Horizontal,"Yair");
    board.post(0,5,Direction::Horizontal,"Raviv");
    CHECK(board.read(0,0,Direction::Horizontal,10)=="Yair_Raviv");
    CHECK(board.read(0,1,Direction::Vertical,4)=="a___");
    board.post(0,0,Direction::Vertical,"CPP");
    board.post(4,0,Direction::Vertical,"100");
    CHECK(board.read(0,0,Direction::Vertical,7)=="CPP_100");
    CHECK(board.read(0,0,Direction::Horizontal,4)=="Cair");
    board.post(2,1,Direction::Horizontal,"ostsBoard");
    CHECK(board.read(2,0,Direction::Horizontal,10)=="PostsBoard");
    board.post(1,1,Direction::Horizontal,"l");
    board.post(3,1,Direction::Vertical,"ne");
    CHECK(board.read(0,1,Direction::Vertical,5)=="alone");
    CHECK(board.read(0,2,Direction::Vertical,5)=="i_s__");
    CHECK(board.read(0,3,Direction::Vertical,5)=="r_t__");
    board.post(4,9,Direction::Vertical,"Bye");
    board.post(6,7,Direction::Horizontal,"Bye");
    CHECK(board.read(5,0,Direction::Horizontal,10)=="0________y");
    CHECK(board.read(6,0,Direction::Horizontal,10)=="0______Bye");
    string end=board.read(4,9,Direction::Vertical,3)+board.read(6,7,Direction::Horizontal,3);
    CHECK(end=="ByeBye");
    CHECK(board.read(6,7,Direction::Horizontal,4)=="Bye_");
    board.post(2,5,Direction::Vertical,"zibi");
    CHECK(board.read(3,5,Direction::Vertical,4)=="ibi_");
    board.post(1,5,Direction::Vertical,"al");
    CHECK(board.read(1,5,Direction::Vertical,5)=="alibi");
    CHECK(board.read(1,4,Direction::Vertical,3)=="_s_");
    CHECK(board.read(3,5,Direction::Vertical,0)=="");
}

TEST_CASE("complicated cases") 
{
   
}


/* Add more test cases here */