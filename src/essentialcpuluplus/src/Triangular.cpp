#include <iostream>
#include<chrono>
#include<vector>
#include<string>
#include "Triangular.h"
using namespace std;

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

ostream& operator<<(ostream& os, const Triangular& rhs) {
	os << "("
		<< rhs.begin() << ","
		<< rhs.length() << ")";
}


istream&
operator>>(istream& is, Triangular& rhs)
{
	char ch1, ch2;
	int bp, len;

	// given the input: ( 3 , 6 ) 6, 10, 15, 21, 28, 36 
	// ch1 == ‘(’, bp == 3, ch2 == ‘,’, len == 6
	is >> ch1 >> bp >> ch2 >> len;

	rhs.beg_pos(bp);
	rhs.length(len);
	rhs.next_reset();

	return is;
}


Triangular::Triangular(int len, int beg_pos):_length(len>0?len:1),_beg_pos(beg_pos>0?beg_pos:1) {
	_next = _beg_pos;
	int elem_cnt = _beg_pos + _length;
	if (_elems.size() < elem_cnt)
		gen_elements(elem_cnt);
}


Triangular::Triangular(const Triangular& rhs)
	: _length(rhs._length),
	_beg_pos(rhs._beg_pos),
	_next(rhs._next)
{}


int sum(const Triangular& trian)
{
	if (!trian.length())
		return 0;

	int val, sum = 0;
	trian.next_reset();

	while (trian.next(val))
		sum += val;

	return sum;
}

int Triangular::
elem(int pos) const
{
	return _elems[pos - 1];
}

bool Triangular::
next(int& value) const
{
	if (!_next)
		return false;

	if (_next < _beg_pos + _length) {
		// error: modifying _next
		value = _elems[_next++];
		return true;
	}
	_next = 0; // error: modifying _next
	return false;
}

Triangular&
Triangular::
operator=(const Triangular& rhs)
{
	if (this != &rhs) {
		_length = rhs._length;
		_beg_pos = rhs._beg_pos;
		_next = 1;
	}

	return *this;
};

vector<int> Triangular::_elems;

bool Triangular::
is_elem(int value)
{
	if (!_elems.size() || _elems[_elems.size() - 1] < value)
		gen_elems_to_value(value);

	vector<int>::iterator found_it;
	vector<int>::iterator end_it = _elems.end();

	found_it = find(_elems.begin(), end_it, value);
	return found_it != end_it;
}

void Triangular::
gen_elements(int length)
{
	if (length < 0 || length > _max_elems) {
		cerr << "Triangular Sequence: oops: invalid size: "
			<< length << " -- max size is "
			<< _max_elems << endl;
		return;
	}

	if (_elems.size() < length)
	{
		int ix = _elems.size() ? _elems.size() + 1 : 1;
		for (; ix <= length; ++ix)
			_elems.push_back(ix * (ix + 1) / 2);
	}
}

void Triangular::
gen_elems_to_value(int value)
{
	int ix = _elems.size();
	if (!ix) {
		_elems.push_back(1);
		ix = 1;
	}

	while (_elems[ix - 1] < value && ix < _max_elems)
	{
		//     cout << "elems to value: " << ix*(ix+1)/2 << endl;
		_elems.push_back(ix * (ix + 1) / 2);
		++ix;
	}

	if (ix == _max_elems)
		cerr << "Triangular Sequence: oops: value too large "
		<< value << " --  exceeds max size of "
		<< _max_elems << endl;

}

void Triangular::
display(int length, int beg_pos, ostream& os)
{
	if (length <= 0 || beg_pos <= 0) {
		cerr << "invalid parameters -- unable to fulfill request: "
			<< length << ", " << beg_pos << endl;
		return;
	}

	int elems = beg_pos + length - 1;

	if (_elems.size() < elems)
		gen_elements(elems);

	for (int ix = beg_pos - 1; ix < elems; ++ix)
		os << _elems[ix] << ' ';
}