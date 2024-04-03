#pragma once
#include "earthair.h"

class Boots: public Earthair {
private:
	int first = 10, last = 5;
protected:
public:
	//Boots():Earth("Ботинки - вездеходы", 6, 60) {
	Boots() {
		this->name = "Ботинки-вездеходы";
		this->speed = 6;
		this->time = 60;
		this->type = 1;
	};

	void time_tranport(int s) override;
	
};