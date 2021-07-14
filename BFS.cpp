//
// Created by 石依凡 on 2021/6/29.
//

#include "BFS.h"
#include <deque>

using namespace std;

inline bool isValid(Pos pos)
{
    return pos.row < 3 and pos.row >= 0 and pos.col < 3 and pos.col >= 0;
}

const Pos CHANGE[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

std::set <Board> BFS::accessed;

void BFS::solve()
{
    deque <Board> nodes;
    deque <Board> path;
    nodes.push_front(Board(*plate));

    while(!nodes.empty())
    {
        Board * p = new Board(nodes.front());
        Board & crntNode = *p;
        nodes.pop_front();

        if(crntNode.depth > 20)
            continue;

        if(accessed.find(crntNode) != accessed.end())
            continue;
        accessed.insert(crntNode);

        if(crntNode.diff() == 0)
        {
            Board * m = & crntNode;
            while(m != nullptr)
            {
                path.push_front(*m);
                m = m->parent;
            }

            cout << "最短路径：\n\n";

            for(auto each: path)
            {
                each.print();
            }
            break;
        }

        Pos empty = crntNode.empty();
        for(int i = 0; i < 4; i++)
        {
            if(isValid(empty + CHANGE[i]))
            {
                if(crntNode.last == Exc({empty, empty + CHANGE[i]}))
                    continue;
                Board child(crntNode.createChild({empty, empty + CHANGE[i]}));
                nodes.push_back(child);
            }
        }
    }
}

BFS::BFS(int *plate1)
{
    for(int i = 0; i < 9; i++)
        (*plate)[i] = plate1[i];
}
