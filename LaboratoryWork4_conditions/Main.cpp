#include <iostream>

//1-й варiант
int main() {
	setlocale(LC_ALL, "");

	int x;
	std::cout << "Умова: Число х менше 5, але бiльше або дорiвнює 2. \nВведiть x: ";
	std::cin >> x;

	if (x < 5 && x >= 2) { // умова методом iндукцiї
		std::cout << "Умова виконана." << std::endl;
	}

	if (x > 5 || x < 2) { // умова методом дедукцiї
		std::cout << "Умова не виконана." << std::endl;
	}

	return 0;
}