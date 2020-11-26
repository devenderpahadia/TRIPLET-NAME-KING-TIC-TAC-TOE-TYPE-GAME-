#ifndef TICTACTOE_H_INCLUDED
#define TICTACTOE_H_INCLUDED

//
// TicTacToe.h
// TripletNameKIng(TicTacToe type game)

#include "Cell.h"
#include "Player.h"
class TicTacToe {
public:
    TicTacToe();
    int getplayer1();
    int getplayer2();
    int getCurrentPlayer();
    void setPlayerInfo();
    void displayBoard();
    void makeMove();
    bool checkForWinner();
    static const int getRow();
    static const int getColumn();
private:
    static const int Row = 3;
    static const int Column = 3;
    Cell gameBoard[Row][Column];
    Player players[2];
    int currentPlayer;
    int player1;
    int player2;
    const int WINNER_1;
    const int WINNER_2;
};
TicTacToe::TicTacToe() : WINNER_1 (9), WINNER_2 (-9) {
    player1 = 3;
    player2 = -3;
}
int TicTacToe::getplayer1() {
    return(player1);
}
int TicTacToe::getplayer2() {
    return(player2);
}
int TicTacToe::getCurrentPlayer() {
    return(currentPlayer);
}
void TicTacToe::setPlayerInfo() {
    char marker1 = 'a';
    char marker2 = 'a';
    players[0].inputPlayerInfo();
    cout << "Input marker in the triplet Name King ie. First letter Of your Name." << endl;
    cout<<"Input Marker:\n";
    cin >> marker1;
    players[0].setPlayerToken(marker1);
    cout << players[0].getFirstName() << " your token is " << players[0].getToken() << endl;
    players[1].inputPlayerInfo();
    cout<<"\nInput Marker:\n";
    cin>>marker2;
    players[1].setPlayerToken(marker2);
    cout << players[1].getFirstName() << " your token is " << players[1].getToken() << endl;
}
void TicTacToe::displayBoard() {
    for ( int r = 0; r < Row; r++ ) {
        cout << "---------" << endl;
        for ( int c = 0; c < Column; c++ ) {
            if ( gameBoard[r][c].getMark() == -2 ) {
                cout <<  "  |";
            }
            else if ( gameBoard[r][c].getMark() == player2 ) {
                cout <<  players[0].getToken()<<" |";
            }
            else if ( gameBoard[r][c].getMark() == player1 ) {
                cout <<  players[1].getToken()<<" |";
            }
            if ( c == 2 ) {
                cout << endl;
            }
        }
    }
    cout << "---------" << endl;
}
void TicTacToe::makeMove() {
    int RowVal = -1;
    int ColumnVal = -1;
    int player = 0;
    bool winner = true;
    int counter = 0;
    do {
        for ( int i= 0; i < 2; i++ ) {
            if ( players[i].getToken() == players[1].getToken() ) {
                player = player1;
            }
            else {
                player = player2;
            }
            cout << players[i].getFirstName() << " make your move!" << endl;
            cout << "What Row?" << endl;
            cin >> RowVal;
            if ( RowVal-1 >= 0 && RowVal-1 < Row ) {
                cout << "What Column?" << endl;
                cin >> ColumnVal;
                if ( ColumnVal-1 >= 0 && ColumnVal-1 < Column ) {
                    if ( gameBoard[RowVal-1][ColumnVal-1].getMark() == -2 ) {
                        gameBoard[RowVal-1][ColumnVal-1].setMark( player );
                        counter++;
                        displayBoard();
                        winner = checkForWinner();
                        if ( winner == true ) {
                            cout << "Congrats! " << players[i].getFirstName() << " has won!" << endl;
                            break;
                        }
                    }
                    else {
                        cout << "Try again!" << endl;
                    }
                }
            }
        }
    }  while ( !winner && counter < Row*Column );
}
bool TicTacToe::checkForWinner() {
    int sum = 0;
    bool win = false;
    for ( int r = 0; r < Row; r++ ) {
        sum = 0;
        for ( int c = 0; c < Column; c++ ) {
            sum += gameBoard[r][c].getMark();
        }
        if ( sum == WINNER_1 ) {
            win = true;
        }
        else if ( sum == WINNER_2 ) {
            win = true;
        }
    }
    for ( int r = 0; r < Row; r++ ) {
        sum = 0;
        for ( int c = 0; c < Column; c++ ) {
            sum += gameBoard[c][r].getMark();
        }
        if ( sum == WINNER_1  ) {
            win = true;
        }
        else if ( sum == WINNER_2 ) {
            win = true;
        }
    }
    sum = 0;
    for ( int r = 0; r < Row; r++ ) {
        for ( int c = 0; c < Column; c++ ) {
            if ( r == c ) {
                sum += gameBoard[r][c].getMark();
            }
        }
        if ( sum == WINNER_1  ) {
            win = true;
        }
        else if ( sum == WINNER_2 ) {
            win = true;
        }
    }
    sum = 0;
    for ( int r = 0; r < Row; r++ ) {
        for ( int c = 0; c < Column; c++ ) {
            if ( r + c == 2 ) {
                sum += gameBoard[r][c].getMark();
            }
        }
        if ( sum == WINNER_1  ) {
            win = true;
        }
        else if ( sum == WINNER_2 ) {
            win = true;
        }
    }
    return ( win );
}
const int TicTacToe::getRow() {
    return(Row);
}
const int TicTacToe::getColumn() {
    return(Column);
}

#endif // TICTACTOE_H_INCLUDED
