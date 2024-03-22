#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class Figura {
private:
    int a;
    string name;
protected:
public:
    bool proverka() {
        return this->a == 0;
    };
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
    //bool t = true;

public:
    virtual bool proverka () {
        return this->stor == 3 && this->A + this->B + this->C == 180;
    };
    Treugolnik(string name, int a, int b, int c, int A, int B, int C) :Figura() {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
        this->name = name;
        //this->proverka();
    };

    Treugolnik() :Treugolnik("Треугольник", 10, 20, 30, 50, 60, 70) {};

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
    bool proverka() override {
        if (Treugolnik::proverka()) {
            return this->C = 90; 
        }
        return false;
    }
public:
    Prymegoltreug(int a, int b, int c, int A, int B) :Treugolnik("Прямоугольный треугольник", a, b, c, A, B, 90) {};
    Prymegoltreug() :Prymegoltreug(10, 20, 30, 50, 60) {};
};

class Ravntreug :public Treugolnik {
protected:
    bool proverka() override {
        if (Treugolnik::proverka()) {
            return (this->a == this->c && this->A == this->C);
        }
        return false;
    };
public:
    Ravntreug(int a, int b, int A, int B) :Treugolnik("Равнобедренный треугольник", a, b, a, A, B, A) {};
    Ravntreug() :Ravntreug(10, 20, 50, 60) {};
};

class Ravnstortreug :public Treugolnik {
protected:
    bool proverka() override {
        if (Treugolnik::proverka()) {
             return (this->a == this->b && this->b == this->c && this->A == this->B && this->B == this->C && this->C == 60);
        }
        return false;
    };
public:
    Ravnstortreug(int a) :Treugolnik("Равносторонний треугольник", a, a, a, 60, 60, 60) {};
    Ravnstortreug() :Ravnstortreug(30) {};
};

class Chetugol :public Figura {
private:
    string name;
    int stor = 4;
protected:
    int a, b, c, d, A, B, C, D;
    
public:
    virtual bool proverka() {
        return this->stor == 4 && this->A + this->B + this->C + this->D == 360;
    };
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
        return this->name + ":\n"
            + (this->proverka() ? "Правильная" : "Непрвильная")
            + "\nКоличество сторон: " + to_string(this->stor)
            + "\nCтороны: a=" + to_string(this->a) + " b=" + to_string(this->b) + " c=" + to_string(this->c) + " d=" + to_string(this->d)
            + "\nУглы: A=" + to_string(this->A) + " B=" + to_string(this->B) + " C=" + to_string(this->C) + " D=" + to_string(this->D);
    };
};

class Kvadrat :public Chetugol {
protected:
    bool proverka() override {
        if (Chetugol::proverka()) {
            return (this->a == this->b && this->b == this->c && this->c == this->d &&
                this->A == this->B && this->B == this->C && this->C == this->D && this->D == 90);
        }
        return false;
    };
public:
    Kvadrat(int a) :Chetugol("Квадрат", a, a, a, a, 90, 90, 90, 90) {};
    Kvadrat() :Kvadrat(20) {};
};

class Prmugol :public Chetugol {
protected:
    bool proverka() override {
        if (Chetugol::proverka()) {
            return (this->a == this->c && this->b == this->d &&
                this->A == this->B && this->B == this->C && this->C == this->D && this->D == 90);
        }
        return false;
    };
public:
    Prmugol(int a, int b) :Chetugol("Прямоугольник", a, b, a, b, 90, 90, 90, 90) {};
    Prmugol() :Prmugol(10, 20) {};
};

class Parallel :public Chetugol {
protected:
    bool proverka() override {
        if (Chetugol::proverka()) {
            return (this->a == this->c && this->b == this->d &&
                this->A == this->C && this->B == this->D);
        }
        return false;
    };
public:
    Parallel(int a, int b, int A, int B) :Chetugol("Параллелограмм", a, b, a, b, A, B, A, B) {};
    Parallel() :Parallel(20, 30, 30, 40) {};
};

class Romb :public Chetugol {
protected:
    bool proverka() override {
        if (Chetugol::proverka()) {
            return (this->a == this->b && this->b == this->c && this->c == this->d &&
                this->A == this->C && this->B == this->D);
        }
        return false;
    };
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

    Figura figra;
    Treugolnik tre;
    Prymegoltreug prtre;
    Prymegoltreug prtreq(10, 20, 30, 50, 40);
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