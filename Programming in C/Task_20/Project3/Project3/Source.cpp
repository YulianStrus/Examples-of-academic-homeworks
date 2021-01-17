#include"iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

void RandMas(int *p_A, int row, int col)
{
	int x = 5, y = -5, srand(time(NULL));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			*p_A = rand() % (x - y) + y;
			cout << *p_A << "\t ";
			*p_A++;
		}
		cout << endl;
	}
}

double SumMas(int *p_A, int row, int col, double ref_SA)
{
	double Sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			Sum += *p_A;
			*p_A++;
		}
	}
	ref_SA = Sum / (row*col);

	return ref_SA;
}

int PosMas(int *p_A, int row, int col, int ref_Pos)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (*p_A % 2 == 0) ref_Pos++;
			*p_A++;
		}
	}

	return ref_Pos;
}

int NegMas(int *p_A, int row, int col, int ref_Neg)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (*p_A % 2 != 0) ref_Neg++;
			*p_A++;
		}
	}

	return ref_Neg;
}



void main()
{
	const int row = 10;
	const int col = 10;
	int M[row][col];
	double SA = 0;
	int	Pos = 0, Neg = 0;
	double &ref_SA = SA;
	int &ref_Pos = Pos;
	int &ref_Neg = Neg;
	int Prod = 1;
	int &ref_Prod = Prod;
	int *p_A = &M[0][0];
	RandMas(p_A, row, col);
	cout << endl;
	cout << "Average arithmetic elements = " << SumMas(p_A, row, col, ref_SA) << endl;
	cout << "Number of paired items = " << PosMas(p_A, row, col, ref_Pos) << endl;
	cout << "Number of odd elements = " << NegMas(p_A, row, col, ref_Neg) << endl;


	system("pause");
}