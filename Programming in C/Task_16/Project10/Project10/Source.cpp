#include "Header.h"

void RandArr(int arr[], int size)
{
	int i = 0;
	for (int i = 0; i < size; ++i) arr[i] = rand() % 20;
	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
	cout << endl;
}

void BubbleSortP(int arr[], int size)
{
	int temp;
	bool change = true;
	while (change)
	{
		change = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				change = true;
			}
		}
	}
	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
}

void BubbleSortM(int arr[], int size)
{
	int temp;
	bool change = true;
	while (change)
	{
		change = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (arr[i] < arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				change = true;
			}
		}
	}
	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
}

void InsertSortP(int arr[], int size)
{
	int tmp, min;
	for (int i = 0; i < size - 1; ++i)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min]) min = j;
		}
		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
	}

	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
}

void InsertSortM(int arr[], int size)
{
	int tmp, min;
	for (int i = 0; i < size - 1; ++i)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] > arr[min]) min = j;
		}
		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
	}

	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
}

void TranspSortP(int arr[], int size)
{
	int tmp;
	for (int i = 1; i < size; ++i)
	{
		tmp = arr[i];
		for (int j = i - 1; j >= 0 & arr[j] > tmp; j--)
		{
			arr[j + 1] = arr[j];
			arr[j] = tmp;
		}
	}

	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
}

void TranspSortM(int arr[], int size)
{
	int tmp;
	for (int i = 1; i < size; ++i)
	{
		tmp = arr[i];
		for (int j = i - 1; j >= 0 & arr[j] < tmp; j--)
		{
			arr[j + 1] = arr[j];
			arr[j] = tmp;
		}
	}

	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
}


void BubbleSortP(double arr[], double size)
{
	int temp;
	bool change = true;
	while (change)
	{
		change = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				change = true;
			}
		}
	}
	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
}

void BubbleSortM(double arr[], double size)
{
	int temp;
	bool change = true;
	while (change)
	{
		change = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (arr[i] < arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				change = true;
			}
		}
	}
	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
}

void InsertSortP(double arr[], double size)
{
	int tmp, min;
	for (int i = 0; i < size - 1; ++i)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min]) min = j;
		}
		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
	}

	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
}

void InsertSortM(double arr[], double size)
{
	int tmp, min;
	for (int i = 0; i < size - 1; ++i)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] > arr[min]) min = j;
		}
		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
	}

	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
}

void TranspSortP(double arr[], double size)
{
	int tmp;
	for (int i = 1; i < size; ++i)
	{
		tmp = arr[i];
		for (int j = i - 1; j >= 0 & arr[j] > tmp; j--)
		{
			arr[j + 1] = arr[j];
			arr[j] = tmp;
		}
	}

	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
}

void TranspSortM(double arr[], double size)
{
	int tmp;
	for (int i = 1; i < size; ++i)
	{
		tmp = arr[i];
		for (int j = i - 1; j >= 0 & arr[j] < tmp; j--)
		{
			arr[j + 1] = arr[j];
			arr[j] = tmp;
		}
	}

	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
}