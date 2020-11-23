#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()
{
	const int size = 10;
	int arr[size], srand(time(NULL)), x=10, y=-10;
	for (int i = 0; i < size; i++) arr[i] = rand()%(x-y)+y;
	for (int i = 0; i < size; i++) cout << arr[i] << " ";

	system("pause");
}