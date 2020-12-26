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

bool less_than(int v1, int v2) {
	return v1 < v2 ? true: false;
}

bool greater_than(int v1, int v2) {
	return v1 > v2 ? true: false;
}
//泛型算法
vector<int> filter(const vector<int>& vec, int filter_value, bool(*pred)(int, int)) {
	vector<int> nvec;
	for (int ix = 0; ix < vec.size(); ++ix)
		if (pred(vec[ix], filter_value))
			nvec.push_back(vec[ix]);
	return nvec;
}


void testfilter() {
	vector<int> input{ 1,2,3,4,5,6 };
	vector<int> output = filter(input, 3, less_than);
	//采用lambda表达式进行计算
	vector<int> output1 = filter(input, 3, [](int x, int y) {return x < y; });
}


class Triangular_iterator
{

public:
	Triangular_iterator(int index):_index(index-1){}
	bool operator==(const Triangular_iterator&) const;
	bool operator!=(const Triangular_iterator&) const;
	int operator*() const;
	Triangular_iterator& operator++();//prefix version	
	Triangular_iterator& operator++(int);//postfix version
private:
	void check_integrity() const;
	int _index;
};






class Triangular {
public:
	 
	Triangular(int,int);
	int length() const { return _length; }
	int beg_pos() const { return _beg_pos; }
	int elem(int pos) const;

	bool next(int& val) const;
	void next_reset() const{
		_next = _beg_pos - 1;
	}
	Triangular& copy(const Triangular& rhs);
private:
	int _length;
	int _beg_pos;
	mutable int _next;
	//static data member
	static vector<int> _elems;
};


Triangular::Triangular(int length=1,int beg_pos =1) {

	//_length = length;
	//_beg_pos = beg_pos;
	//for (int i= beg_pos())
	//{
	//}
}


int Triangular::elem(int pos) const 
{
	return _elems[pos - 1];
}


bool Triangular::next(int& value) const
{
	if (_next < _beg_pos + _length -1)
	{
		value = _elems[_next++];
		return true;
	}
	return false;
}


Triangular& Triangular::copy(const Triangular& rhs) {
	//检查两个对象是否相同
	if (this != &rhs) {
		_length = rhs._length;
		_beg_pos = rhs._beg_pos;
		_next = rhs._beg_pos - 1;
	}
	return *this;
}


int sum(const Triangular& trian)
{
	if (!trian.length())
		return 0;

	int val, sum1 = 0;
	trian.next_reset();
	while (trian.next(val))
		sum1 += val;
	return sum1;
}
vector<int> Triangular::_elems;



void testtriangular() {
	Triangular tri(4);
	Triangular tr3(3);
	Triangular tr4;
	tr4.copy(tr3);

	std::cout <<" ==sum of elements" << sum(tri) << std::endl;
}



inline bool Triangular_iterator::
operator==(const Triangular_iterator& rhs) const
{
	return _index == rhs._index;
}


inline bool Triangular_iterator::
operator!=(const Triangular_iterator& rhs) const
{
	return !(*this == rhs);
}


class iterator_overflow {};

inline void Triangular_iterator::
check_integrity() const
{
	//we'll look at the throw expression in Chapter 7...
	if (_index > Triangular::_max_elems)
		throw iterator_overflow();

}

int main() {
	test_pointer_algorithm();
	testfilter();
	testtriangular();

}