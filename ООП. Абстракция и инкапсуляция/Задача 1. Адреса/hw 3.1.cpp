#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

using namespace std;

class Dann {
private: 
    string a, b;
    int c, d;
protected:
public:
    Dann() {
        this->a = "";
        this->b = "";
        this->c = 0;
        this->d = 0;
    };
    void set_city(string name) {
        this->a = name;
    };
    void set_street(string name) {
        this->b = name;
    };
    void set_house(int num) {
        this->c = num;
    };
    void set_flat(int num) {
        this->d = num;
    };
    string print() {
        return this->a + ", " + this->b + ", " + to_string(this->c) + ", " + to_string(this->d);
    };
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream file("C:\\test\\in.txt");
    string chitka;
    bool first_row = true;
    int adres = 0, r = 0;
    int index = 0;
    if (file.is_open()) {
        Dann dann;
        Dann* f = new Dann[0] ;
        while (!file.eof()) {
            file >> chitka;
            if (first_row) {
                adres = stoi(chitka);
                r = adres - 1;
                first_row = false;
                f = new Dann[adres];
            }
            else {
                if (index == 0) {
                    dann = Dann();
                    index++;
                    dann.set_city(chitka);
                }
                else if (index == 1) {
                    index++;
                    dann.set_street(chitka);
                }
                else if (index == 2) {
                    index++;
                    dann.set_house(stoi(chitka));
                }
                else if (index == 3) {
                    index = 0;
                    dann.set_flat(stoi(chitka));
                    f[r] = dann;
                    r--;
                }
            }
        }
        file.close();

        ofstream fout("C:\\test\\out.txt");
        fout << adres << endl;

        for (int i = 0; i < adres; i++) {
            fout << f[i].print() << endl;
        }
        fout.close();
        delete[] f;
    }

    return 0;
}