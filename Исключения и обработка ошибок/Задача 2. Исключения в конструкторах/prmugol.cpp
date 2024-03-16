#include "prmugol.h"

bool Prmugol::isTry() {
	if (this->a != this->c) throw Error("стороны 'a' и 'c' не равны друг другу");
	if (this->b != this->d) throw Error("стороны 'b' и 'd' не равны друг другу");
	if ((this->A != this->B) || (this->B != this->C) || (this->C != this->D) || (this->D != 90)) throw Error("углы 'A', 'B', 'C' и 'D' не равны 90");

	return true;
}