#pragma once
#include "earthair.h"

class Eagle : public Earthair {
private:
	int percent(int distance);
protected:
public:
	Eagle() {
		this->name = "Îð¸ë";
		this->speed = 8;
		this->type = 2;
	};

	void time_tranport(int s) override;

};