#include "Monomial.h"

using namespace std;
//Операции
bool Monomial::operator!=(const Monomial &m)
{
	if ((SimilarPol(m) == true)&&(coeff==m.coeff))
	{
		return false;
	}
	else return true;
}
bool Monomial::operator==(const Monomial &m)
{
	if (*this != m)
	{
		return false;
	}
	else
		return true;
}
//умножение мономов
Monomial Monomial::operator*(Monomial &m)
{
	Monomial res;
	res.SetCoeff(coeff*m.GetCoeff());
	res.SetDegreeX(degreeX + m.GetDegreeX());
	res.SetDegreeY(degreeY + m.GetDegreeY());
	res.SetDegreeZ(degreeZ + m.GetDegreeZ());
	return res;
}
//оператор присваивания

Monomial& Monomial::operator=(const Monomial &m)
{
	if (*this != m)
	{
		coeff = m.coeff;
		degreeX = m.degreeX;
		degreeY = m.degreeY;
		degreeZ = m.degreeZ;
	}
	return *this;
}
bool Monomial::operator>(const Monomial &_m)
{
	if ((degreeX > _m.degreeX) || (degreeY > _m.degreeY) || (degreeZ > _m.degreeZ))
	{
		return true;
	}
	else {
		return false;
	}
}
bool Monomial::operator<(const Monomial &_m)
{
	if (*this > _m)
	{
		return false;
	}
	else {
		return true;
	}
}
bool Monomial::SimilarPol(const Monomial &m)
{
	if ((degreeX == m.degreeX) && (degreeY += m.degreeY) && (degreeZ == m.degreeZ))
	{
		return true;
	}
	else return false;
}
void Monomial::PrintMon()
{
	if (coeff != 0)
	{
		cout << coeff;
		if (degreeX != 0)
		{
			cout << "X^" << degreeX;
		}
		if (degreeY != 0)
		{
			cout << "Y^" << degreeY;
		}
		if (degreeZ != 0)
		{
			cout << "Z^" << degreeZ;
		}
	}
}