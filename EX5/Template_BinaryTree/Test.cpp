/**
 * Tests for binarytree
 *
 * AUTHOR: Yair Raviv
 * 
 * Date: 2021-05
 */

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "doctest.h"
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <array>
#include <time.h>
#include "BinaryTree.hpp"
using namespace std;
using namespace ariel;


class Point
{
    public:
        int x, y;
        Point() : x(0), y(0) {}
        Point(int x, int y) : x(x), y(y) {}
        bool operator==(const Point& other) const {return(x==other.x&&y==other.y);}
};

TEST_CASE("Integer trees")
{
  vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
  SUBCASE("ITERATORS AND CONSTRUCTION TEST")
  {
    BinaryTree<int> tree_1;

    //tree 1 , contain 1-10 , pre order of ths tree should be : 1,2,3,4,5,6,7,8,9,10.
    /*
                        1
                      /   \
                     3     6 
                    / \   / \
                   2   4 7   9  
                      /   \   \
                     5     8  10
    */
    tree_1.add_root(1);
    tree_1.add_left(1,2);
    tree_1.add_right(1,6);
    tree_1.add_left(2,3);
    tree_1.add_left(6,7);
    tree_1.add_right(2,4);
    tree_1.add_right(6,9);
    tree_1.add_right(7,8);
    tree_1.add_right(9,10);
    tree_1.add_left(4,5);

    int i = 1;
    for(auto it = tree_1.begin_preorder();it!=tree_1.end_preorder();it++)
    {
        CHECK(i==(*it));
        i++;
    }
    //pair<BinaryTree<int>::iterator,vector<int>::iterator > mispair;
    //auto pair = std::mismatch(tree_1.begin_preorder(),tree_1.end_preorder(),vec.begin());


    //tree 2 , contain 1-10 , post order of ths tree should be : 1,2,3,4,5,6,7,8,9,10.
    /*
                       10
                      /   \
                     4     9 
                    / \   / \
                   1   3 6   8  
                      /   \   \
                     2     5   7
    */
    BinaryTree<int> tree_2;

    tree_2.add_root(10);
    tree_2.add_left(10,4);
    tree_2.add_right(10,9);
    tree_2.add_left(4,1);
    tree_2.add_left(9,6);
    tree_2.add_right(4,3);
    tree_2.add_right(9,8);
    tree_2.add_right(6,5);
    tree_2.add_right(8,7);
    tree_2.add_left(3,2);

    i = 1;
    for(auto it = tree_2.begin_postorder();it!=tree_2.end_postorder();it++)
    {
        CHECK(i==(*it));
        i++;
    }



    //tree 3 , contain 1-10 , in order of ths tree should be : 1,2,3,4,5,6,7,8,9,10.
    /*
                        5
                      /   \
                     2     8 
                    / \   / \
                   1   4 6   9  
                      /   \   \
                     3     7  10
    */
    BinaryTree<int> tree_3;

    tree_3.add_root(5);
    tree_3.add_left(5,2);
    tree_3.add_right(5,8);
    tree_3.add_left(2,1);
    tree_3.add_left(8,6);
    tree_3.add_right(2,4);
    tree_3.add_right(8,9);
    tree_3.add_right(6,7);
    tree_3.add_right(9,10);
    tree_3.add_left(4,3);

    i = 1;
    for(auto it = tree_3.begin_inorder();it!=tree_3.end_inorder();it++)
    {
        CHECK(i==(*it));
        i++;
    }

    i=1;
    for (int item : tree_3)
    {
      CHECK(item == i);
      i++;
    }
  }
  SUBCASE("OVERRIDING WITH ADD ELEMENTS METHODS")
  {
    //tree 1 contain 10,20,30,40,50,60,70,80,90,100 before overriding
    BinaryTree<int> tree_1;
    tree_1.add_root(10);
    tree_1.add_left(10,20);
    tree_1.add_right(10,60);
    tree_1.add_left(20,30);
    tree_1.add_left(60,70);
    tree_1.add_right(20,40);
    tree_1.add_right(60,90);
    tree_1.add_right(70,80);
    tree_1.add_right(90,100);
    tree_1.add_left(40,50);

    //tree 1 , contain 1-10 after overriding, pre order of ths tree should be : 1,2,3,4,5,6,7,8,9,10.
    tree_1.add_root(1);
    tree_1.add_left(1,2);
    tree_1.add_right(1,6);
    tree_1.add_left(2,3);
    tree_1.add_left(6,7);
    tree_1.add_right(2,4);
    tree_1.add_right(6,9);
    tree_1.add_right(7,8);
    tree_1.add_right(9,10);
    tree_1.add_left(4,5);

    int i = 1;
    for(auto it = tree_1.begin_preorder();it!=tree_1.end_preorder();it++)
    {
        CHECK(i==(*it));
        i++;
    }


    //tree 2 contain 10,20,30,40,50,60,70,80,90,100 before overriding
    BinaryTree<int> tree_2;
    tree_2.add_root(10);
    tree_2.add_left(10,20);
    tree_2.add_right(10,60);
    tree_2.add_left(20,30);
    tree_2.add_left(60,70);
    tree_2.add_right(20,40);
    tree_2.add_right(60,90);
    tree_2.add_right(70,80);
    tree_2.add_right(90,100);
    tree_2.add_left(40,50);

    //tree 2 , contain 1-10 after overrifing, post order of ths tree should be : 1,2,3,4,5,6,7,8,9,10.

    tree_2.add_root(10);
    tree_2.add_left(10,4);
    tree_2.add_right(10,9);
    tree_2.add_left(4,1);
    tree_2.add_left(9,6);
    tree_2.add_right(4,3);
    tree_2.add_right(9,8);
    tree_2.add_right(6,5);
    tree_2.add_right(8,7);
    tree_2.add_left(3,2);

    i = 1;
    for(auto it = tree_2.begin_postorder();it!=tree_2.end_postorder();it++)
    {
        CHECK(i==(*it));
        i++;
    }


    //tree 3 contain 10,20,30,40,50,60,70,80,90,100 before overriding
    BinaryTree<int> tree_3;
    tree_3.add_root(10);
    tree_3.add_left(10,20);
    tree_3.add_right(10,60);
    tree_3.add_left(20,30);
    tree_3.add_left(60,70);
    tree_3.add_right(20,40);
    tree_3.add_right(60,90);
    tree_3.add_right(70,80);
    tree_3.add_right(90,100);
    tree_3.add_left(40,50);


    //tree 3 , contain 1-10 after overriding, in order of ths tree should be : 1,2,3,4,5,6,7,8,9,10.

    tree_3.add_root(5);
    tree_3.add_left(5,2);
    tree_3.add_right(5,8);
    tree_3.add_left(2,1);
    tree_3.add_left(8,6);
    tree_3.add_right(2,4);
    tree_3.add_right(8,9);
    tree_3.add_right(6,7);
    tree_3.add_right(9,10);
    tree_3.add_left(4,3);

    i = 1;
    for(auto it = tree_3.begin_inorder();it!=tree_3.end_inorder();it++)
    {
        CHECK(i==(*it));
        i++;
    }
  }
  SUBCASE("Exceptions")
  {
    BinaryTree<int> tree_1;
    // //empty tree
    CHECK_THROWS(tree_1.add_left(1,2));
    CHECK_THROWS(tree_1.add_right(1,3));
    //root is 2
    CHECK_NOTHROW(tree_1.add_root(2));
    CHECK_THROWS(tree_1.add_left(1,2));
    CHECK_THROWS(tree_1.add_right(1,3));

    //override root to be 1
    CHECK_NOTHROW(tree_1.add_root(1));
    CHECK_NOTHROW(tree_1.add_left(1,3));
    CHECK_NOTHROW(tree_1.add_right(1,6));
    CHECK_NOTHROW(tree_1.add_left(3,2));
    CHECK_NOTHROW(tree_1.add_right(3,4));
    CHECK_NOTHROW(tree_1.add_left(6,5));
    CHECK_NOTHROW(tree_1.add_right(6,7));
    /*
      now the tree looks like :     1
                                  /   \
                                 3     6 
                                / \   / \
                               2   4 5   7  
    */
    srand(time(NULL));
    for(int i = 0;i<20;i++)
    {
      int tmp = rand() % 100 + 1;
      if(tmp>7)
      {
        CHECK_THROWS(tree_1.add_left(tmp , 10));
      }
    }
  }
}


