#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

template <typename T>

void Matrix(T M[10][10], T row, T col)
{
	int x = 10, y = -10, srand(time(NULL));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			M[i][j] = rand() % (x - y) + y;
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << M[i][j] << "\t ";
		cout << endl;
	}
}

template <typename T>
void SumCol(T M[10][10], T row, T col)
{
	
	for (int i = 0; i < row; i++)
	{
		int Sum = 0;
		for (int j = 0; j < col; j++)
			Sum += M[i][j];
		cout << "Sum " << i << " column = " << Sum ;
		cout << endl;
	}
}

int main()
{
	const int row = 10;
	const int col = 10;
	int M[row][col];
	Matrix(M, row, col);
	cout << endl;
	SumCol(M, row, col);
	

	system("pause");
}