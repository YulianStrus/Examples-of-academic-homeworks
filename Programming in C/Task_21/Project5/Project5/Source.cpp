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

	int A = 0, Ch=0, Num=0;
	
	for (int i = 0; i < 500; i++)
		if ((in_string[i] >= 97)&(in_string[i] <= 122)|(in_string[i] >= 65)&(in_string[i] <= 90)) A++;
	cout << "Number of Alpha  = " << A << endl;
	for (int i = 0; i < 500; i++)
		if ((in_string[i] >= 48)&(in_string[i] <= 57)) Num++;
	cout << "Number of Number  = " << Num << endl;
	Ch = strlen(in_string) - (A + Num);
	cout << "Number of Character  = " << Ch << endl;	
	
	system("pause");
	return 0;
}