/*#include "TCluster.h"
#include <iostream>
#include <ctime>
#include <string>
using namespace std;
//���������� �������� � ������
void TCluster::PreparationForWork(int _MP, int _SizeQ, int _Tacts)
{
	MicroProcessors = _MP;
	Tacts = _Tacts;
	NumberFreeMP = MicroProcessors;//� ������ ������ ��� ��������
	masBusyMP = new int[MicroProcessors];//��������� ������ � ������� ���������
	for (int i = 0; i < MicroProcessors; i++)
	{
		masBusyMP[i] = 0;//� ������ ������ ��� ��������
	}
	//�������� ������� ������������ �������
	TQueue<TTask> WorkQ(_SizeQ);
	//������ ������ ��������
	Work(WorkQ);
}
//������ ��������
void TCluster::Work(TQueue<TTask>& _queue)
{
	for (int i = 0; i < Tacts; i++)
	{
		TTask task(MicroProcessors, Tacts);//������� ������
		if (task.GetIsCreate() == 2)//������ ��������� (�� ������)
		{
			NumberTasks++;
			if ((task.GetNumberProcessors() > MicroProcessors) || (_queue.Full() == true))				
			{
				NumberImpossibleTask++;//������ ���������� ��������� (��� ����������� ��� ������ �������� �� ��������)
			}
			else
			{
				_queue.AddElQueue(task);//�������� ������ � �������
			}
		}
		//���� ����, ��� ����� �� �������
		if (_queue.Empty() == false)
		{
			int tempMP;
			int tempTact;
			tempMP = _queue.GetTop().GetNumberProcessors();
			tempTact = _queue.GetTop().GetTacts();
			int tempBusyMP = tempMP;
			//���� ������ ����� ��� ���������� ������
			if (NumberFreeMP >= tempBusyMP)
			{
				for (int i = 0; i < MicroProcessors; i++)
				{
					if ((masBusyMP[i] == 0) && (tempBusyMP > 0))//��������� �� ����� � ��� ����� ���������� ������
					{
						masBusyMP[i] = tempTact + 1;//�������� ���������
						tempBusyMP--;//����������� ����� 1
					}
					if (tempBusyMP == 0)
					{
						break;
					}
				}
				NumberFreeMP = NumberFreeMP - tempMP;//�������� ��������� �������� ������ ��� �������
				_queue.TakeElQueue().GetNumberProcessors();//������ ���������� �� ���������� - �������� �� �������
			}
		}
		//������ �� ����������������
		for (int i = 0; i < MicroProcessors; i++)
		{
			if (masBusyMP[i] > 0)//���� ��������� �����
			{
				masBusyMP[i]--;
				if (masBusyMP[i] == 0)//���� ��������� �����������
				{
					NumberFreeMP++;//+1 ��������� ���������
				}
			}
		}
		BusyMPTact = BusyMPTact + (MicroProcessors - NumberFreeMP);//����� ������� ����������� �� �����
	}
	NumberNotCompletedTask = _queue.BusyElSize();//������� ����� �������� � �������
}
//����� ����� ���������� �� ������ ��������
void TCluster::GetStatistics()
{
	NumberCompletedTasks = NumberTasks - (NumberNotCompletedTask + NumberImpossibleTask);
	cout << "�����, ��������� �����: " <<  NumberTasks << endl;
	cout << "�����, ������� ����������� �����: " << NumberCompletedTasks << endl;
	cout << "����� �����, �� �������� �����������: " <<  NumberNotCompletedTask << endl;
	cout << "����� ����������� ��� ���������� �����: " <<  NumberImpossibleTask << endl;
	cout << "������� ������������� �����������: " <<  BusyMPTact / Tacts + 1 << " �� " << MicroProcessors << endl;	
}*/