#pragma once
#include "treugolnik.h"
#include "error.h"

class Ravnstortreug :public Treugolnik {
protected:
    bool isTry() override;
public:
    Ravnstortreug() : Ravnstortreug(30, 30, 30, 60, 60, 60) {};
    Ravnstortreug(int a, int b, int c, int A, int B, int C) :Treugolnik("Равносторонний треугольник", a, b, c, A, B, C) {
        this->print();
    };
};