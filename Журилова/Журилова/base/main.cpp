#include "TCluster.h"
#include "Monomial.h"
#include <iostream>
#include <string>
#define MAXsizeQ 100

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Monomial mon(1, 2, 3, 4);
	Monomial m;
	m = mon;
	int exit;
	if (m == mon)
	{
		cout << "круть" << endl;
	}
	else
	{
		cout << "хрень какая-то" << endl;
	}
	cin >> exit;
	/*int number_of_processors;

	int tacts;

	cout << " Enter count of processors " << endl;
	cin >> number_of_processors;
	cout << endl;

	cout << "Enter count of tacts" << endl;
	cin >> tacts;
	cout << endl;

	TCluster cluster;
	cluster.PreparationForWork(number_of_processors, MAXsizeQ, tacts);
	cluster.GetStatistics();*/
}