#ifndef __Popynomial_H__
#define __Popynomial_H__
#include <string>
#include <iostream>
#include "TList.h"

using namespace std;

//Класс полиномов
class Polynomial
{
private: 
	TList<Monomial> Pol;
public:
	//Конструкторы
	Polynomial(string pol)
	{
		ConvertStringToPolynomial(pol);
	}
	//Преобразование в полином из строки и обратно
	void ConvertStringToPolynomial(string pol);
	bool isVariable(char c);
	bool isOperation(char c);
	bool isNumber(char c);
	

	//Операции
	double CalcInPoint(double X, double Y, double Z);//Вычисление в точке
	Polynomial operator+(Polynomial &pl);
	Polynomial MultConst(double A);
	Polynomial operator*(Polynomial &pl);
	Polynomial operator-(Polynomial &pl);
	Polynomial& operator=(const Polynomial& pol);
	bool operator !=(const Polynomial &pl);
	bool operator ==(const Polynomial &pl);

	//Проверка правильности ввода полинома	
	string GetPolinom();
	string ToString(double k);
	void PrintPol();
};
bool isPolynomRight(string pol);
#endif

