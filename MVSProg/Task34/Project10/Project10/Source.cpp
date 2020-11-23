#pragma once;
#include "iostream"
#include "stdio.h"
#include "time.h"
using namespace std;

void main()
{
	char fam[5][50] = { '\0' };
	char tmp[50];
	int index = 0;
	cout << "Enter 5 student surnames:" << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << "\`th:  ";
		gets_s(fam[i], 50);
	}
	bool chg = true;
	while (chg)
	{
		chg = false;
		for (int i = 0; i < 4; i++)
		{
			if (strlen(fam[i]) > strlen(fam[i + 1]))
			{
				strcpy(tmp, fam[i]);
				strcpy(fam[i], fam[i + 1]);
				strcpy(fam[i + 1], tmp);
				chg = true;
			}
		}
	}

	cout << "\nSort:" << endl;
	for (int i = 0; i < 5; i++)
		cout << fam[i] << endl;
	system("pause");
}