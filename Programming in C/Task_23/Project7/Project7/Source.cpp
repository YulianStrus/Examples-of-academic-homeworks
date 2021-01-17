#pragma once;
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int**Create(int**mas, int row, int col);
void RandAdd(int ** mas, int row, int col);
void ShowMas(int**mas, int row, int col);
void DelArr(int**mas, int row, int col);
int** RolRowToUp(int **mas, int &row, int col, int n);
int** RolRowToDown(int **mas, int &row, int col, int n);
int** RolColToRight(int **mas, int &row, int col, int n);
int** RolColToLeft(int **mas, int &row, int col, int n);

void main()
{
	int row = 6, col = 6, n, a;
	int **mas = new int*;
	mas = Create(mas, row, col);
	RandAdd(mas, row, col);
	ShowMas(mas, row, col);
	cout << "Enter number:" << endl;
	cout << "1 - Row Up:" << "\n2 - Row Down:" << "\n3 - Col Right:" << "\n4 - Col Left:" << endl;
	cin >> a;
	switch (a)
	{
	case 1:
		cout << "Enter number position (1-6):" << endl;
		cin >> n;
		if ((n >= 0)&(n <= 6))
		{
			mas = RolRowToUp(mas, row, col, n);
			ShowMas(mas, row, col);
		}
		else cout << "Error!" << endl;
		break;
	case 2:
		cout << "Enter number position (1-6):" << endl;
		cin >> n;
		if ((n >= 0)&(n <= 6))
		{
		mas = RolRowToDown(mas, row, col, n);
		ShowMas(mas, row, col);
		}
		else cout << "Error!" << endl;
		break;
	case 3:
		cout << "Enter number position (1-6):" << endl;
		cin >> n;
		if ((n >= 0)&(n <= 6))
		{
		mas = RolColToRight(mas, row, col, n);
		ShowMas(mas, row, col);
		}
		else cout << "Error!" << endl;
		break;
	case 4:
		cout << "Enter number position (1-6):" << endl;
		cin >> n;
		if ((n >= 0)&(n <= 6))
		{
		mas = RolColToLeft(mas, row, col, n);
		ShowMas(mas, row, col);
		}
		else cout << "Error!" << endl;
		break;
	default : cout << "Erorr!" << endl;
	}

	DelArr(mas, row, col);
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

int** RolRowToUp(int **mas, int &row, int col, int n)
{
	int **temp = new int*;
	temp = Create(temp, row, col);


	for (int i = 0; i + n < row; ++i)
		for (int j = 0; j < col; ++j)
			temp[i][j] = mas[i + n][j];

	for (int i = (row - n); i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
				temp[i][j] = mas[(i + n) - row][j];
		}
	}


	DelArr(mas, row, col);

	mas = Create(mas, row, col);

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			mas[i][j] = temp[i][j];
	DelArr(temp, row, col);
	return mas;
}

int** RolRowToDown(int **mas, int &row, int col, int n)
{
	int **temp = new int*;
	temp = Create(temp, row, col);


	for (int i = n; i < row; ++i)
		for (int j = 0; j < col; ++j)
			temp[i][j] = mas[i - n][j];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			temp[i][j] = mas[row - n + i][j];
		}
	}

	DelArr(mas, row, col);

	mas = Create(mas, row, col);

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			mas[i][j] = temp[i][j];
	DelArr(temp, row, col);
	return mas;
}

int** RolColToRight(int **mas, int &row, int col, int n)
{
	int **temp = new int*;
	temp = Create(temp, row, col);


	for (int i = 0; i < row; ++i)
		for (int j = n; j < col; ++j)
			temp[i][j] = mas[i][j - n];

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			temp[i][j] = mas[i][col - n + j];
		}
	}

	DelArr(mas, row, col);

	mas = Create(mas, row, col);

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			mas[i][j] = temp[i][j];
	DelArr(temp, row, col);
	return mas;
}
int** RolColToLeft(int **mas, int &row, int col, int n)
{
	int **temp = new int*;
	temp = Create(temp, row, col);


	for (int i = 0; i < row; ++i)
		for (int j = 0; j + n < col; ++j)
			temp[i][j] = mas[i][j + n];

	for (int i = 0; i < row; ++i)
	{
		for (int j = (row - n); j < col; ++j)
		{
			temp[i][j] = mas[i][(j + n) - col];
		}
	}


	DelArr(mas, row, col);

	mas = Create(mas, row, col);

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			mas[i][j] = temp[i][j];
	DelArr(temp, row, col);
	return mas;
}