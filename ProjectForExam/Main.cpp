#include"Main.h"

#pragma region Authorization+Menu
void authorization() {
    AccountData account1 = { "Volko","Qwerty123" };
    AccountData account2 = { "l","p" };

    string cin_login;
    cout << "Щоб отримати доступ до користування програмою, авторизуйтеся."
        << "\nВведiть логiн: " << endl;

    for (int counter = 1; ; counter++) {
        cin_checker(cin_login);
        if (cin_login == account1.correctLogin || cin_login == account2.correctLogin) break;

        else cout << "Неправильний логiн (" << counter << " спроба), спробуйте ще раз." << endl;
    }

    string cin_password;
    cout << "\nВiтаю, " << cin_login << ", теперь пiдтвердiть, що це ви." << endl;

    for (int counter = 1; ; counter++) {
        cin_checker(cin_password);

        if (cin_login == account1.correctLogin && cin_password == account1.correctPassword) break;
        else if (cin_login == account2.correctLogin && cin_password == account2.correctPassword) break;

        else if (counter == 4) {
            cout << "Ви занадто багато разiв помилилися.\n" << endl;
            exit(0);
        }

        else cout << "Неправильний пароль (" << counter << " спроба), спробуйте ще раз." << endl;
    }
}


void startMenu() {
    cout << "Ця програма - багатофункцiональний калькулятор для рiзноманiтних завдань\n"
        << "(окрiм простих арифметичних дiй, на якi здатен звичайний калькулятор).\nОберiть потрiбний роздiл: \n"
        << "1. Iнформацiя про число.\n"
        << "2. Повноцiннi калькулятори.\n"
        << "3. Вихiд.\n" 
        << "4. ???" << endl;

    cin_checker(selectedMenuItem, STARTMENU_NUMBER_INFO, STARTMENU_RAINBOW);

    switch (selectedMenuItem) {
    case STARTMENU_NUMBER_INFO:
        numberInfoMenu();
        break;

    case STARTMENU_CALCULATORS:
        calculatorsMenu();
        break;

    case STARTMENU_EXIT:
        cout << "Виконується вихiд..." << endl;
        exit(0);

    case STARTMENU_RAINBOW:
        rainbowText();
        break;
    }

}


void numberInfoMenu() {
    cout << "\nОберiть пункт меню: \n"
        << "1. Розклад числа на розряди.\n"
        << "2. Розклад числа на простi множники (додатково - список простих чисел).\n"
        << "3. Перехiд числа вiд десяткової до будь-якої iншої системи числення.\n"
        << "4. Перехiд числа вiд будь-якої iншої до десяткової системи числення." << endl;

    cin_checker(selectedMenuItem, 1, 4);

    switch (selectedMenuItem) {
    case 1:
        numberToDigits();
        break;

    case 2:
        numberIntoPrimeDivisors();
        break;

    case 3:
        decimalToAnotherNumSys();
        break;

    case 4:
        anotherNumSysToDecimal();
        break;
    }

}


void calculatorsMenu() {
    cout << "\nОберiть пункт меню: \n"
        << "1. Порахувати визначник матриць 2x2 або 3x3 (додатково - знайти обернену матрицю).\n"
        << "2. Розв'язати квадратне рiвняння.\n"
        << "3. Знайти НСД та НСК двох чисел.\n"
        << "4. Калькулятор векторiв у просторi." << endl;

    cin_checker(selectedMenuItem, 1, 4);

    switch (selectedMenuItem) {
    case 1:
        cout << "\nЯкий розмiр матрицi вас цiкавить?\n1. 2x2\n2. 3x3" << endl;
        cin_checker(selectedMenuItem, 1, 2);
        if (selectedMenuItem == 1) matrixCalc_2x2();
        else matrixCalc_3x3();
        break;

    case 2:
        quadraticEquationsCalc();
        break;

    case 3:
        NSD_NSK_calc();
        break;

    case 4:
        vectorCalc();
        break;
    }

}
#pragma endregion


