#include "ravntreug.h"

bool Ravntreug::isTry() {
	if (this->a != this->c) throw Error("стороны 'a' и 'c' не равны друг другу");
	if(this->A != this->C) throw Error("углы 'A' и 'C' не равны друг другу");

	return true;
}