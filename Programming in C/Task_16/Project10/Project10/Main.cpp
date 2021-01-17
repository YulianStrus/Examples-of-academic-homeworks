#include "Header.h"

void main()
{
	int *arr;
	int size;
	cout << "Enter size mas: " << endl;
	cin >> size;
	arr= new int [size];
	RandArr(arr, size);
	cout << endl;
	cout << "Enter sort: " << endl;
	cout << "+ \"on growth\"" << endl;
	cout << "- \"by recurrence\"" << endl;
	char s;
	cin >> s;
	cout << endl;
	if (s == '+')
	{
		cout << "Enter type sort: " << endl;
		cout << "1 - Bubble" << endl;
		cout << "2 - Insert" << endl;
		cout << "3 - Transposition" << endl;
		int t;
		cin >> t;
		cout << endl;
		switch(t)
		{
		case 1: BubbleSortP(arr, size); break;
		case 2: InsertSortP(arr, size); break;
		case 3: TranspSortP(arr, size); break;
		}
	}
	
	else if (s == '-')
	{
		cout << "Enter type sort: " << endl;
		cout << "1 - Bubble" << endl;
		cout << "2 - Insert" << endl;
		cout << "3 - Transposition" << endl;
		int t;
		cin >> t;
		cout << endl;
		switch (t)
		{
		case 1: BubbleSortM(arr, size); break;
		case 2: InsertSortM(arr, size); break;
		case 3: TranspSortM(arr, size); break;
		}
	}
	
	else cout << "Error!";


	system("pause");
}
