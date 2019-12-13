#include "Monomial.h"

using namespace std;

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