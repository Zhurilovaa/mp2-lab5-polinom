#include "TList.h"
using namespace std;

//������ ����?
template<class T>
bool TList<T>::Empty()
{
	if (pFirst == nullptr)
	{
		return true;
	}
	else if (pFirst != nullptr)
	{
		return false;
	}
}

//��������, ������� ������� - ��� �����?
template<class T>
bool TList<T>::ListEnd()
{
	if (pCurrent == pConnect)
	{
		return true;
	}
	else
		return false;
}

//������� ������� - ���������?
template<class T>
bool TList<T>::LastElem() 
{ 
	if (pCurrent == pLast)
	{
		return true;
	}
	else
		return false;
}

//��� ������ �� ������
template<class T>
void TList<T>::StepNext()
{
	p�urrent = p�urrent->pNext;
}

//��� ����� �� ������
template <class T>
void TList<T>::StepBack()
{
	pCurrent = pCurrent->pPast;
}

//�������� ����� �����
template <class T>
void TList<T>::InsertConnect(T _data)
{
	//������� ����� ��������� �����, ������ ��� ������� ��� ������
	p�onnect = new TNode;
	p�onnect->data = _data;
	pCurrent = p�onnect;
}

//������� � ������
template <class T>
void  TList<T>::InsertFirst(T _data)
{
	TNode* p = new TNode;
	p->data = _data;
	if (Empty() == true)
	{
		p->pNext = p�onnect;
		p->pPast = p�onnect;
		pFirst = pLast = pCurrent = p;
		p�onnect->pNext = p;
		p�onnect->pPast = p;
	}
	else
	{
		p->pNext = pFirst;
		p->pPast = p�onnect;
		pFirst->pPast = p;
		p�onnect->pNext = p;
		pFirst = p;
	}
}

//�������  � �����
template <class T>
void TList<T>::InsertLast(T _data)
{
	TNode* p = new TNode;
	p->data = _data;
	if (Empty() == true)
	{
		InsertFirst(_data);
	}
	else
	{
		pLast->pNext = p;
		p->pPast = pLast;
		p�onnect->pPast = p;
		p->pNext = p�onnect;
		pLast = p;
	}
}

//������� � ������� ���������
template <class T>
void TList<T>::Insert�urrent(T _data)
{
	TNode* p = new TNode;
	p->data = _data;
	if ((pCurrent == pFirst) || (pFirst = nullptr))
	{
		InsertFirst(_data);
	}
	else
	{
		p->pNext = pCurrent;
		p->pPast = pCurrent->pPast;
		pCurrent->pPast = p;
		StepBackList();
		StepBackList();
		pCurrent->pNext = p;
	}
}

//��������� ������ �������� ��������
template <class T>
T TList<T>::GetDataCur()
{
	return pCurrent->data;
}

//��������� ������ �� ������� �������
template <class T>
void TList<T>::SetCurrentData(T _data)
{
	pCurrent->data = _data;
}

//����� �������� � ������
template <class T>
void TList<T>::Reset()
{
	pCurrent = pFirst;
}

//�������� �� ������
template <class T>
void TList<T>::DeleteFirst()
{
	if (Empty() == true)
	{
		throw "Cannot delete from an empty list!";
	}
	else if (Empty() == false)
	{
		TNode* p = pFirst->pNext;
		delete pFirst;
		pFirst = pCurrent = p;
		pCurrent->pPast = pConnect;
		pConnect->pNext = pCurr;
	}
}

//�������� ��������
template <class T>
void TList<T>::DeleteCurrent()
{
	TNode* p = pCurrent;
	if (p == pFirst)
		DeleteFirst();
	else if (p == pLast)
		DeleteLast();
	else
	{
		StepBack();
		pCurrent->pNext = p->pNext;
		StepNext();
		pCurrent->pPast = p->pPast;
		delete p;
	}
}

//�������� � �����
template <class T>
void TList<T>::DeleteLast()
{
	TNode* p = pLast;
	pCurrent = pLast;
	StepBack();
	pCurrent->pNext = pConnect;
	pConnect->pPast = pCurrent;
	pLast = pCurrent;
	pCurrent = pLast->pNext;
	delete p;
}

//�������� ����� ������
template <class T>
void TList<T>::DeleteAllList()
{
	while ((pFirst != pConnect) && (pFirst != nullptr))
	{
		TNode* temp = pFirst;
		pFirst = pFirst->pNext;
		delete temp;
	}
	pFirst = pLast = pCurrent = nullptr;
}