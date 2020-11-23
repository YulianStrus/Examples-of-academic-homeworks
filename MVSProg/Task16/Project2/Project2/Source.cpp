#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()
{
	//1
	const int size = 15;
	int arr[size];
	int x = 10, y = -10, srand(time(NULL));
	for (int i = 0; i < size; i++) arr[i] = rand() % (x - y) + y;
	for (int i = 0; i < size; i++) cout << arr[i] << " ";
	cout << endl;
	//2
	int Sum = 0;
	for (int i = 0; i < size; i++ ) Sum += arr[i];
	cout << "Sum= " << Sum << endl;
	//3
	int Pdob = 1;
	for (int i = 0; i < size; i++)
		if (arr[i]%3==0)Pdob *= arr[i];
	cout << "Pdob= " << Pdob << endl;
	//4
	int count = 0;
	for (int i = 0; i < size; i++)
		if ((arr[i] % 7 == 0) && (i%2==0))++count;
	cout << "Count= " << count << endl;
	//5
	int value;
	cout << "Input number "; cin >> value;
	for (int i = 0; i < size; i++)
		if (arr[i] >= value) cout << i << "";
	cout << endl;
	//6
	int min = arr[0];
	for (int i = 1; i < size; i++)
		if (arr[i] < min) min = arr[i];
	cout << "Min= " << min << endl;

	system("pause");
}