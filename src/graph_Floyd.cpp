// graph depth first traverse
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
const int INF = 1000000000;
const int MAXV = 200;
int n, m;
int dis[MAXV][MAXV];

void Floyd() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}

int main()
{
    int u, v, w;

    fill(dis[0], dis[0] + MAXV * MAXV, INF);
    n = 6;
    m = 8;
    for (int i = 0; i < n; i++)
        dis[i][i] = 0;
     
    dis[0][1] = 1;
    dis[0][3] = 4;
    dis[0][4] = 4;
    dis[1][3] = 2;

    
    dis[2][5] = 1;
    dis[3][2] = 2;
    dis[3][4] = 3; 
    dis[4][5] = 3;

    Floyd();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", dis[i][j]);
        }
        printf("\n");
    }
    return 0;
}
