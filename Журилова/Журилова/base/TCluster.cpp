/*#include "TCluster.h"
#include <iostream>
#include <ctime>
#include <string>
using namespace std;
//Подготовка кластера к работе
void TCluster::PreparationForWork(int _MP, int _SizeQ, int _Tacts)
{
	MicroProcessors = _MP;
	Tacts = _Tacts;
	NumberFreeMP = MicroProcessors;//в начале работы все свободны
	masBusyMP = new int[MicroProcessors];//выделение памяти в массиве занятости
	for (int i = 0; i < MicroProcessors; i++)
	{
		masBusyMP[i] = 0;//в начале работы все свободны
	}
	//создание очереди необходимого размера
	TQueue<TTask> WorkQ(_SizeQ);
	//Запуск работы кластера
	Work(WorkQ);
}
//Работа кластера
void TCluster::Work(TQueue<TTask>& _queue)
{
	for (int i = 0; i < Tacts; i++)
	{
		TTask task(MicroProcessors, Tacts);//Создали задачу
		if (task.GetIsCreate() == 2)//задача создалась (не пустая)
		{
			NumberTasks++;
			if ((task.GetNumberProcessors() > MicroProcessors) || (_queue.Full() == true))				
			{
				NumberImpossibleTask++;//задачу невозможно выполнить (нет процессоров или некуда положить на ожидание)
			}
			else
			{
				_queue.AddElQueue(task);//добавили задачу в очередь
			}
		}
		//если есть, что взять из очереди
		if (_queue.Empty() == false)
		{
			int tempMP;
			int tempTact;
			tempMP = _queue.GetTop().GetNumberProcessors();
			tempTact = _queue.GetTop().GetTacts();
			int tempBusyMP = tempMP;
			//если хватит места для выполнения задачи
			if (NumberFreeMP >= tempBusyMP)
			{
				for (int i = 0; i < MicroProcessors; i++)
				{
					if ((masBusyMP[i] == 0) && (tempBusyMP > 0))//Процессор не занят и еще нужны процессоры задаче
					{
						masBusyMP[i] = tempTact + 1;//занимаем процессор
						tempBusyMP--;//необходимые минус 1
					}
					if (tempBusyMP == 0)
					{
						break;
					}
				}
				NumberFreeMP = NumberFreeMP - tempMP;//пересчет свободных согласно только что занятым
				_queue.TakeElQueue().GetNumberProcessors();//задача поставлена на выполнение - забираем из очереди
			}
		}
		//проход по микропроцессорам
		for (int i = 0; i < MicroProcessors; i++)
		{
			if (masBusyMP[i] > 0)//если процессор занят
			{
				masBusyMP[i]--;
				if (masBusyMP[i] == 0)//если процессор освободился
				{
					NumberFreeMP++;//+1 свободный процессор
				}
			}
		}
		BusyMPTact = BusyMPTact + (MicroProcessors - NumberFreeMP);//число занятых процессоров на такте
	}
	NumberNotCompletedTask = _queue.BusyElSize();//сколько задач осталось в очереди
}
//Вывод сбора статистики из работы кластера
void TCluster::GetStatistics()
{
	NumberCompletedTasks = NumberTasks - (NumberNotCompletedTask + NumberImpossibleTask);
	cout << "Число, созданных задач: " <<  NumberTasks << endl;
	cout << "Число, успешно выполненных задач: " << NumberCompletedTasks << endl;
	cout << "Число задач, не успевшых выполниться: " <<  NumberNotCompletedTask << endl;
	cout << "Число невозможных для выполнения задач: " <<  NumberImpossibleTask << endl;
	cout << "Средняя загруженность процессоров: " <<  BusyMPTact / Tacts + 1 << " из " << MicroProcessors << endl;	
}*/