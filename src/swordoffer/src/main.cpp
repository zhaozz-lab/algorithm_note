#include <iostream>
#include<chrono>
#include<vector>
#include<string>
using namespace std;
//#define BENCHMARK 1
int add(int x,int y ) {

	return x+y;
}

int* (*func)() = 0;

int testtime(int x,int y ,int (*func)(int,int)) {
	auto start = std::chrono::steady_clock::now();
	func(x, y);
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	printf("the spend time is %f", elapsed.count());
	return -1;
}
void test_callback() {
	if (BENCHMARK)
		testtime(1, 2, add);
	else
		printf("==");
}

//指针的算术运算
//int* find(const vector<int>& vec, int value) {
//	for (int ix = 0; ix < vec.size(); ++ix) {
//		if (vec[ix] == value)
//			return &vec[ix];
//	}
//	return 0;
//}


template <typename elemType>
elemType* find(const vector<elemType>& vec, const elemType& value) {

	for (int ix = 0; ix < vec.size(); ++ix) {
		if (vec[ix] == value)
			return &vec[ix];
	}
	return 0;
}


//template <typename elemType>
//elemType* find(const elemType* vec,int size, const elemType& value) {
//
//	for (int ix = 0; ix < size; ++ix) {
//		if (vec[ix] == value)
//			return &vec[ix];
//	}
//	return 0;
//}


template <typename elemType>
elemType* find(const elemType* array, int size, const elemType& value) {

	if (!array || size < 1)
	{
		return 0;
	}
	for (int ix = 0; ix < size; ++ix) {
		if (array[ix] == value)
			return &array[ix];
	}
	return 0;
}


template <typename elemType>
elemType* find(const elemType* first, const elemType* last, const elemType& value) {

	if (!first || !last)
	{
		return 0;
	}
	for (; first != last;++first) {
		if (*first == value)
			return first;
	}
	return 0;
}


void test_pointer_algorithm() {
	int ia[8] = { 1,2,3,4,5,6,7,8 };
	float fa[8] = { 1,2,3,4,5,6,7,8 };
	char sa[4] = { 't','s','3','2' };
	
	int* pi = find(ia, ia + 8, ia[3]);
	int* pi0 = find(ia, ia + 8, 0);

	float* pf = find(fa, fa + 8, fa[3]);
	float* pf0 = find(fa, fa + 8, 0);

	char* ps = find(sa, sa + 4, sa[3]);
	char* ps0 = find(sa, sa + 4, 0);

}

int main() {
	test_pointer_algorithm();




}