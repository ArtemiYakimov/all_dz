#pragma once
#include <string>
#include "treugolnik.h"

using namespace std;

class Prmtreugol :public Treugolnik {
public:
    Prmtreugol() :Treugolnik("������������� �����������", 10, 20, 30, 50, 60, 90) {};
};