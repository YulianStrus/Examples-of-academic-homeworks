#include "Header.h"

void Rect(int a, int b)
{
	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < a; j++)
			cout << "*";
		cout << endl;
	}
}