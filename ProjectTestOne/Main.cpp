#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	int a, b, c;

	cout << "¬ведите первое число:" << endl;
	cin >> a;
	cout << "¬ведите второе число:" << endl;
	cin >> b;
	c = a + b;
	cout << "–езультат: " << c << endl;
	return 0;
}