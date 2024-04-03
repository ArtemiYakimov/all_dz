#include "earthair.h"

string Earthair::get_name() {
	return this->name;
};

int Earthair::get_type() {
	return this->type;
};

double Earthair::get_all_time() {
	return this->all_time;
};

void Earthair::time_tranport(int s) {
	this->all_time = 0;
};
