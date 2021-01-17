#include "iostream"
#include "stdio.h"
#include "time.h"
using namespace std;


void main()
{
	int size = 20;
	int tmp, tmp1;
	FILE *f, *g;
	srand(time(NULL));
	f = fopen("..\\files\\f.txt", "wb");
	for (int i = 0; i < size; ++i)
	{
		tmp = rand() % 10;
		cout << tmp << " ";
		fwrite(&tmp, sizeof(int), 1, f);
	}
	fclose(f);
	cout << endl;

	f = fopen("..\\files\\f.txt", "rb");
	fread(&tmp, sizeof(int), 1, f);
	g = fopen("..\\files\\g.txt", "wb");
	fwrite(&tmp, sizeof(int), 1, g);
	fclose(g);
	cout << tmp << " ";
	for (int i = 1; i < size; ++i)
	{
		int count = 0;
		fread(&tmp, sizeof(int), 1, f);
		g = fopen("..\\files\\g.txt", "rb");
		for (int k = 0; k < i; ++k)
		{
			fread(&tmp1, sizeof(int), 1, g);
			if (tmp == tmp1) ++count;
		}
		fclose(g);
		if (count == 0)
		{
			g = fopen("..\\files\\g.txt", "ab");
			fwrite(&tmp, sizeof(int), 1, g);
			fclose(g);
			cout << tmp << " ";
		}
	}
	cout << endl;
	fclose(f);

	system("pause");
}
