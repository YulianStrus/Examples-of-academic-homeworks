#include "iostream"
using namespace std;
void main()
{
	const int size = 10;
	int arr[size];
	int *p_arr = &arr[0];
	for (int i = 0; i < size; i++)
	{
		*p_arr = rand() % 20;
		cout << *p_arr << " ";
		++p_arr;
	}
	cout << endl;

	int *parr = &arr[size / 2];
	for (int i = 0; i < size/2; i++)
	{
		int tmp = arr[i];
		arr[i] = *parr;
		*parr = tmp;
		parr++;
	}
	   
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;


	system("pause");
}