#pragma once
#include "earthair.h"

class CamelFast : public Earthair {
private:
	int first = 10, last = 60;
	double second = 6.5;
protected:
public:
	CamelFast() {
		this->name = "Верблюд-быстроход";
		this->speed = 40;
		this->time = 10;
		this->type = 1;
	}

	void time_tranport(int s) override;

};