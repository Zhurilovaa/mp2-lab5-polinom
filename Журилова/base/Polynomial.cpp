#include <math.h>
#include <sstream>
#include "Polynomial.h"
using namespace std;


bool Polynomial::isVariable(char c)//Символ переменная
{
	if ((c == 'X') || (c == 'Y') || (c == 'Z'))
	{
		return true;
	}
	else return false;
}
bool Polynomial::isOperation(char c) 
{
	if ((c == '+') || (c == '-'))
	{
		return true;
	}
	else return false;
}
bool Polynomial::isNumber(char c) 
{
	if ((c >= '0') && (c <= '9'))
	{
		return true;
	}
	else return false;
}

double Polynomial::CalcInPoint(double _X, double _Y, double _Z)//Вычисление в точке
{
	double X, Y, Z, X1, Y1, Z1;
	X = _X;//Значение x
	Y = _Y;//Значение y
	Z = _Z;//Значение z
	double result, Coeff;
	result = 0.0;
	Monomial temp;
	for (Pol.Reset(); Pol.ListEnd()==false; Pol.StepNext())
	{
		temp = Pol.GetDataCur();
		Coeff = temp.GetCoeff();
		X1 = temp.GetDegreeeX();
		Y1 = temp.GetDegreeeY();
		Z1 = temp.GetDegreeeZ();
		result = result + Coeff * pow(X, X1) * pow(Y, Y1) * pow(Z, Z1);
	}
	return result;
}
Polynomial Polynomial::operator+(Polynomial &pol)
{
	Monomial temp1, temp2;
	Polynomial result("");
	Pol.Reset();
	pol.Pol.Reset();
	double tempCoeff;
	while (Pol.ListEnd()==false)
	{
		temp1 = Pol.GetDataCur();
		temp2 = pol.Pol.GetDataCur();

		if (temp1 < temp2)
		{
			result.Pol.InsertLast(temp2);
			pol.Pol.StepNext();
		}
		else if (temp1.SimilarPol(temp2)==true)
		{
			tempCoeff = temp1.GetCoeff() + temp2.GetCoeff();
			if (tempCoeff != 0)
			{
				temp1.SetCoeff(tempCoeff);
				result.Pol.InsertLast(temp1);
			}
			Pol.StepNext();
			pol.Pol.StepNext();
		}
		else
		{
			result.Pol.InsertLast(temp1);
			Pol.StepNext();
		}
	}
	while (pol.Pol.ListEnd()==false)//Остались ли во втором полиноме мономы?
	{
		result.Pol.InsertLast(temp2);
		pol.Pol.StepNext();
		temp2 = pol.Pol.GetDataCur();
	}
	return result;
}
Polynomial  Polynomial::MultConst(double A)
{
	Polynomial temp = *this;
	double tempCoeff;
	Monomial tempMon;
	while (temp.Pol.ListEnd() == false)
	{
		tempMon = temp.Pol.GetDataCur();
		tempCoeff = A * tempMon.GetCoeff();
		tempMon.SetCoeff(tempCoeff);
		temp.Pol.SetCurrentData(tempMon);
	}
	return temp;
}
Polynomial Polynomial::operator*(Polynomial &pol)
{
	Polynomial result("");
	Pol.Reset();
	pol.Pol.Reset();
	Monomial temp1, temp2, temp3;
	while (Pol.ListEnd()==false)
	{
		temp1 = Pol.GetDataCur();
		while (pol.Pol.ListEnd()==false)
		{
			temp2 = pol.Pol.GetDataCur();
			temp3 = temp1 * temp2;
			result.Pol.InsertLast(temp3);
			pol.Pol.StepNext();
		}
		pol.Pol.Reset();
		Pol.StepNext();
	}
	result.SortPolynom();
	return result;
}
Polynomial Polynomial::operator-(Polynomial &pol)
{
	Monomial temp1, temp2;
	Polynomial result("");

	Pol.Reset();
	pol.Pol.Reset();
	double newcoeff, coeff2;

	while (Pol.ListEnd()==false)
	{
		temp1 = Pol.GetDataCur();
		temp2 = pol.Pol.GetDataCur();
		coeff2 = temp2.GetCoeff();
		temp2.SetCoeff(-1 * coeff2);
		if (temp1 < temp2)
		{
			result.Pol.InsertLast(temp2);
			pol.Pol.StepNext();
		}
		else if (temp1.SimilarPol(temp2)==true)
		{
			newcoeff = temp1.GetCoeff() + temp2.GetCoeff();
			if (newcoeff != 0)
			{
				temp1.SetCoeff(newcoeff);
				result.Pol.InsertLast(temp1);
			}
			Pol.StepNext();
			pol.Pol.StepNext();
		}
		else
		{
			result.Pol.InsertLast(temp1);
			Pol.StepNext();
		}
	}
	while (pol.Pol.ListEnd()==false)
	{
		result.Pol.InsertLast(temp2);
		pol.Pol.StepNext();
		temp2 = pol.Pol.GetDataCur();
	}
	return result;
}
Polynomial& Polynomial::operator=(const Polynomial& pol) 
{
	if (*this != pol)
	{
		Pol.DeleteAllList();
		Polynomial temp = pol;
		Monomial mon(0, -1, -1, -1);
		Pol.InsertConnect(mon);
		if (temp.Pol.Empty() == false)
		{
			for (temp.Pol.Reset(); temp.Pol.ListEnd()==false; temp.Pol.StepNext())
			{
				Pol.InsertLast(temp.Pol.GetDataCur());
			}
		}
	}
	return *this;
}
bool Polynomial::operator!=(const Polynomial &pol)
{
	Polynomial temp = pol;
	Monomial temp1, temp2;
	for (temp.Pol.Reset(); temp.Pol.ListEnd() == false; temp.Pol.StepNext())
	{
		temp1 = Pol.GetDataCur();
		temp2 = temp.Pol.GetDataCur();
		if (temp1 != temp2)
		{
			return true;
		}
	}
	return false;
}
bool Polynomial::operator==(const Polynomial &pol)
{
	Polynomial temp = pol;
	if (*this != temp)
		return false;
	else return true;
}
string Polynomial::To_String(double s)
{
	std::ostringstream oss;
	oss << s;
	return oss.str();
}
string Polynomial::GetPolinom() 
{
	string result = "";
	double coeff;
	int X, Y, Z;
	Monomial temp;
	if (Pol.Empty() == true)
	{
		result = "0";
	}
	else
	{
		for (Pol.Reset(); Pol.ListEnd()==false; Pol.StepNext())
		{
			temp = Pol.GetDataCur();
			coeff = temp.GetCoeff();
			X = temp.GetDegreeeX();
			Y = temp.GetDegreeeY();
			Z = temp.GetDegreeeZ();
			if (coeff > 0)
			{
				result = result + "+";
			}
			string monom = "";
			if ((X == 0) && (Y != 0) && (Z != 0))
			{
				monom = To_String(coeff);
				monom += 'Y';
				monom += '^';
				monom += To_String(Y);
				monom += 'Z';
				monom += '^';
				monom += To_String(Z);
			}
			else if ((X != 0) && (Y == 0) && (Z != 0))
			{
				monom = To_String(coeff);
				monom += 'X';
				monom += '^';
				monom += To_String(X);
				monom += 'Z';
				monom += '^';
				monom += To_String(Z);
			}
			else if ((X != 0) && (Y != 0) && (Z == 0))
			{
				monom = To_String(coeff);
				monom += 'X';
				monom += '^';
				monom += To_String(X);
				monom += 'Y';
				monom += '^';
				monom += To_String(Y);
			}
			else if ((X == 0) && (Y == 0) && (Z != 0))
			{
				monom = To_String(coeff);
				monom += 'Z';
				monom += '^';
				monom += To_String(Z);
			}
			else if ((X != 0) && (Y == 0) && (Z == 0))
			{
				monom = To_String(coeff);
				monom += 'X';
				monom += '^';
				monom += To_String(X);
			}
			else if ((X == 0) && (Y != 0) && (Z == 0))
			{
				monom = To_String(coeff);
				monom += 'Y';
				monom += '^';
				monom += To_String(Y);
			}
			else if ((X == 0) && (Y == 0) && (Z == 0))
			{
				monom = To_String(coeff);
			}
			else if ((Z != 0) && (Y != 0) && (Z != 0))
			{
				monom = To_String(coeff);
				monom += 'X';
				monom += '^';
				monom += To_String(X);
				monom += 'Y';
				monom += '^';
				monom += To_String(Y);
				monom += 'Z';
				monom += '^';
				monom += To_String(Z);
			}
			result += monom;
		}
	}
	return result;
}
bool isPolynomRight(string pol)
{
	int size = pol.size();
	string Used = "XYZ+-0123456789.^";
	string NotUsed = "!@#$%&*(){}[],=?";
	bool workVar = false;
	bool pointInCoefficient=false;
	int workMon = 0;
	int sizeNot = NotUsed.size();
	int countVarMon[3] = { 0,0,0 };
	if (size = 0)
		return false;
	if (pol[0] == Used[15])
	{
		return false;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (pol[i] == NotUsed[j])
				{
					return false;
				}
			}
			for (int m = 0; m < 3; m++)
			{
				if ((pol[i] == Used[m]) && (workVar == false))
				{
					if (countVarMon[m] == 1)
					{
						return false;
					}
					countVarMon[m]++;
					workVar = true;
					pointInCoefficient = false;
					workMon = 0;
					break;
				}
				if (workVar == true)
				{
					if (pol[i] != '^')
					{
						return false;
					}
					else
					{
						i++;
						if ((pol[i] < '0') || (pol[i] > '9'))//Недопустимый символ
							return false;
						else
						{
							string temp = "xyz+-";
							int mistake = 0;
							for (int n = 0; n < 5; n++)
							{
								if (pol[i + 1] != temp[n])
								{
									mistake++;
								}
							}
							if (mistake == 5)
							{
								return false;
							}
							else
							{
								workVar = false;
							}
						}
					}
				}
			}
			if ((pol[i] == '-') || (pol[i] == '+'))
			{
				if (workMon > 0)//Не закончили работу с предыдущим мономом
				{
					return false;
				}
				else//Закончили, идем дальше
				{
					countVarMon[0] = countVarMon[1] = countVarMon[2] = 0;
					workMon++;
				}
			}
			if ((pol[i] >= '0') && (pol[i] <= '9'))
			{
				workMon = 0;
			}
			if (pol[i] == '.')
			{
				if (pointInCoefficient == true)
					return false;
				else
				{
					if ((pol[i - 1] < '0') || (pol[i - 1] > '9'))
						return false;
					else
						pointInCoefficient=true;
				}
			}
		}
		if ((pol[size - 1] == '-') || (pol[size - 1] == '+'))
		{
			return false;
		}
		return true;
	}
}
