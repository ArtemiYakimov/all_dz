#pragma once
#include <string>
using namespace std;

class Earthair {
private:
protected:
	string name;
	int type, speed;
	double all_time;
	int time;
public:
	string get_name();
	int get_type();
	double get_all_time();
	virtual void time_tranport(int s);
};
