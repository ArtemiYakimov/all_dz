#include "prmtreugol.h"
#include <iostream>

bool Prmtreugol::isTry(){
	if(this->C != 90) throw Error("���� '�' �� ����� 90");

	return true;
};