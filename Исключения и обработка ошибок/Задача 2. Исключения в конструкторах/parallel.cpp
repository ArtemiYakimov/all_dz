#include "parallel.h"

bool Parallel::isTry() {
	if (this->a != this->c) throw Error("стороны 'a' и 'c' не равны друг другу");
	if (this->b != this->d) throw Error("стороны 'b' и 'd' не равны друг другу");
	if (this->A != this->C) throw Error("углы 'A' и 'C' не равны друг другу");
	if (this->B != this->D) throw Error("углы 'B' и 'D' не равны друг другу");

	return true;
}