#pragma region Digits
string digitName(short int numberOfDigit) {
    switch (numberOfDigit) { 
    case 0:   return "одиницi";
    case 1:   return "десятки";
    case 2:   return "сотнi";
    case 3:   return "тисячi";
    case 4:   return "десятки тисяч";
    case 5:   return "сотнi тисяч";
    case 6:   return "мiльйони";
    case 7:   return "десятки мiльйонiв";
    case 8:   return "сотнi мiльйонiв";
    case 9:   return "мiльярди";
    case 10:  return "десятки мiльярдiв";
    case 11:  return "сотнi мiльярдiв";
    case 12:  return "трильйони";
    case 13:  return "десятки трильйонiв";
    case 14:  return "сотнi трильйонiв";
    case 15:  return "квадрiльйони";
    case 16:  return "десятки квадрiльйонiв";
    case 17:  return "сотнi квадрiльйонiв";
    case 18:  return "квiнтильйони";
    case 19:  return "десятки квiнтильйонiв";
    default:  return "undefined";
    }
}


void numberToDigits() {
    long long int number, temp_ten;
    short int amountOfDigits = 0, digit = 0;
    short int digitNumber;

    cout << "\nВведiть число для розкладу на розряди (максимум - " << LLONG_MAX << "): " << endl;
    cin_checker(number);
    if (number < 0) number *= -1;

    unsigned long long int number_copy = number;
    for (; number_copy > 0; amountOfDigits++)
        number_copy /= 10;

    cout << "\nОберiть варiант розрахунку:\n"
        << "1. Знайти цифру конкретного розряду.\n"
        << "2. Знайти цифри для усiх розрядiв, якi є у числi." << endl;

    cin_checker(selectedMenuItem, 1, 2);
    cout << endl;

    if (selectedMenuItem == 1) {
        cout << "Введiть порядковий номер розряду (розряд одиниць має номер 0), який вам потрiбен: ";
        cin_checker(digit);

        while (digit >= amountOfDigits || digit < 0) {
            cout << "Такого розряду немає, спробуйте ще раз: ";
            cin_checker(digit);
        }
        temp_ten = (pow(10, digit));
        digitNumber = (number / temp_ten) % 10;

        cout << "Розряд: " << digitName(digit) << ", цифра цього розряду: " << digitNumber << "." << endl;
    }

    else {
        for (; digit < amountOfDigits; digit++) {
            temp_ten = (pow(10, digit));
            digitNumber = (number / temp_ten) % 10;

            cout << "Розряд: " << digitName(digit) << ", цифра цього розряду: " << digitNumber << "." << endl;
        }
    }
}
#pragma endregion


#pragma region PrimeDivisors+PrimeNumbers
int* primeNumbers(unsigned short int size) {
    unsigned short int outer_cursor_index = 3;
    if (size < outer_cursor_index) size = 3; //Помилка: занадто мале значення, тому параметр буде трохи збiльшений

    int* primeNumber = new int[size] {1, 2, 3};

    for (unsigned int rawNumber, addToNext = 2; outer_cursor_index < size; addToNext += 2) {
        rawNumber = primeNumber[2] + addToNext;

        for (unsigned int inner_index = 1, checkNumber = 1; inner_index < outer_cursor_index; inner_index++) {
            checkNumber = rawNumber % primeNumber[inner_index];

            if (checkNumber == 0) break;

            else if (inner_index == outer_cursor_index - 1) {
                primeNumber[outer_cursor_index] = rawNumber;
                outer_cursor_index++;
                break;
            }
        }
    }
    return primeNumber;
}


