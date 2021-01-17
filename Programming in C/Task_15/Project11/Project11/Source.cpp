#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

void FuncRect(int a, int b)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
			cout << "*";
		cout << endl;
	}
}
void main()
{
	int N, K;
	cout << "Enter height: " << endl;
	cin >> K;
	cout << "Enter width: " << endl;
	cin >> N;

	FuncRect(N, K);


	system("pause");
}
