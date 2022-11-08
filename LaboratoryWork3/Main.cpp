#include"MainHeader.h"

void startMenu() {
	cout << "����i�� ����� ����:\n"
		<< "1. ����������� i�������i��� ������.\n"
		<< "2. ������ ��i�� �� ��������i� �����i.\n"
		<< "3. ��������� ������." << endl;

	cin >> dec >> selectedMenuItem;

	switch (selectedMenuItem) {
	case 1:
		infoModelStandart();
		infoModelCout();
		break;


	case 2:
		accessChecker();
		infoModelEditor();
		break;


	case 3:
	default:
		exit(0);
	}
}



void infoModelStandart() {

	triangleName = "ABC";
	triangleColor = "yellow";

	angle1 = 45, angle2 = 60, angle3 = 75;
		bool isItRightTriangle(angle1 == rightAngle
							|| angle2 == rightAngle
							|| angle3 == rightAngle);

	// ����� �i ���������� ����������, ���� � �i
	tradeCode = "QR045a5";

	 productAmount = 641;
	 cost = 46.75;
}



void infoModelCout() {
	wcout << L"\nI�������i��� ������ ����������:" << endl;
	cout << "����� ����������: ";
	for (int i = 0; i < 3; i++) {
		cout << triangleName[i];
	}
	cout << "\n���i� ����������: " << triangleColor << endl;

	cout << "������ ��� ����������: " << angle1 << endl;
	cout << "������ ��� ����������: " << angle2 << endl;
	cout << "����i� ��� ����������: " << angle3 << endl;

	bool isItRightTriangle(angle1 == rightAngle
		|| angle2 == rightAngle
		|| angle3 == rightAngle);
	cout << "�� ��������� �����������: " << ((isItRightTriangle) ? "���" : "�i") << endl;

	cout << "�������� ��� � ���i �����: ";
	for (int i = 0; i < 7; i++) {
		cout << tradeCode[i];
	}
	cout << "\n�i���i��� ������: " << productAmount << endl;
	cout << "�i�� ������: " << cost << endl;
}



void accessChecker() {
	char login[MAX_LOGIN_LENGTH];
	wcout << L"\n��� �������� ������ �� �����������, �������������."
		<< L"\n����i�� ���i�: " << endl;

	for (int counter = 1; counter < 5; counter++) {

		wcin.ignore();
		cin >> login;

		int loginComplete(strcmp(login, trueLogin));
		if (loginComplete == 0) break;

		else if (counter == 4) {
			cout << "�� ������� ������ ���i� ����������.\n" << endl;
			exit(0);
		}
		else cout << "������������ ���i� (" << counter << " ������), ��������� �� ���." << endl;
	}


	char password[MAX_PASSWORD_LENGTH];
	wcout << L"\n�i���, " << login << L", ������ �i������i��, �� �� ��." << endl;

	for (int counter = 1; counter < 5; counter++) {

		wcin.ignore();
		cin >> password;

		int passwordComplete(strcmp(password, truePassword));
		if (passwordComplete == 0) break;

		else if (counter == 4) {
			cout << "�� ������� ������ ���i� ����������.\n" << endl;
			exit(0);
		}
		else cout << "������������ ������ (" << counter << " ������), ��������� �� ���." << endl;
	}
	cout << "\n�� ���i��� ��������������.\n" << endl;
}



