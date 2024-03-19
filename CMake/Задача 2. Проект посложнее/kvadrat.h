#pragma once
#include <string>
#include "chetugol.h"

using namespace std;

class Kvadrat :public Chetugol {
public:
    Kvadrat() :Chetugol(" вадрат", 20, 20, 20, 20, 90, 90, 90, 90) {};
};