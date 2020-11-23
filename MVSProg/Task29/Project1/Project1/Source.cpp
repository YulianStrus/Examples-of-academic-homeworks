#pragma once;
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int* Create(int *mas, int size)
{

	mas = new int[size];
	return mas;

}
void CinArray(int *mas, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << "Enter " << i << " number: ";
		cin >> mas[i];
	}
}
void RandArray(int *mas, int size)
{
	srand(time(0));
	for (int i = 0; i < size; ++i)
		mas[i] = rand() % 10;
}
void CoutArray(int *mas, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
}
void DelArray(int *mas)
{
	delete[]mas;
}
int* CompresArray(int *mas, int &size, int k)
{
	int z = 0;
	for (int i = 0; i < size; i++)
		if (mas[i] == k) z++;
	
	int *temp = new int;
	temp = Create(temp, size);
	int j = 0;
	for (int i = 0; i < size; ++i)
		if (mas[i] != k)
		{
			temp[j] = mas[i]; j++;
		}
		else { temp[j] = temp[i]; }
	DelArray(mas);
	size = size - z;
	mas = new int[size];
	for (int i = 0; i < size; ++i)mas[i] = temp[i];
	DelArray(temp);
	return mas;
}
void CreateBlok(int *arr, int size_a)
{
	for (int i = 0; i < size_a; ++i)
	{
		cout << "Enter " << i << " number: ";
		cin >> arr[i];
	}
}
int* AddBlockToArray(int *mas, int size, int *arr, int size_a, int n)
{
	
	int *tmp = new int;
	tmp = new int[size];
	for (int i = 0; i < n; i++) tmp[i] = mas[i];
	for (int i = 0; i < size_a; i++) tmp[i + n] = arr[i];
	for (int i = n; i < size-size_a; i++) tmp[i + size_a] = mas[i];
	DelArray(mas);
	mas = new int[size];
	for (int i = 0; i < size; ++i)mas[i] = tmp[i];
	DelArray(tmp);
	return mas;
}

int* DeleteBlockFromArray(int *mas, int size, int z, int w)
{
	int *tmp = new int;
	tmp = new int[size];
	for (int i = 0; i < w; i++) tmp[i] = mas[i];
	for (int i = w; i < size; i++) tmp[i] = mas[i+z];
	DelArray(mas);
	mas = new int[size];
	for (int i = 0; i < size; ++i)mas[i] = tmp[i];
	DelArray(tmp);
	return mas;
}

void main()
{
	int size = 5;
	int *mas = new int;
	mas = Create(mas, size);
	int size_a = 10;
	int *arr = new int;
	int k, n;
	cout << endl;
	cout << "CinArray:" << endl;
	CinArray(mas, size);
	cout << "The array is full of keyboard: " << endl;
	CoutArray(mas, size);
	DelArray(mas);

	cout << endl;
	cout << "RandArray:" << endl;
	size = 20;
	mas = Create(mas, size);
	RandArray(mas, size);
	cout << "The array is filled with random numbers: " << endl;
	CoutArray(mas, size);
	
	cout << endl;
	cout << "CompresArray:" << endl;
	cout << "Enter number: ";
	cin >> k;
	cout << "Array with new del element:" << endl;
	mas = CompresArray(mas, size, k);
	CoutArray(mas, size);

	cout << endl;
	cout << "AddBlockToArray:" << endl;
	cout << "Enter the value of the blok: ";
	cin >> size_a;
	CreateBlok(arr, size_a);
	for (int i = 0; i < size_a; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Enter insertion position: ";
	cin >> n;
	cout << "Array with new add element:" << endl;
	size = size + size_a;
	mas = AddBlockToArray(mas, size, arr, size_a, n);
	CoutArray(mas, size);

	cout << endl;
	cout << "DeleteBlockFromArray:" << endl;
	int z=5, w;
	cout << "Enter the value of the blok: ";
	cin >> z;
	cout << "Enter delete position: ";
	cin >> w;
	size = size - z;
	mas = DeleteBlockFromArray(mas, size, z, w);
	CoutArray(mas, size);

	DelArray(mas);

	system("pause");
}