#include "eagle.h"

int Eagle::percent(int distance) {
	return 6;
};

void Eagle::time_tranport(int s) {
	int couf = percent(s);
	double x = (s * couf) / 100;
	double y = s - x;
	double t = y / this->speed;
	this->all_time = t;
};