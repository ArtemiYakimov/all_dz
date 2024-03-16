#pragma once
#include "treugolnik.h"
#include "error.h"

class Prmtreugol :public Treugolnik {
protected:
    bool isTry() override;
public:
    Prmtreugol() : Prmtreugol(10, 20, 30, 50, 60, 90) {};
    Prmtreugol(int a, int b, int c, int A, int B, int C) : Treugolnik("Прямоугольный треугольник", a, b, c, A, B, C) {
        this->print();
    };
};