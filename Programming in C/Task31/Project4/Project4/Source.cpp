#pragma once;
#include "iostream"
#include "stdio.h"
#include "stdlib.h"
using namespace std;

int main(int argc, char* argv[])
{
	cout << "Enter the string: ";
	char in_string[500];
	gets_s(in_string);
	int S = 0;
	for (int i = 0; i < 500; i++)
		if (in_string[i] == '%') S++;

	cout << "Number of characters %  = " << S << endl;
	system("pause");
	return 0;
}