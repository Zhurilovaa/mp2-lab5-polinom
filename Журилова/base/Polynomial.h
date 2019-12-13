#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__
#include <string>
#include <iostream>
#include "TList.h"
#include "Monomial.h"

using namespace std;

//Класс полиномов
class Polynomial
{
private: 
	TList<Monomial> Pol;
public:
	//Конструкторы
	Polynomial(string pol)
	{
		ConvertStringToPolynomial(pol);
	}
	//Преобразование в полином из строки и обратно
	void ConvertStringToPolynomial(string pol);
	bool isVariable(char c);
	bool isOperation(char c);
	bool isNumber(char c);
	void SortPolynom();

	//Операции
	double CalcInPoint(double X, double Y, double Z);//Вычисление в точке
	Polynomial operator+(Polynomial &pl);
	Polynomial MultConst(double A);
	Polynomial operator*(Polynomial &pl);
	Polynomial operator-(Polynomial &pl);
	Polynomial& operator=(const Polynomial& pol);
	bool operator !=(const Polynomial &pl);
	bool operator ==(const Polynomial &pl);

	//Проверка правильности ввода полинома	
	string Polynomial::To_String(double s);
	string GetPolinom();	
};
bool isPolynomRight(string pol);
void Polynomial::ConvertStringToPolynomial(string pol)
{
	Pol.DeleteAllList();
	Monomial tempMon(0, -1, -1, -1);//временный моном
	Pol.InsertConnect(tempMon);//Связующее звено - невозможный моном
	string temp;
	double coeff = 0;
	int coeffSign = 1;
	int X = 0;
	int Y = 0;
	int Z = 0;
	int size = pol.size();
	for (int i = 0; i < size;)
	{
		while (pol[i] == ' ')
		{
			i++;//если пробел пропускаем;
		}
		if ((i < size) && (isOperation(pol[i]) == true))//Если операция + или -
		{
			if (pol[i] == '-')
			{
				coeffSign = -1;
			}
			else if (pol[i] == '+')
			{
				coeffSign = 1;
			}
		}
		while ((i < size) && (isNumber(pol[i]) == true))//цифра
		{
			temp = temp + pol[i];
			i++;
		}
		while ((i < size) && (isVariable(pol[i]) == true))//какая-то переменная
		{
			switch (pol[i])
			{
			case 'X':
			{
				if (pol[i + 1] == '^')
				{
					i = i + 2;
					while ((i < size) && (isVariable(pol[i]) == false) && (isOperation(pol[i]) == false))
					{
						X = X * 10 + (pol[i] - '0');
						i++;
					}
				}
				else
				{
					X = 1;
					i++;
				}
				continue;
			}
			case 'Y':
			{
				if (pol[i + 1] == '^')
				{
					i = i + 2;
					while ((i < size) && (isVariable(pol[i]) == false) && (isOperation(pol[i]) == false))
					{
						Y = Y * 10 + (pol[i] - '0');
						i++;
					}
				}
				else
				{
					Y = 1;
					i++;
				}
				continue;
			}
			case 'Z':
			{
				if (pol[i + 1] == '^')
				{
					i = i + 2;
					while ((i < size) && (isVariable(pol[i]) == false) && (isOperation(pol[i]) == false))
					{
						Z = Z * 10 + (pol[i] - '0');
						i++;
					}
				}
				else
				{
					Z = 1;
					i++;
				}
				continue;
			}
			}
		}
		if (temp == "")
		{
			coeff = 1 * coeffSign;
		}
		else
		{
			coeff = coeffSign * stoi(temp);
		}
		tempMon.SetData(coeff, X, Y, Z);//Создали моном
		if (Pol.Empty() == true)//полином еще пуст
			Pol.InsertFirst(tempMon);
		else
		{
			Pol.InsertLast(tempMon);
		}
		tempMon.CleanMon();//очистили временный моном, после его записи в полином
	}
	if (Pol.Empty() == false)
	{
		SortPolynom();//сортируем полином
	}
}
void  Polynomial::SortPolynom()
{
	Polynomial pPol("");//пустой полином
	Monomial p;
	double pCoeff;
	while (Pol.ListEnd() == false)
	{
		p = Pol.GetDataCur();
		if (pPol.Pol.Empty() == true)//Временный полином пока пуст
		{
			pPol.Pol.InsertFirst(p);
			Pol.DeleteFirst();
		}
		else
			if (pPol.Pol.Empty() == false)
			{
				pPol.Pol.Reset();//Текущий элемент - первый
				Monomial tempMon = pPol.Pol.GetDataCur();
				Monomial prov(1, 0, 0, 0);
				while ((tempMon > p) && (pPol.Pol.LastElem() == false) && (tempMon > prov))
				{
					pPol.Pol.StepNext();
					tempMon = pPol.Pol.GetDataCur();
				}
				if (tempMon.SimilarPol(p) == true)//Если полиномы подобные
				{
					pCoeff = tempMon.GetCoeff() + p.GetCoeff();
					p.SetCoeff(pCoeff);
					pPol.Pol.SetCurrentData(p);
					Pol.DeleteFirst();
				}
				else if (pPol.Pol.ListEnd() == true)//Дошли до фиктивного, втсавка только в конец
				{
					pPol.Pol.InsertLast(p);
					Pol.DeleteFirst();
				}
				else if (pPol.Pol.ListEnd() == false)//Не подобные и не послений. Вставка в текущее место
				{
					pPol.Pol.InsertСurrent(p);
					Pol.DeleteFirst();
				}
			}
	}
	*this = pPol;
}
#endif

