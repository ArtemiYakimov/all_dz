#include "error.h"

Error::Error(string c) {
	this->b = c;
};

string Error::vozvrat() {
	return "Ошибка создания фигуры. Причина: " + this->b;
};