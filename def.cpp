#include <iostream>
#include <ctime>
#include <random>
#include <windows.h>
#include "dec.hpp"

using namespace std;

char board[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};


void getComputerChoice()
{
    srand(time(0));
    int choice;
    do
    {
        choice = rand()%10;
    } while (board[choice] != ' ');
    board[choice]='O';
}

void getXplayerChoice()
{
    while (true)
    {
        cout<<"Select Your Position (1-9): ";
        int choice;
        cin>>choice;
        choice--;
        if(choice<0||choice>8)
        {
            cout<<"Please Select between 1-9"<<endl;;
        }
        else if(board[choice] != ' ')
        {
            cout<<"Please Select an empty positon."<<endl;
        }
        else
        {
            board[choice]='X';
            break;
        }   
    }
}

void getOplayerChoice()
{
    while (true)
    {
        cout<<"Select Your Position (1-9): ";
        int choice;
        cin>>choice;
        choice--;
        if (choice<0||choice>8)
        {
            cout<<"Please Select between 1-9"<<endl;;
        }
        else if (board[choice]!=' ')
        {
            cout<<"Please Select an empty positon."<<endl;
        }
        else
        {
            board[choice]='O';
            break;
        }   
    }
}

int countBoard(char symbol)
{
    int total=0;
    for (int i = 0; i < 9; i++)
    {
        if (board[i]==symbol)
        {
            total++;
        }
    }
    return total;
}

char checkWinner()
{
    //checking rows
    if (board[0]==board[1] && board[1]==board[2] && board[0] != ' ')
        return board[0];
    if (board[3]==board[4] && board[4]==board[5] && board[3] != ' ')
        return board[3];
    if (board[6]==board[7] && board[7]==board[8] && board[6] != ' ')
        return board[6];
    
    //checking columns
    if (board[0]==board[3] && board[3]==board[6] && board[0] != ' ')
        return board[0];
    if (board[1]==board[4] && board[4]==board[7] && board[1] != ' ')
        return board[1];
    if (board[2]==board[5] && board[5]==board[8] && board[2] != ' ')
        return board[2];
    
    //checking diagonals
    if (board[0]==board[4] && board[4]==board[8] && board[0] != ' ')
        return board[0];
    if (board[2]==board[4] && board[4]==board[6] && board[2] != ' ')
        return board[2];

    if (countBoard('X')+countBoard('O')<9)
    {
        return 'C';
    }
    else
    return 'D';


}

void playerVsPlayer()
{
    string player1,player2;
    system("cls");
    cout<<"Enter Player 1 Name: "<<endl;
    cin>>player1;
    cout<<"Enter Player 2 Name: "<<endl;
    cin>>player2;

    while (true)
    {
        system("cls");
        if (countBoard('X') == countBoard ('O') )
        {
            cout<<player1<<"'s Turn."<< endl;
            showBoard();
            getXplayerChoice();
        }
        else
        {
            cout<<player2<<"'s Turn."<< endl;
            showBoard();
            getOplayerChoice();
        }
            

        char winner=checkWinner();
        if (winner == 'X')
        {
            system("cls");
            showBoard();
            cout<<endl<<player1<<" won the game."<<endl<<endl;
            break;
        }
        else if (winner == 'O')
        {
            system("cls");
            showBoard();
            cout<<endl<<player2<<" won the game."<<endl<<endl;
            break;
        }
        else if (winner == 'D')
        {
            system("cls");
            showBoard();
            cout<<endl<<"DRAW."<<endl<<endl;
            break;
        } 
    }

}

void computerVsPlayer()
{
    string playername;
    system("cls");
    cout<<"Enter Name: ";
    cin>>playername;
    while (true)
    {
        system("cls");
        if (countBoard('X') == countBoard ('O') )
        {
            showBoard();
            cout<<playername<<"'s Turn."<< endl;
            getXplayerChoice();
            system("cls");
            showBoard();
        }
        else
        {
            showBoard();
            cout<<"Thinking..."<< endl;
            Sleep(3000);
            getComputerChoice();
            system("cls");
            showBoard();
        }
        
        
        
        char winner=checkWinner();
        if (winner == 'X')
        {
            system("cls");
            showBoard();
            cout<<playername<<" won the game."<<endl;
            break;
        }
        else if (winner == 'O')
        {
            system("cls");
            showBoard();
            cout<<"Computer won the game."<<endl;
            break;
        }
        else if (winner == 'D')
        {
            system("cls");
            showBoard();
            cout<<"DRAW."<<endl;
            break;
        }
        
        
        
    }
    
}

void showBoard()
{
    
    cout<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"   "<<board[0]<<"   |   "<<board[1]<<"   |   "<<board[2]<<endl;
    cout<<"   "<<"    |   "<<"    |   "<<endl;
    cout<< "-----------------------"<<endl;
    cout<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"   "<<board[3]<<"   |   "<<board[4]<<"   |   "<<board[5]<<endl;
    cout<<"   "<<"    |   "<<"    |   "<<endl;
    cout<< "-----------------------"<<endl;
    cout<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"   "<<board[6]<<"   |   "<<board[7]<<"   |   "<<board[8]<<endl;
    cout<<"   "<<"    |   "<<"    |   "<<endl;
}
