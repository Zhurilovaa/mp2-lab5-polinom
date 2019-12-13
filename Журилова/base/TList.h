#ifndef __TLIST_H__
#define __TLIST_H__
#include "Monomial.h"
using namespace std;

template <class T>
class TList
{
private:
	//��������� ����� �������
	struct TNode
	{
		T data;//������ �����
		TNode *pNext;//��������� �� ��������� �����
		TNode *pPast;//��������� �� ���������� �����
	};
	TNode *pFirst;//������ �����
	TNode *pLast;//��������� �����
	TNode *pCurrent;//������� �����
	TNode *p�onnect;//��������� ����� (��������� ������ � �����)
public:
	TList()
	{
		//������ ���� ��� ��������
		pFirst = pCurrent = pLast = p�onnect = nullptr;
	}
	TList(const TList<T> &list)//����������� �����������
	{
		pFirst = pCurrent = pLast = nullptr;//��� ������ ������� ������, � ������� ��������, ������

		TNode *temp = list.p�onnect;
		InsertConnect(temp->data);
		if (list.pFirst != nullptr)
		{
			temp = temp->pNext;
		}
		while ((temp != list.p�onnect) && (temp != nullptr))
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
	bool Empty();//������ ����
	bool ListEnd();//����� �� ����� ������
	bool LastElem();//������ ������� - ���������?
	

	//������ �� ������
	void StepNext();//��� ������ �� ������
	void StepBack();//��� ����� �� ������

	//�������
	void InsertConnect(T _data);//��������� �������
	void InsertFirst(T _data);//������� � ������
	void InsertLast(T _data);//������� � �����
	void Insert�urrent(T _data);//������� ����� �������

	//��������� � ���������
	T GetDataCur();//������� �������� ��������
	void SetCurrentData(T _data);//��������� ������ � ������� �������
	void Reset();//������� � ������

	//��������
	void DeleteFirst();//�������� �������
	void DeleteCurrent();//�������� ��������
	void DeleteLast();//�������� ����������
	void DeleteAllList();//�������� ����� ������
};

#endif