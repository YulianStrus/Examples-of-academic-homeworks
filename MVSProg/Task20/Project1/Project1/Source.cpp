#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()

{
	const int row = 4;
	const int col = 5;
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

	int min = M[0][0];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			if (M[i][j] < min) min = M[i][j];
	}
	cout << "min= " << min << endl << endl;

	int max = M[0][0];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			if (M[i][j] > min) max = M[i][j];
	}
	cout << "max= " << max << endl << endl;

	int Sum =0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			Sum += M[i][j];
	}
	cout << "Sum= " << Sum << endl << endl;

	
	double ser;
	for (int i = 0; i < row; i++) {
	ser=0;
		for (int j = 0; j < col; j++)
			ser += M[i][j];
			ser=ser-col;
	cout << "for " << i << " row ser= " << ser << endl;
	}
	cout << endl;

	cout << "col 1 and col 2" << endl;
	int temp[col];
	for (int j = 0; j < col; ++j)
		temp[j] = M[1][j];
	for (int j = 0; j < col; ++j)
		M[1][j] = M[2][j];
	for (int j = 0; j < col; ++j)
		M[2][j] = temp[j];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;

	cout << "row 2 to row 3" << endl;
	int tmp[row];
	for (int i = 0; i < row; ++i)
		tmp[i] = M[i][2];
	for (int i = 0; i < row; ++i)
		M[i][2] = M[i][3];
	for (int i = 0; i < row; ++i)
		M[i][3] = tmp[i];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;

	system("pause");
}
