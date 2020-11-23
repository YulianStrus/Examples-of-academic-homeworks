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
void Diagon(T M[10][10], T row, T col)
{
	cout << "Element about the main diagonal: " << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (j > i) cout << M[i][j] << "\t ";
			else cout << "\t ";
		}
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
	Diagon(M, row, col);
	cout << endl;

	system("pause");
}