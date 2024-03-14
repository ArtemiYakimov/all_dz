#pragma once
#include <string>
#include "figura.h"

using namespace std;

class Treugolnik :public Figura {
private:
    string name;
    int a, b, c, A, B, C;
protected:
    Treugolnik(string name, int a, int b, int c, int A, int B, int C);
public:
    Treugolnik();
    string print() override;
};
