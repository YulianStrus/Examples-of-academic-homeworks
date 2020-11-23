#pragma once;
#include "iostream"
#include "stdio.h"
#include "time.h"
using namespace std;

void main()
{
	char fam[5][50] = { '\0' };
	int max = 0, tmp = 0;
	int index = 0;
	cout << "Enter 5 student surnames:" << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << i+1 << "\`th:  ";
		gets_s(fam[i], 50);
		tmp = strlen(fam[i]);
		if (tmp > max)
		{
			max = tmp;
			index = i;
		}
	}
	cout << "\nLongest last name: " << fam[index] << endl;
	system("pause");
} 