#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()

{
	const int row = 5;
	const int col = 5;
	int M[row][col];
	int x = 30, y = 10, srand(time(NULL));
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

	int k=0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if ((j > i)&(M[i][j] % 2 == 0)) k++;
		}
	}
	cout << "k= " << k << endl;

	system("pause");
}
