#include "iostream"
using namespace std;
void main()
{
	const int size = 10;
	int arr[size];
	int *p_arr = &arr[0];
	int k=0;
	for (int i = 0; i < size; i++)
	{
		*p_arr = rand() % 20;
		cout << *p_arr << " ";
		++p_arr;		
	}
	cout << endl;
	
	for (int i = size - 1; i >= 0; i--)
	{
		int *pp_arr = &arr[i];
		cout << *pp_arr << " ";
	}
	cout << endl;

	int *ppp_arr = &arr[0];
	for (int i = 1; i < size; i++)
	{
		*ppp_arr += arr[i];
	}
	cout << "Sum = " <<*ppp_arr << endl;
	
	system("pause");
}