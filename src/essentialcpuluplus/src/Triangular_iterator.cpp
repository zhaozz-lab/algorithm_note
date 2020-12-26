#include <iostream>
#include<chrono>
#include<vector>
#include<string>
#include "Triangular_iterator.h"
#include "Triangular.h"
using namespace std;

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