//
// Created by 石依凡 on 2021/6/28.
//

#ifndef EIGHT_DIGITS_BOARD_H
#define EIGHT_DIGITS_BOARD_H

#include <iostream>

struct Pos
{
    int row = -1;
    int col = -1;

    Pos operator+(Pos a)
    {
        return {row + a.row, col + a.col};
    }

    bool operator==(Pos a)
    {
        return row == a.row and col == a.col;
    }
};

struct Exc
{
    Pos former;
    Pos latter;

    bool operator==(Exc a)
    {
        return (former == a.former and latter == a.latter) or (former == a.latter and latter == a.former);
    }
};

class Board
{
public:
    int board[3][3];
    Exc last;
    int depth;
    Board * parent;

    Board();
    Board(int * m);
    Board(const Board& other);
    ~Board() = default;

    Board createChild(Exc method);
    int diff();
    Pos empty();
    void print();

    bool operator==(const Board other) const;
    int operator< (const Board other) const;
};


#endif //EIGHT_DIGITS_BOARD_H
