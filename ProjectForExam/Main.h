#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <limits.h>
#include <cmath>
#include <Windows.h>
#define PI 3.14159265
using namespace std;


#pragma region CinChecker
template <typename T>
T cin_checker(T& cinNumber) {
    cin >> cinNumber;
    while (1 == 1) {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Помилка введення: некоректне значення!\nВведiть правильно: ";
            cin >> cinNumber;
        }
        else {
            cin.ignore(32767, '\n');
            break;
        }
    }
    return cinNumber;
}

template <typename T, typename K>
T cin_checker(T& cinNumber, K min, K max) {
    cin >> cinNumber;
    while (1 == 1) {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Помилка введення: некоректне значення! \nВведiть правильно: ";
            cin >> cinNumber;
        }

        else if (cinNumber < min) {
            cin.ignore(32767, '\n');
            cout << "Помилка введення: значення менше мiнiмуму! \nВведiть правильно: ";
            cin >> cinNumber;
        }
        else if (cinNumber > max) {
            cin.ignore(32767, '\n');
            cout << "Помилка введення: значення бiльше максимуму! \nВведiть правильно: ";
            cin >> cinNumber;
        }

        else {
            cin.ignore(32767, '\n');
            break;
        }
    }
    return cinNumber;
}
#pragma endregion



short int selectedMenuItem;

enum MenuItems {
    STARTMENU_NUMBER_INFO = 1,
    STARTMENU_CALCULATORS,
    STARTMENU_EXIT,
    STARTMENU_RAINBOW
};

enum Colors {
    RED = 4,
    ORANGE = 6,
    YELLOW = 14,
    GREEN = 2, // або 10
    LIGHT_BLUE = 3, // або 11
    DARK_BLUE = 1,
    PURPLE = 5, // або 13
    WHITE = 15,
};


struct AccountData {
    string correctLogin;
    string correctPassword;
};


struct Point {
    int x;
    int y;
    int z;
};



class Vectors {
    int x;
    int y;
    int z;
    float module;

public:
    void СalculateCoords(Point pointBegin, Point pointEnd) {
        x = pointBegin.x - pointEnd.x;
        y = pointBegin.y - pointEnd.y;
        z = pointBegin.z - pointEnd.z;

        cout << "Координати вектора: {" << x << "; " << y << "; " << z << "}";
    }

    void SetСoords() {
        cout << "Введiть x: ";
        cin_checker(x);
        cout << "Введiть y: ";
        cin_checker(y);
        cout << "Введiть z: ";
        cin_checker(z);
    }

    int GetX() {
        return x;
    }
    int GetY() {
        return y;
    }
    int GetZ() {
        return z;
    }

    float СalculateModule() {
        module = sqrt(pow(x, 2)  + pow(y, 2) + pow(z, 2));
        return module;
    }

    void PrintModule() {
        cout << "Модуль вектора: " << СalculateModule() << endl;
    }
};


void authorization();
void startMenu();
void numberInfoMenu();
void calculatorsMenu();

string digitName(short int numberOfDigit);
void numberToDigits();

int* primeNumbers(unsigned short int size);
void printPrimeNumbers();
void numberIntoPrimeDivisors();

void decimalToAnotherNumSys();
void anotherNumSysToDecimal(); // я не знаю як їх нормально назвати по-різному 


void matrixCalc_2x2();
void matrixCalc_3x3();

void quadraticEquationsCalc();

int euclideanMethod(long int firstNumber, long int secondNumber);
void NSD_NSK_calc();

void vectorCalc();

void rainbowText();