#include "figura.h"

Figura::Figura() {
    this->a = 0;
    this->b = "Фигура";
};
Figura::Figura(int a, string b) {
    this->a = a;
    this->b = b;
};
string Figura::print() {
    return this->b + ": " + to_string(this->a);
};