#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()

{
	const int K = 10;
	int A[K], B[K], C[K*2];
	int x = 15, y = -15, srand(time(NULL));
	for (int i = 0; i <K; i++) {
		A[i] = rand() % (x - y) + y;
		cout << A[i] << " ";
	}
	cout << endl;
	for (int i = 0; i <K; i++) {
		B[i] = rand() % (x - y) + y;
		cout << B[i] << " ";
	}
	cout << endl << endl;
	for (int i = 0; i < K; i++)
	
		C[i] = A[i];
	for (int j = 10; j < K * 2; j++)
			C[j] = B[j-10];
	

	for (int i = 0; i < K*2; i++) cout << C[i] << " ";
	cout << endl;

	system("pause");
}
