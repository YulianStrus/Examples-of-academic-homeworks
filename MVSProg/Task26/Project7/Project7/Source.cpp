#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()
{
	const int size = 20;
	int arr[size];
	int *p_arr = &arr[0];
	int x = 12, y = 1, srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		*p_arr = rand() % (x - y) + y;
		cout << *p_arr << " ";
		++p_arr;
	}
	cout << endl;


	double Sum2 = 0, Sum3 = 0, Sum4 = 0, Sum5 = 0;
	
	for (int i = 0; i < size; i++)
	{
		int *parr = &arr[i];
		if ((*parr == 1) | (*parr == 2) | (*parr == 3)) Sum2++;
	}
	if (Sum2==0) cout << "Score 2 = 0 %" << endl;
	else {
		double Sc2 = (Sum2 / size) * 100;
		cout << "Score 2 = " << Sc2 << " %" << endl;
	}

	for (int i = 0; i < size; i++)
	{
		int *parr = &arr[i];
		if ((*parr == 4) | (*parr == 5) | (*parr == 6))Sum3++;
	}
	if (Sum3 == 0) cout << "Score 3 = 0 %" << endl;
	else {
		double Sc3 = (Sum3 / size) * 100;
		cout << "Score 3 = " << Sc3 << " %" << endl;
	}
	for (int i = 0; i < size; i++)
	{
		int *parr = &arr[i];
		if ((*parr == 7) | (*parr == 8) | (*parr == 9)) Sum4++;
	}
	if (Sum4 == 0) cout << "Score 4 = 0 %" << endl;
	else {
		double Sc4 = (Sum4 / size) * 100;
		cout << "Score 4 = " << Sc4 << " %" << endl;
	}
	for (int i = 0; i < size; i++)
	{
		int *parr = &arr[i];
		if ((*parr == 10) | (*parr == 11) | (*parr == 12)) Sum5++;
	}
	if (Sum5 == 0) cout << "Score 5 = 0 %" << endl;
	else {
		double Sc5 = (Sum5 / size) * 100;
		cout << "Score 5 = " << Sc5 << " %" << endl;
	}

	system("pause");
}