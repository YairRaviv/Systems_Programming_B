#include<iostream>
#include<string>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <fstream>
#include <sstream>
#include<unordered_map>
using namespace std;
using namespace pandemic;
const unsigned int cities_num=49;

namespace pandemic
{

            //init board in private function.
            Board::Board()
            {
                this->init();
            }
            //empty destructor , no heap use.
            Board::~Board()
            {

            }
            //return true if the disease level is 0 in all cities.
            bool Board::is_clean()
            {
                for(unsigned int i =1;i<cities_num;i++)
                {
                    if(cities_info.at(i).at("D_level")!=0){return false;}
                }
                return true;
            }
            //return referance to the disease level of this city.
            int& Board::operator[](City city)
            {
                return cities_info.at(city).at("D_level");
            }
            //for each city with this color - update the cure existance to 1(true).
            void Board::cure_found(const Color& c)
            {
                for(unsigned int i=1;i<cities_num;i++)
                {
                    if(cities_info.at(i).at("color")==c)
                    {
                        cities_info.at(i).at("cure")=1;
                    }
                }
            }
            //find the first city with this color - and check if there is cure for this city - return true.
            bool Board::cure_exist(const Color& color)
            {
                for(unsigned int i =1;i<cities_num;i++)
                {
                    if(cities_info.at(i).at("color")==color)
                    {
                        return (cities_info.at(i).at("cure")!=0);
                    }
                }
                return false;
            }
            //update cure existance to 0(false) in all cities
            void Board::remove_cures()
            {
                for(unsigned int i =1 ; i<cities_num;i++)
                {
                    cities_info.at(i).at("cure")=0;
                }
            }
            //update research station existance to 0(false) in all cities
            void Board::remove_stations()
            {
                for(unsigned int i =1;i<cities_num;i++)
                {
                    cities_info.at(i).at("Research_station")=0;
                }
            }
            void Board::init()
            {   

                //update the convertion tables of city number <-> city name.
                table["Atlanta"] = City::Atlanta;
                table["Chicago"] = City::Chicago;
                table["Montreal"] = City::Montreal;
                table["SanFrancisco"] = City::SanFrancisco;
                table["Washington"] = City::Washington;
                table["NewYork"] = City::NewYork;
                table["Madrid"] = City::Madrid;
                table["London"] = City::London;
                table["Paris"] = City::Paris;
                table["Essen"] = City::Essen;
                table["Milan"] = City::Milan;
                table["StPetersburg"] = City::StPetersburg;

                //Yellow Cities
                table["Bogota"] = City::Bogota;
                table["Miami"] = City::Miami;
                table["MexicoCity"] = City::MexicoCity;
                table["LosAngeles"] = City::LosAngeles;
                table["Lima"] = City::Lima;
                table["SaoPaulo"] = City::SaoPaulo;
                table["BuenosAires"] = City::BuenosAires;
                table["Santiago"] = City::Santiago;
                table["Khartoum"] = City::Khartoum;
                table["Kinshasa"] = City::Kinshasa;
                table["Lagos"] = City::Lagos;
                table["Johannesburg"] = City::Johannesburg;

                //Black Cities
                table["Algiers"] = City::Algiers;
                table["Baghdad"] = City::Baghdad;
                table["Cairo"] = City::Cairo;
                table["Chennai"] = City::Chennai;
                table["Delhi"] = City::Delhi;
                table["Istanbul"] = City::Istanbul;
                table["Karachi"] = City::Karachi;
                table["Kolkata"] = City::Kolkata;
                table["Moscow"] = City::Moscow;
                table["Mumbai"] = City::Mumbai;
                table["Riyadh"] = City::Riyadh;
                table["Tehran"] = City::Tehran;

                //Red Cities
                table["Bangkok"] = City::Bangkok;
                table["Beijing"] = City::Beijing;
                table["HoChiMinhCity"] = City::HoChiMinhCity;
                table["HongKong"] = City::HongKong;
                table["Jakarta"] = City::Jakarta;
                table["Manila"] = City::Manila;
                table["Osaka"] = City::Osaka;
                table["Seoul"] = City::Seoul;
                table["Shanghai"] = City::Shanghai;
                table["Sydney"] = City::Sydney;
                table["Taipei"] = City::Taipei;
                table["Tokyo"]  = City::Tokyo;


                table_to_string[City::Atlanta] = "Atlanta";
                table_to_string[City::Chicago] = "Chicago";
                table_to_string[City::Montreal] = "Montreal";
                table_to_string[City::SanFrancisco] = "SanFrancisco";
                table_to_string[City::Washington] = "Washington";
                table_to_string[City::NewYork] = "NewYork";
                table_to_string[City::Madrid] = "Madrid";
                table_to_string[City::London] = "London";
                table_to_string[City::Paris] = "Paris";
                table_to_string[City::Essen] = "Essen";
                table_to_string[City::Milan] = "Milan";
                table_to_string[City::StPetersburg] = "StPetersburg";

                //Yellow Cities
                table_to_string[City::Bogota] = "Bogota";
                table_to_string[City::Miami] = "Miami";
                table_to_string[City::MexicoCity] = "MexicoCity";
                table_to_string[City::LosAngeles] = "LosAngeles";
                table_to_string[City::Lima] = "Lima";
                table_to_string[City::SaoPaulo] = "SaoPaulo";
                table_to_string[City::BuenosAires] = "BuenosAires";
                table_to_string[City::Santiago] = "Santiago";
                table_to_string[City::Khartoum] = "Khartoum";
                table_to_string[City::Kinshasa] = "Kinshasa";
                table_to_string[City::Lagos] = "Lagos";
                table_to_string[City::Johannesburg] = "Johannesburg";

                //Black Cities
                table_to_string[City::Algiers] = "Algiers";
                table_to_string[City::Baghdad] = "Baghdad";
                table_to_string[City::Cairo] = "Cairo";
                table_to_string[City::Chennai] = "Chennai";
                table_to_string[City::Delhi] = "Delhi";
                table_to_string[City::Istanbul] = "Istanbul";
                table_to_string[City::Karachi] = "Karachi";
                table_to_string[City::Kolkata] = "Kolkata";
                table_to_string[City::Moscow] = "Moscow";
                table_to_string[City::Mumbai] = "Mumbai";
                table_to_string[City::Riyadh] = "Riyadh";
                table_to_string[City::Tehran] = "Tehran";

                //Red Cities
                table_to_string[City::Bangkok] = "Bangkok";
                table_to_string[City::Beijing] = "Beijing";
                table_to_string[City::HoChiMinhCity] = "HoChiMinhCity";
                table_to_string[City::HongKong] = "HongKong";
                table_to_string[City::Jakarta] = "Jakarta";
                table_to_string[City::Manila] = "Manila";
                table_to_string[City::Osaka] = "Osaka";
                table_to_string[City::Seoul] = "Seoul";
                table_to_string[City::Shanghai] = "Shanghai";
                table_to_string[City::Sydney] = "Sydney";
                table_to_string[City::Taipei] = "Taipei";
                table_to_string[City::Tokyo]  = "Tokyo";

                //init all details of the cities : color , disease level , cure existance , research station existance

                const unsigned int blue_cities = 13;
                const unsigned int yellow_cities = 25;
                const unsigned int black_cities = 37;
                for(unsigned int i=1;i<blue_cities;i++)
                {
                    cities_info[i]["color"]=Color::Blue;
                    cities_info[i]["D_level"]=0;
                    cities_info[i]["cure"]=0;
                    cities_info[i]["Research_station"]=0;
                }
                for(unsigned int i=blue_cities;i<yellow_cities;i++)
                {
                    cities_info[i]["color"]=Color::Yellow;
                    cities_info[i]["D_level"]=0;
                    cities_info[i]["cure"]=0;
                    cities_info[i]["Research_station"]=0;
                }
                for(unsigned int i=yellow_cities;i<black_cities;i++)
                {
                    cities_info[i]["color"]=Color::Black;
                    cities_info[i]["D_level"]=0;
                    cities_info[i]["cure"]=0;
                    cities_info[i]["Research_station"]=0;
                }
                for(unsigned int i=black_cities;i<cities_num;i++)
                {
                    cities_info[i]["color"]=Color::Red;
                    cities_info[i]["D_level"]=0;
                    cities_info[i]["cure"]=0;
                    cities_info[i]["Research_station"]=0;
                }

                //update the connections map between the cities by using cities_map.txt
                ifstream cities("cities_map.txt");
                string line;
                while(getline(cities , line))
                {
                    string src;
                    string tmp_city;
                    unsigned int i = 0;
                    while(line[i]!=' ')
                    {
                        src+=line[i];
                        i++;
                    }
                    i++;
                    //skip over the color
                    while(line[i]!=' ')
                    {
                        i++;
                    }
                    i++;
                    while(i<line.length())
                    {
                        if(line[i]!=' ')
                        {
                            tmp_city+=line[i];
                        }
                        else
                        {
                            unsigned int key = table.at(src);
                            unsigned int value = table.at(tmp_city);
                            neighbors[key][value]=1;
                            tmp_city = "";
                        }
                        i++;
                        if(i==line.length())
                        {
                            unsigned int key = table.at(src);
                            unsigned int value = table.at(tmp_city);
                            neighbors[key][value]=1;
                        }
                    }
                }
                
                
            }

            //stream out the information at this format , every city in different line:
            //City : (city name) , disease level : (number) , cure existance : (true/false) , Research station existence : (true/false).
            ostream& operator<<(ostream& os ,const Board& board)
            {
                string ans;
                for(unsigned int i = 1; i<cities_num; i++)
                {
                    ans = board.table_to_string.at(i);
                    bool cure = (board.cities_info.at(i).at("cure")!=0);
                    bool research = (board.cities_info.at(i).at("Research_station")!=0);
                    os<<boolalpha;
                    os<<"City : "<<ans<<" , disease level : "<<board.cities_info.at(i).at("D_level");
                    os<<" , cure existence : "<<cure<<" , Research station existence : ";
                    os<<research<<"\n";
                }
                return os;
            }
}            
          
            
    




    