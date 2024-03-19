#pragma once
#include <string>
#include "chetugol.h"

using namespace std;

class Prmugol :public Chetugol {
public:
    Prmugol() :Chetugol("Прямоугольник", 10, 20, 10, 20, 90, 90, 90, 90) {};
};