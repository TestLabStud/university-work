#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	int a, b, c;

	cout << "������� ������ �����:" << endl;
	cin >> a;
	cout << "������� ������ �����:" << endl;
	cin >> b;
	c = a + b;
	cout << "���������: " << c << endl;
	return 0;
}