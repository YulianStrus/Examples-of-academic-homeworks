#include "iostream"
using namespace std;

void RandMas(int M[3][4], int row, int col)
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

void TransMas(int M[3][4], int row, int col, int k)
{
	for (int i = 0; i < row; i++)
	{
		int n = M[i][3];
		for (int j = col-1; j > k; j--)
			M[i][j] = M[i][j-1];
		M[i][k] = n;
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
	const int row = 3;
	const int col = 4;
	int M[row][col];
	RandMas(M, row, col);
	cout << endl;
	int k = 1;
	TransMas(M, row, col, k);

	system("pause");
}