#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()

{
	const int row = 4;
	const int col = 4;
	int M[row][col];
	int x = 90, y = 10, srand(time(NULL));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			M[i][j] = rand() % (x - y) + y;
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;

	int Sum=0;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (j < i) Sum += M[i][j];
	cout << "Sum= " << Sum << endl;


	cout << endl;
	system("pause");
}
