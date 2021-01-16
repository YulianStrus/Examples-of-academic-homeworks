#pragma once;
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int**Create(int**mas, int row, int col);
void RandAdd(int ** mas, int row, int col);
void ShowMas(int**mas, int row, int col);
void DelArr(int**mas, int row, int col);
int** AddRowToArr(int **mas, int &row, int col);


void main()
{
	int row = 4, col = 4;
	int **mas = new int*;
	mas = Create(mas, row, col);
	RandAdd(mas, row, col);
	ShowMas(mas, row, col);
	cout << "\nNew matrix:" << endl;
	mas = AddRowToArr(mas, row, col);
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

int** AddRowToArr(int **mas, int &row, int col)
{
	int **temp = new int*;
	temp = Create(temp, row + 1, col);
	
	srand(time(NULL));
	for (int j = 0; j < col; ++j)
		temp[0][j] = rand() % 9;

	for (int i = 1; i <= row; ++i)
		for (int j = 0; j < col; ++j)
			temp[i][j] = mas[i-1][j];

	DelArr(mas, row, col);

	++row; mas = new int*[row];
	for (int count = 0; count < row; count++)
		mas[count] = new int[col];

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			mas[i][j] = temp[i][j];
	DelArr(temp, row, col);
	return mas;
}