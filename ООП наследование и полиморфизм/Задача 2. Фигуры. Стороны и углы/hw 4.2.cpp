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
public:
    Treugolnik(string name, int a, int b, int c, int A, int B, int C) :Figura() {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
        this->name = name;
    };

    Treugolnik() :Treugolnik("Треугольник", 10, 20, 30, 50, 60, 90) {};

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
public:
    Chetugol(string name, int a, int b, int c, int d, int A, int B, int C, int D) :Figura() {
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
        Chetugol() :Chetugol("Четырехугольник", 10, 20, 30, 40, 50, 60, 70, 80) {};

    string print() override {
        return this->name + ":\nCтороны: a = " + to_string(this->a) + " b = " + to_string(this->b) + " c = " + to_string(this->c) + " d = " + to_string(this->d) +
            ":\nУглы: A = " + to_string(this->A) + " B = " + to_string(this->B) + " C = " + to_string(this->C) + " D = " + to_string(this->D);
    };
};

class Prymegoltreug :public Treugolnik {
public:
    Prymegoltreug(int a, int b, int c, int A, int B) :Treugolnik("Прямоугольный треугольник", a, b, c, A, B, 90) {};
    Prymegoltreug() :Prymegoltreug(10, 20, 30, 50, 60) {};
};

class Ravntreug :public Treugolnik {
public:
    Ravntreug(int a, int b, int A, int B) :Treugolnik( "Равнобедренный треугольник", a, b, a, A, B, A) {};
    Ravntreug() :Ravntreug(10, 20, 50, 60) {};
};

class Ravnstortreug :public Treugolnik {
public:
    Ravnstortreug(int a) :Treugolnik("Равносторонний треугольник", a, a, a, 60, 60, 60) {};
    Ravnstortreug() :Ravnstortreug(30){};
};

class Prmugol :public Chetugol {
public:
    Prmugol(int a, int b) :Chetugol("Прямоугольник", a, a, b, b, 90, 90, 90, 90) {};
    Prmugol() :Prmugol(10, 20) {};
};

class Kvadrat :public Chetugol {
public:
    Kvadrat(int a) :Chetugol("Квадрат", a, a, a, a, 90, 90, 90, 90) {};
    Kvadrat() :Kvadrat(20) {};
};

class Parallel :public Chetugol {
public:
    Parallel(int a, int b, int A, int B) :Chetugol("Параллелограмм", a, b, a, b, A, B, A, B) {};
    Parallel() :Parallel(20, 30, 30, 40) {};
};

class Romb :public Chetugol {
public:
    Romb(int a, int A, int B) :Chetugol("Ромб", a, a, a, a, A, B, A, B) {};
    Romb() :Romb(30, 30, 40) {};
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
