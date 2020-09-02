#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;
const int  N = 110;
int father[N];
bool isRoot[N];


int findFather(int x) {
	int a = x;
	while (x != father[x])
	{
		x = father[x];
	}

	while (a != father[a])
	{
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}


void Union(int a, int b) {
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB)
		father[faA] = faB;
}


void init(int n) {
	for (int i = 1; i <= n; i++)
	{
		father[i] = i;
		isRoot[i] = false;
	}
}
int main()
{
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= m; i++) {
		isRoot[findFather(i)] = true;
		scanf("%d%d", &a, &b);
		Union(a, b);
	}

	for (int i = 1; i <= n; i++)
		isRoot[findFather(i)] = true;



	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += isRoot[i];
	}
	printf("%d\n", ans);
	return 0;
}
