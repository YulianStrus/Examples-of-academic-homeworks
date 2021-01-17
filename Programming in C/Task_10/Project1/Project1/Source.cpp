#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()

{
	const int size = 10;
	int arr[size];
	int Sum=0;
		int x = 15, y = -15, srand(time(NULL));
		for (int i = 0; i < size; i++) {
			arr[i] = rand() % (x - y) + y;
			cout << arr[i] << " ";
		}
		for (int i = 0; i < size; i++)
		{
			if (i % 2 != 0)
				Sum += arr[i];
		}
		cout << "Sum of pairs of elements with odd indices = " << Sum << endl;
		


	system("pause");
}