//
// Created by 石依凡 on 2021/6/29.
//

#ifndef EIGHT_DIGITS_BFS_H
#define EIGHT_DIGITS_BFS_H

#include "Board.h"
#include <set>

class BFS
{
public:
    int plate[3][3];
    static std::set <Board> accessed;

    BFS(int * plate);
    void solve();
};


#endif //EIGHT_DIGITS_BFS_H
