#include <iostream>
#include <ctime>
#include <random>
#include <windows.h>
#include "dec.hpp"

using namespace std;

int main()
{
    system("cls");
    cout<< "-----------------------"<<endl;
    cout<<"  1:Single Player "<<endl<<endl;
    cout<<"  2:Multiplayer"<<endl<<endl;
    cout<<"  3:EXIT "<<endl;
    cout<< "-----------------------"<<endl;  
    cout<<"  Enter the Mode: \n\t";
    
    int n;cin>>n;
    switch (n)
    {
    case 1:
        computerVsPlayer();
        break;
    case 2:
        playerVsPlayer();
        break;
    case 3:
        return 0;
    default:
        break;
    }
    return 0;
}
