#include "parallel.h"

bool Parallel::isTry() {
	if (this->a != this->c) throw Error("������� 'a' � 'c' �� ����� ���� �����");
	if (this->b != this->d) throw Error("������� 'b' � 'd' �� ����� ���� �����");
	if (this->A != this->C) throw Error("���� 'A' � 'C' �� ����� ���� �����");
	if (this->B != this->D) throw Error("���� 'B' � 'D' �� ����� ���� �����");

	return true;
}