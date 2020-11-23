#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()

{
	const int row = 9;
	const int col = 9;
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

	for (int i = 0; i < row/2; ++i) {
		for (int j = 0; j < col; j++) {
			if ((j >= i)&(j<=col-i-1)) cout << M[i][j] << " ";
			else cout << "   ";
		}
		cout << endl;
	}
	for (int i = row/2; i < row; ++i) {
		for (int j = 0; j < col; j++) {
			if ((j <= i)&(j >= col - i - 1)) cout << M[i][j] << " ";
			else cout << "   ";
		}
		cout << endl;
	}



		cout << endl;
	system("pause");
}
