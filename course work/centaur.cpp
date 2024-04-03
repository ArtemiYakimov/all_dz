#include "centaur.h"

void Centaur::time_tranport(int s) {
	int t = s / this->speed;
	int stop = t / this->time;
	if (t % this->time == 0) {
		stop -= 1;
	}
	int x = 0;

	if (stop == 1) {
		x += this->always;
	}
	else {
		x += this->always + (stop - 1) * this->always;
	}

	this->all_time = t + x;
}