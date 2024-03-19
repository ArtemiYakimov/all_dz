#pragma once
#include <string>
#include "figura.h"

using namespace std;

class Chetugol :public Figura {
private:
    string name;
    int a, b, c, d, A, B, C, D;
protected:
    Chetugol(string name, int a, int b, int c, int d, int A, int B, int C, int D);
public:
    Chetugol();
    string print() override;
};