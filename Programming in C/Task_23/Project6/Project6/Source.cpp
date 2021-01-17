#pragma once;
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int**Create(int**mas, int row, int col);
void RandAdd(int ** mas, int row, int col);
void ShowMas(int**mas, int row, int col);
void DelArr(int**mas, int row, int col);
int** AddColToArr(int **mas, int &row, int col, int n);


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
	mas = AddColToArr(mas, row, col, n);
	col--;
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

int** AddColToArr(int **mas, int &row, int col, int n)
{
	int **temp = new int*;
	temp = Create(temp, row , col - 1);
	if (n == 0)
	{
		for (int i = 0; i < row; ++i)
			for (int j = 1; j < col; ++j)
				temp[i][j-1] = mas[i][j];
	}

	else
	{
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < n; ++j)
				temp[i][j] = mas[i][j];

		for (int i = 0; i < row; ++i)
			for (int j = n; j < col-1; ++j)
				temp[i][j] = mas[i][j+1];
	}

	DelArr(mas, row, col);

	mas = Create(mas, row, col - 1);

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			mas[i][j] = temp[i][j];
	DelArr(temp, row, col);
	return mas;
}