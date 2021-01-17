#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()

{
	const int row = 10;
	const int col = 5;
	int M[row][col];
	int x = 20, y = -10, srand(time(NULL));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			M[i][j] = rand() % (x - y) + y;
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << M[i][j] << "\t ";
		}
		cout << endl;
	}
	cout << endl << endl;

	int min = M[0][0];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			if (M[i][j] < min) min = M[i][j];
	}
	cout << "min= " << min << endl;

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (M[i][j] == min) cout << "M[" << i << "][" << j << "]" << endl;



	cout << endl;
	system("pause");
}