void infoModelEditor() {
	infoModelStandart();
	cout << "����i�� ��������, ���� ������ ��i����:\n"
		<< "1. ��i���� ���.\n"
		<< "2. ����� ����������.\n"
		<< "3. ���i� ����������.\n"
		<< "4. ����i� ���i� ����������.\n"
		<< "5. �������� ��� � ���i �����.\n"
		<< "6. �i���i��� ������.\n"
		<< "7. �i�� ������.\n"
		<< "8. �������� �� �������� ��� ��i�." << endl;

	bool changeAll(false);
	cin >> dec >> selectedMenuItem;


	switch (selectedMenuItem) {
	case 1:
		changeAll = true;


	case 2:
		cout << "\n����i�� ���� ����� ���������� (������ - ��� �����i ��������i �i����): " << endl;
		wcin.ignore();
		getline(cin, triangleName);

		cout << "����� ���i��� ��i���� �� ";
		for (int i = 0; i < 3; i++) {
			cout << triangleName[i];
		}
		cout << ".\n" << endl;

		if (changeAll == false) break;


	case 3:
		cout << "����i�� ����� ���i� ����������: " << endl;
		getline(cin, triangleColor);

		cout << "���i� ���i��� ��i���� �� " << triangleColor << ".\n" << endl;

		if (changeAll == false) break;


	case 4:
		for (int counter = 0; counter < 4; counter++) {

			cout << "����i�� ������ ���: " << endl;
			cin >> angle1;
			cout << "����i�� ������ ���: " << endl;
			cin >> angle2;
			cout << "����i�� ����i� ���: " << endl;
			cin >> angle3;

			int summ = angle1 + angle2 + angle3;
			bool isItRightTriangle(angle1 == rightAngle
				|| angle2 == rightAngle
				|| angle3 == rightAngle);
			if (summ == 180) {
				cout << "�������� ���i� ���i��� ��i���� �� " << angle1 << ", "
					<< angle2 << " �� " << angle3 << ", ������ ��������� "
					<< ((isItRightTriangle) ? "�����������.\n" : "�� �����������.\n") << endl;
				break;
			}

			else if (counter == 3) {
				cout << "�� ������� ������ ���i� ����� ����������i ��������.\n" << endl;
				exit(0);
			}

			else cout << "���� ������i �����������, ��������� �� ���.\n" << endl;
		}
		if (changeAll == false) break;

	case 5:
		cout << "����i�� ����� �������� ��� (������ - 7 ������i�): " << endl;
		wcin.ignore();
		getline(cin, tradeCode);

		cout << "�������� ��� ���i��� ��i���� �� ";
		for (int i = 0; i < 7; i++) {
			cout << tradeCode[i];
		}
		cout << ".\n" << endl;

		if (changeAll == false) break;


	case 6:
		cout << "����i�� ���� �i���i��� ������: " << endl;
		cin >> productAmount;
		cout << "�i���i��� ���i��� ��i���� �� " << productAmount << ".\n" << endl;

		if (changeAll == false) break;


	case 7:
		cout << "����i�� ���� �i�� ������: " << endl;
		cin >> cost;
		cout << "�i�� ���i��� ��i���� �� " << cost << ".\n" << endl;

		break;


	case 8:
		cout << "�� ������� �i���� �� ��i������.\n" << endl;

		break;


	default:
		exit(0);
	}
	infoModelSaveMenu();
}



void infoModelSaveMenu() {

	cout << "����i�� ���i��� �i����i�i:\n"
		<< "1. ����������� �������� i�������i��� ������.\n"
		<< "2. ����������� �������� i�������i��� ������ � ������� .txt ����.\n"
		<< "3. �i���� �� ����i���� �� ��������� ������ ��������." << endl;

	cin >> dec >> selectedMenuItem;
	switch (selectedMenuItem) {
	case 1:
		cout << "�������� i�������i���� ������:\n" << endl;
		infoModelCout();
		break;


	case 2:
		infoModelInFile();
		break;

	case 3:
	default:
		exit(0);
	}
}



void infoModelInFile() {
	ofstream fileWriter;
	fileWriter.open("info_model.txt", ios::out);


	fileWriter << "I�������i��� ������ ����������:" << endl;
	fileWriter << "����� ����������: ";
	for (int i = 0; i < 3; i++) {
		fileWriter << triangleName[i];
	}
	fileWriter << "\n���i� ����������: " << triangleColor << endl;

	fileWriter << "������ ��� ����������: " << angle1 << endl;
	fileWriter << "������ ��� ����������: " << angle2 << endl;
	fileWriter << "����i� ��� ����������: " << angle3 << endl;

	bool isItRightTriangle(angle1 == rightAngle
		|| angle2 == rightAngle
		|| angle3 == rightAngle);
	fileWriter << "�� ��������� �����������: " << ((isItRightTriangle) ? "���" : "�i") << endl;

	fileWriter << "�������� ��� � ���i �����: ";
	for (int i = 0; i < 7; i++) {
		fileWriter << tradeCode[i];
	}
	fileWriter << "\n�i���i��� ������: " << productAmount << endl;
	fileWriter << "�i�� ������: " << cost << endl;


	fileWriter.close();


	cout << "���i �����������..." << endl;
	Sleep(2000);
	cout << "..." << endl;
	Sleep(2000);
	cout << "\nI�������i��� ������ ���i��� ��������� � ���� \"info_model.txt\"" << endl;
}


int main(){
	setlocale(LC_ALL, "");

	startMenu();

	return 0;
}