void numberIntoPrimeDivisors() {
    long int number;
    cout << "\nВведiть число для розкладу на простi множники: ";
    cin_checker(number);
    if (number < 0) number *= -1;

    while (number == 1) {
        cout << "Помилка: одиницю неможливо розкласти на простi множники. Введiть правильно: " << endl;
        cin_checker(number);
    }

    unsigned long int number_copy = number;
    int* divisor = new int[32];
    unsigned int divisor_index;

    for (unsigned short int primeNum_size = 20; number != 1; primeNum_size += 5) {
        divisor_index = 0;
        number = number_copy;
        int* primeNumber = primeNumbers(primeNum_size);

        for (unsigned int checkNumber, primeNum_index = 1; number != 1; ) {
            checkNumber = number % primeNumber[primeNum_index];

            if (checkNumber == 0) {
                number /= primeNumber[primeNum_index];
                divisor[divisor_index] = primeNumber[primeNum_index];
                divisor_index++;
            }

            else {
                if (primeNum_index == primeNum_size - 1) break;
                else primeNum_index++; 
            }
        }
        delete[] primeNumber;
    }

    cout << "Простi множники числа: ";
    for (int i = 0; i < divisor_index; i++) {
        if (i == divisor_index - 1) cout << " " << divisor[i] << ".\n" << endl;
        else cout << " " << divisor[i] << ",";
    }

    delete[] divisor;
    printPrimeNumbers();
}


void printPrimeNumbers() {
    cout << "Додаткова функцiя: виведення списку простих чисел.\n"
        <<"Чи потрiбно її застосовувати? \n1. Так.\n2. Нi." << endl;
    cin_checker(selectedMenuItem, 1, 2);

    if (selectedMenuItem == 1) {
        unsigned short int primeNumbersAmount;
        cout << "\nВведiть кiлькiсть простих чисел: ";

        cin_checker(primeNumbersAmount);
        int* primeNumber = primeNumbers(primeNumbersAmount);

        cout << "Простi числа: ";
        for (int i = 0; i < primeNumbersAmount; i++) {
            if (i == (primeNumbersAmount - 1)) cout << " " << primeNumber[i] << ".\n";
            else  cout << " " << primeNumber[i] << ",";
        }
        delete[] primeNumber;
    }
}
#pragma endregion 


#pragma region NumberSystems
void decimalToAnotherNumSys() {
    long int decimalNumber;
    string result;
    short int radix;

    cout << "\nВведiть число: ";
    cin_checker(decimalNumber);
    if (decimalNumber < 0) decimalNumber *= -1;

    cout << "Введiть основу системи числення (максимум - 16), до якої буде виконуватися перехiд: ";
    cin_checker(radix, 2, 16);

    cout << "\nЧисло " << decimalNumber << " в 10-й у " << radix << "-у систему числення: ";

    unsigned short int temp;
    char char_temp;
    ostringstream temp_for_result;

    while (true) {

        temp = decimalNumber % radix;
        decimalNumber /= radix;

        switch (temp) {
        case 10: char_temp = 'A';
            temp_for_result << char_temp;
            break;
        case 11: char_temp = 'B';
            temp_for_result << char_temp;
            break;
        case 12: char_temp = 'C';
            temp_for_result << char_temp;
            break;
        case 13: char_temp = 'D';
            temp_for_result << char_temp;
            break;
        case 14: char_temp = 'E';
            temp_for_result << char_temp;
            break;
        case 15: char_temp = 'F';
            temp_for_result << char_temp;
            break;
        default:
            temp_for_result << temp;
        }

        result = temp_for_result.str();

        if (decimalNumber == 0) {
            reverse(result.begin(), result.end());
            break;
        }
    }
    cout << result << endl;
}


void anotherNumSysToDecimal() {
    string numberToDecimal;
    int result = 0;
    short int radix;

    cout << "\nВведiть число: ";
    cin_checker(numberToDecimal);
    cout << "Введiть основу системи числення (максимум - 16), вiд якої буде виконуватися перехiд: ";
    cin_checker(radix, 2, 16);

    int numberLength = numberToDecimal.length();
    cout << "\nЧисло " << numberToDecimal << " в " << radix << "-й у 10-у систему числення: ";
    reverse(numberToDecimal.begin(), numberToDecimal.end());

    for (int i = 0; i < numberLength; i++) {

        switch (numberToDecimal[i]) {
        case 'A':
            numberToDecimal[i] = 10;
            break;
        case 'B':
            numberToDecimal[i] = 11;
            break;
        case 'C':
            numberToDecimal[i] = 12;
            break;
        case 'D':
            numberToDecimal[i] = 13;
            break;
        case 'E':
            numberToDecimal[i] = 14;
            break;
        case 'F':
            numberToDecimal[i] = 15;
            break;
        default: numberToDecimal[i] -= '0';
        }

        result += (numberToDecimal[i] * pow(radix, i));
    }
    cout << result << endl;
}
#pragma endregion



