#pragma once;
#include "iostream"
#include "stdio.h"
#include "time.h"
using namespace std;

int **Create(int **mas, int row, int col);
void RandAdd(int **mas, int row, int col);
void ShowMas(int **mas, int row, int col);
void DelMas(int**mas, int row, int col);
int** AddRowToArr(int **mas, int &row, int col);

void main()
{
	int row = 5, col = 5;
	int **mas = new int*;
	mas = Create(mas, row, col);
	RandAdd(mas, row, col);
	ShowMas(mas, row, col);
	cout << "\nNew mas:" << endl;
	mas = AddRowToArr(mas, row, col);
	ShowMas(mas, row, col);
	DelMas(mas, row, col);

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
int** AddRowToArr(int **mas, int &row, int col)
{
	int **temp = new int*;
	temp = Create(temp, row + 1, col);

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			temp[i][j] = mas[i][j];

	srand(time(0));
	for (int j = 0; j < col; ++j)
		temp[row][j] = rand() % 10;

	DelMas(mas, row, col);

	++row; mas = new int*[row];
	for (int count = 0; count < row; count++)
		mas[count] = new int[col];

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			mas[i][j] = temp[i][j];
	DelMas(temp, row, col);
	return mas;
}