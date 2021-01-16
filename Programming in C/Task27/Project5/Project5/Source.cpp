#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

void CreateMas(int *p_M, int size)
{
	int x = 10, y = -10;
	for (int i = 0; i < size; i++)
	{
		p_M[i] = rand() % (x - y) + y; cout << p_M[i] << " ";
	}
	cout << endl;
}

void ChangeMas(int *p_M, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (p_M[i] < 0) p_M[i] = 0; cout << p_M[i] << " ";
	}
	cout << endl;
}

void main()
{
	const int size = 20;
	int M[size];
	int *p_M = &M[0];
	CreateMas(p_M, size);
	ChangeMas(p_M, size);

	system("pause");
}