#include "Polynomial.h"
/*
void Polynomial::Proba()
{
	Polynomial tmp("");
	Monomial p;
	double coef;
	while (Pol.ListEnd()==false)
	{
		p = Pol.GetDataCur();
		if (tmp.Pol.Empty()==true)
		{
			tmp.Pol.InsertFirst(p); Pol.DeleteFirst();
		}
		else
		{
			tmp.Pol.Reset();
			Monomial tmp1 = tmp.Pol.GetDataCur();
			Monomial prov(1, 0, 0, 0);
			while ((tmp1 > p) && (tmp.Pol.ListEnd()==false) && (tmp1 > prov))
			{
				tmp.Pol.StepNext();
				tmp1 = tmp.Pol.GetDataCur();
			}

			if (tmp1.SimilarPol(p)==true)
			{
				coef = tmp1.GetCoeff() + p.GetCoeff();
				p.SetCoeff(coef);
				tmp.Pol.SetCurrentData(p);
				Pol.DeleteFirst();
			}
			else if (tmp.Pol.ListEnd()==true)
			{
				tmp.Pol.InsertLast(p);
				Pol.DeleteFirst();
			}
			else if (tmp.Pol.ListEnd()==false)
			{
				tmp.Pol.Insert—urrent(p);
				Pol.DeleteFirst();
			}
		}
	}
	*this = tmp;
}*/