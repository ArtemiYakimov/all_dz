#pragma once
#include <string>

using namespace std;

class Error :public exception {
public:
	string b;
	Error(string c);
	string vozvrat();
};