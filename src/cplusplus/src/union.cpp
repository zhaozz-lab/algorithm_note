#include<iostream>
using namespace std;

class base {
public:
	base() {
		cout << "construct the base class" << endl;
	}

	virtual ~base() {
		cout << "destruct the base class" << endl;
	}
};

class derived :public base {
public:
	derived() {
		cout << "construct the derived class" << endl;
	}

	~derived() {
		cout << "destruct the derived class" << endl;
	}
};

void main() {

	base* pbase = new base();
	delete pbase;
	derived* pderived = new derived();
	delete pderived;
	cout << "--------------" << endl;
	base* pbasederived = new derived();
	delete pbasederived;
}
