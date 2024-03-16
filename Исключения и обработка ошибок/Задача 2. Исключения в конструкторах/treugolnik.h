#pragma once
#include <iostream>
#include "figura.h"
#include "error.h"

class Treugolnik :public Figura {
private:
    string name;
    int stor = 3;
protected:
    int a, b, c, A, B, C;
    Treugolnik(string name, int a, int b, int c, int A, int B, int C);
    virtual bool isTry();
    bool proverka();
public:
    Treugolnik();
    void print() override;
};