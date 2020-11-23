#pragma once;
#include "iostream"
#include "stdio.h"
#include "time.h"
using namespace std;

int **Create(int **mas, int row, int col);
void RandAdd(int **mas, int row, int col);
void ShowMas(int **mas, int row, int col);
void DelMas(int**mas, int row, int col);

void main()
{
	int row = 10, col = 10;
	int **mas = new int*;
	cout << "Enter number row: ";
	cin >> row;
	cout << "Enter number col: ";
	cin >> col;
	mas = Create(mas, row, col);
	RandAdd(mas, row, col);
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