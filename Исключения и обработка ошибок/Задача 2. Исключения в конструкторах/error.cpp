#include "error.h"

Error::Error(string c) {
	this->b = c;
};

string Error::vozvrat() {
	return "������ �������� ������. �������: " + this->b;
};