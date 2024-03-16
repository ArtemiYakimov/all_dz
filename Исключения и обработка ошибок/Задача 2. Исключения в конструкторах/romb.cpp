#include "romb.h"

bool Romb::isTry() {
	if ((this->a != this->b) || (this->b != this->c) || (this->c != this->d)) throw Error("стороны 'a', 'b', 'c' и 'd' не равны друг другу");
	if (this->A != this->C) throw Error("углы 'A' и 'C' не равны друг другу");
	if (this->B != this->D) throw Error("углы 'B' и 'D' не равны друг другу");

	return true;
}