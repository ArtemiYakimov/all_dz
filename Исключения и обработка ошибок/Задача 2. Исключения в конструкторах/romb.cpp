#include "romb.h"

bool Romb::isTry() {
	if ((this->a != this->b) || (this->b != this->c) || (this->c != this->d)) throw Error("������� 'a', 'b', 'c' � 'd' �� ����� ���� �����");
	if (this->A != this->C) throw Error("���� 'A' � 'C' �� ����� ���� �����");
	if (this->B != this->D) throw Error("���� 'B' � 'D' �� ����� ���� �����");

	return true;
}