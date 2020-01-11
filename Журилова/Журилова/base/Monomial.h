#ifndef __Monomial_H__
#define __Monomial_H__
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

	//������ � �������
	void CleanMon() { coeff = degreeX = degreeY = degreeZ = 0; }//������� ������
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

	//�������� ��� ��������
	Monomial operator*(const Monomial &m);//��������� �������
	Monomial& operator=(const Monomial& _m);//�������� ������������
	bool operator>(const Monomial &_m);//������ ������
	bool operator<(const Monomial &_m);//������ ������
	bool operator>=(const Monomial &_m);//������ ��� �����
	bool operator<=(const Monomial &_m);//������ ��� �����
	bool SimilarPol(const Monomial &_m);//�������� ������
};

#endif