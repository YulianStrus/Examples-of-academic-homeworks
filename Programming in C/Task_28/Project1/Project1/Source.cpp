#include "iostream"
#include "stdio.h"
using namespace std;

void main()
{
	char a1[100], a2[100];
	FILE *f1 = fopen("..\\files\\f1.txt", "r"),
		*tmp = fopen("..\\files\\tmp.txt", "w");
	fgets(a1, 100, f1);
	fputs(a1, tmp);
	fclose(f1);
	fclose(tmp);

	FILE *f2 = fopen("..\\files\\f2.txt", "r");
		f1 = fopen("..\\files\\f1.txt", "w");
	fgets(a2, 100, f2);
	fputs(a2, f1);
	fclose(f1);
	fclose(f2);

	tmp = fopen("..\\files\\tmp.txt", "r"),
		f2 = fopen("..\\files\\f2.txt", "w");
	fgets(a1, 100, tmp);
	fputs(a1, f2);
	fclose(tmp);
	fclose(f2);
	cout << "Task complete!!!" << endl;
	system("pause"); 
}