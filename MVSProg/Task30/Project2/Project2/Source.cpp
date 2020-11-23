#pragma once;
#include "iostream"
using namespace std;

int* RandMas(int* mas, int size)
{
	for (int i = 0; i < size; i++)
		mas[i] = rand() % 10;
	return mas;
}

void CoutMas(int *mas, int size)
{
	for (int i = 0; i < size; i++)
		cout << mas[i] << " ";
	cout << endl;
}

int* AddOneElement(int* mas, int &size, int k)
{

	int *tmp = new int[++size];
	for (int i = 0; i < size-1; i++) 
		tmp[i] = mas[i];
	tmp[size-1] = k;
	delete[]mas;
	mas = new int[size];
	for (int i = 0; i < size; ++i)mas[i] = tmp[i];
	delete[]tmp;
	return mas;
}

int* DelOneElement(int* mas, int &size, int z)
{
	int *tmp = new int[--size];
	for (int i = 0; i < z; i++)
		tmp[i] = mas[i];
	for (int i = z; i < size; i++)
		tmp[i] = mas[i+1];
	delete[]mas;
	mas = new int[size];
	for (int i = 0; i < size; ++i)mas[i] = tmp[i];
	delete[]tmp;
	return mas;
}

int* AddPosElement(int* mas, int &size, int n, int m)
{
	int *tmp = new int[++size];
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
			tmp[i] = mas[i];
		tmp[n] = m;
		for (int i = n; i < size; i++)
			tmp[i + 1] = mas[i];
	}
	else
	{
		tmp[n] = m;
		for (int i = 0; i < size; i++)
			tmp[i + 1] = mas[i];
	}

	delete[]mas;
	mas = new int[size];
	for (int i = 0; i < size; ++i)mas[i] = tmp[i];
	delete[]tmp;
	return mas;
}

int main()
{
	int size = 10;
	int*mas = new int[size];
	RandMas(mas, size);
	CoutMas(mas, size);
	
	int a;
	cout << "Select an action: " << endl;
	cout << "1 - Supplement an array with one element" << endl;
	cout << "2 - Deleting an item at the specified position (0 - 9)" << endl;
	cout << "3 - Insert a new element into an arbitrary position (0 - 9) in the array" << endl;
	cin >> a;

	switch(a)
	{
	case 1:
		int k;
		cout << "Enter add element: ";
		cin >> k;
		AddOneElement(mas, size, k);
		CoutMas(mas, size);
		break;
	case 2:
		int z;
		cout << "Enter position element: ";
		cin >> z;
		if ((z>=0)&(z < size))
		{
			DelOneElement(mas, size, z);
			CoutMas(mas, size);
		}
		else cout << "Error!" << endl;
		break;
	case 3:
		int n, m;
		cout << "Enter number: ";
		cin >> m;
		cout << "Enter position number: ";
		cin >> n;
		if ((n >= 0)&(n < size))
		{
			AddPosElement(mas, size, n, m);
			CoutMas(mas, size);
		}
		else cout << "Error!" << endl;
		break;
	default: cout << "Error!" << endl;
	}

	delete[]mas;

	system("pause");
}