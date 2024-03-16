#pragma once
#include "chetugol.h"
#include "error.h"

class Kvadrat :public Chetugol {
protected:
    bool isTry() override;
public:
    Kvadrat() : Kvadrat(20, 20, 20, 20, 90, 90, 90, 90) {};
    Kvadrat(int a, int b, int c, int d, int A, int B, int C, int D) :Chetugol(" вадрат", a, b, c, d, A, B, C, D) {
        this->print();
    };
};