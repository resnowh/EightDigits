//
// Created by 石依凡 on 2021/6/28.
//

#include "DFS.h"
#include <deque>

using namespace std;

inline bool isValid(Pos pos)
{
    return pos.row < 3 and pos.row >= 0 and pos.col < 3 and pos.col >= 0;
}

const Pos CHANGE[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

std::set <Board> DFS::accessed;

void DFS::solve()
{
    deque <Board> nodes;
    deque <Board> path;

    deque <Board> shortest;
    int steps = 99999;

    nodes.push_front(Board(*plate));
    path.push_back(Board(*plate));

    while(!nodes.empty())
    {
        Board crntNode = nodes.back();
        nodes.pop_back();

        if(crntNode.depth > 15)
            continue;

        if(accessed.find(crntNode) != accessed.end())
            continue;
        accessed.insert(crntNode);

        if(crntNode.depth > path.back().depth)
            path.push_back(crntNode);
        else if(crntNode.depth == path.back().depth)
        {
            accessed.erase(path.back());
            path.pop_back();
            path.push_back(crntNode);
        }
        else
        {
            int j = path.back().depth;
            for(int i = 0; i < j - crntNode.depth + 1; i++)
            {
                accessed.erase(path.back());
                path.pop_back();
            }
            path.push_back(crntNode);
        }

        if(crntNode.diff() == 0)
        {
            if(path.size() < steps)
            {
                steps = path.size();
                shortest = path;
            }

//            for(auto each: path)
//            {
//                each.print();
//            }
//            cout << "\n\n\n";
            continue;
        }

        Pos empty = crntNode.empty();
        for(int i = 0; i < 4; i++)
        {
            if(isValid(empty + CHANGE[i]))
            {
                if(crntNode.last == Exc({empty, empty + CHANGE[i]}))
                    continue;
                nodes.push_back(Board(crntNode.createChild({empty, empty + CHANGE[i]})));
            }
        }
    }

    cout << "最短路径：\n\n";

    for(auto each: shortest)
    {
        each.print();
    }
}

DFS::DFS(int *plate1)
{
    for(int i = 0; i < 9; i++)
        (*plate)[i] = plate1[i];
}