#pragma region Matrixes
void matrixCalc_2x2() {
    float a11, a12, a21, a22;
    cout << "Порядок введення значень в матрицю такий:\na11\ta12\na21\ta11\n\n" << "#\t#\n#\t#" << endl;
    cout << "\nВведiть a11: " << endl;
    cin_checker(a11);
    cout << "Введiть a12: " << endl;
    cin_checker(a12);
    cout << "Введiть a21: " << endl;
    cin_checker(a21);
    cout << "Введiть a22: " << endl;
    cin_checker(a22);
    cout << "\nГрафiчне вiдображення заданих даних:\n" << a11 << "\t" << a12 << "\n" << a21 << "\t" << a22 << endl;

    float det = 0;
    det = (a11 * a22) - (a12 * a21);
    cout << "\nЗначення визначника матрицi: " << det << "\n" << endl;

    cout << "Додаткова функцiя: знайти обернену матрицю.\n"
        << "Чи потрiбно її застосовувати? \n1. Так.\n2. Нi." << endl;

    cin_checker(selectedMenuItem, 1, 2);

    if (selectedMenuItem == 1) {
        if (det == 0) cout << "\nВизначник дорiвнює нулю, тому оберненої матрицi не iснує." << endl;

        else {
            float deldet = 0, ma11 = 0, ma21 = 0, ma12 = 0, ma22 = 0;
            deldet = 1 / det;
            ma11 = deldet * a22;
            ma21 = -deldet * a12;
            ma12 = -deldet * a21;
            ma22 = deldet * a11;

            cout << "\nОбернена матриця:\n" << ma11 << "\t" << ma21 << "\n" << ma12 << "\t" << ma22 << endl;
        }
    }
}


void matrixCalc_3x3() {
    float a11 = 0, a12 = 0, a13 = 0, a21 = 0, a22 = 0, a23 = 0, a31 = 0, a32 = 0, a33 = 0;
    cout << "Порядок введення значень в матрицю такий:\na1\ta2\ta3\na4\ta5\ta6\na7\ta8\ta9\n\n"
        << "#\t#\t#\n#\t#\t#\n#\t#\t#" << endl;

    cout << "\nВведiть a11: " << endl;
    a11 = cin_checker(a11);
    cout << "Введiть a12: " << endl;
    a12 = cin_checker(a12);
    cout << "Введiть a13: " << endl;
    a13 = cin_checker(a13);
    cout << "Введiть a21: " << endl;
    a21 = cin_checker(a21);
    cout << "Введiть a22: " << endl;
    a22 = cin_checker(a22);
    cout << "Введiть a23: " << endl;
    a23 = cin_checker(a23);
    cout << "Введiть a31: " << endl;
    a31 = cin_checker(a31);
    cout << "Введiть a32: " << endl;
    a32 = cin_checker(a32);
    cout << "Введiть a33: " << endl;
    a33 = cin_checker(a33);
    cout << "\nГрафiчне вiдображення заданих даних:\n" << a11 << "\t" << a12 << "\t" << a13
        << "\n" << a21 << "\t" << a22 << "\t" << a23 << "\n" << a31 << "\t" << a32 << "\t" << a33 << endl;

    float temp_plus = 0, temp_minus = 0, det = 0;
    temp_plus = (a11 * a22 * a33) + (a21 * a13 * a32) + (a12 * a23 * a31);
    temp_minus = (a13 * a22 * a31) + (a11 * a23 * a32) + (a21 * a12 * a33);
    det = temp_plus - temp_minus;
    cout << "\nЗначення визначника матрицi: " << det << "\n" << endl;

    cout << "Додаткова функцiя: знайти обернену матрицю.\n"
        << "Чи потрiбно її застосовувати? \n1. Так.\n2. Нi." << endl;

    cin_checker(selectedMenuItem, 1, 2);

    if (selectedMenuItem == 1) {
        if (det == 0) cout << "\nВизначник дорiвнює нулю, тому оберненої матрицi не iснує." << endl;

        else {
            float deldet = 0, ma11 = 0, ma21 = 0, ma31 = 0, ma12 = 0, ma22 = 0, ma32 = 0, ma13 = 0, ma23 = 0, ma33 = 0;
            deldet = 1 / det;
            ma11 = deldet * ((a22 * a33) - (a23 * a32));
            ma21 = -deldet * ((a12 * a33) - (a13 * a32));
            ma31 = deldet * ((a12 * a23) - (a13 * a22));
            ma12 = -deldet * ((a21 * a33) - (a23 * a31));
            ma22 = deldet * ((a11 * a33) - (a13 * a31));
            ma32 = -deldet * ((a11 * a23) - (a13 * a21));
            ma13 = deldet * ((a21 * a32) - (a22 * a31));
            ma23 = -deldet * ((a11 * a32) - (a12 * a31));
            ma33 = deldet * ((a11 * a22) - (a12 * a21));

            cout << "\nОбернена матриця:\n" << ma11 << "\t" << ma21 << "\t" << ma31 << "\n" << ma12 << "\t"
                << ma22 << "\t" << ma32 << "\n" << ma13 << "\t" << ma23 << "\t" << ma33 << endl;
        }
    }
}
#pragma endregion


