#ifndef __TList_H__
#define __TList_H__
#include <iostream>
#include "Monomial.h"
using namespace std;
template <class T>
struct TNode
{
	T data;//данные звена
	TNode *pNext;//указатель на следующее звено
	TNode *pPast;//указатель на предыдущее звено
	TNode() : pNext(nullptr), pPast(nullptr) {};
};
template <class T>
class TList
{
private:
	//Структура звено списока	
	TNode<T> *pFirst;//Первое звено
	TNode<T> *pLast;//Последнее звено
	TNode<T> *pCurrent;//Текущее звено
	TNode<T> *pConnect;//Связующее звено (фиктивное начало и конец)
public:
	TList()
	{
		//список пуст при создании
		pFirst = pCurrent = pLast = pConnect = nullptr;
	}
	TList(const TList<T>& list)//Конструктор копирования
	{
		pFirst = pCurrent = pLast = nullptr;//Для начала сделали список, в который копируем, пустым

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
	~TList()//Деструктор
	{
		DeleteAllList();
	}

	//Проверки
	bool Empty()//Список пуст
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
	bool ListEnd()//Дошли до конца списка
	{
		if (pCurrent == pConnect)
		{
			return true;
		}
		else
			return false;
	}
	bool LastElem()//Данный элемент - последний?
	{
		if (pCurrent == pLast)
		{
			return true;
		}
		else
			return false;
	}


	//Проход по списку
	void StepNext()//Шаг вперед по списку
	{
		pCurrent = pCurrent->pNext;
	}
	void StepBack()//Шаг назад по списку
	{
		pCurrent = pCurrent->pPast;
	}

	//Вставка
	void InsertConnect(T _data)//Фиктивная вставка
	{
		//Создаем новое фиктивное звено, делаем его текущим для работы
		pConnect = new TNode<T>;
		pConnect->data = _data;
		pCurrent = pConnect;
	}
	void InsertFirst(T _data)//Вставка в начало
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
	void InsertLast(T _data)//Вставка в конец
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
	void InsertСurrent(T _data)//Вставка перед текущим
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

	//Получение и установка
	T GetDataCur()//Возврат текущего элемента
	{
		return pCurrent->data;
	}
	void SetCurrentData(T _data)//Установка данных в текущий элемент
	{
		pCurrent->data = _data;
	}

	void Reset()//Текущий в начало
	{
		pCurrent = pFirst;
	}


	//Удаление
	void DeleteFirst()//Удаление первого
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
	void DeleteCurrent()//Удаление текущего
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
	void DeleteLast()//Удаление последнего
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