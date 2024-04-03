#include "race.h"
#include <string>

string Race::get_all_name() {
	string t = "";
	for (int i = 0; i < this->size; i++) {
		t += (*this->arr[i]).get_name() + (i < this->size - 1 ? ", " : "");
	}
	return t;
};

string Race::add(Earthair* other) {
	if ((*other).get_type() == this->type || this->type == 3) {
		bool flag = false;

		for (int i = 0; i < this->size; i++) {
			if ((*this->arr[i]).get_name() == (*other).get_name()) {
				flag = true;
				break;
			}
		}

		if (flag) {
			return (*other).get_name() + " уже зарегистрирован!";
		}
		else {
			this->arr[this->size] = other;
			this->size += 1;
			return (*other).get_name() + " успешно зарегистрирован!";
		}
	}
	else {
		return "Попытка зарагистрировать неправильный тип транспортного средства!";
	}
};

void Race::start() {
	for (int i = 0; i < this->size; i++) {
		(*this->arr[i]).time_tranport(this->length);
	}

	Earthair* other;
	int y;
	for (int i = 0; i < this->size; i++) {
		y = i;
		other = this->arr[i];
		for (int j = i; j < this->size; j++) {
			if ((*this->arr[j]).get_all_time() < (*other).get_all_time()) {
				y = j;
				other = this->arr[j];
			}
		}
		this->arr[y] = this->arr[i];
		this->arr[i] = other;
	}
};

void Race::finish() {
	this->type = 0;
	this->length = 0;
	this->size = 0;
};

int Race::get_count() {
	return this->size;
};

Earthair* Race::get_transport() {
	Earthair* earthairs = new Earthair[this->size];
	for (int i = 0; i < this->size; i++) {
		earthairs[i] = *this->arr[i];
	}
	return earthairs;
};