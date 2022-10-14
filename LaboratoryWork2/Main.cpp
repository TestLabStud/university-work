#include <iostream>

using namespace std;

int main()
{
   setlocale(LC_ALL, "");
   // Інформаційна модель верхнього одягу
   
   
    // Назва (тип) одягу
    string clothesName = "Худi";
    // Колір
    string clothesColor = "Бiлий";
    // Матеріал
    string clothesMaterial = "Тканина";
    // Розмір
    string clothesSize = "XL";
    // Наявність капюшону
    bool hood = true;
    // Чи можна розстебнути
    bool unbuttoning = true;
    // Країна-виробник
    string producingCountry = "Iталiя";
    // Товарний код у базі даних
    unsigned short int tradeCode = 4589;
    // Рік виробництва
    unsigned short int releaseDate = 2020;
    // Ціна
    float cost = 2355.99;
    
    unsigned int totalMemoryInBytes =
        sizeof(clothesName) +
        sizeof(clothesColor) +
        sizeof(clothesMaterial) +
        sizeof(clothesSize) +
        sizeof(hood) +
        sizeof(unbuttoning) +
        sizeof(producingCountry) +
        sizeof(tradeCode) +
        sizeof(releaseDate) +
        sizeof(cost);
    
    cout << "Назва (тип) одягу: \t\t" << clothesName << endl;
    cout << "Колiр одягу: \t\t\t" << clothesColor << endl;
    cout << "Матерiал одягу: \t\t" << clothesMaterial << endl;
    cout << "Розмiр одягу: \t\t\t" << clothesSize << endl;
    cout << "Наявнiсть капюшону: \t\t" << ((hood) ? "Є" : "Немає") << endl;
    cout << "Чи можна розстебнути: \t\t" << ((unbuttoning) ? "Так" : "Нi") << endl;
    cout << "Країна-виробник: \t\t" << producingCountry << endl;
    cout << "Товарний код у базi даних: \t" << tradeCode << endl;
    cout << "Рiк виробництва:\t\t" << releaseDate << endl;
    cout << "Цiна одягу:\t\t\t" << cost << endl;

    cout << "\nЗагальний об'єм використанної пам'ятi (в байтах): " 
        << totalMemoryInBytes << endl;
}