#include<iostream>
#include<string>
#include "Direction.hpp"
#include "Board.hpp"
#include<unordered_map>
using namespace std;
using namespace ariel;
const unsigned int maximum=21474836;


            Board::Board()
            {
                unordered_map<unsigned int,unordered_map<unsigned int,char>> table;
                max_row=0;
                max_column=0;
                min_row=maximum;
                min_column=maximum;
            }
            void Board::post(unsigned int row,unsigned int column,ariel::Direction d,string massage)
            {
                //update minimum sizes of the board
                if(row<min_row){min_row = row;}
                if(column<min_column){min_column = column;}

                //insert the massage
                unsigned int i = 0;
                while(i<massage.length())
                {
                    table[row][column] = massage.at(i);
                    i++;
                    //choose direction
                    if(d == Direction::Horizontal){column++;}
                    else {row++;}
                }
                //update maximum sizes of the board
                if(row>max_row){max_row = row;}
                if(column>max_column){max_column = column;}
            }
            string Board::read(unsigned int row,unsigned int column,ariel::Direction d,unsigned int len)
            {
                string ans;
                unsigned int i = 0;
                while(i<len)
                {
                    //check if exist value
                    if(table[row][column]==0)
                    {
                        ans+='_';
                    }
                    else
                    {
                        ans+=table.at(row).at(column);
                    }
                    i++;
                    //choose direction
                    if(d == Direction::Horizontal){column++;}   
                    else {row++;}
                }
                return ans;

            }
             void Board::show()
            {   
                //run from [min row,min column]->[max row,max column]
                for(unsigned int i=min_row;i<=max_row;i++)
                {
                    for(unsigned int j=min_column;j<=max_column;j++)
                    {
                        if(table[i][j]==0)
                        {
                        cout<<'_';
                        }
                        else
                        {
                        cout<<table.at(i).at(j);
                        }
                    }
                    cout<<endl;
                }
            }

            
    




    
