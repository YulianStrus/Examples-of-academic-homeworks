
#include "iostream"
#include "time.h"
#include "stdlib.h"
using namespace std;

void CreateMas(int *mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		mas[i] = rand() % 20; cout << mas[i] << " ";
	}
	cout << endl;
}

void CompresMas (int *mas, int size, int k)
{
	size = k;
	int *tmp = new int[size];
	for (int i = 0; i < size; i++)
		tmp[i] = mas[i];
	delete[] mas;
	size = k;
	mas = new int[size];
	for (int i = 0; i < size; i++)
		mas[i] = tmp[i];
	delete[] tmp;
	for (int i = 0; i < size; i++) cout << mas[i] << " ";
}

void main()
{
	const int size = 20;
	int *mas = new int [size];
	CreateMas(mas, size);
	int k;
	cout << "Enter position number: " << endl;
	cin >> k;
	if (k > size) cout << "Error!!!" << endl;
	else	CompresMas(mas, size, k);
	cout << endl;

	system("pause");
}