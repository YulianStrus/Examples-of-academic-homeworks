#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()
{
	//1
	const int size = 7;
	int arr[size];
	int x = 50, y = -12, a=0, b=0, srand(time(NULL));
	for (int i = 0; i < size; i++) 
	{
		arr[i] = rand() % (x - y) + y;
		if (arr[i] < 0) b++;
		else a++;
	}
	for (int i = 0; i < size; i++)
		cout << arr[i] << " " << endl;
	cout << "Number of positive elements = " << a << endl;
	cout << "Number of negative items =  " << b << endl;
	
	cout << endl;
	

	system("pause");
}