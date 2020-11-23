#pragma once;
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int**Create(int**mas, int row, int col);
void RandAdd(int ** mas, int row, int col);
void ShowMas(int**mas, int row, int col);
void DelArr(int**mas, int row, int col);
int** AddRowToArr(int **mas, int &row, int col, int n);


void main()
{
	int row = 6, col = 6, n;
	int **mas = new int*;
	mas = Create(mas, row, col);
	RandAdd(mas, row, col);
	ShowMas(mas, row, col);
	cout << "Enter number position:" << endl;
	cin >> n;
	cout << "\nNew matrix:" << endl;
	mas = AddRowToArr(mas, row, col, n);
	ShowMas(mas, row, col);

	system("pause");
}

int **Create(int **mas, int row, int col)
{
	mas = new int*[row];
	for (int i = 0; i < row; i++) mas[i] = new int[col];
	return mas;
}

void RandAdd(int ** mas, int row, int col)
{
	srand(time(NULL));
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)mas[i][j] = rand() % 10;
}

void ShowMas(int**mas, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) cout << mas[i][j] << " ";
		cout << endl;
	}
}

void DelArr(int**mas, int row, int col)
{
	for (int i = 0; i < row; i++) delete[]mas[i];
}

int** AddRowToArr(int **mas, int &row, int col, int n)
{
	int **temp = new int*;
	temp = Create(temp, row - 1, col);
	if (n == 0)
	{
		for (int i = 1; i < row; ++i)
			for (int j = 0; j < col; ++j)
				temp[i-1][j] = mas[i][j];
	}

	else
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < col; ++j)
				temp[i][j] = mas[i][j];

		for (int i = n; i < row-1; ++i)
			for (int j = 0; j < col; ++j)
				temp[i][j] = mas[i+1][j];
	}

	DelArr(mas, row, col);

	--row; mas = new int*[row];
	for (int count = 0; count < row; count++)
		mas[count] = new int[col];

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			mas[i][j] = temp[i][j];
	DelArr(temp, row, col);
	return mas;
}