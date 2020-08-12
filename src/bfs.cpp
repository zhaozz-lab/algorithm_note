#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>


//给出一个m x n的矩阵，矩阵中的元素为0或1，称位置(x,y)与其上下左右四个位置(x,y-1),(x,y+1),(x+1,y),(x-1,y)。
//如果矩阵中若干个1是相邻的，那么称这些1构成了一个块,求给定的矩阵中块的个数
 /*0 1 1 1 0 0 1
 0 0 1 0 0 0 0 
 0 0 0 0 1 0 0
 0 0 0 1 1 1 0
 1 1 1 0 1 0 0
 1 1 1 1 0 0 0*/ 
//如上图所示，块的个数为4
using namespace std;

const int maxn = 100;
struct node
{
    int x, y;

} Node;

//int n, m;
int m = 6;
int n = 7;
int matrix[maxn][maxn];
bool inq[maxn][maxn] = { false };//记录位置(x,y)是否已如果队
int X[4] = { 0,0,1,-1 };
int Y[4] = { -1,1,0,0 };
bool judge(int x, int y) {
    //越界返回false
    if (x >= m || x <= 0 || y >= n || y <= 0)
        return false;
    if (matrix[x][y] == 0 || inq[x][y] == true)
        return false;
    return true;
}

//BFS 函数访问位置(x,y)所在的块，将块中所有“1”的inq都设置为true

void BFS(int x, int y)
{
    queue<node> Q;//定义队列
    Node.x = x;
    Node.y = y;
    Q.push(Node);
    inq[x][y] = true;
    while (!Q.empty())
    {
        node top = Q.front();//取出队首元素
        Q.pop(); //队首元素出队
        for (int i = 0; i < 4; i++){//循环4次，得到4个相邻位置

            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if (judge(newX, newY)) {
                Node.x = newX;
                Node.y = newY;
                Q.push(Node);
                inq[newX][newY] = true;
            }

        }
    }
 
}

int main()
{
    //scanf("%d%d", &n, &m);
    
    int matrix[6][7] = { {0, 1, 1, 1, 0, 0, 1},
                         {0, 0 ,1, 0, 0, 0, 0},
                         {0, 0, 0, 0, 1, 0, 0},
                         {0, 0, 0, 1, 1, 1, 0},
                         {1, 1, 1, 0, 1, 0, 0},
                         {1, 1, 1, 1, 0, 0, 0},
    };
    int ans = 0;
    for(int x=0;x<m;x++)
        for(int y=0;y<n;y++)
            if (matrix[x][y] == 1 && inq[x][y] == false) {
                ans++;
                BFS(x, y);
            }
   /* DFS(0, 0, 0);
    printf("%d\n", maxValue);*/
    printf("%d\n", ans);
    return 1;
}
