#include "iostream"
#include "stdlib.h"
#include "conio.h"
#include "string.h"
using namespace std;
char** Create(char **mas, int row, int size);
void RandArr(char **mas, int row, int size);
void ShowArr(char **mas, int row);
void DelArr(char **mas, int row);
void MaxName(char **mas, int row);
char** SortName(char **mas, int row, int size);

void main()
{
	int row;
	cout << "Enter number surnames: " << endl;
	cin >> row;
	cin.ignore();
	int size = 128;
	char **mas = new char*;
	mas = Create(mas, row, size);
	RandArr(mas, row, size);
	MaxName(mas, row);
	cout << "\nSort array: " << endl;
	mas = SortName(mas, row, size);
	ShowArr(mas, row);
	DelArr(mas, row);
	system("pause");
}

char** Create(char **mas, int row, int size)
{
	mas = new char*[row];
	for (int i = 0; i < row; ++i)
		mas[i] = new char[size];
	return mas;
}

void RandArr(char **mas, int row, int size)
{
	for (int i = 0; i < row; ++i)
	{
		cout << "Please enter the " << i + 1 << " surname:   ";
		gets_s(mas[i], size);
	}
}

void ShowArr(char **mas, int row)
{
	for (int i = 0; i < row; ++i)
		cout << mas[i] << endl;
}

void DelArr(char **mas, int row)
{
	for (int i = 0; i < row; ++i)
		delete[]mas[i];
}

void MaxName(char **mas, int row)
{
	int max = 0, tmp, num;
	for (int i = 0; i < row; i++)
	{

		tmp = strlen(mas[i]);
		if (tmp > max)
		{
			max = tmp;
			num = i;
		}
	}
	cout << "\nLongest last name: " << mas[num] << endl;

}

char** SortName(char **mas, int row, int size)
{
	char tmp[50];
	bool chg = true;
	while (chg)
	{
		chg = false;
		for (int i = 0; i < row-1; i++)
		{
			if (strlen(mas[i]) > strlen(mas[i + 1]))
			{
				strcpy(tmp, mas[i]);
				strcpy(mas[i], mas[i + 1]);
				strcpy(mas[i + 1], tmp);
				chg = true;
			}
		}
	}
	return mas;
}