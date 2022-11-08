#include"MainHeader.h"

void startMenu() {
	cout << "Оберiть пункт меню:\n"
		<< "1. Переглянути iнформацiйну модель.\n"
		<< "2. Внести змiни до параметрiв моделi.\n"
		<< "3. Завершити роботу." << endl;

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

	// нехай цi трикутники продаються, чому б нi
	tradeCode = "QR045a5";

	 productAmount = 641;
	 cost = 46.75;
}



void infoModelCout() {
	wcout << L"\nIнформацiйна модель трикутника:" << endl;
	cout << "Назва трикутника: ";
	for (int i = 0; i < 3; i++) {
		cout << triangleName[i];
	}
	cout << "\nКолiр трикутника: " << triangleColor << endl;

	cout << "Перший кут трикутника: " << angle1 << endl;
	cout << "Другий кут трикутника: " << angle2 << endl;
	cout << "Третiй кут трикутника: " << angle3 << endl;

	bool isItRightTriangle(angle1 == rightAngle
		|| angle2 == rightAngle
		|| angle3 == rightAngle);
	cout << "Чи трикутник прямокутний: " << ((isItRightTriangle) ? "Так" : "Нi") << endl;

	cout << "Товарний код у базi даних: ";
	for (int i = 0; i < 7; i++) {
		cout << tradeCode[i];
	}
	cout << "\nКiлькiсть товару: " << productAmount << endl;
	cout << "Цiна товару: " << cost << endl;
}



void accessChecker() {
	char login[MAX_LOGIN_LENGTH];
	wcout << L"\nЩоб отримати доступ до редагування, авторизуйтеся."
		<< L"\nВведiть логiн: " << endl;

	for (int counter = 1; counter < 5; counter++) {

		wcin.ignore();
		cin >> login;

		int loginComplete(strcmp(login, trueLogin));
		if (loginComplete == 0) break;

		else if (counter == 4) {
			cout << "Ви занадто багато разiв помилилися.\n" << endl;
			exit(0);
		}
		else cout << "Неправильний логiн (" << counter << " спроба), спробуйте ще раз." << endl;
	}


	char password[MAX_PASSWORD_LENGTH];
	wcout << L"\nВiтаю, " << login << L", теперь пiдтвердiть, що це ви." << endl;

	for (int counter = 1; counter < 5; counter++) {

		wcin.ignore();
		cin >> password;

		int passwordComplete(strcmp(password, truePassword));
		if (passwordComplete == 0) break;

		else if (counter == 4) {
			cout << "Ви занадто багато разiв помилилися.\n" << endl;
			exit(0);
		}
		else cout << "Неправильний пароль (" << counter << " спроба), спробуйте ще раз." << endl;
	}
	cout << "\nВи успiшно авторизувалися.\n" << endl;
}



