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

	
	int Sum = 0;
	for (int i = 0; i < size ; i++)
	{
		int *parr = &arr[i];
		if (i % 2 != 0) Sum+=*parr;
	}

	cout << "The sum of items with odd numbers = " << Sum << endl;



	system("pause");
}