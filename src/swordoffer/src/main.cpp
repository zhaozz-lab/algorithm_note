#include <iostream>
#include<chrono>
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
int main() {
	testtime(1, 2, add);

}