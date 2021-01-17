#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()

{
	const int row = 10;
	const int col = 5;
	int M[row][col];
	int x = 20, y = -20, srand(time(NULL));
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

	int max = M[0][0];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			if (M[i][j] > max) max = M[i][j];
	}
	
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (M[i][j] < 0) M[i][j]=max;
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << M[i][j] << "\t ";
		}
		cout << endl;
	}


	cout << endl;
	system("pause");
}
