#include "treugolnik.h"

Treugolnik::Treugolnik(string name, int a, int b, int c, int A, int B, int C) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->A = A;
    this->B = B;
    this->C = C;
    this->name = name;
};

Treugolnik::Treugolnik() :Figura() {
    this->a = 10;
    this->b = 20;
    this->c = 30;
    this->A = 50;
    this->B = 60;
    this->C = 90;
    this->name = "“реугольник";
};
string Treugolnik::print() {
    return this->name + ":\nCтороны: a = " + to_string(this->a) + " b = " + to_string(this->b) + " c = " + to_string(this->c) +
        "\n”глы: A = " + to_string(this->A) + " B = " + to_string(this->B) + " C = " + to_string(this->C);
};