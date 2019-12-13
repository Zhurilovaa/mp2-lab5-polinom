#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__
#include <string>
#include <iostream>
#include "TList.h"
#include "Monomial.h"

using namespace std;

//����� ���������
class Polynomial
{
private: 
	TList<Monomial> Pol;
public:
	//������������
	Polynomial(string pol)
	{
		ConvertStringToPolynomial(pol);
	}
	//�������������� � ������� �� ������ � �������
	void ConvertStringToPolynomial(string pol);
	bool isVariable(char c);
	bool isOperation(char c);
	bool isNumber(char c);
	void SortPolynom();

	//��������
	double CalcInPoint(double X, double Y, double Z);//���������� � �����
	Polynomial operator+(Polynomial &pl);
	Polynomial MultConst(double A);
	Polynomial operator*(Polynomial &pl);
	Polynomial operator-(Polynomial &pl);
	Polynomial& operator=(const Polynomial& pol);
	bool operator !=(const Polynomial &pl);
	bool operator ==(const Polynomial &pl);

	//�������� ������������ ����� ��������	
	string Polynomial::To_String(double s);
	string GetPolinom();	
};
bool isPolynomRight(string pol);
#endif

