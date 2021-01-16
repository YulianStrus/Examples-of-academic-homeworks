#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()

{
	const int size = 10;
	int arr[size], k, l, n;
	int x = 10, y = -5, srand(time(NULL));
	for (int i = 0; i < size; i++) 
	{
		arr[i] = rand() % (x - y) + y;
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 1; i < size; i++)
		if (arr[i] < 0) k = i;
	cout << "k=" << k << endl;
	for (int i = size; i > 0; i--)
		if (arr[i] < 0) l = i;
	cout << "l=" << l << endl;
	n = k - l - 1;
		cout << n << endl;


	system("pause");
}