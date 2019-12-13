#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__
#include <string>
#include <iostream>
#include "TList.h"
#include "Monomial.h"

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
	void SortPolynom();

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
	string Polynomial::To_String(double s);
	string GetPolinom();	
};
bool isPolynomRight(string pol);
#endif

