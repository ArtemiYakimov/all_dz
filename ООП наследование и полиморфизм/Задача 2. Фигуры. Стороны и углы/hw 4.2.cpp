#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class Figura {
private:
    int a;
    string b;
protected:
public:
    Figura() {
        this->a = 0;
        this->b = "Фигура";
    };
    Figura(int a, string b) {
        this->a = a;
        this->b = b;
    };
    virtual string print() {
        return this->b + ": " + to_string(this->a);
    };
};

class Treugolnik :public Figura {
private:
    string name;
    int a, b, c, A, B, C;
protected:
    Treugolnik(string name, int a, int b, int c, int A, int B, int C) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
        this->name = name;
    };
public:
    Treugolnik() :Figura() {
        this->a = 10;
        this->b = 20;
        this->c = 30;
        this->A = 50;
        this->B = 60;
        this->C = 90;
        this->name = "Треугольник";
    };
    string print() override {
        return this->name + ":\nCтороны: a = " + to_string(this->a) + " b = " + to_string(this->b) + " c = " + to_string(this->c) +
            ":\nУглы: A = " + to_string(this->A) + " B = " + to_string(this->B) + " C = " + to_string(this->C);
    };
};

class Chetugol :public Figura {
private:
    string name;
    int a, b, c, d, A, B, C, D;
protected:
    Chetugol(string name, int a, int b, int c, int d, int A, int B, int C, int D) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
        this->name = name;
    };
public:
    Chetugol() :Figura() {
        this->a = 10;
        this->b = 20;
        this->c = 30;
        this->d = 40;
        this->A = 50;
        this->B = 60;
        this->C = 70;
        this->D = 80;
        this->name = "Четырехугольник";
    };
    string print() override {
        return this->name + ":\nCтороны: a = " + to_string(this->a) + " b = " + to_string(this->b) + " c = " + to_string(this->c) + " d = " + to_string(this->d) +
            ":\nУглы: A = " + to_string(this->A) + " B = " + to_string(this->B) + " C = " + to_string(this->C) + " D = " + to_string(this->D);
    };
};

class Prymegoltreug :public Treugolnik {
public:
    Prymegoltreug() :Treugolnik("Прямоугольный треугольник", 10, 20, 30, 50, 60, 90) {};
};

class Ravntreug :public Treugolnik {
public:
    Ravntreug() :Treugolnik( "Равнобедренный треугольник", 10, 20, 10, 50, 60, 50) {};
};

class Ravnstortreug :public Treugolnik {
public:
    Ravnstortreug() :Treugolnik("Равносторонний треугольник", 30, 30, 30, 60, 60, 60) {};
};

class Prmugol :public Chetugol {
public:
    Prmugol() :Chetugol("Прямоугольник", 10, 20, 10, 20, 90, 90, 90, 90) {};
};

class Kvadrat :public Chetugol {
public:
    Kvadrat() :Chetugol("Квадрат", 20, 20, 20, 20, 90, 90, 90, 90) {};
};

class Parallel :public Chetugol {
public:
    Parallel() :Chetugol("Параллелограмм", 20, 30, 20, 30, 30, 40, 30, 40) {};
};

class Romb :public Chetugol {
public:
    Romb() :Chetugol("Ромб", 30, 30, 30, 30, 30, 40, 30, 40) {};
};

void print_info(Figura* f) {
    cout << f->print() << endl;
    cout << endl;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Treugolnik tre;
    Chetugol ugol;
    Ravntreug ravn;
    Ravnstortreug storon;
    Prmugol prug;
    Parallel paral;
    Romb rombik;
    Prymegoltreug treugprm;
    Kvadrat kvad;

    print_info(&tre);
    print_info(&ravn);
    print_info(&storon);
    print_info(&ugol);
    print_info(&prug);
    print_info(&paral);
    print_info(&rombik);
    print_info(&treugprm);
    print_info(&kvad);
    
    return 0;
}
