#include <iostream>
#include <Windows.h>
#include <string>
#include "figura.h"
#include "treugolnik.h"
#include "ravntreug.h"
#include "ravnstortreug.h"
#include "chetugol.h"
#include "prmugol.h"
#include "parallel.h"
#include "romb.h"
#include "prmtreugol.h"
#include "kvadrat.h"


using namespace std;

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
    Prmtreugol prtrug;
    Kvadrat kvad;

    print_info(&tre);
    print_info(&prtrug);
    print_info(&ravn);
    print_info(&storon);
    print_info(&ugol);
    print_info(&prug);
    print_info(&kvad);
    print_info(&paral);
    print_info(&rombik);

    return 0;
}