#ifndef __TCluster_H__
#define __TCluster_H__
/*#include <string>
#include "TQueue.h"
#include "TTask.h"

using namespace std;
class TCluster
{
private:
	int MicroProcessors;//���������� ����������������
	int* masBusyMP;//������ ��������� �����������			
	int NumberFreeMP;//���������� ��������� �����������		
	int NumberTasks;//���������� �����		
	int NumberCompletedTasks;//���������� ����������� �����
	int NumberNotCompletedTask;//���������� �� ����������� �����
	int NumberImpossibleTask;//���������� �����, ������� ������ ���������		
	int BusyMPTact;//���������� ������� ����������� �� ���������� �����
	int Tacts;//�����			
public:

	//�����������
	TCluster() 
	{
		NumberTasks = 0;
		NumberCompletedTasks = 0;
		NumberNotCompletedTask = 0;
		NumberImpossibleTask = 0;
		BusyMPTact = 0;
	}

	//����������
	~TCluster()
	{
		if (masBusyMP != nullptr)//���� ������ ��� �� ����
		{
			delete[]  masBusyMP;
		}
	}

	//���������������� �������� ����� �������� ��������
	void PreparationForWork(int _MP, int _SizeQ, int _Tacts);

	//������ ��������
	void Work(TQueue<TTask>& _queue);

	//������� ����������
	void GetStatistics();
};*/
#endif