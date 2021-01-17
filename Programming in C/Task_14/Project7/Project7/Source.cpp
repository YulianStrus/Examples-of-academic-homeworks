#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()

{
	const int row = 5;
	const int col = 4;
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

	int  k=0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			k++;			
	}


	int  a, b, c, d, n=0;
	cout << "Enter c1 " << endl;
	cin >> a >> c;
	cout << "Enter c2 " << endl;
	cin >> b >> d; 
	for (int i = a; i <= b; i++) {
		for (int j = c; j <= d; j++)
			n++;
		//a -= 1; b -= 1;
	}
	k -= n;
	if (k < 0) cout << "Error!" << endl;
	else cout << "k= " << k << endl;

	system("pause");
}
