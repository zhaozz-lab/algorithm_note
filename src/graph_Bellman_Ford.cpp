﻿// graph depth first traverse
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
const int MAXV = 510;
const int INF = 0x3fffffff;
using namespace std;
struct Node {
    int v, dis;//v为邻接边的目标顶点，dis为邻接边的边权
    Node(int _v,int _dis):v(_v),dis(_dis){}
};
vector<Node> Adj[MAXV];

int n, m, st, ed, weight[MAXV];

int d[MAXV], w[MAXV], num[MAXV];
set<int> pre[MAXV];//前驱

void Bellman(int s) {
    fill(d, d + MAXV, INF);
    memset(num, 0, sizeof(num));
    memset(w, 0, sizeof(w));

    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;

    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (int j = 0; j < Adj[u].size(); j++) {
                int v = Adj[u][j].v;
                int dis = Adj[u][j].dis;
                if (d[u] + dis < d[v]) {
                    d[v] = d[u] + dis;
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                    pre[v].clear();
                    pre[v].insert(u);
               
                }
                else if(d[u] + dis == d[v])
                {
                    if (w[u] + weight[v] > w[v]) {
                        w[v] = w[u] + weight[v];
                    }
                    pre[v].insert(u);
                    num[v] = 0;
                    set<int>::iterator it;
                    for (it = pre[v].begin(); it != pre[v].end(); it++) {
                        num[v] += num[*it];
                    }

                }

            }
        }
    }

}

int main()
{
    
    
    return 0;
}
