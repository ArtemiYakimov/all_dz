#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class Figura {
private:
    int a;
    string name;
protected:
    bool proverka() {
        return this->a == 0;
    };
public:
    Figura() {
        this->a = 0;
        this->name = "Фигура";
    };

    virtual string print() {
        return this->name + ":\n" + (this->proverka() ? "Правильная" : "Неправильная") + "\nКоличество сторон: " + to_string(this->a);
    };
};

class Treugolnik :public Figura {
private:
    string name;
    int stor = 3;
protected:
    int a, b, c, A, B, C;

    Treugolnik(string name, int a, int b, int c, int A, int B, int C) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
        this->name = name;
    };

    virtual bool isTry() {
        return true;
    };

    bool proverka() {
        return (this->stor == 3 && this->A + this->B + this->C == 180) && this->isTry();
    };
public:
    Treugolnik() :Figura() {
        this->a = 10;
        this->b = 20;
        this->c = 30;
        this->A = 50;
        this->B = 60;
        this->C = 70;
        this->name = "Треугольник";
    };

    string print() override {
        return this->name + ":\n"
            + (this->proverka() ? "Правильная" : "Неправильная")
            + "\nКоличество сторон: " + to_string(this->stor)
            + "\nCтороны: a=" + to_string(this->a) + " b=" + to_string(this->b) + " c=" + to_string(this->c)
            + "\nУглы: A=" + to_string(this->A) + " B=" + to_string(this->B) + " C=" + to_string(this->C);
    };
};

class Prymegoltreug :public Treugolnik {
protected:
    bool isTry() override {
        return this->C = 90;
    };
public:
    Prymegoltreug() : Prymegoltreug(10, 20, 30, 50, 60, 90) {};
    Prymegoltreug(int a, int b, int c, int A, int B, int C) : Treugolnik("Прямоугольный треугольник", a, b, c, A, B, C) {};
};

class Ravntreug :public Treugolnik {
protected:
    bool isTry() override {
        return (this->a == this->c && this->A == this->C);
    };
public:
    Ravntreug() :Treugolnik("Равнобедренный треугольник", 10, 20, 10, 50, 60, 50) {};
};

class Ravnstortreug :public Treugolnik {
protected:
    bool isTry() override {
        return (this->a == this->b && this->b == this->c && this->A == this->B && this->B == this->C && this->C == 60);
    };
public:
    Ravnstortreug() : Treugolnik("Равносторонний треугольник", 30, 30, 30, 60, 60, 60) {};
};

class Chetugol :public Figura {
private:
    string name;
    int stor = 4;
protected:
    int a, b, c, d, A, B, C, D;
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
    virtual bool isTry() {
        return true;
    }
    bool proverka() {
        return (this->stor == 4 && this->A + this->B + this->C + this->D == 360) && this->isTry();
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
        return this->name + ":\n"
            + (this->proverka() ? "Правильная" : "Непрвильная")
            + "\nКоличество сторон: " + to_string(this->stor)
            + "\nCтороны: a=" + to_string(this->a) + " b=" + to_string(this->b) + " c=" + to_string(this->c) + " d=" + to_string(this->d)
            + "\nУглы: A=" + to_string(this->A) + " B=" + to_string(this->B) + " C=" + to_string(this->C) + " D=" + to_string(this->D);
    };
};

class Kvadrat :public Chetugol {
protected:
    bool isTry() override {
        return (this->a == this->b && this->b == this->c && this->c == this->d &&
            this->A == this->B && this->B == this->C && this->C == this->D && this->D == 90);
    };
public:
    Kvadrat() :Chetugol("Квадрат", 20, 20, 20, 20, 90, 90, 90, 90) {};
};

class Prmugol :public Chetugol {
protected:
    bool isTry() override {
        return (this->a == this->c && this->b == this->d &&
            this->A == this->B && this->B == this->C && this->C == this->D && this->D == 90);
    };
public:
    Prmugol() :Chetugol("Прямоугольник", 10, 20, 10, 20, 90, 90, 90, 90) {};
};

class Parallel :public Chetugol {
protected:
    bool isTry() override {
        return (this->a == this->c && this->b == this->d &&
            this->A == this->C && this->B == this->D);
    };
public:
    Parallel() :Chetugol("Параллелограмм", 20, 30, 20, 30, 30, 40, 30, 40) {};
};

class Romb :public Chetugol {
protected:
    bool isTry() override {
        return (this->a == this->b && this->b == this->c && this->c == this->d &&
            this->A == this->C && this->B == this->D);
    };
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

    Figura figra;
    Treugolnik tre;
    Prymegoltreug prtre;
    Prymegoltreug prtreq(10, 20, 30, 50, 40, 90);
    Ravntreug ravn;
    Ravnstortreug storon;
    Chetugol ugol;
    Kvadrat kvad;
    Prmugol prug;
    Parallel paral;
    Romb rombik;


    print_info(&figra);
    print_info(&tre);
    print_info(&prtre);
    print_info(&prtreq);
    print_info(&ravn);
    print_info(&storon);
    print_info(&ugol);
    print_info(&prug);
    print_info(&kvad);
    print_info(&paral);
    print_info(&rombik);

    return 0;
}