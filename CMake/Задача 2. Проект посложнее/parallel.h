#pragma once
#include <string>
#include "chetugol.h"

using namespace std;

class Parallel :public Chetugol {
public:
    Parallel() :Chetugol("��������������", 20, 30, 20, 30, 30, 40, 30, 40) {};
};