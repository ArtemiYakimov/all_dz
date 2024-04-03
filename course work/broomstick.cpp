#include "broomstick.h"

int Stick::percent(int distance) {
	return distance / 1000;
};

void Stick::time_tranport(int s) {
	int couf = percent(s);
	double x = (s * couf) / 100;
	double y = s - x;
	double t = y / this->speed;
	this->all_time = t;
};