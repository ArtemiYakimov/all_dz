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
    this->name = "Треугольник";
};

void Treugolnik::print() {
    cout << this->name + " (стороны " + to_string(a) + ", " + to_string(b) + ", " + to_string(c) +
        "; углы " + to_string(A) + ", " + to_string(B) + ", " + to_string(C) + ") создан" << endl;

    if (this->proverka()) {
        if (this->isTry()) {
            cout << "Фигура создана, ошибок нет." << endl;
            cout << endl;
        }
    }
};

bool Treugolnik::isTry() {
    return true;
};

bool Treugolnik::proverka() {
    if (this->stor != 3 || (this->A + this->B + this->C != 180)) {
        throw Error("сумма углов не равна 180");
    }
    return true;
};