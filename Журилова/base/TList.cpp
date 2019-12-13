#include "TList.h"
using namespace std;

//Список пуст?
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

//Проверка, текущий элемент - это конец?
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

//Текущий элемент - последний?
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

//Шаг вперед по списку
template<class T>
void TList<T>::StepNext()
{
	pСurrent = pСurrent->pNext;
}

//Шаг назад по списку
template <class T>
void TList<T>::StepBack()
{
	pCurrent = pCurrent->pPast;
}

//Создание копии звена
template <class T>
void TList<T>::InsertConnect(T _data)
{
	//Создаем новое фиктивное звено, делаем его текущим для работы
	pСonnect = new TNode;
	pСonnect->data = _data;
	pCurrent = pСonnect;
}

//Вставка в начало
template <class T>
void  TList<T>::InsertFirst(T _data)
{
	TNode* p = new TNode;
	p->data = _data;
	if (Empty() == true)
	{
		p->pNext = pСonnect;
		p->pPast = pСonnect;
		pFirst = pLast = pCurrent = p;
		pСonnect->pNext = p;
		pСonnect->pPast = p;
	}
	else
	{
		p->pNext = pFirst;
		p->pPast = pСonnect;
		pFirst->pPast = p;
		pСonnect->pNext = p;
		pFirst = p;
	}
}

//Вставка  в конец
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
		pСonnect->pPast = p;
		p->pNext = pСonnect;
		pLast = p;
	}
}

//Вставка в текущее положение
template <class T>
void TList<T>::InsertСurrent(T _data)
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

//Получение данных текущего элемента
template <class T>
T TList<T>::GetDataCur()
{
	return pCurrent->data;
}

//Установка данных на текущий элемент
template <class T>
void TList<T>::SetCurrentData(T _data)
{
	pCurrent->data = _data;
}

//Сброс текущего в начало
template <class T>
void TList<T>::Reset()
{
	pCurrent = pFirst;
}

//Удаление из начала
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

//Удаление текущего
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

//Удаление с конца
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

//Удаление всего списка
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