TEST_CASE("trees of objects(Points)")
{
  SUBCASE("ITERATORS AND CONSTRUCTION TEST")
  {

    Point arr[] = {Point(1,1),Point(2,2),Point(3,3),Point(4,4),Point(5,5),Point(6,6),Point(7,7)};

    //tree of points , contain (1,1),(2,2)...(7,7), pre order should be : (1,1),(2,2)...(7,7)
    /*
                   (1,1)
                 /       \
            (2,2)        (5,5) 
           /     \      /     \
        (3,3)  (4,4) (6,6)   (7,7)
    */
    BinaryTree<Point> tree_1;
    tree_1.add_root(Point(1,1));
    tree_1.add_left(Point(1,1),Point(2,2));
    tree_1.add_right(Point(1,1),Point(5,5));
    tree_1.add_left(Point(2,2),Point(3,3));
    tree_1.add_right(Point(2,2),Point(4,4));
    tree_1.add_left(Point(5,5),Point(6,6));
    tree_1.add_right(Point(5,5),Point(7,7));
    int i = 0;
    for(auto it = tree_1.begin_preorder();it!=tree_1.end_preorder();it++)
    {
      CHECK(it->x==arr[i].x);
      CHECK(it->y==arr[i].y);
      i++;
    }


    //tree of points , contain (1,1),(2,2)...(7,7), post order should be : (1,1),(2,2)...(7,7)
     /*
                   (7,7)
                 /       \
            (3,3)        (6,6) 
           /     \      /     \
        (1,1)  (2,2) (4,4)   (5,5)
    */
    BinaryTree<Point> tree_2;
    tree_2.add_root(Point(7,7));
    tree_2.add_left(Point(7,7),Point(3,3));
    tree_2.add_right(Point(7,7),Point(6,6));
    tree_2.add_left(Point(3,3),Point(1,1));
    tree_2.add_right(Point(3,3),Point(2,2));
    tree_2.add_left(Point(6,6),Point(4,4));
    tree_2.add_right(Point(6,6),Point(5,5));
    i = 0;
    for(auto it = tree_2.begin_postorder();it!=tree_2.end_postorder();it++)
    {
      CHECK(it->x==arr[i].x);
      CHECK(it->y==arr[i].y);
      i++;
    }


    //tree of points , contain (1,1),(2,2)...(7,7), post order should be : (1,1),(2,2)...(7,7)
     /*
                   (4,4)
                 /       \
            (2,2)        (6,6) 
           /     \      /     \
        (1,1)  (3,3) (5,5)   (7,7)
    */
    BinaryTree<Point> tree_3;
    tree_3.add_root(Point(4,4));
    tree_3.add_left(Point(4,4),Point(2,2));
    tree_3.add_right(Point(4,4),Point(6,6));
    tree_3.add_left(Point(2,2),Point(1,1));
    tree_3.add_right(Point(2,2),Point(3,3));
    tree_3.add_left(Point(6,6),Point(5,5));
    tree_3.add_right(Point(6,6),Point(7,7));
    i = 0;
    for(auto it = tree_3.begin_inorder();it!=tree_3.end_inorder();it++)
    {
      CHECK(it->x==arr[i].x);
      CHECK(it->y==arr[i].y);
      i++;
    }
  }
  SUBCASE("OVERRIDING WITH ADD ELEMENTS METHODS")
  {
    Point arr[] = {Point(1,1),Point(2,2),Point(3,3),Point(4,4),Point(5,5),Point(6,6),Point(7,7)};
    BinaryTree<Point> tree_1;
    tree_1.add_root(Point(10,10));
    tree_1.add_left(Point(10,10),Point(20,20));
    tree_1.add_right(Point(10,10),Point(50,50));
    tree_1.add_left(Point(20,20),Point(30,30));
    tree_1.add_right(Point(20,20),Point(40,40));
    tree_1.add_left(Point(50,50),Point(60,60));
    tree_1.add_right(Point(50,50),Point(70,70));
    //tree of points , contain (10,10),(20,20)...(70,70) Before overriding
    /*
                   (10,10)
                 /         \
            (20,20)        (50,50) 
           /     \         /     \
        (30,30) (40,40) (60,60) (70,70)
    */
    tree_1.add_root(Point(1,1));
    tree_1.add_left(Point(1,1),Point(2,2));
    tree_1.add_right(Point(1,1),Point(5,5));
    tree_1.add_left(Point(2,2),Point(3,3));
    tree_1.add_right(Point(2,2),Point(4,4));
    tree_1.add_left(Point(5,5),Point(6,6));
    tree_1.add_right(Point(5,5),Point(7,7));
    int i = 0;
    for(auto it = tree_1.begin_preorder();it!=tree_1.end_preorder();it++)
    {
      CHECK(it->x==arr[i].x);
      CHECK(it->y==arr[i].y);
      i++;
    }
  }
  SUBCASE("Exceptions")
  {
    BinaryTree<Point> tree_1;
    // //empty tree
    CHECK_THROWS(tree_1.add_left(Point(1,1),Point(2,2)));
    CHECK_THROWS(tree_1.add_left(Point(1,1),Point(3,3)));
    //root is 2
    CHECK_NOTHROW(tree_1.add_root(Point(2,2)));
    CHECK_THROWS(tree_1.add_left(Point(1,1),Point(2,2)));
    CHECK_THROWS(tree_1.add_left(Point(1,1),Point(3,3)));

    //override root to be 1
    CHECK_NOTHROW(tree_1.add_root(Point(1,1)));
    CHECK_NOTHROW(tree_1.add_left(Point(1,1),Point(3,3)));
    CHECK_NOTHROW(tree_1.add_right(Point(1,1),Point(6,6)));
    CHECK_NOTHROW(tree_1.add_left(Point(3,3),Point(2,2)));
    CHECK_NOTHROW(tree_1.add_right(Point(3,3),Point(4,4)));
    CHECK_NOTHROW(tree_1.add_left(Point(6,6),Point(5,5)));
    CHECK_NOTHROW(tree_1.add_right(Point(6,6),Point(7,7)));
    /*
                  (1,1)
                /      \
            (3,3)      (6,6) 
           /     \     /   \
        (2,2) (4,4) (5,5) (7,7)
    */
    srand(time(NULL));
    for(int i = 0;i<20;i++)
    {
      int tmp = rand() % 100 + 1;
      if(tmp>7)
      {
        CHECK_THROWS(tree_1.add_left(Point(tmp,tmp) , Point(10,10)));
      }
    }
  }
}






