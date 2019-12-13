#include "Monomial.h"

using namespace std;
//Операции
//не равно
bool Monomial::operator!=(const Monomial& m)
{
	if ((coeff != m.coeff) || (degreeX != m.degreeX) || (degreeY != m.degreeY) || (degreeZ != m.degreeZ))
	{
		return true;
	}
	else return false;
}
//равно
bool Monomial::operator==(const Monomial& m)
{
	if (*this != m)
		return false;
	else return true;
}
//умножение мономов
Monomial Monomial::operator*(Monomial& m)
{
	Monomial res(coeff, degreeX, degreeY, degreeZ);
	res.coeff = res.coeff * m.coeff;
	res.degreeX = res.degreeX + m.degreeX;
	res.degreeY = res.degreeY + m.degreeY;
	res.degreeZ = res.degreeZ + m.degreeZ;
	return res;
}
//оператор присваивания
Monomial& Monomial::operator=(const Monomial& m)
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
bool Monomial::operator>(const Monomial& _m)
{
	if ((degreeX > _m.degreeX) || (degreeY > _m.degreeY) || (degreeZ > _m.degreeZ))
	{
		return true;
	}
	else {
		return false;
	}
}
bool Monomial::operator<(const Monomial& _m)
{
	if ((*this > _m)||(*this==_m))
	{
		return false;
	}
	else {
		return true;
	}
}
bool Monomial::operator>=(const Monomial& _m)
{
	if (*this < _m)
	{
		return false;
	}
	else return true;
}
bool Monomial::operator<=(const Monomial& _m)
{
	if (*this > _m)
	{
		return false;
	}
	else return true;
}
bool Monomial::SimilarPol(const Monomial& m)
{
	if ((degreeX == m.degreeX) && (degreeY += m.degreeY) && (degreeZ == m.degreeZ))
	{
		return true;
	}
	else return false;
}