#ifndef __TList_H__
#define __TList_H__
#include <iostream>
using namespace std;
template <class T>
struct TNode
{
	T data;//������ �����
	TNode *pNext;//��������� �� ��������� �����
	TNode *pPast;//��������� �� ���������� �����
	TNode() : pNext(nullptr), pPast(nullptr) {};
};
template <class T>
class TList
{
private:
	//��������� ����� �������	
	TNode<T> *pFirst;//������ �����
	TNode<T> *pLast;//��������� �����
	TNode<T> *pCurrent;//������� �����
	TNode<T> *pConnect;//��������� ����� (��������� ������ � �����)
public:
	TList()
	{
		//������ ���� ��� ��������
		pFirst = pCurrent = pLast = pConnect = nullptr;
	}
	TList(const TList<T>& list)//����������� �����������
	{
		pFirst = pCurrent = pLast = nullptr;//��� ������ ������� ������, � ������� ��������, ������

		TNode<T> *temp = list.pConnect;
		InsertConnect(temp->data);
		if (list.pFirst != nullptr)
		{
			temp = temp->pNext;
		}
		while ((temp != list.pConnect) && (temp != nullptr))
		{
			InsertLast(temp->data);
			temp = temp->pNext;
		}

	}
	~TList()//����������
	{
		DeleteAllList();
	}

	//��������
	bool Empty()//������ ����
	{
		if (pFirst == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool ListEnd()//����� �� ����� ������
	{
		if (pCurrent == pConnect)
		{
			return true;
		}
		else
			return false;
	}
	bool LastElem()//������ ������� - ���������?
	{
		if (pCurrent == pLast)
		{
			return true;
		}
		else
			return false;
	}


	//������ �� ������
	void StepNext()//��� ������ �� ������
	{
		pCurrent = pCurrent->pNext;
	}
	void StepBack()//��� ����� �� ������
	{
		pCurrent = pCurrent->pPast;
	}

	//�������
	void InsertConnect(T _data)//��������� �������
	{
		//������� ����� ��������� �����, ������ ��� ������� ��� ������
		pConnect = new TNode<T>;
		pConnect->data = _data;
		pCurrent = pConnect;
	}
	void InsertFirst(T _data)//������� � ������
	{
		TNode<T> *p = new TNode<T>;
		p->data = _data;
		if (Empty() == true)
		{
			p->pNext = pConnect;
			p->pPast = pConnect;
			pFirst = pLast = pCurrent = p;
			pConnect->pNext = p;
			pConnect->pPast = p;
		}
		else
		{
			p->pNext = pFirst;
			p->pPast = pConnect;
			pFirst->pPast = p;
			pConnect->pNext = p;
			pFirst = p;
		}
	}
	void InsertLast(T _data)//������� � �����
	{
		TNode<T> *p = new TNode<T>;
		p->data = _data;
		if (Empty() == true)
		{
			InsertFirst(_data);
		}
		else
		{
			pLast->pNext = p;
			p->pPast = pLast;
			pConnect->pPast = p;
			p->pNext = pConnect;
			pLast = p;
		}
	}

	void Insert�urrent(T _data)//������� ����� �������
	{
		TNode<T> *p = new TNode<T>;
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
			StepBack();
			StepBack();
			pCurrent->pNext = p;
		}
	}

	//��������� � ���������
	T GetDataCur()//������� �������� ��������
	{
		return pCurrent->data;
	}
	void SetCurrentData(T _data)//��������� ������ � ������� �������
	{
		pCurrent->data = _data;
	}

	void Reset()//������� � ������
	{
		pCurrent = pFirst;
	}


	//��������
	void DeleteFirst()//�������� �������
	{
		if (Empty() == true)
		{
			throw "Cannot delete from an empty list!";
		}
		else if (Empty() == false)
		{
			TNode<T> *p = pFirst->pNext;
			delete pFirst;
			pFirst = pCurrent = p;
			pCurrent->pPast = pConnect;
			pConnect->pNext = pCurrent;
		}
	}

	void DeleteCurrent()//�������� ��������
	{
		TNode<T> *p = pCurrent;
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
	void DeleteLast()//�������� ����������
	{
		TNode<T> *p = pLast;
		pCurrent = pLast;
		StepBack();
		pCurrent->pNext = pConnect;
		pConnect->pPast = pCurrent;
		pLast = pCurrent;
		pCurrent = pLast->pNext;
		delete p;
	}
	void DeleteAllList()
	{
		while ((pFirst != pConnect) && (pFirst != nullptr))
		{
			TNode<T> *temp = pFirst;
			pFirst = pFirst->pNext;
			delete temp;
		}
		pFirst = pLast = pCurrent = nullptr;
	}
};
#endif