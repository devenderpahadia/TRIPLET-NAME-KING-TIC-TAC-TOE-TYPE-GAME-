#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

//
// Cell.h
// TripletNameKIng(TicTacToe type game)
#include <iostream>
using namespace std;
class Cell {
public:
    Cell();
    void setMark(int);
    int getMark();
private:
    int mark;
};
Cell::Cell() {
    mark = -2;
}
void Cell::setMark( int indexValue) {
    mark = indexValue;
}
int Cell::getMark() {
    return(mark);
}

#endif // CELL_H_INCLUDED
