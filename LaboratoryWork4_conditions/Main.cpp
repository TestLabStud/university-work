#include <iostream>

//1-� ���i���
int main() {
	setlocale(LC_ALL, "");

	int x;
	std::cout << "�����: ����� � ����� 5, ��� �i���� ��� ���i���� 2. \n����i�� x: ";
	std::cin >> x;

	if (x < 5 && x >= 2) { // ����� ������� i�����i�
		std::cout << "����� ��������." << std::endl;
	}

	if (x > 5 || x < 2) { // ����� ������� ������i�
		std::cout << "����� �� ��������." << std::endl;
	}

	return 0;
}