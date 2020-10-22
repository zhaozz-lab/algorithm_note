// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int maxn = 2010;
const int INF = 1000000;

map<int, string> intToString; //编号->姓名
map<string, int> stringToInt;//姓名->编号
map<string, int> Gang;//head->人数

int G[maxn][maxn] = { 0 }, weight[maxn] = { 0 };
int n, k, numPerson = 0; //边数n，下限k，总人数numPerson
bool vis[maxn] = { false };

//DFS 函数访问单个连通块，nowVisit为当前访问的编号
//head 为头目，numMember为成员编号，totalValue为联通块的总边权
void DFS(int nowVisit, int& head, int& numMember, int& totalValue)
{
    numMember++;//成员人数加1
    vis[nowVisit] = true;
    if (weight[nowVisit] >weight[head])
    {
        head = nowVisit; //当前访问节点的点权大于头目的点权，则更新头目
    }

    for (int i = 0; i < numPerson; i++)
    {
        if (G[nowVisit][i] > 0) {
            totalValue += G[nowVisit][i];
            G[nowVisit][i] = G[i][nowVisit] = 0;
            if (vis[i]==false)
            {
                DFS(i, head, numMember, totalValue);
            }
        }
    }

}

//DFSTrave 函数遍历整个图，获取每个联通块的信息
void DFSTrave() {
    for (int i = 0; i < numPerson; i++)
    {
        if (vis[i] == false)
        {
            int head = i, numMember = 0, totalValue = 0;
            DFS(i, head, numMember, totalValue);
            if (numMember > 2 && totalValue > k) {
                Gang[intToString[head]] = numMember;
            }
        }
    }
}


int change(string str)
{
    if (stringToInt.find(str) != stringToInt.end()) { //如果str已经出现过，返回编号
        return stringToInt[str];
    }
    else
    {
        stringToInt[str] = numPerson;
        intToString[numPerson] = str;
        return numPerson++;
    }
}

int main()
{
    int w;
    string str1, str2;

    n = 8;
    k = 59;

    for(int i=0;i<n;i++)
    {
        cin >> str1 >> str2 >> w; //输入边的两个端点和点权
        int id1 = change(str1);
        int id2 = change(str2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;

    }
    DFSTrave();
    cout << Gang.size() << endl;

    map<string, int>::iterator it;

    for (it = Gang.begin();it!=Gang.end();it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
