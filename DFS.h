//
// Created by 石依凡 on 2021/6/28.
//

#ifndef EIGHT_DIGITS_DFS_H
#define EIGHT_DIGITS_DFS_H

#include <iostream>
#include <cstring>
#include "Board.h"
#include <vector>
#include <set>

class DFS
{
public:
    int plate[3][3];
    static std::set <Board> accessed;

    DFS(int * plate);
    void solve();
};


#endif //EIGHT_DIGITS_DFS_H
