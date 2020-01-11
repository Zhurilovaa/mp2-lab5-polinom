#ifndef __Monomial_H__
#define __Monomial_H__
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
		coeff = 0;
		degreeX = 0;
		degreeY = 0;
		degreeZ = 0;
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
	int GetDegreeX() { return degreeX; };
	int GetDegreeY() { return degreeY; };
	int GetDegreeZ() { return degreeZ; };
	double GetCoeff() { return coeff; };
	void SetData(double _coeff, int dX, int dY, int dZ)
	{
		coeff = _coeff;
		degreeX = dX;
		degreeY = dY;
		degreeZ = dZ;
	}
	void SetDegreeX(int dX) { degreeX = dX; };
	void SetDegreeY(int dY) { degreeY = dY; };
	void SetDegreeZ(int dZ) { degreeZ = dZ; };
	void SetCoeff(double _coeff) { coeff = _coeff; };

	//Операции над мономами
	Monomial operator*(const Monomial &m);//Умножение мономов
	Monomial& operator=(const Monomial& _m);//Оператор присваивания
	bool operator>(const Monomial &_m);//Строго больше
	bool operator<(const Monomial &_m);//Строго меньше
	bool operator>=(const Monomial &_m);//Больше или равно
	bool operator<=(const Monomial &_m);//Меньше или равно
	bool SimilarPol(const Monomial &_m);//Подобные мономы
};

#endif