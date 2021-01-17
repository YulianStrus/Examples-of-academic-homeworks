#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()

{
	const int row = 6;
	const int col = 6;
	int M[row][col];
	int x = 5, y = 0, srand(time(NULL));
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


	int tmp, elm;
	for (int j = 0; j < row; j++)
	{
		tmp=M[0][j];
		for (int i = 1; i < col; ++i)
		{
			tmp += M[i][j];
		}
		cout << "Suma elementiv " << j << " column = " << tmp << endl;
		for (int i = 0; i < col; ++i)
		{
			if (M[i][j] > tmp - M[i][j]) cout << i << " " << j << endl;
			else cout << "Error! M[" <<i << "][" << j << "]= "<< M[i][j] << " < " << tmp-M[i][j]  << endl;
		}
		cout << endl;
	}

	system("pause");
}
