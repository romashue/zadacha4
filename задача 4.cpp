#include <iostream>

using namespace std;

unsigned int Composed(unsigned char valuec1, unsigned char valuec2, unsigned char valuec3, unsigned char valuec4)
{
    unsigned int I;
    I = valuec4;  // c4 � ������� 8� �����, ��������� 0
    I <<= 8; // �������� int ����� �� 8 ���. ������� 8 ��� ���������� 0, c4 ���������� � 9-16 �����.
    I |= valuec3; // ���������� ��� �������� 0 ���� �� ��, ��� � ����� c3

    // ���������� ������ ��������� �����
    I <<= 8;
    I |= valuec2;
    I <<= 8;
    I |= valuec1;

    return I;
}

void Decomposed(unsigned int valueI) 
{
    unsigned char c1 = valueI & 0xFF;
    unsigned char c2 = (valueI >> 8) & 0xFF;
    unsigned char c3 = (valueI >> 16) & 0xFF;
    unsigned char c4 = (valueI >> 24) & 0xFF;

    cout << "c1 = " << static_cast<unsigned>(c1) - 48 << endl;
    cout << "c2 = " << static_cast<unsigned>(c2) - 48 << endl;
    cout << "c3 = " << static_cast<unsigned>(c3) - 48 << endl;
    cout << "c4 = " << static_cast<unsigned>(c4) - 48 << endl;
}
using namespace std;

int main() {
    
    setlocale(LC_ALL, "ru");

    unsigned char c1;
    unsigned char c2;
    unsigned char c3;
    unsigned char c4;

    cout << "����� c1 = ";
    cin >> c1;
    cout << "����� c2 = ";
    cin >> c2;
    cout << "����� c3 = ";
    cin >> c3;
    cout << "����� c4 = ";
    cin >> c4;

    unsigned I = Composed(c1, c2, c3, c4);

    Decomposed(I);

}