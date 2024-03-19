#pragma once
#include <string>
#include "treugolnik.h"

using namespace std;

class Ravnstortreug :public Treugolnik {
public:
    Ravnstortreug() :Treugolnik("Равносторонний треугольник", 30, 30, 30, 60, 60, 60) {};
};
