#pragma once
#include <string>
#include "chetugol.h"

using namespace std;

class Romb :public Chetugol {
public:
    Romb() :Chetugol("Ромб", 30, 30, 30, 30, 30, 40, 30, 40) {};
};