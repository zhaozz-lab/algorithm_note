#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;

const int maxn = 50;

int post[7] = { 2,3,1,5,7,6,4 };
int in[7] = { 1,2,3,4,5,6,7 };
struct node {
	int data;
	node* lchild;
	node* rchild;
};

int n = 7;

node* create(int postL, int postR, int inL, int inR)
{
	if (postL>postR)
	{
		return NULL;//后续序列长度小于等于0时，直接返回
	}

	node* root = new node;
	root->data = post[postR];
	int k;
	for (k = inL; k <= inR; k++)
	{
		if (in[k] == post[postR])
			break;
	}

	int numLeft = k - inL;//左子树的节点个数
	root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);

	root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);

	return root;
 
}

int num = 0;
void BFS(node* root) {
	queue<node*> q;//注意队列里是保存地址
	q.push(root);

	while (!q.empty())
	{
		node* now = q.front();
		q.pop();
		printf("%d", now->data);
		num++;
		if (num < n) printf(" ");
		if (now->lchild != NULL) q.push(now->lchild);
		if (now->rchild != NULL) q.push(now->rchild);

	}
}


int main()
{
	node* root = create(0, n - 1, 0, n - 1);
	cout << root->data << endl;
	BFS(root);
	return 1;
}
