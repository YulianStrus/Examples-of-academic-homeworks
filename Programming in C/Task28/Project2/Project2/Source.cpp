#include"iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

void RandMas(int *p_A, int size)
{
	int x = 5, y = -5, srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		*p_A = rand() % (x - y) + y;
		cout << *p_A << " ";
		*p_A++;
	}
}

int NullMas(int *p_A, int size, int ref_Null)
{
	for (int i = 0; i < size; i++)
	{
		if (*p_A == 0) ref_Null++;
		*p_A++;
	}

	return ref_Null;
}

int PosMas(int *p_A, int size, int ref_Pos)
{
	for (int i = 0; i < size; i++)
	{
		if (*p_A > 0) ref_Pos++;
		*p_A++;
	}

	return ref_Pos;
}

int NegMas(int *p_A, int size, int ref_Neg)
{
	for (int i = 0; i < size; i++)
	{
		if (*p_A < 0) ref_Neg++;
		*p_A++;
	}

	return ref_Neg;
}



void main()
{
	const int size = 20;
	int A[size];
	int Sum = 0, Pos=0, Neg=0;
	int &ref_Null = Sum;
	int &ref_Pos = Pos;
	int &ref_Neg = Neg;
	int Prod = 1;
	int &ref_Prod = Prod;
	int *p_A = &A[0];
	RandMas(p_A, size);
	cout << endl;
	cout << "Number of zero elements = " << NullMas(p_A, size, ref_Null) << endl;
	cout << "Number of positive elements = " << PosMas(p_A, size, ref_Pos) << endl;
	cout << "Number of negative items = " << NegMas(p_A, size, ref_Neg) << endl;

	system("pause");
}