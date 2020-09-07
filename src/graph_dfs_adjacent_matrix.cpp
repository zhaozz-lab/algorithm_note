// graph depth first travese
#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int N = 10;



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




void dfs(int u, int depth) {
    vis[u] = true;
    for (int i = 0; i < N; i++)
    {
        int v = adjMatrix[u][i];
        
        if (vis[i] == false && v!=0)
        {
            cout << i << "  "<<"depth is "<<depth<< endl;
            dfs(i, depth + 1);
        }
    }
}

void DFSTrave() 
{
    for (int u = 0; u < N; u++)
    {
        if (vis[u] == false)
        {
            dfs(u, 1);
        }
    }
}

int main()
{
    for(int i=0;i<N;i++)
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
    
    DFSTrave();

    return 0;
}
