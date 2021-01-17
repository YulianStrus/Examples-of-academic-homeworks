#include "iostream"
#include "stdio.h"
using namespace std;

void revers(char s[]);

void main()
{
	char tmp[100];
	FILE *f = fopen("..\\files\\f.txt", "r"),
		*g = fopen("..\\files\\g.txt", "w");
	fgets(tmp, 100, f);
	revers(tmp);
	fputs(tmp, g);
	fclose(f);
	fclose(g);

	cout << "Task complete!!!" << endl;

	system("pause");
}

void revers(char s[])
{
	int len = strlen(s);
	for (int i = 0; i < len / 2; i++) 
	{
		char temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
}