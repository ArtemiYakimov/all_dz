#pragma once
#include "chetugol.h"
#include "error.h"

class Prmugol :public Chetugol {
protected:
    bool isTry() override;
public:
    Prmugol() : Prmugol(10, 20, 10, 20, 90, 90, 90, 90) {};
    Prmugol(int a, int b, int c, int d, int A, int B, int C, int D) :Chetugol("Прямоугольник", a, b, c, d, A, B, C, D) {
        this->print();
    };
};