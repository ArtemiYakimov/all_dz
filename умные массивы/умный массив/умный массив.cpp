#include <Windows.h>
#include <iostream>

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
		arr.add_element(14);
		arr.add_element(15);

		arr.add_element(21);
		arr.add_element(10);
		arr.add_element(132);

		cout << arr.get_element(7) << endl;
		cout << arr.get_element(17) << endl;
	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
	}

	return 0;
}