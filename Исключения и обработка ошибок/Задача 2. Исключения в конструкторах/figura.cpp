#include <iostream>
#include "figura.h"

using namespace std;

Figura::Figura() {
    this->a = 0;
    this->b = "Фигура";
};
Figura::Figura(int a, string b) {
    this->a = a;
    this->b = b;
};
void Figura::print() {
    cout << this->b + ": " + to_string(this->a) << endl;
};