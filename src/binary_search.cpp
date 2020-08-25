#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;

const int MAXN = 110;
struct node
{
	int data;
	node* lchild;
	node* rchild;
	node(int _data,node* _lchild, node* _rchild):data(_data),lchild(_lchild),rchild(_rchild){}
};


void search(node* root, int x)
{
	if (root == NULL)
		return;
	if (root->data == x)
		printf("find %d", x);
	if (root->data < x)
	{
		search(root->rchild, x);
	}
	else
	{
		search(root->lchild, x);
	}
}


void insert(node*& root, int x)
{
	if (root == NULL){
		root = new node(x, NULL, NULL);
		return;
	}
	if (root->data == x)
	{
		//printf("the data is exist \n");
		return;
	}
	else if (root->data < x)
		insert(root->rchild, x);
	else	
		insert(root->lchild, x);
}


node* create(int data[], int n)
{
	node* root = NULL;
	for (int i = 0; i < n; i++)
	{
		insert(root, data[i]);
	}
	return root;
}

node* findMax(node* root)
{
	while (root != NULL)
	{
		root = root->rchild;

	}
	return root;
}


node* findMin(node* root)
{
	while (root != NULL)
	{
		root = root->lchild;

	}
	return root;
}


void deleteNode(node*& root, int x)
{
	if (root == NULL)
		return;
	if (root->data == x) {
		if (root->lchild == NULL && root->rchild == NULL)
			root == NULL;
	}
	else if (root->lchild != NULL)
	{
		node* pre = findMax(root->lchild);
		root->data = pre->data;
		deleteNode(root->lchild, root->data);

	}
	else
	{
		node* next = findMin(root->rchild);
		root->data = next->data;
		deleteNode(root->rchild, root->data);
	}

	if (root->data > x) {
		deleteNode(root->lchild, x);
	}
	else
	{
		deleteNode(root->rchild, x);
	}
}


int main()
{
	int data[10] = { 3,4,6,7,9,8 };
	node* root = create(data, 6);

	search(root, 10);
	search(root, 6);
	node* minnode = findMin(root);
	printf("the min value is %d", minnode->data);

	node* maxnode = findMax(root);
	printf("the min value is %d", maxnode->data);

	search(root, 3);
	deleteNode(root, 3);

	printf("after delete");
	search(root, 3);

	





	return 0;
}