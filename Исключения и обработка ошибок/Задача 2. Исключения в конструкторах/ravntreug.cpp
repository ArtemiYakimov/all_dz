#include "ravntreug.h"

bool Ravntreug::isTry() {
	if (this->a != this->c) throw Error("������� 'a' � 'c' �� ����� ���� �����");
	if(this->A != this->C) throw Error("���� 'A' � 'C' �� ����� ���� �����");

	return true;
}