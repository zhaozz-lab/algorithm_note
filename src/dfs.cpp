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
int main()
{
    scanf("%d%d", &n, &V);
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    DFS(0, 0, 0);
    printf("%d\n", maxValue);

    return 1;
}
