#pragma once
#include "earthair.h"

class Camel : public Earthair {
private:
	int first = 5, last = 8;
protected:
public:
	Camel() {
		this->name = "Верблюд";
		this->speed = 10;
		this->time = 30;
		this->type = 1;
	};

	void time_tranport(int s) override;
};