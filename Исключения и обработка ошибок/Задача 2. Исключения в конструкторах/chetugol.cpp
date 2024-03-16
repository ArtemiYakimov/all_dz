#include <iostream>
#include "chetugol.h"

using namespace std;

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
    this->name = "���������������";
};

void Chetugol::print() {
    cout << this->name + " (������� " + to_string(this->a) + ", " + to_string(this->b) + ", " + to_string(this->c) + ", " + to_string(this->d) +
        "; ���� " + to_string(this->A) + ", " + to_string(this->B) + ", " + to_string(this->C) + ", " + to_string(this->D) + ") ������" << endl;

    if (this->proverka()) {
        if (this->isTry()) {
            cout << "������ �������, ������ ���." << endl;
            cout << endl;
        }
    }
};

bool Chetugol::isTry() {
    return true;
};

bool Chetugol::proverka() {
    if (this->stor != 4 || (this->A + this->B + this->C + this->D != 360)) {
        throw Error("����� ����� �� ����� 360");
    }
    return true;
};