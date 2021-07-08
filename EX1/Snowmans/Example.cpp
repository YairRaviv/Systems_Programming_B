#include<iostream>
#include<string>
#include "snowman.hpp"
//#include "snowman.cpp"
using namespace std;
using namespace ariel;

int main()
{
    cout<<"Welcome to snowman game!!!"<<endl<<endl;
    cout<<"This is some of our snowmans";
     string a= snowman(11111111);
    string b= snowman(22222222);
    string c= snowman(33333333);
    string d= snowman(42442313);
    cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<endl;
    cout<<"Do you want to build your own snowman??"<<endl<<"1.yes"<<endl<<"2.no"<<endl;
    int ans;
    cin>>ans;
    switch(ans)
    {
        case 1:
        {
            cout<<"great!! lets begin :"<<endl<<endl;
            break;
        }
        case 2:
        {
            cout<<"Oh no!! you should try it later .. "<<endl;
            cout<<snowman(21442311)<<endl<<endl;
            cout<<"bye bye"<<endl;
            break;
        }
        default:
        {
            cout<<"there is no such option !!!"<<endl;
            break;
        }
    }
    if(ans==1)
    {
        int tmp;
        int num=0;
        cout<<"which Hat do you like??"<<endl<<"1.Straw\n2.Mexican\n3.Fez\n4.Russian\n"<<endl;
        cin>>tmp;
        num+=tmp;
        num*=10;
        tmp=0;
        cout<<"which Nose do you like??"<<endl<<"1.Normal\n2.Dot\n3.Line\n4.None\n"<<endl;
        cin>>tmp;
        num+=tmp;
        num*=10;
        tmp=0;
        cout<<"which Eyes do you like??"<<endl<<"1.Dot\n2.Small o\n3.Big O\n4.Closed eye\n"<<endl;
        cin>>tmp;
        num+=tmp;
        num*=10;
        num+=tmp;
        num*=10;
        tmp=0;
        cout<<"which Hands do you like??"<<endl<<"left hand:\n1.On waist\n2.Upwards\n3.Downwards\n4.No hand\n"<<endl;
        cin>>tmp;
        num+=tmp;
        num*=10;
        tmp=0;
        cout<<"Right hand:\n1.On waist\n2.Upwards\n3.Downwards\n4.No hand\n"<<endl;
        cin>>tmp;
        num+=tmp;
        num*=10;
        tmp=0;
        cout<<"which Torso do you like??"<<endl<<"1.Bottons\n2.Vest\n3.Inward Arms\n4.None\n"<<endl;
        cin>>tmp;
        num+=tmp;
        num*=10;
        tmp=0;
        cout<<"which Base do you like??"<<endl<<"1.Bottons\n2.Feet\n3.Flat\n4.None\n"<<endl;
        cin>>tmp;
        num+=tmp;
        string result;
        try{
            result=snowman(num);
            cout<<"congratulations!! your snowman in ready\n"<<result<<endl<<endl<<"Bye Bye"<<endl;
        }
        catch(invalid_argument)
        {
            cout<<"wrong Answer!!"<<endl;
        }

    }
    return 0;
}