//#pragma once
//#ifndef _ADD_H_ 
//#define _ADD_H_ 
//
//#ifdef  ADD_DLL 
//#define EXPORT_DLL _declspec(dllexport)
//#else 
//#define EXPORT_DLL _declspec(dllimport)
//#endif 
_declspec(dllexport) int add(int*);
int add(int* a) {
	int sum = 0;
	for (int i = 0; i < 2; i++) {
		sum += a[i];
	}
	return sum;
}

//#undef EXPORT_DLL 
//
//#endif 