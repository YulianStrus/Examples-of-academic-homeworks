#include<iostream>
#include <thread>

using namespace std;

void Matrix(int **matrix, int row, int col)
{
	srand(time(NULL));
	for (int i = 0; i < row; ++i)
		for (int k = 0; k < col; ++k)
			matrix[i][k] = rand() % 9 + 1;
	for (int i = 0; i < row; ++i)
	{
		for (int k = 0; k < col; ++k)
			cout << matrix[i][k] << " ";
		cout << endl;
	}
	cout << endl << endl;
}

void SumDiag(int **matrix, int row, int col)
{
	int count = 0;
	int sum = 0;
	for (int i = 0; i < row; ++i)
	{
		for (int k = 0; k < col; ++k)
		{
			if (k > count)
				sum += matrix[i][k];
		}
		count++;
	}
	cout << "The sum of the numbers above is mainly diagonal = " << sum << endl << endl;
}

void MultDiag(int **matrix, int row, int col)
{
	int count = row - 1;
	unsigned long long int mult = 1;
	for (int i = 0; i < row; ++i)
	{
		for (int k = 0; k < col; ++k)
		{
			if (k > count)
				mult *= matrix[i][k];
		}
		--count;
	}
	cout << "The product of numbers below the lateral diagonal = " << mult << endl << endl;
}

int main(void)
{
	int row = 9;
	int col = 9;
	int **matrix = new int*[row];
	for (int i = 0; i < row; ++i)
		matrix[i] = new int[col];

	thread th1(Matrix, matrix, row, col);
	if (th1.joinable())th1.join();
	else th1.detach();

	thread th2(SumDiag, matrix, row, col);
	if (th2.joinable())th2.join();
	else th2.detach();

	thread th3(MultDiag, matrix, row, col);
	if (th3.joinable())th3.join();
	else th3.detach();

	for (int i = 0; i < row; ++i)
		delete[]matrix[i];
	delete[]matrix;

	system("pause");
}