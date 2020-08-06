// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
void selectSort(int A[],int n)
{
    for (int i = 0; i < n; i++)
    {
        int k = i;
        for (int j = i; j < n; j++)
        {
            if(A[j] < A[k])
                k = j;
        }
        int temp = A[k];
        A[k] = A[i];
        A[i] = temp;
   }
}


//void insertSort(int A[], int n)
//{
//    for (int i = 1; i < n; i++) {
//        int temp = A[i], j = i;
//    }
//}
int main()
{
    int A[5] = { 2,5,1,6,3 };

    selectSort(A, 5);
    for (int i = 0; i < 5; i++)
    {
        std::cout << A[i] << std::endl;
    }
    return 1;
}
