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
#include "error.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        Prmtreugol prtreq(3, 4, 5, 30, 60, 90);             // Good
        //Prmtreugol prtreq2(3, 4, 5, 40, 60, 80);              // Bad
        Ravntreug ravn(7, 6, 7, 70, 40, 70);                // Good
        //Ravntreug ravn2(5, 6, 7, 30, 60, 90);                 // Bad
        Ravnstortreug storon;                               // Good
        //Ravnstortreug storon2(7, 7, 7, 70, 40, 70);           // Bad
        Prmugol prug;                                       // Good
        //Prmugol prug2(2, 5, 2, 6, 70, 40, 70, 40);            // Bad
        Kvadrat kvad;                                       // Good
        //Kvadrat kvad2(12, 12, 12, 11, 90, 90, 90, 90);        // Bad
        Parallel paral(24, 36, 24, 36, 70, 110, 70, 110);   // Good
        //Parallel paral2;                                      // Bad
        Romb rombik(53, 53, 53, 53, 30, 150, 30, 150);      // Good
        Romb rombik2;                                           // Bad
    }
    catch (Error& error) {
        cout << error.vozvrat() << endl;
        cout << endl;
    }

    return 0;
}