#pragma once
#include <string>
#include "treugolnik.h"

using namespace std;

class Ravnstortreug :public Treugolnik {
public:
    Ravnstortreug() :Treugolnik("�������������� �����������", 30, 30, 30, 60, 60, 60) {};
};
