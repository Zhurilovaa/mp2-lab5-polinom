#ifndef __TLIST_H__
#define __TLIST_H__
#include "Monomial.h"
using namespace std;

template <class T>
class TList
{
private:
	//Структура звено списока
	struct TNode
	{
		T data;//данные звена
		TNode *pNext;//указатель на следующее звено
		TNode *pPast;//указатель на предыдущее звено
	};
	TNode *pFirst;//Первое звено
	TNode *pLast;//Последнее звено
	TNode *pCurrent;//Текущее звено
	TNode *pСonnect;//Связующее звено (фиктивное начало и конец)
public:
	TList()
	{
		//список пуст при создании
		pFirst = pCurrent = pLast = pСonnect = nullptr;
	}
	TList(const TList<T> &list)//Конструктор копирования
	{
		pFirst = pCurrent = pLast = nullptr;//Для начала сделали список, в который копируем, пустым

		TNode *temp = list.pСonnect;
		InsertConnect(temp->data);
		if (list.pFirst != nullptr)
		{
			temp = temp->pNext;
		}
		while ((temp != list.pСonnect) && (temp != nullptr))
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
	bool Empty();//Список пуст
	bool ListEnd();//Дошли до конца списка
	bool LastElem();//Данный элемент - последний?
	

	//Проход по списку
	void StepNext();//Шаг вперед по списку
	void StepBack();//Шаг назад по списку

	//Вставка
	void InsertConnect(T _data);//Фиктивная вставка
	void InsertFirst(T _data);//Вставка в начало
	void InsertLast(T _data);//Вставка в конец
	void InsertСurrent(T _data);//Вставка перед текущим

	//Получение и установка
	T GetDataCur();//Возврат текущего элемента
	void SetCurrentData(T _data);//Установка данных в текущий элемент
	void Reset();//Текущий в начало

	//Удаление
	void DeleteFirst();//Удаление первого
	void DeleteCurrent();//Удаление текущего
	void DeleteLast();//Удаление последнего
	void DeleteAllList();//Удаление всего списка
};

#endif