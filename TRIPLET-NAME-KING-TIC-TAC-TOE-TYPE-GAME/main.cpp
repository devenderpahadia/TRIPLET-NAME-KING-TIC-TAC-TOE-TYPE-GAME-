//
//  main.cpp
//  TripletNameKIng(TicTacToe type game)
//
#include <iostream>
#include "TicTacToe.h"
using namespace std;
int main(int argc, const char * argv[])
{
    cout<<"\nDEVENDER KUMAR PAHADIA\n";
    char playerAnswer;
    TicTacToe T;
    cout << "Would you like to play Triplet Name King (Tic Tac Toe Type Game)? (Y/N)" << endl;
    cin >> playerAnswer;
    if ( playerAnswer == 'y' || playerAnswer == 'Y' ) {
        T.setPlayerInfo();
        T.displayBoard();
        T.makeMove();
    }
    else
        cout << "Bye!" << endl;
    return 0;
}
