#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()
{
	const int size = 7;
	double arr[size] = {5,7,6,9,8,11,10};
	int Sum=0;
	for (int i = 0; i < size; i++)
	{
		int e = arr[i];
		if (e % 2 == 0) 
			Sum += arr[i];
	}
	cout << "Sum of pairs of array elements = " << Sum << endl;

	system("pause");
}