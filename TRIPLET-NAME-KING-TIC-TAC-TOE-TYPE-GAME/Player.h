#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

//
// Player.h
// TripletNameKIng(TicTacToe type game)

#include <iostream>
#include <string>
using namespace std;
class Player {
public:
    Player();
    Player(string,string);
    void inputPlayerInfo();
    void setFirstName(string);
    string getFirstName();
    void setLastName(string);
    string getLastName();
    void setPlayerToken(char);
    char getToken();
private:
    string firstName;
    string lastName;
    char token;
};
Player::Player(){
    firstName = " ";
    lastName = " ";
}
Player::Player(string firstname, string lastname ) {
    setFirstName(firstname);
    setLastName(lastname);
}
void Player::inputPlayerInfo() {
    string firstname;
    string lastname;
    static int personCounter = 1;
    cout << "Player " << personCounter << ":  Enter your first name: " << endl;
    cin >> firstname;
    setFirstName(firstname);
    cout << "Enter your last name: " << endl;
    cin >> lastname;
    setLastName(lastname);
    personCounter++;
}
void Player::setFirstName( string firstname ) {
    firstName = firstname;
}
string Player::getFirstName() {
    return(firstName);
}
void Player::setLastName( string lastname ) {
    lastName = lastname;
}
string Player::getLastName() {
    return(lastName);
}
void Player::setPlayerToken( char marker ) {
    token = marker;
}
char Player::getToken() {
    return(token);
}

#endif // PLAYER_H_INCLUDED
