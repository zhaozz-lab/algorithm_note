﻿#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;

const int MAXN = 110;
struct node {
	int weight;    //数据域
	vector<int> child;//指针域
}Node[MAXN];

bool cmp(int a ,int b)
{
	return Node[a].weight > Node[b].weight;
}

int n, m, S;
int path[MAXN]; // 记录路径
//当前访问节点为index,numNode 为当前路径上的节点个数
//sum为当前的节点权和

void DFS(int index, int numNode, int sum)
{
	if (sum > S)
		return;
	if (sum == S) {
		if (Node[index].child.size() != 0)
			return;
		for (int i = 0; i < numNode; i++)
		{
			printf("%d", Node[path[i]].weight);
			if (i < numNode - 1)
				printf(" ");
			else
			{
				printf("\n");
			}
		}
			return;
	}
	for (int i = 0; i < Node[index].child.size(); i++)
	{
		int child = Node[index].child[i];
		path[numNode] = child;
		DFS(child, numNode + 1, sum + Node[child].weight);
		}
}

int main()
{
	n = 4, m = 1, S = 2;
	for (int i = 0; i < n; i++)
		Node[i].weight = 1;
	int id, k, child;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d", &id, &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &child);
			Node[id].child.push_back(child);
		}
		sort(Node[id].child.begin(), Node[id].child.end(), cmp);
	}
	path[0] = 0;
	DFS(0, 1, Node[0].weight);
	return 0;
}