#pragma region QuadraticEquations
    void quadraticEquationsCalc() {
        float D, x1, x2;
        float a, b, c;
        cout << "\nСтандартний вид квадратного рiвняння: ax^2 + bx + c = 0" << endl;

        cout << "Введiть число a: ";
        cin_checker(a);
        cout << "Введiть число b: ";
        cin_checker(b);
        cout << "Введiть число c: ";
        cin_checker(c);


        cout << "\nВведене вами рiвняння: ";
        if (a == 1) cout << "x^2";
        else if (a == -1) cout << "-x^2";
        else cout << a << "x^2";

        if (b > 0) cout << " + " << b << "x";
        else if (b == 1) cout << " + x";
        else if (b == -1) cout << " - x";
        else cout << " - " << (b * -1) << "x";

        if (c > 0) cout << " + " << c;
        else cout << " - " << (c * -1);
        cout << " = 0" << endl;

        while (1 == 1) {
            if (a == 0) {
                if (b == 0) {
                    if (c == 0) {
                        cout << "Рiвняння має безліч розв'язків." << endl;
                        break;
                    }
                    else {
                        cout << "Рiвняння не має розв’язку." << endl;
                        break;
                    }
                }
            }
            else {
                D = (pow(b, 2)) - (4 * a * c);
                cout << "\nДискримiнант: " << D << endl;
                if (D < 0) {
                    cout << "Дискримiнант вiд'ємний, тому рiвняння не має розв’язку." << endl;
                    break;
                }
                else if (D == 0) {
                    x1 = x2 = -b / (2 * a);
                    cout << "Дискримiнант дорiвнює нулю, тому корень рiвняння один.\nx = " << x1 << endl;
                    break;
                }
                else {
                    x1 = (-b + sqrt(D)) / (2 * a);
                    x2 = (-b - sqrt(D)) / (2 * a);
                    cout << "Дискримiнант додатний, тому коренiв рiвняння два. \nx1 = " << x1 << "\nx2 = " << x2 << endl;
                    break;
                }
            }
        }
    }
#pragma endregion


#pragma region NSK_NSD
int euclideanMethod(long int firstNumber, long int secondNumber) {
    if (firstNumber % secondNumber == 0) return secondNumber;
    else return euclideanMethod(secondNumber, firstNumber % secondNumber);
}

