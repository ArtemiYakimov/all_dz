#include "ravnstortreug.h"

bool Ravnstortreug::isTry() {
	if ((this->a != this->b) || (this->b != this->c)) throw Error("стороны 'a', 'b' и 'c' не равны друг другу");
	if ((this->A != this->B) || (this->B != this->C) || (this->C != 60)) throw Error("углы 'A', 'B' и 'C' не равны 60");

	return true;
}