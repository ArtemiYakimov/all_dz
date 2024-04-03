#pragma once
#include "earthair.h"

class Centaur : public Earthair {
private:
	int always = 2;
protected:
public:
	Centaur() {
		this->name = "Кентавр";
		this->speed = 15;
		this->time = 8;
		this->type = 1;
	}

	void time_tranport(int s) override;

};
