#include <iostream>

using namespace std;

int main()
{
   setlocale(LC_ALL, "");
   // ������������ ������ ��������� �����
   
   
    // ����� (���) �����
    string clothesName = "���i";
    // ����
    string clothesColor = "�i���";
    // �������
    string clothesMaterial = "�������";
    // �����
    string clothesSize = "XL";
    // �������� ��������
    bool hood = true;
    // �� ����� �����������
    bool unbuttoning = true;
    // �����-��������
    string producingCountry = "I���i�";
    // �������� ��� � ��� �����
    unsigned short int tradeCode = 4589;
    // г� �����������
    unsigned short int releaseDate = 2020;
    // ֳ��
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
    
    cout << "����� (���) �����: \t\t" << clothesName << endl;
    cout << "���i� �����: \t\t\t" << clothesColor << endl;
    cout << "�����i�� �����: \t\t" << clothesMaterial << endl;
    cout << "����i� �����: \t\t\t" << clothesSize << endl;
    cout << "�����i��� ��������: \t\t" << ((hood) ? "�" : "����") << endl;
    cout << "�� ����� �����������: \t\t" << ((unbuttoning) ? "���" : "�i") << endl;
    cout << "�����-��������: \t\t" << producingCountry << endl;
    cout << "�������� ��� � ���i �����: \t" << tradeCode << endl;
    cout << "�i� �����������:\t\t" << releaseDate << endl;
    cout << "�i�� �����:\t\t\t" << cost << endl;

    cout << "\n��������� ��'�� ������������ ���'��i (� ������): " 
        << totalMemoryInBytes << endl;
}