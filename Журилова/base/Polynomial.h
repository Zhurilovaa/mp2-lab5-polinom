#ifndef __Popynomial_H__
#define __Popynomial_H__
#include <string>
#include <iostream>
#include "TList.h"

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
	string GetPolinom();
	string ToString(double k);
	void PrintPol();
};
bool isPolynomRight(string pol);
#endif

