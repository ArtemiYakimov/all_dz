#pragma once
#include "chetugol.h"
#include "error.h"

class Romb :public Chetugol {
protected:
    bool isTry() override;
public:
    Romb() :Romb(30, 30, 30, 30, 30, 40, 30, 40) {};
    Romb(int a, int b, int c, int d, int A, int B, int C, int D) :Chetugol("Ромб", a, b, c, d, A, B, C, D) {
        this->print();
    };
};