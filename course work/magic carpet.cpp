#include "magic carpet.h"

int Carpet::percent(int distance) {
	if (distance < 1000) {
		return 0;
	}
	else if (distance >= 1000 && distance < 5000) {
		return 3;
	}
	else if (distance >= 5000 && distance < 10000) {
		return 10;
	}
	else {
		return 5;
	}
};

void Carpet::time_tranport(int s) {
	int couf = percent(s);
	double x = (s * couf) / 100;
	double y = s - x;
	double t = y / this->speed;
	this->all_time = t;
};