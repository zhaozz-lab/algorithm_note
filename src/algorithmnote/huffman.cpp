#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> q;


int main()
{
	int n;
	long long x, y, ans = 0;
	long long temp[5] = { 3,5,4,1,2 };
	for (int i = 0; i < 5; i++) {
		q.push(temp[i]);
	}
	while (q.size() > 1) {
		x = q.top();
		q.pop();
		y = q.top();
		q.pop();
		cout << x << " " << y << endl;
		ans += x + y;
	}
	cout << ans << endl;
	return 0;
}
