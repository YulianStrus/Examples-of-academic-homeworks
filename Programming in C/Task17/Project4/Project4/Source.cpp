#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()

{
	const int size = 10;
	int A[size], B[size];
	int x = 15, y = -15, srand(time(NULL));
	for (int i = 0; i < size; i++) {
		A[i] = rand() % (x - y) + y;
		cout << A[i] << " ";
	}
	cout << endl << endl;
	for (int i = 0; i < size; i++)
		B[i] = A[i];

	for (int i = 0; i < size; i++) cout << B[i] << " ";
	cout << endl;

	system("pause");
}
