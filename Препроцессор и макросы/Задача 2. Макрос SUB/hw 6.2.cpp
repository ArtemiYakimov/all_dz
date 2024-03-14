#include <iostream>
#include <Windows.h>
#define SUB(a, c) ((a) - (c)) 
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	int a = 6;
	int b = 5;
	int c = 2;
	cout << SUB(a, b) << endl;
	cout << SUB(a, b) * c << endl;
	cout << SUB(a, b + c) * c << endl;
	
    return 0;
}