#pragma once
#include "figura.h"
#include "error.h"

class Chetugol :public Figura {
private:
    string name;
    int stor = 4;
protected:
    int a, b, c, d, A, B, C, D;
    Chetugol(string name, int a, int b, int c, int d, int A, int B, int C, int D);
    virtual bool isTry();
    bool proverka();
public:
    Chetugol();
    void print() override;
};