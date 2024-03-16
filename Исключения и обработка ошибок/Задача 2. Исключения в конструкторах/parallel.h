#pragma once
#include "chetugol.h"
#include "error.h"

class Parallel :public Chetugol {
protected:
    bool isTry() override;
public:
    Parallel() :Parallel(20, 30, 20, 30, 30, 40, 30, 40) {};
    Parallel(int a, int b, int c, int d, int A, int B, int C, int D) :Chetugol("ֿאנאככוכמדנאלל", a, b, c, d, A, B, C, D) {
        this->print();
    };
};