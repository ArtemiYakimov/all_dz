#include <iostream>
#include <Windows.h>
using namespace std;

class smart_array {
private:
	int* arr;
	int position = 0;
	int size = 0;
public:
	smart_array(int size) {
		this->size = size;
		this->arr = new int[size]();
	};
	~smart_array() {
		delete[] this->arr;
		this->position = 0;
		this->size = 0;
	};
	int get_size() {
		return this->size;
	};
	int get_position() {
		return this->position;
	};
	smart_array& operator = (smart_array& other_arr) {

		this->size = other_arr.get_size();
		this->position = other_arr.get_position();

		int* new_arr = new int[this->size];
		for (int i = 0; i < this->size; i++) {
			new_arr[i] = other_arr.get_element(i);
		}
		delete[] this->arr;
		this->arr = new_arr;

		return *this;
	};
	void add_element(int number) {
		if (this->position == this->size) {
			int* new_arr = new int[this->size + (this->size / 2)];
			for (int i = 0; i < this->size; i++) {
				new_arr[i] = this->arr[i];
			}
			delete[] this->arr;
			this->arr = new_arr;
			this->size += 1;
		}
		this->arr[this->position] = number;
		this->position += 1;
	};
	int get_element(int index) {
		if (index < this->position) {
			return this->arr[index];
		}

		throw length_error("Попытка обратиться к несуществующему элементу в массиве ...");
	};
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;

		cout << arr.get_element(0) << endl;
		cout << arr.get_element(1) << endl;
		cout << arr.get_element(2) << endl;
	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
	}

	return 0;
}