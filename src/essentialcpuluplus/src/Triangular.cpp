#include <iostream>
#include<chrono>
#include<vector>
#include<string>
#include "Triangular.h"
using namespace std;

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