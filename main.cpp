#include <iostream>
#include "DFS.h"
#include "BFS.h"
#include <iostream>

using namespace std;

int main()
{
    int map[] = {2, 8, 3, 1, 6, 4, 7, -1, 5};

    int mode;
    cout << "请输入类型，1：BFS；2：DFS\n";
    while(cin >> mode)
    {
        if(mode == 1)
        {
            BFS(map).solve();
        }
        else if(mode == 2)
        {
            DFS(map).solve();
        } else
        {
            cout << "请重新输入。\n";
            continue;
        }
        cout << "请输入类型，1：BFS；2：DFS\n";
    }
    return 0;
}
