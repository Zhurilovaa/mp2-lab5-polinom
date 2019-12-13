#ifndef __MONOMIAL_H__
#define __MONOMIAL_H__

using namespace std;
//Класс моном
class Monomial
{
private:
	double coeff;
	int degreeX;
	int degreeY;
	int degreeZ;
public:
	//Конструкторы
	Monomial()
	{
		coeff = degreeX = degreeY = degreeZ = 0;
	}
	Monomial(const Monomial& m)
	{
		coeff = m.coeff;
		degreeX = m.degreeX;
		degreeY = m.degreeY;
		degreeZ = m.degreeZ;
	}
	Monomial(double _coeff, int dX, int dY, int dZ)
	{
		coeff = _coeff;
		degreeX = dX;
		degreeY = dY;
		degreeZ = dZ;
	}

	//Работа с мономом
	void CleanMon() { coeff = degreeX = degreeY = degreeZ = 0; }//Очистка монома
	int GetDegreeeX() { return degreeX; };
	int GetDegreeeY() { return degreeY; };
	int GetDegreeeZ() { return degreeZ; };
	double GetCoeff() { return coeff; };
	void SetData(double _coeff, int dX, int dY, int dZ)
	{
		coeff = _coeff;
		degreeX = dX;
		degreeY = dY;
		degreeZ = dZ;
	}
	void SetDegreeeX(int dX) { degreeX =dX; };
	void SetDegreeeY(int dY) { degreeY = dY; };
	void SetDegreeeZ(int dZ) { degreeZ = dZ; };
	void SetCoeff(double _coeff) { coeff = _coeff; };

	//Операции над мономами
	bool operator!=(const Monomial& _m);//Не равно
	bool operator==(const Monomial& _m);//Равенство
	Monomial operator*(Monomial& m);//Умножение мономов
	Monomial& operator=(const Monomial& _m);//Оператор присваивания
	bool operator>(const Monomial& _m);//Строго больше
	bool operator<(const Monomial& _m);//Строго меньше
	bool operator>=(const Monomial& _m);//Больше или равно
	bool operator<=(const Monomial& _m);//Меньше или равно
	bool SimilarPol(const Monomial& _m);//Подобные мономы
};
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
#endif

