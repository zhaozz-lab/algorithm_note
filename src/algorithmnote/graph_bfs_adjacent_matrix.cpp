// graph depth first travese


#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
const int N = 5;

int adjMatrix[N][N];
bool vis[N] = { false };
//0----1-----2
//|    |     |
//|----4-----3


//assume the graph is 
//  0 1 2 3 4 
//0 0 2 0 0 1 
//1 2 0 2 0 2
//2 0 2 0 1 0
//3 0 0 1 0 1
//4 1 2 0 1 0

void bfs(int u) {
    vis[u] = true;
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int index = q.front();
        q.pop();
        for (int i = 0; i < N; i++)
        {
            int v = adjMatrix[index][i];
            
            if (vis[i] == false && adjMatrix[index][i] != 0)
            {
                cout << i << "  " << endl;
                q.push(i);
                vis[i] = true;
            }
        }

    }

}

void BFSTrave() 
{
    for (int u = 0; u < N; u++)
    {
        if (vis[u] == false)
        {
            bfs(u);
        }
    }
   
}

int main()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            adjMatrix[i][j] = 0;

    adjMatrix[0][1] = 2;
    adjMatrix[1][0] = 2;

    adjMatrix[0][4] = 1;
    adjMatrix[4][0] = 1;

    adjMatrix[1][0] = 2;
    adjMatrix[1][2] = 2;
    adjMatrix[1][4] = 2;

    adjMatrix[2][1] = 2;
    adjMatrix[2][3] = 1;

    adjMatrix[3][2] = 1;
    adjMatrix[3][4] = 1;

    adjMatrix[4][0] = 1;
    adjMatrix[4][1] = 2;
    adjMatrix[4][3] = 1;
   
    
    BFSTrave();

    return 0;
}
