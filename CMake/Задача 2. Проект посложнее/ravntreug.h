#pragma once
#include <string>
#include "treugolnik.h"

using namespace std;

class Ravntreug :public Treugolnik {
public:
    Ravntreug() :Treugolnik("Равнобедренный треугольник", 10, 20, 10, 50, 60, 50) {};
};