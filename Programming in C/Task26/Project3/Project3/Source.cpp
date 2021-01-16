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

	int min = arr[0], k;
	int max = arr[0], l;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < min) {
			min = arr[i]; k = i;
		}
		if (arr[i] > max) {
			max = arr[i]; l = i;
		}
	}
	for (int i = 1; i < size; i++)
	{
		if (i == k) arr[i] = max;
		if (i == l)arr[i] = min;
	}


	for (int i = 0; i < size; i++)
	{
		int *pp_arr = &arr[i];
		cout << *pp_arr << " ";
	}
	cout << endl;



	system("pause");
}