void infoModelEditor() {
	infoModelStandart();
	cout << "Оберiть параметр, який хочете змiнити:\n"
		<< "1. Змiнити усе.\n"
		<< "2. Назву трикутника.\n"
		<< "3. Колiр трикутника.\n"
		<< "4. Розмiр кутiв трикутника.\n"
		<< "5. Товарний код у базi даних.\n"
		<< "6. Кiлькiсть товару.\n"
		<< "7. Цiну товару.\n"
		<< "8. Залишити та зберегти без змiн." << endl;

	bool changeAll(false);
	cin >> dec >> selectedMenuItem;


	switch (selectedMenuItem) {
	case 1:
		changeAll = true;


	case 2:
		cout << "\nВведiть нову назву трикутника (формат - три великi латинськi лiтери): " << endl;
		wcin.ignore();
		getline(cin, triangleName);

		cout << "Назву успiшно змiнено на ";
		for (int i = 0; i < 3; i++) {
			cout << triangleName[i];
		}
		cout << ".\n" << endl;

		if (changeAll == false) break;


	case 3:
		cout << "Введiть новий колiр трикутника: " << endl;
		getline(cin, triangleColor);

		cout << "Колiр успiшно змiнено на " << triangleColor << ".\n" << endl;

		if (changeAll == false) break;


	case 4:
		for (int counter = 0; counter < 4; counter++) {

			cout << "Введiть перший кут: " << endl;
			cin >> angle1;
			cout << "Введiть другий кут: " << endl;
			cin >> angle2;
			cout << "Введiть третiй кут: " << endl;
			cin >> angle3;

			int summ = angle1 + angle2 + angle3;
			bool isItRightTriangle(angle1 == rightAngle
				|| angle2 == rightAngle
				|| angle3 == rightAngle);
			if (summ == 180) {
				cout << "Значення кутiв успiшно змiнено на " << angle1 << ", "
					<< angle2 << " та " << angle3 << ", теперь трикутник "
					<< ((isItRightTriangle) ? "прямокутний.\n" : "не прямокутний.\n") << endl;
				break;
			}

			else if (counter == 3) {
				cout << "Ви занадто багато разiв ввели неправильнi значення.\n" << endl;
				exit(0);
			}

			else cout << "Кути введенi неправильно, спробуйте ще раз.\n" << endl;
		}
		if (changeAll == false) break;

	case 5:
		cout << "Введiть новий товарний код (формат - 7 символiв): " << endl;
		wcin.ignore();
		getline(cin, tradeCode);

		cout << "Товарний код успiшно змiнено на ";
		for (int i = 0; i < 7; i++) {
			cout << tradeCode[i];
		}
		cout << ".\n" << endl;

		if (changeAll == false) break;


	case 6:
		cout << "Введiть нову кiлькiсть товару: " << endl;
		cin >> productAmount;
		cout << "Кiлькiсть успiшно змiнено на " << productAmount << ".\n" << endl;

		if (changeAll == false) break;


	case 7:
		cout << "Введiть нову цiну товару: " << endl;
		cin >> cost;
		cout << "Цiну успiшно змiнено на " << cost << ".\n" << endl;

		break;


	case 8:
		cout << "Ви вибрали нiчого не змiнювати.\n" << endl;

		break;


	default:
		exit(0);
	}
	infoModelSaveMenu();
}



void infoModelSaveMenu() {

	cout << "Оберiть варiант вiдповiдi:\n"
		<< "1. Переглянути оновлену iнформацiйну модель.\n"
		<< "2. Завантажити оновлену iнформацiйну модель в окремий .txt файл.\n"
		<< "3. Нiчого не зберiгати та завершити роботу програми." << endl;

	cin >> dec >> selectedMenuItem;
	switch (selectedMenuItem) {
	case 1:
		cout << "Оновлена iнформацiонна модель:\n" << endl;
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


	fileWriter << "Iнформацiйна модель трикутника:" << endl;
	fileWriter << "Назва трикутника: ";
	for (int i = 0; i < 3; i++) {
		fileWriter << triangleName[i];
	}
	fileWriter << "\nКолiр трикутника: " << triangleColor << endl;

	fileWriter << "Перший кут трикутника: " << angle1 << endl;
	fileWriter << "Другий кут трикутника: " << angle2 << endl;
	fileWriter << "Третiй кут трикутника: " << angle3 << endl;

	bool isItRightTriangle(angle1 == rightAngle
		|| angle2 == rightAngle
		|| angle3 == rightAngle);
	fileWriter << "Чи трикутник прямокутний: " << ((isItRightTriangle) ? "Так" : "Нi") << endl;

	fileWriter << "Товарний код у базi даних: ";
	for (int i = 0; i < 7; i++) {
		fileWriter << tradeCode[i];
	}
	fileWriter << "\nКiлькiсть товару: " << productAmount << endl;
	fileWriter << "Цiна товару: " << cost << endl;


	fileWriter.close();


	cout << "Данi записуються..." << endl;
	Sleep(2000);
	cout << "..." << endl;
	Sleep(2000);
	cout << "\nIнформацiйну модель успiшно збережено у файл \"info_model.txt\"" << endl;
}


int main(){
	setlocale(LC_ALL, "");

	startMenu();

	return 0;
}