TEST_CASE("String trees")
{
  SUBCASE("ITERATORS AND CONSTRUCTION TEST")
  {
    string arr[] = {"node 1" , "node 2" ,"node 3" ,"node 4" ,"node 5" ,"node 6" ,"node 7" ,"node 8" ,"node 9" ,"node 10"};
    BinaryTree<string> tree_1;

    //tree 1 , contain "nodes" 1-10 , pre order of ths tree should be : node 1,node 2,node 3,... node 10.
    tree_1.add_root("node 1");
    tree_1.add_left("node 1","node 2");
    tree_1.add_right("node 1","node 6");
    tree_1.add_left("node 2","node 3");
    tree_1.add_left("node 6","node 7");
    tree_1.add_right("node 2","node 4");
    tree_1.add_right("node 6","node 9");
    tree_1.add_right("node 7","node 8");
    tree_1.add_right("node 9","node 10");
    tree_1.add_left("node 4","node 5");

    int i = 0;
    for(auto it = tree_1.begin_preorder();it!=tree_1.end_preorder();it++)
    {
        CHECK(arr[i]==(*it));
        i++;
    }


    //tree 2 , contain "nodes" 1-10 , post order of ths tree should be : node 1,node 2,node 3,... node 10.
    BinaryTree<string> tree_2;

    tree_2.add_root("node 10");
    tree_2.add_left("node 10","node 4");
    tree_2.add_right("node 10","node 9");
    tree_2.add_left("node 4","node 1");
    tree_2.add_left("node 9","node 6");
    tree_2.add_right("node 4","node 3");
    tree_2.add_right("node 9","node 8");
    tree_2.add_right("node 6","node 5");
    tree_2.add_right("node 8","node 7");
    tree_2.add_left("node 3","node 2");

    i = 0;
    for(auto it = tree_2.begin_postorder();it!=tree_2.end_postorder();it++)
    {
        CHECK(arr[i]==(*it));
        i++;
    }



    //tree 3 , contain "nodes" 1-10 , in order of ths tree should be : node 1,node 2,node 3,... node 10.
    BinaryTree<string> tree_3;

    tree_3.add_root("node 5");
    tree_3.add_left("node 5","node 2");
    tree_3.add_right("node 5","node 8");
    tree_3.add_left("node 2","node 1");
    tree_3.add_left("node 8","node 6");
    tree_3.add_right("node 2","node 4");
    tree_3.add_right("node 8","node 9");
    tree_3.add_right("node 6","node 7");
    tree_3.add_right("node 9","node 10");
    tree_3.add_left("node 4","node 3");

    i = 0;
    for(auto it = tree_3.begin_inorder();it!=tree_3.end_inorder();it++)
    {
        CHECK(arr[i]==(*it));
        i++;
    }

    i=0;
    for (string item : tree_3)
    {
      CHECK(item == arr[i]);
      i++;
    }
  }
  SUBCASE("OVERRIDING WITH ADD ELEMENTS METHODS")
  {
    string arr[] = {"node 1" , "node 2" ,"node 3" ,"node 4" ,"node 5" ,"node 6" ,"node 7" ,"node 8" ,"node 9" ,"node 10"};
    //tree 1 contain node 10,node 20,node 30...node 100 before overriding
    BinaryTree<string> tree_1;
    tree_1.add_root("node 10");
    tree_1.add_left("node 10","node 20");
    tree_1.add_right("node 10","node 60");
    tree_1.add_left("node 20","node 30");
    tree_1.add_left("node 60","node 70");
    tree_1.add_right("node 20","node 40");
    tree_1.add_right("node 60","node 90");
    tree_1.add_right("node 70","node 80");
    tree_1.add_right("node 90","node 100");
    tree_1.add_left("node 40","node 50");

    //tree 1 contain node 1,node 2,node 3...node 10 after overriding pre order of ths tree should be : 1,2,3,4,5,6,7,8,9,10.
    tree_1.add_root("node 1");
    tree_1.add_left("node 1","node 2");
    tree_1.add_right("node 1","node 6");
    tree_1.add_left("node 2","node 3");
    tree_1.add_left("node 6","node 7");
    tree_1.add_right("node 2","node 4");
    tree_1.add_right("node 6","node 9");
    tree_1.add_right("node 7","node 8");
    tree_1.add_right("node 9","node 10");
    tree_1.add_left("node 4","node 5");

    int i = 0;
    for(auto it = tree_1.begin_preorder();it!=tree_1.end_preorder();it++)
    {
        CHECK(arr[i]==(*it));
        i++;
    }


    //tree 2 contain node 10,node 20,node 30...node 100 before overriding
    BinaryTree<string> tree_2;
    tree_2.add_root("node 100");
    tree_2.add_left("node 100","node 40");
    tree_2.add_right("node 100","node 90");
    tree_2.add_left("node 40","node 10");
    tree_2.add_left("node 90","node 60");
    tree_2.add_right("node 40","node 30");
    tree_2.add_right("node 90","node 80");
    tree_2.add_right("node 60","node 50");
    tree_2.add_right("node 80","node 70");
    tree_2.add_left("node 30","node 20");

    //tree 2 , contain 1-10 after overrifing, post order of ths tree should be : 1,2,3,4,5,6,7,8,9,10.

    tree_2.add_root("node 10");
    tree_2.add_left("node 10","node 4");
    tree_2.add_right("node 10","node 9");
    tree_2.add_left("node 4","node 1");
    tree_2.add_left("node 9","node 6");
    tree_2.add_right("node 4","node 3");
    tree_2.add_right("node 9","node 8");
    tree_2.add_right("node 6","node 5");
    tree_2.add_right("node 8","node 7");
    tree_2.add_left("node 3","node 2");

    i = 0;
    for(auto it = tree_2.begin_postorder();it!=tree_2.end_postorder();it++)
    {
        CHECK(arr[i]==(*it));
        i++;
    }


    //tree 3 contain node 10,node 20,node 30...node 100 before overriding
    BinaryTree<string> tree_3;
    tree_3.add_root("node 50");
    tree_3.add_left("node 50","node 20");
    tree_3.add_right("node 50","node 80");
    tree_3.add_left("node 20","node 10");
    tree_3.add_left("node 80","node 60");
    tree_3.add_right("node 20","node 40");
    tree_3.add_right("node 80","node 90");
    tree_3.add_right("node 60","node 70");
    tree_3.add_right("node 90","node 100");
    tree_3.add_left("node 40","node 30");


    //tree 3 , contain 1-10 after overriding, in order of ths tree should be : 1,2,3,4,5,6,7,8,9,10.

    tree_3.add_root("node 5");
    tree_3.add_left("node 5","node 2");
    tree_3.add_right("node 5","node 8");
    tree_3.add_left("node 2","node 1");
    tree_3.add_left("node 8","node 6");
    tree_3.add_right("node 2","node 4");
    tree_3.add_right("node 8","node 9");
    tree_3.add_right("node 6","node 7");
    tree_3.add_right("node 9","node 10");
    tree_3.add_left("node 4","node 3");

    i = 0;
    for(auto it = tree_3.begin_inorder();it!=tree_3.end_inorder();it++)
    {
        CHECK(arr[i]==(*it));
        i++;
    }
  }
  SUBCASE("Exceptions")
  {
    BinaryTree<string> tree_1;
    // //empty tree
    CHECK_THROWS(tree_1.add_left("node 1" , "node 2"));
    CHECK_THROWS(tree_1.add_left("node 1" , "node 3"));
    //root is node 2
    CHECK_NOTHROW(tree_1.add_root("node 2"));
    CHECK_THROWS(tree_1.add_left("node 1" , "node 2"));
    CHECK_THROWS(tree_1.add_right("node 1" , "node 3"));

    //override root to be node 1
    CHECK_NOTHROW(tree_1.add_root("node 1"));
    CHECK_NOTHROW(tree_1.add_left("node 1" , "node 3"));
    CHECK_NOTHROW(tree_1.add_right("node 1" , "node 6"));
    CHECK_NOTHROW(tree_1.add_left("node 3" , "node 2"));
    CHECK_NOTHROW(tree_1.add_right("node 3" , "node 4"));
    CHECK_NOTHROW(tree_1.add_left("node 6" , "node 5"));
    CHECK_NOTHROW(tree_1.add_right("node 6" , "node 7"));
    /*
      now the tree looks like :     node 1
                                   /      \
                                node 3   node 6 
                               /   \      /    \
                          node 2 node 4 node 5  node 7  
    */
    srand(time(NULL));
    for(int i = 0;i<20;i++)
    {
      int tmp = rand() % 100 + 1;
      string node = "node ";
      node+=to_string(tmp);
      //cout<<"the node is : "<<node<<endl;
      if(tmp>7)
      {
        CHECK_THROWS(tree_1.add_left(node , "null"));
        CHECK_THROWS(tree_1.add_right(node , "null"));
        //cout<<"exception has been thrown for node : "<<node<<endl;
      }
      else
      {
        //cout<<"exception doesnt thrown for node : "<<node<<endl;
      }
    }
  }
}