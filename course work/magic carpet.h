#pragma once
#include "earthair.h"

class Carpet : public Earthair {
private:
	int percent(int distance);
protected:
public:
	Carpet() {
		this->name = "Ковёр-самолет";
		this->speed = 10;
		this->type = 2;
	};

	void time_tranport(int s) override;

};