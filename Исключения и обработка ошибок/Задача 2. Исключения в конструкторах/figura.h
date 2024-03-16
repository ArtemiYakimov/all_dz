#pragma once
#include <string>

using namespace std;

class Figura {
private:
    int a;
    string b;
protected:
public:
    Figura();
    Figura(int a, string b);
    virtual void print();
};