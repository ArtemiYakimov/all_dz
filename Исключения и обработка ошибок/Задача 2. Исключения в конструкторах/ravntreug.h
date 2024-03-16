#pragma once
#include "treugolnik.h"
#include "error.h"

class Ravntreug :public Treugolnik {
protected:
    bool isTry() override;
public:
    Ravntreug() :Ravntreug(10, 20, 10, 50, 60, 50) {};
    Ravntreug(int a, int b, int c, int A, int B, int C) :Treugolnik("Равнобедренный треугольник", a, b, c, A, B, C) {
        this->print();
    };
};