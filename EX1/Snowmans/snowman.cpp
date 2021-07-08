#include<iostream>
#include<string>
#include<stdexcept>
#include "snowman.hpp"
using namespace std;

string Hat(char h);
string Face(string f);
string Body(string b);
string Legs(char l);
string Torso(char t);
char Nose(char n);
char Eye(char e);
char Hand(char h,char side);


//this function return true if the input is legal , false o.w
bool check_input(int input)
{
    const int b_lim=11111111;
    const int t_lim=44444444;
    const int ten=10;
    const int one=1;
    const int four=4;
    const int zero=0;
     if(input<b_lim||input>t_lim)
    {
        return false;
    }
    int tmp=input;
    int i=tmp%ten;
    while(tmp>zero)
    {
        if(i>four||i<one){return false;}
        tmp/=ten;
        i=tmp%ten;
    }
    return true;
}


string ariel::snowman(int a)
{

        //check the legality of the input with "check input" function 
        if(!check_input(a))
        {
            string error = "Invalid code '"+std::to_string(a)+"'";
            throw std::invalid_argument(error);
        }

        //convert the input to string (its more comfortable to process)
        string input = to_string(a);
        const int zero = 0;
        const int one = 1;
        const int five = 5;
        const int four = 4;
        const int three = 3;
        const int seven = 7;


        //split the input to the differente parts of the snowman
        char h= input[zero];
        string f=input.substr(one,five);
        string b=input.substr(four,three);
        char l=input[seven];

        //get the parts of the snowman from the proseccing functions
        string hat = Hat(h);
        string face = Face(f);
        string body = Body(b);
        string legs = Legs(l);
        string snowman = hat + face + body + legs;
        return snowman;
}

//this fuction get char that represent the type of the hat and return the coresponding hat
string Hat(char h)
{
    string hat;
    if(h=='1'){hat = "       \n _===_ \n";}
    if(h=='2'){hat = "  ___  \n ..... \n";}
    if(h=='3'){hat="   _   \n  /_\\  \n";}
    if(h=='4'){hat = "  ___  \n (_*_) \n";}
    return hat;
}

//this fuction get string that represent the type of the nose,eyes,and the arms(for case the arm is upwards)
// and return string that represent the coresponding face.
//this function using more help fuction to get the different parts of the face and gather them to full face
string Face(string f)
{
    string face;
    if(f[3]=='2')
    {
        face+="\\";
        face+="(";
    }
    else {face+=" (";}
    face+=Eye(f[1]);
    face+=Nose(f[0]);
    face+=Eye(f[2]);
    face+=')';
    if(f[4]=='2'){face+="/\n";}
    else {face+=" \n";}
    return face;

}


//this fuction get string that represent the type of the torso and the arms
// and return string that represent the coresponding body.
//this function using more help fuction to get the different parts of the body and gather them to full body
string Body(string b)
{
    string body;
    if(b[0]=='2'){body+=" (";}
    else {body+=Hand(b[0],'l');
    body+='(';}
    body+=Torso(b[2]);
    body+=')';
    if(b[1]=='2'){body+=" \n";}
    else
    {
        body+=Hand(b[1],'r');
        body+="\n";
    }
    return body;
}

//this function get char that represent the legs of the snowman and return a full string 
//of the coresponding legs 
string Legs(char l)
{
    if(l=='1'){return " ( : ) ";}
    if(l=='2'){return " (\" \") ";}
    if(l=='3'){return " (___) ";}
    return " (   ) ";
}

//this fuction get char that represent the nose of the snowman , and return of the coresponding nose
char Nose(char n)
{
    if(n=='1'){return ',';}
    if(n=='2'){return '.';}
    if(n=='3'){return '_';}
    return ' ';
}


//this fuction get char that represent the eye of the snowman , and return of the coresponding eye.
char Eye(char e)
{
    if(e=='1'){return '.';}
    if(e=='2'){return 'o';}
    if(e=='3'){return 'O';}
    return '-';
}

//this fuction get char that represent the arm of the snowman , and char that represent the side of the arm,
//and return the char of the coresponding arm.
char Hand(char h,char side)
{
    //left side.
    if(side == 'l')
    {
        if(h=='1'){return '<';}
        if(h=='2'){return '\\';}
        if(h=='3'){return '/';}
        return ' ';
    }
    //right side.
    if(side == 'r')
    {
        if(h=='1'){return '>';}
        if(h=='2'){return '/';}
        if(h=='3'){return '\\';}
        return ' ';
    }
    return ' ';
}

//this fuction get char that represent the torso of the snowman , and return the char of the coresponding torso.
string Torso(char t)
{
    if(t=='1'){return " : ";}
    if(t=='2'){return "] [";}
    if(t=='3'){return "> <";}
    return "   ";
    
}


