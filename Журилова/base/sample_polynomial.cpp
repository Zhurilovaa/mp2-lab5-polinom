#include <iostream>
#include <string>
#include "TList.h"
#include "Monomial.h"
#include "Polynomial.h"

using namespace std;

void GetMenu()
{
	cout << "���� ���������:" << endl;
	cout << "0.�������� ����." << endl;
	cout << "1.������ ������ �������." << endl;
	cout << "2.������ ������ �������." << endl;
	cout << "3.������� ������ �������." << endl;
	cout << "4.������� ������ �������." << endl;	
	cout << "5.����� �������� � �����." << endl;
	cout << "6.������� ��������." << endl;
	cout << "7.������� ��������." << endl;
	cout << "8.��������� ���������." << endl;
	cout << "9.��������� �������� �� ���������." << endl;
	cout << "10.���������� ������." << endl;	
}

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "����� ����������!" << endl;
	cout << "������ ��������� ������������� ��� ������ � ����������, ����������� � ���� 3 ���������� X,Y,Z." << endl;
	cout << "������� ����� ��������:" << endl;
	cout << "1.���������� ����� ������� � ������� �������� (X,Y,Z);" << endl;
	cout << "2.������� ����������� ����� ���������� � ������� ����� '^' ;" << endl;
	cout << "3.������� ������ ���� ����������������." << endl;
	cout << "������: 0.6X^5Y^3Z^2+8X^4+3Y^2" << endl;

	GetMenu();
	string pol1 = "";
	string pol2 = "";
	int X, Y, Z;
	Polynomial p1(""), p2(""), p3(""), p4("");//p3 - ��������� �� �������� + - *, MultConst
	int choice = -1;
	int choise1 = 0;
	while(choice!=10)
		cin >> choice;
		switch (choice)
		{
		case 0:
			GetMenu();
			break;
		case 1:
			cout << "������� ������� 1: ";
			cin >> pol1;
			break;
		case 2:
			cout << "������� ������� 2: ";
			cin >> pol2;
			break;
		case 3:
			cout << pol1 << endl;
			break;
		case 4:
			cout << pol2 << endl;
			break;
		case 5:
			cout << "������� �������, � ������� ����� ����� �������� � �����, ��� 1 ��� 2" << endl;
			cin >> choise1;
			while ((choise1 > 2) && (choise1 <= 0))
			{
				cout << "������� ������� ��������! ���������� ���." << endl;
				cin >> choise1;
			}
			switch (choise1)
			{
			case 1:
				cout << "������� �������� X,Y,Z " << endl;
				cin >> X >> Y >> Z;
				cout << "�������� �������� � ����� (" << X << "," << Y << "," << Z << ") : ";
				cout << p1.CalcInPoint(X, Y, Z) << endl;
				break;
			case 2:
				cout << "������� �������� X,Y,Z " << endl;
				cin >> X >> Y >> Z;
				cout << "�������� �������� � ����� (" << X << "," << Y << "," << Z << ") : ";
				cout << p2.CalcInPoint(X, Y, Z) << endl;
				break;
			default:
				break;
			}
			break;
		case 6:
			cout << "�������� ���������: " << endl;
			p3 = p1 + p2;
			cout << p3.GetPolinom() << endl;
			break;			
		case 7:
			cout << " ��������� ���������: " << endl;
			cout << "1.�� ������� ������� ������" << endl;
			cout << "2.�� ������� ������� ������" << endl;
			cin >> choise1;
			switch (choise1)
			{
			case 1:
				p3 = p1 - p2;
				cout << p3.GetPolinom() << endl;
				break;
			case 2:
				p3 = p2 - p1;
				cout << p3.GetPolinom() << endl;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		case 8:
			p3 = p1 * p2;
			cout << p3.GetPolinom();
		case 9:
			cout << "��������� �������� �� ���������: " << endl;
			cout << "1.������" << endl;
			cout << "2.������" << endl;
			cin >> choise1;
			int A;
			cin >> A;
			switch (choise1)
			{
			case 1:
				p3 = p1.MultConst(A);
				cout << "���������" << endl;
				cout << p3.GetPolinom() << endl;
				break;
			case 2:
				p3 = p2.MultConst(A);
				cout << "���������" << endl;
				cout << p3.GetPolinom() << endl;
				break;
			default:
				break;
			}
			break;				
		}	

	return 0;
}
