#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()

{
	const int K = 20;
	int A[K], B[K/2], C[K/2];
	int x = 15, y = -15, srand(time(NULL));
	for (int i = 0; i <K; i++) {
		A[i] = rand() % (x - y) + y;
		cout << A[i] << " ";
	}
	cout << endl << endl;

	for (int i = 0; i < K / 2; i++)
		B[i] = A[i];
	for (int j = K / 2; j < K; j++)
		C[j-K/2] = A[j];

	for (int i = 0; i < K / 2; i++) cout << B[i] << " ";
	cout << endl;
	for (int i = 0; i < K / 2; i++) cout << C[i] << " ";
	cout << endl;

	system("pause");
}
