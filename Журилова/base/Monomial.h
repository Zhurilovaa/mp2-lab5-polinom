#ifndef __MONOMIAL_H__
#define __MONOMIAL_H__
#include "TList.h"

using namespace std;
//����� �����
class Monomial
{
private:
	double coeff;
	int degreeX;
	int degreeY;
	int degreeZ;
public:
	//������������
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

	//������ � �������
	void CleanMon() { coeff = degreeX = degreeY = degreeZ = 0; }//������� ������
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

	//�������� ��� ��������
	bool operator!=(const Monomial& _m);//�� �����
	bool operator==(const Monomial& _m);//���������
	Monomial operator*(Monomial& m);//��������� �������
	Monomial& operator=(const Monomial& _m);//�������� ������������
	bool operator>(const Monomial& _m);//������ ������
	bool operator<(const Monomial& _m);//������ ������
	bool operator>=(const Monomial& _m);//������ ��� �����
	bool operator<=(const Monomial& _m);//������ ��� �����
	bool SimilarPol(const Monomial& _m);//�������� ������
};
#endif

