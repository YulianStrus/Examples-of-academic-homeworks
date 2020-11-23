#include "iostream"
using namespace std;

void RandMas(int M[4][5], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			M[i][j] = rand() % 10;
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
}

void TransMas(int M[4][5], int row, int col, int k)
{
	for (int j = 0; j < col; j++)
	{
		int n = M[0][j];
		for (int i = 0; i < k; i++)
			M[i][j] = M[i + 1][j];
		M[k][j] = n;
	}


	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	const int row = 4;
	const int col = 5;
	int M[row][col];
	RandMas(M, row, col);
	cout << endl;
	int k = 2;
	TransMas(M, row, col, k);

	system("pause");
}