#include "ravnstortreug.h"

bool Ravnstortreug::isTry() {
	if ((this->a != this->b) || (this->b != this->c)) throw Error("������� 'a', 'b' � 'c' �� ����� ���� �����");
	if ((this->A != this->B) || (this->B != this->C) || (this->C != 60)) throw Error("���� 'A', 'B' � 'C' �� ����� 60");

	return true;
}