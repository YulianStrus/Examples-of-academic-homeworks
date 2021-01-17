#pragma once;
#include "iostream"
#include "stdio.h"
#include "stdlib.h"
using namespace std;

int main(int argc, char* argv[])
{
	char a;
	cout << "Enter the string: ";
	char in_string[500];
	gets_s(in_string);
	cout << "Enter symbol: ";
	cin >> a;
	int S = 0;
	for (int i = 0; i < 500; i++)
		if (in_string[i] == a) S++;

	cout << "Number of characters " << a << " = " << S << endl;
	system("pause");
	return 0;
}