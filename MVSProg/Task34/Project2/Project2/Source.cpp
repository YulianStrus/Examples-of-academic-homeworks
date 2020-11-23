#pragma once;
#include "iostream"
#include "stdio.h"
#include "time.h"
using namespace std;

int **Create(int **mas, int row, int col);
void RandAdd(int **mas, int row, int col);
void ShowMas(int **mas, int row, int col);
void DelMas(int**mas, int row, int col);
int *TranspMatrix(int **mas, int row, int col, int *A);

void main()
{
	int row = 5, col = 5;
	int **mas = new int*;
	mas = Create(mas, row, col);
	RandAdd(mas, row, col);
	ShowMas(mas, row, col);
	cout << endl;
	int size = row * col;
	int *A = new int [size];
	A=TranspMatrix(mas, row, col, A);
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
	DelMas(mas, row, col);
	delete A;

	system("pause");
}

int **Create(int **mas, int row, int col)
{
	mas = new int*[row];
	for (int i = 0; i < row; i++) mas[i] = new int[col];
	return mas;
}
void RandAdd(int **mas, int row, int col)
{
	srand(time(NULL));
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) mas[i][j] = rand() % 10;
}
void ShowMas(int **mas, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}
}
void DelMas(int**mas, int row, int col)
{
	for (int i = 0; i < row; i++)
		delete[]mas[i];
}
int *TranspMatrix(int **mas, int row, int col, int *A)
{
	int size = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			A[size] = mas[i][j]; size++;
		}
	}
	return A;
}