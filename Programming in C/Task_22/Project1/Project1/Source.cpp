#pragma once;
#include "iostream"
#include "stdio.h"
#include "stdlib.h"
using namespace std;

int main(int argc, char* argv[])
{
	char string[] = "this is string - ";
	cout << "Enter the string: ";
	char in_string[500];
	gets_s(in_string);

	for (int i = 0; i < 500; i++)
		if (in_string[i] == ' ') in_string[i] = '\t';

	cout << string << in_string << endl;
	system("pause");
	return 0;
}