#include <iostream>
#include<chrono>
#include<vector>
#include<string>
#include "Triangular_iterator.h"
typedef Triangular_iterator iterator;
using namespace std;

class Triangular {
	friend class Triangular_iterator;
public:
	 
	Triangular(int len=1,int bp=1);
	Triangular(const Triangular&);
	Triangular& operator =(const Triangular &rhs);

	int length() const { return _length; }
	int beg_pos() const { return _beg_pos; }
	int elem(int pos) const;

	void length(int nlen) { _length = nlen; }
	void beg_pos(int npos) { _beg_pos = npos; }

	bool next(int& val) const;
	void next_reset() const{
		_next = 1;
	}

	static bool is_elem(int);
	static void gen_elements(int length);
	static void gen_elems_to_value(int value);
	static void display(int length, int beg_pos, ostream& os = cout);

	

	Triangular_iterator begin() const
	{
		return Triangular_iterator(_beg_pos);
	}

	Triangular_iterator end() const
	{
		return Triangular_iterator(_beg_pos+length);
	}

	Triangular& copy(const Triangular& rhs);
private:
	int _length;
	int _beg_pos;
	mutable int _next;
	//static data member
	//static  const int _max_elems = 1024;
	enum
	{
		_max_elems = 1024
	};
	static vector<int> _elems;
};