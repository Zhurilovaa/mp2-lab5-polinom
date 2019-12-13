#include <iostream>
#include <string>
#include "TList.h"
#include "Monomial.h"
#include "Polynomial.h"

using namespace std;

void GetMenu()
{
	cout << "Меню программы:" << endl;
	cout << "0.Показать меню." << endl;
	cout << "1.Ввести первый полином." << endl;
	cout << "2.Ввести второй полином." << endl;
	cout << "3.Вывести первый полином." << endl;
	cout << "4.Вывести второй полином." << endl;	
	cout << "5.Найти значение в точке." << endl;
	cout << "6.Сложить полиномы." << endl;
	cout << "7.Вычесть полиномы." << endl;
	cout << "8.Умножение полиномов." << endl;
	cout << "9.Умножение полинома на константу." << endl;
	cout << "10.Завершение работы." << endl;	
}

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Добро подаловать!" << endl;
	cout << "Данная программа предназначена для работы с полиномами, включающими в себя 3 переменные X,Y,Z." << endl;
	cout << "Правила ввода полинома:" << endl;
	cout << "1.Переменные нужно вводить в верхнем регистре (X,Y,Z);" << endl;
	cout << "2.Степени указываются после переменной с помощью знака '^' ;" << endl;
	cout << "3.Степени должны быть неотрицательными." << endl;
	cout << "Пример: 0.6X^5Y^3Z^2+8X^4+3Y^2" << endl;

	GetMenu();
	string pol1 = "";
	string pol2 = "";
	int X, Y, Z;
	Polynomial p1(""), p2(""), p3(""), p4("");//p3 - результат от операций + - *, MultConst
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
			cout << "Введите полином 1: ";
			cin >> pol1;
			break;
		case 2:
			cout << "Введите полином 2: ";
			cin >> pol2;
			break;
		case 3:
			cout << pol1 << endl;
			break;
		case 4:
			cout << pol2 << endl;
			break;
		case 5:
			cout << "Укажите полином, в котором нужно найти значение в точке, это 1 или 2" << endl;
			cin >> choise1;
			while ((choise1 > 2) && (choise1 <= 0))
			{
				cout << "Неверно введено значение! Попробуйте ещё." << endl;
				cin >> choise1;
			}
			switch (choise1)
			{
			case 1:
				cout << "Введите значения X,Y,Z " << endl;
				cin >> X >> Y >> Z;
				cout << "Значение полинома в точке (" << X << "," << Y << "," << Z << ") : ";
				cout << p1.CalcInPoint(X, Y, Z) << endl;
				break;
			case 2:
				cout << "Введите значения X,Y,Z " << endl;
				cin >> X >> Y >> Z;
				cout << "Значение полинома в точке (" << X << "," << Y << "," << Z << ") : ";
				cout << p2.CalcInPoint(X, Y, Z) << endl;
				break;
			default:
				break;
			}
			break;
		case 6:
			cout << "Сложение полиномов: " << endl;
			p3 = p1 + p2;
			cout << p3.GetPolinom() << endl;
			break;			
		case 7:
			cout << " Вычитание полиномов: " << endl;
			cout << "1.Из первого вычесть второй" << endl;
			cout << "2.Из второго вычесть первый" << endl;
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
			cout << "Умножение полинома на константу: " << endl;
			cout << "1.Первый" << endl;
			cout << "2.Второй" << endl;
			cin >> choise1;
			int A;
			cin >> A;
			switch (choise1)
			{
			case 1:
				p3 = p1.MultConst(A);
				cout << "Результат" << endl;
				cout << p3.GetPolinom() << endl;
				break;
			case 2:
				p3 = p2.MultConst(A);
				cout << "Результат" << endl;
				cout << p3.GetPolinom() << endl;
				break;
			default:
				break;
			}
			break;				
		}	

	return 0;
}
