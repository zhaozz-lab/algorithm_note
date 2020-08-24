// graph depth first travese


#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
const int N = 5;


struct Node
{
    int v;//边的终点编号
    int w;//边的权重
    Node(int _v, int _w) :v(_v), w(_w) {}
};


vector<Node> Adj[N];
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
        for (int i = 0; i < Adj[index].size(); i++)
        {
            Node v = Adj[index][i];
            
            if (vis[v.v] == false)
            {
                cout << v.v << "  " << v.w << endl;
                q.push(v.v);
                vis[v.v] = true;
            }
        }

    }
    /*for (int i = 0; i < Adj[u].size(); i++)
    {
        Node v = Adj[u][i];
        
        if (vis[v.v] == false)
        {
            cout << v.v << "  " << v.w <<"depth is "<<depth<< endl;
            bfs(v.v, depth + 1);
        }
    }*/
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
   
    Adj[0].push_back(Node(1, 1));
    Adj[0].push_back(Node(4, 1));
    
    Adj[1].push_back(Node(0, 2));
    Adj[1].push_back(Node(2, 2));
    Adj[1].push_back(Node(4, 2));
    
    Adj[2].push_back(Node(1, 2));
    Adj[2].push_back(Node(3, 1));
    
    Adj[3].push_back(Node(2, 1));
    Adj[3].push_back(Node(4, 1));
    
    Adj[4].push_back(Node(0, 1));
    Adj[4].push_back(Node(1, 2));
    Adj[4].push_back(Node(3, 1));
   
    
    BFSTrave();

    return 0;
}
