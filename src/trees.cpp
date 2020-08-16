#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;


struct node {
	int data;
	node* lchild;
	node* rchild;
};


node* newNode(int v) {
	node* Node = new node;
	Node->data = v;
	Node->lchild = Node->rchild = NULL;
	return Node;
}


void search(node* root, int x, int newdata)
{
	if (root == NULL)
		return;

	if (root->data == x)
		root->data = newdata;

	search(root->lchild, x, newdata);
	search(root->rchild, x, newdata);
}
//根节点指针root要使用引用，否则会插入不成功；
//前面的search函数中不需要加是因为search函数修改的是指针root指向的内容
void insert(node*& root, int x)
{
	if (root == NULL)
	{
		root = newNode(x);
		return;
	}

	if (x < root->data)
		insert(root->lchild, x);
	else
	{
		insert(root->rchild, x);
	}
}

//二叉树的建立
node* Create(int data[], int n)
{
	node* root = NULL;
	for (int i = 0; i < n; i++)
	{
		insert(root, data[i]);
	}
	return root;
}


void preorder(node* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d\n", root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}


void inorder(node* root)
{
	if (root == NULL)
	{
		return;
	}

	preorder(root->lchild);
	printf("%d\n", root->data);
	preorder(root->rchild);
}


void postorder(node* root)
{
	if (root == NULL)
	{
		return;
	}

	preorder(root->lchild);

	preorder(root->rchild);
	printf("%d\n", root->data);
}

//层序遍历
void LayerOrder(node* root)
{
	queue<node*> q;//注意队列里保存的是地址
	q.push(root);//将根节点地址入队
	while (!q.empty())
	{
		node* now = q.front();
		q.pop();
		printf("%d", now->data);
		if (now->lchild != NULL)
			q.push(now->lchild);
		if (now->rchild != NULL)
			q.push(now->rchild);

	}
}


int main()
{
	int data1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	node* root = Create(data1, 10);
	cout << "the preorder is " << endl;
	preorder(root);

	cout << "the inorder is " << endl;
	inorder(root);

	cout << "the posterorder is " << endl;
	postorder(root);

	cout << "the layer order is " << endl;
	LayerOrder(root);
	return 1;
}
