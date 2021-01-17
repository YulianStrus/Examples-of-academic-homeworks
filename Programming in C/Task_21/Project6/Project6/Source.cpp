#pragma once;
#include "iostream"
#include "string.h"
using namespace std;

int main(int argc, char* argv[])
{
	cout << "Enter the string: ";
	char in_string[500];
	gets_s(in_string);
	cout << "Enter the word: ";
	char word[25];
	gets_s(word);
	int n = strlen(word);
	char *next_tmp = NULL;
	char *tmp[20];
	int k = 0;
	*tmp = strtok(in_string, " ,.-");
	while (*tmp != NULL)
	{
		int a = strcmp(*tmp, word);
		if (a == 0) { k++; *tmp = strtok(NULL, " ,.-"); }
		else *tmp = strtok(NULL, " ,.-"); 
	}

	if (k==0) cout << "Does not match!!!" << endl;
	else cout << "Coincides with!" << endl;

	system("pause");
	return 0;
}