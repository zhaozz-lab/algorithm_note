#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;
const int  N = 100;
int n = 6;
int heap[N] = {0,2,3,4,1,9,5 };


void downAdjust(int low, int high) {
	int i = low, j = i * 2;
	while (j<high)
	{
		if (j + 1 <= high && heap[j + 1] > heap[j])
			j = j + 1;
		if (heap[j] > heap[i]) {
			swap(heap[i], heap[j]);
		    i = j;
			j = i * 2;
		}
		else
		{
			break;
		}
	}
}


void creatHeap() {
	for (int i = n / 2; i >= 1; i--) {
		downAdjust(i, n);
	}
}


void deleteTop() {
	heap[1] = heap[n--];
	downAdjust(1, n);
}


void upAdjust(int low, int high) {
	int i = high, j = high / 2;
	while (j >= low)
	{
		if (heap[j] < heap[i])
		{
			swap(heap[i], heap[j]);
			i = j;
			j = i / 2;
		}
		else
		{
			break;
		}
	}
}


void insert(int x) {
	heap[++n] = x;
	upAdjust(1, n);
}


void heapSort(){
	creatHeap();
	for (int i = n; i > 1; i--) {
		swap(heap[i], heap[1]);
		downAdjust(1, i - 1);
	}
}


int main()
{
	creatHeap();
	heapSort();
	for (int i = 0; i < n; i++)
		cout << heap[i] << endl;
	return 0;
}
