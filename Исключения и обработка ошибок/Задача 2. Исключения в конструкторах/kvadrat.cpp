#include "kvadrat.h"

bool Kvadrat::isTry() {
	if ((this->a != this->b) || (this->b != this->c) || (this->c != this->d)) throw Error("������� 'a', 'b', 'c' � 'd' �� ����� ���� �����");
	if ((this->A != this->B) || (this->B != this->C) || (this->C != this->D) || (this->D != 90)) throw Error("���� 'A', 'B', 'C' � 'D' �� ����� 90");

	return true;
}