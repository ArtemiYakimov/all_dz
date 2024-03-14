int summ(int a, int b) {
    return a + b;
};

int raznost(int a, int b) {
    return a - b;
};

int multiplic(int a, int b) {
    return a * b;
};

double delenie(int a, int b) {
    return static_cast<double> (a) / static_cast<double> (b);
};

int step(int a, int b) {
    int z = 1;
    for (int i = 0; i < b; i++) {
        z *= a;
    }
    return z;
};