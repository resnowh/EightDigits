//
// Created by 石依凡 on 2021/6/28.
//

#include "Board.h"

Board::Board(int * m): depth(0), parent(nullptr)
{
    for(int i = 0; i < 9; i++)
        (*board)[i] = m[i];
}

Board::Board(const Board &other): depth(other.depth), parent(other.parent)
{
    for(int i = 0; i < 9; i++)
        (*board)[i] = (*other.board)[i];

    last = other.last;
}

Board::Board(): depth(0), parent(nullptr)
{
    for(int i = 0; i < 9; i++)
        (*board)[i] = -1;
}

Board Board::createChild(Exc method)
{
    last = method;
    Pos a = method.former;
    Pos b = method.latter;

    Board temp(*this);
    temp.depth++;
    temp.board[a.row][a.col] = board[b.row][b.col];
    temp.board[b.row][b.col] = board[a.row][a.col];

    temp.parent = this;

    return temp;
}

int Board::diff()
{
    int num = 0;

    for(int i = 0; i < 3; i++)
        if(board[0][i] != i + 1)
            num++;

    if(board[1][0] != 8)
        num++;
    if(board[1][2] != 4)
        num++;

    if(board[2][0] != 7)
        num++;
    if(board[2][1] != 6)
        num++;
    if(board[2][2] != 5)
        num++;

    return num;
}

Pos Board::empty()
{
    int i, j;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            if(board[i][j] < 0)
                return {i, j};

    return {-1, -1};
}

void Board::print()
{
    for(auto & i : board)
    {
        for(int j : i)
        {
            std::cout << j << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "\n";
}

bool Board::operator==(const Board other) const
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != other.board[i][j])
                return false;
        }
    }

    return true;
}

int Board::operator<(const Board other) const
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != other.board[i][j])
                return board[i][j] - other.board[i][j] < 0;
        }
    }

    return 0;
}

