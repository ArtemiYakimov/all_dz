#include "chetugol.h"

Chetugol::Chetugol(string name, int a, int b, int c, int d, int A, int B, int C, int D) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
    this->name = name;
};

Chetugol::Chetugol() :Figura() {
    this->a = 10;
    this->b = 20;
    this->c = 30;
    this->d = 40;
    this->A = 50;
    this->B = 60;
    this->C = 70;
    this->D = 80;
    this->name = "Четырехугольник";
};
string Chetugol::print() {
    return this->name + ":\nCтороны: a = " + to_string(this->a) + " b = " + to_string(this->b) + " c = " + to_string(this->c) + " d = " + to_string(this->d) +
        "\nУглы: A = " + to_string(this->A) + " B = " + to_string(this->B) + " C = " + to_string(this->C) + " D = " + to_string(this->D);
};