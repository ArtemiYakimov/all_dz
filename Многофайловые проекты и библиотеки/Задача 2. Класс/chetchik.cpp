#include <iostream>
#include "chetchik.h"

using namespace std;

Counter::Counter() {
    this->a = 1;
};
Counter::Counter(int b) {
    this->a = b;
};
void Counter::uvel() {
    ++this->a;
};
void Counter::umen() {
    --this->a;
};
void Counter::znach() {
    cout << this->a << endl;
};