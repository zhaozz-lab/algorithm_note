// graph depth first travese
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXV = 1000;//最大顶点数
const int INF = 100000;
int n, m, s, G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV] = { false };
//Dijkstra的基本思想是对图G(V,E)设置集合S，存放已被访问的顶点，然后每次从集合V-S中选择与起点s最短距离最小
//一个顶点（记为u），访问并加入集合S，之后，令顶点u为中介点，优化起点s与所有从u能到达的顶点v之间的距离。这样的
//操作执行n次(n为顶点个数)，直到集合顶点S已包含所有顶点。

void Dijkstra(int s) {
    fill(d, d + MAXV, INF);//fill函数将整个d数组赋值为INF
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        //d[]中保存每个点与点i的距离
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
    
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
                d[v] = d[u] + G[u][v];
            }
        }
    }
}


int main()
{
    int u, v, w;
    n = 6;
    m = 8;
    s = 0;
    fill(G[0], G[0] + MAXV * MAXV, INF);
    G[0][1] = 1;
    G[0][3] = 4;
    G[0][4] = 4;

    G[1][3] = 2;
    G[2][5] = 1;

    G[3][2] = 2;
    G[3][4] = 3;
    G[4][5] = 3;

    Dijkstra(s);
    for (int i = 0; i < n; i++)
        printf(" %d ", d[i]);
    
    return 0;
}
