#pragma once
#include<iostream>
#include<string>
#include <fstream>
#include "windows.h"
using namespace std;

const short int MAX_LOGIN_LENGTH = 8;
const short int MAX_PASSWORD_LENGTH = 12;
const short int rightAngle = 90;

void startMenu();
void infoModelStandart();
void infoModelCout();
void accessChecker();
void infoModelEditor();
void infoModelSaveMenu();
void infoModelInFile();



short int selectedMenuItem;


string triangleName, triangleColor, tradeCode;

unsigned short int angle1, angle2, angle3;
bool isItRightTriangle;
				
 int productAmount;
 double cost;


 char trueLogin[]{ "Volko" };
 char truePassword[]{ "Qwerty_123" };