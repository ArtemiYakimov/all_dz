#include "prmtreugol.h"
#include <iostream>

bool Prmtreugol::isTry(){
	if(this->C != 90) throw Error("угол 'С' не равен 90");

	return true;
};