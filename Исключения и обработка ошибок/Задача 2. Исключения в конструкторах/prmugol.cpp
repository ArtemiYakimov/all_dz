#include "prmugol.h"

bool Prmugol::isTry() {
	if (this->a != this->c) throw Error("������� 'a' � 'c' �� ����� ���� �����");
	if (this->b != this->d) throw Error("������� 'b' � 'd' �� ����� ���� �����");
	if ((this->A != this->B) || (this->B != this->C) || (this->C != this->D) || (this->D != 90)) throw Error("���� 'A', 'B', 'C' � 'D' �� ����� 90");

	return true;
}