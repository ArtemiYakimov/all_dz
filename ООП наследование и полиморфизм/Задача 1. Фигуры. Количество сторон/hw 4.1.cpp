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
    string print() {
        return this->b + ": " + to_string(this->a);
    };
};

class Treugolnik:public Figura {
public:
    Treugolnik() :Figura(3, "Треугольник") {};
};

class Chetugol :public Figura {
public:
    Chetugol() :Figura(4, "Четрырехугольник") {};
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figura fig;
    Treugolnik tre;
    Chetugol ugol;

    cout << "Количество сторон: " << endl;
    cout << fig.print() << endl;
    cout << tre.print() << endl;
    cout << ugol.print() << endl;

    return 0;
}
