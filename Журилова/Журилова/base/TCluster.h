#ifndef __TCluster_H__
#define __TCluster_H__
/*#include <string>
#include "TQueue.h"
#include "TTask.h"

using namespace std;
class TCluster
{
private:
	int MicroProcessors;//количестов микропроцессоров
	int* masBusyMP;//массив зан€тости процессоров			
	int NumberFreeMP;//количество свободных процессоров		
	int NumberTasks;//количество задач		
	int NumberCompletedTasks;//количество выполненных задач
	int NumberNotCompletedTask;//количество не выполненных задач
	int NumberImpossibleTask;// оличество задач, которые нельз€ выполнить		
	int BusyMPTact;//количество зан€тых процессоров на конкретном такте
	int Tacts;//такты			
public:

	// онструктор
	TCluster() 
	{
		NumberTasks = 0;
		NumberCompletedTasks = 0;
		NumberNotCompletedTask = 0;
		NumberImpossibleTask = 0;
		BusyMPTact = 0;
	}

	//ƒеструктор
	~TCluster()
	{
		if (masBusyMP != nullptr)//если массив был не пуст
		{
			delete[]  masBusyMP;
		}
	}

	//ѕодготовительные действи€ перед запуском кластера
	void PreparationForWork(int _MP, int _SizeQ, int _Tacts);

	//–абота кластера
	void Work(TQueue<TTask>& _queue);

	//¬озврат статистики
	void GetStatistics();
};*/
#endif