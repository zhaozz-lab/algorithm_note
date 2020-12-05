#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;
const int maxn = 30;
int n, V, maxValue = 0;//物品件数n，背包容量V，最大价值maxValue
int w[maxn], c[maxn];
// 有n件物品，每件物品的重量为w[i],价值为c[i],现在需要选出若干物品放入一个容量为V的背包中
//使得在选入背包的物品重量和不超过V的情况下，物品的价值最大
void DFS(int index, int sumW, int sumC)
{
    if (index == n) { 
        if (sumW <= V && sumC > maxValue)
        {
            maxValue = sumC;
        }
        return;
    }

    DFS(index + 1, sumW, sumC); //不选第index件物品
    DFS(index + 1, sumW + w[index], sumC + c[index]);//选第index件物品
}

namespace stackmethod {
    vector<int> direction{ -1,0,1,0,-1 };
    int maxAreaOsIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        int localarea, area = 0, x, y;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j])
                {
                    localarea = 1;
                    grid[i][j] = 0;
                    stack<pair<int, int>> island;
                    island.push({ i,j });
                    while (!island.empty())
                    {
                        auto location = island.top();
                        int r = location.first;
                        int c = location.second;
                        island.pop();
                        for (int k = 0; k < 4; ++k)
                        {
                            x = r + direction[k], y = c + direction[k + 1];
                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                                grid[x][y] = 0;
                                ++localarea;
                                island.push({ x,y });
                            }
                        }
                    }
                    area = max(area, localarea);
                }
            }
        }

        return area;
    }
}


namespace recursionmethod {
    vector<int> direction{ -1,0,1,0,-1 };
    int dfs(vector<vector<int>>& grid, int i, int j);
    int maxAreaOsIsland(vector<vector<int>>grid) {
        int m = grid.size(), n = grid[0].size();
        int maxarea=0;
        for (int i=0;i< m;++i)
        {
            for (int j = 0; j < n; ++j) {
                
                if (grid[i][j])
                {
                    cout << "-------------" << endl;
                    maxarea = max(maxarea,dfs(grid, i, j));
                    cout << maxarea << endl;
                }         
           }
        }
        return maxarea;
    }

    int dfs(vector<vector<int>>&grid,int i,int j) {
        if (grid[i][j]==0)
        {
            return 0;
        }
        
        grid[i][j] = 0;
        int area = 1;
        int x, y;
        for (int k = 0;k<4;++k)
        {
            x = i + direction[k];
            y = j + direction[k + 1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()&&grid[x][y])
            {
                cout << "x " << x << " y " << y << endl;
                area += dfs(grid, x, y);
            }
        }
    }
}




int main()
{
	/*  scanf("%d%d", &n, &V);
	  for (int i = 0; i < n; i++) {
		  scanf("%d", &w[i]);
	  }
	  for (int i = 0; i < n; i++) {
		  scanf("%d", &c[i]);
	  }

	  DFS(0, 0, 0);
	  printf("%d\n", maxValue);*/

    vector<vector<int>> grid;
    grid.push_back({ 0, 1, 1, 1, 0, 0, 1 });
    grid.push_back({ 0, 0 ,1, 0, 0, 0, 0 });
    grid.push_back({ 0, 1, 1, 1, 0, 0, 1 });
        
    //int area = stackmethod::maxAreaOsIsland(grid);
    int area = recursionmethod::maxAreaOsIsland(grid);
    cout << "the area is " << area << endl;
    return 1;
}