void NSD_NSK_calc() {
    long int firstNumber, secondNumber;
    cout << "\nВведiть перше число: ";
    cin_checker(firstNumber);
    if (firstNumber < 0) firstNumber *= -1;

    cout << "Введiть друге число: ";
    cin_checker(secondNumber);
    if (secondNumber < 0) secondNumber *= -1;

    long int NSD = euclideanMethod(firstNumber, secondNumber);
    cout << "\nНСД = " << NSD << endl;
    long int NSK = firstNumber * secondNumber / NSD;
    cout << "НСК = " << NSK << endl;
}
#pragma endregion 


#pragma region Vectors
void vectorCalc() { 
    cout << "\nОберiть необхiдну функцiю: \n"
        << "1. Порахувати координати вектора за його початком та кiнцем.\n"
        << "2. Порахувати модуль вектора за його координатами.\n"
        << "3. Порахувати косинус кута мiж двума векторами за їх координатами (додатково - знайти кут)." << endl;

    cin_checker(selectedMenuItem, 1, 3);

    switch (selectedMenuItem) {
    case 1:
        Point firstPoint, lastPoint;
        cout << "\nВведiть координати першої точки (початку):\nВведiть x: ";
        cin_checker (firstPoint.x);
        cout << "Введiть y: ";
        cin_checker(firstPoint.y);
        cout << "Введiть z: ";
        cin_checker(firstPoint.z);

        cout << "\nВведiть координати другої точки (кiнця):\nВведiть x: ";
        cin_checker(lastPoint.x);
        cout << "Введiть y: ";
        cin_checker(lastPoint.y);
        cout << "Введiть z: ";
        cin_checker(lastPoint.z);

        Vectors vectorForXYZ;
        cout << endl;
        vectorForXYZ.СalculateCoords(firstPoint, lastPoint);
        break;

    case 2:
        Vectors vectorForModule;
        cout << "\nВведiть координати вектору: " << endl;
        vectorForModule.SetСoords();

        cout << endl;
        vectorForModule.PrintModule();
        break;

    case 3:
        Vectors vector1, vector2;
        cout << "\nВведiть координати першого вектору: " << endl;
        vector1.SetСoords();
        cout << "\nВведiть координати другого вектору: " << endl;
        vector2.SetСoords();

        float dotProduct = (vector1.GetX()*vector2.GetX()) 
            + (vector1.GetY() * vector2.GetY()) + (vector1.GetZ() * vector2.GetZ());

        float modulesProduct = vector1.СalculateModule() * vector2.СalculateModule();

        float vectorsCosine = dotProduct / modulesProduct;
        cout << "\nКосинус кута мiж векторами: " << vectorsCosine << endl;

        cout << "\nДодаткова функцiя: пiдрахунок кута за косинусом.\n"
            << "Чи потрiбно її застосовувати? \n1. Так.\n2. Нi." << endl;
        cin_checker(selectedMenuItem, 1, 2);

        if (selectedMenuItem == 1) {
            double temp_angle = (acos(vectorsCosine) * 180.0 / PI);
            int angle = temp_angle;
            cout << "\nКут мiж векторами: " << angle;

            if (angle % 10 == 1) cout << " градус." << endl;
            else if (angle % 10 <= 4 && angle %10 != 0) cout << " градуси." << endl;
            else cout << " градусiв." << endl;
        }
        break;
    }
}
#pragma endregion


#pragma region RainbowText
void rainbowText() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, RED);
    cout << "\n\n\tРа";
    SetConsoleTextAttribute(h, ORANGE);
    cout << "йд";
    SetConsoleTextAttribute(h, YELLOW);
    cout << "уж";
    SetConsoleTextAttribute(h, GREEN);
    cout << "ни";
    SetConsoleTextAttribute(h, LIGHT_BLUE);
    cout << "й т";
    SetConsoleTextAttribute(h, DARK_BLUE);
    cout << "ек";
    SetConsoleTextAttribute(h, PURPLE);
    cout << "ст." << endl;
    SetConsoleTextAttribute(h, WHITE);
}
#pragma endregion



int main() {
    setlocale(LC_ALL, "");

    authorization();
    cout << endl;
    startMenu();
    cout << "\n\nПрограма завершила свою роботу, натиснiть будь-яку клавiшу та/або \"Enter\", щоб її закрити: ";
    cin.get();
    return 0;
}