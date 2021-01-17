#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()
{
	//1
	const int size = 10;
	int arr[size];
	int Dob = 1;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter element [" << i << "] = "; cin >> arr[i]; cout << endl;
		Dob *= arr[i];
	}
	cout << "Product elements of the array = " << Dob << endl;

	system("pause");
}