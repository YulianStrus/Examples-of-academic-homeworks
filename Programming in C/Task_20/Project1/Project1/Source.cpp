#include"iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

void RandMas(int *p_A, int size)
{
	int x = 15, y = -15, srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		*p_A = rand() % (x - y) + y;
		cout << *p_A << " ";
		*p_A++;
	}
}

int SumMas(int *p_A, int size, int ref_Sum)
{
	for (int i = 0; i < size; i++)
	{
		ref_Sum += *p_A;
		*p_A++;
	}
	
	return ref_Sum;
}

int ProdMas(int *p_A, int size, int ref_Prod)
{
	
	for (int i = 0; i < size; i++)
	{
		ref_Prod *= *p_A;
		*p_A++;
	}

	return ref_Prod;
}


void main()
{
	const int size = 10;
	int A[size];
	int Sum = 0;
	int &ref_Sum = Sum;
	int Prod = 1;
	int &ref_Prod = Prod;
	int *p_A = &A[0];
	RandMas(p_A, size);
	cout << endl;
	cout << SumMas(p_A, size, ref_Sum) << endl;
	cout << ProdMas(p_A, size, ref_Prod) << endl;

	system("pause");
}