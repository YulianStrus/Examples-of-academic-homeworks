#include "iostream"
#include "stdio.h"
#include "time.h"
using namespace std;


void main()
{
	int size = 20;
	int tmp;
	FILE *f, *g;
	srand(time(NULL));
	f=fopen("..\\files\\f.txt", "wb");
	for (int i = 0; i < size; ++i)
	{
		tmp = rand() % 1000;
		cout << tmp << " ";
		fwrite(&tmp, sizeof(int), 1, f);
	}
	fclose(f);
	cout << endl;
	f = fopen("..\\files\\f.txt", "rb");
	g = fopen("..\\files\\g.txt", "wb");

	for (int i = 0; i < 20; ++i)
	{
		fread(&tmp, sizeof(int), 1, f);
		if (tmp % 2 == 0)
		{
			fwrite(&tmp, sizeof(int), 1, g);
			cout << tmp << " ";
		}
	}

	fclose(f);
	cout << endl;
	fclose(g);
	f=fopen("..\\files\\f.txt", "rb");
	g=fopen("..\\files\\g.txt", "ab");
	for (int i = 0; i < size; ++i)
	{
		fread(&tmp, sizeof(int), 1, f);
		if (tmp % 3 == 0 && tmp % 7 != 0)
		{
			fwrite(&tmp, sizeof(int), 1, g);
			cout << tmp << " ";
		}
	}
	cout << endl;
	fclose(f);
	fclose(g);

	system("pause");
}

