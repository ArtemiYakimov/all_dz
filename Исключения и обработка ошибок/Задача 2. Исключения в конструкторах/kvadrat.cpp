#include "kvadrat.h"

bool Kvadrat::isTry() {
	if ((this->a != this->b) || (this->b != this->c) || (this->c != this->d)) throw Error("стороны 'a', 'b', 'c' и 'd' не равны друг другу");
	if ((this->A != this->B) || (this->B != this->C) || (this->C != this->D) || (this->D != 90)) throw Error("углы 'A', 'B', 'C' и 'D' не равны 90");

	return true;
}