#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;


struct node {
	int v, height;
	node* lchild, * rchild;
	
};


node* newNode(int v) {
	node* Node = new node;
	Node->v = v;
	Node->height = 1;
	Node->lchild = Node->rchild = NULL;
	return Node;
}


int getHeight(node* root) {
	if (root == NULL)
		return 0;
	return root->height;
}


int getBalanceFactor(node* root) {
	return getHeight(root->lchild) - getHeight(root->rchild);
}


void updateHeight(node* root)
{
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}


void search(node* root, int x)
{
	if (root == NULL)
		return;

	if (x == root->v)
	{
		printf("find %d", x);
	    return;
		}
	if (x < root->v) {
		search(root->lchild, x);
	}
	else
	{
		search(root->rchild, x);
	}

}


void L(node* &root) {
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}


void R(node*& root) {
	node* temp = root->lchild;
	root->rchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
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

	if (x < root->v)
	{
		insert(root->lchild, x);
		updateHeight(root);//update tree height
		if (getBalanceFactor(root) == 2) {
			if (getBalanceFactor(root->lchild) == 1) {
				R(root);
			}
			else if (getBalanceFactor(root->lchild) == -1) {
				L(root->lchild);
				R(root);
			}
		}
	}
	else
	{
		insert(root->rchild, x);
		updateHeight(root);
		if (getBalanceFactor(root) == -2) {
			if (getBalanceFactor(root->rchild) == -1) {
				L(root);
			}
			else if (getBalanceFactor(root->rchild) == 1) {
				R(root->rchild);
				L(root);
			}
		}
	}
}

//AVL树的建立
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
	printf("%d\n", root->v);
	preorder(root->lchild);
	preorder(root->rchild);
}


void inorder(node* root)
{
	if (root == NULL)
	{
		return;
	}

	inorder(root->lchild);
	printf("%d\n", root->v);
	inorder(root->rchild);
}


void postorder(node* root)
{
	if (root == NULL)
	{
		return;
	}

	preorder(root->lchild);

	preorder(root->rchild);
	printf("%d\n", root->v);
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
		printf("%d", now->v);
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
