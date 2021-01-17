#include "iostream"
#include "cstdio"
#include "time.h"
using namespace std;

void main()
{
	FILE *f, *g, *h;
	int size = 6;
	int x1 = -1, y1 = -10, x2 = 10, y2 = 1;
	int tmp;
	srand(time(NULL));
	f=fopen("..\\files\\f.txt", "wb");
	for (int i = 0; i < size; ++i)
	{
		tmp = rand() % (x1 - y1) + y1;
		cout << tmp << " ";
		fwrite(&tmp, sizeof(int), 1, f);
	}
	for (int i = 0; i < size; ++i)
	{
		tmp = rand() % (x2 - y2) + y2;
		cout << tmp << " ";
		fwrite(&tmp, sizeof(int), 1, f);
	}
	fclose(f);
	cout << endl;
	f=fopen("..\\files\\f.txt", "rb");
	h=fopen("..\\files\\h.txt", "wb");
	for (int i = 0; i < 2 * size; ++i)
	{
		fread(&tmp, sizeof(int), 1, f);
		if (tmp < 0) fwrite(&tmp, sizeof(int), 1, h);
	}
	fclose(f);
	fclose(h);
	f=fopen("..\\files\\f.txt", "rb");
	g=fopen("..\\files\\g.txt", "wb");
	h=fopen("..\\files\\h.txt", "rb");
	for (int i = 0; i < 2 * size; ++i)
	{
		fread(&tmp, sizeof(int), 1, f);
		if (tmp > 0)
		{
			fwrite(&tmp, sizeof(int), 1, g);
			cout << tmp << " ";
			fread(&tmp, sizeof(int), 1, h);
			fwrite(&tmp, sizeof(int), 1, g);
			cout << tmp << " ";
		}
	}
	fclose(f);
	fclose(g);
	fclose(h);
	cout << endl;
	f=fopen("..\\files\\f.txt", "rb");
	g=fopen("..\\files\\g.txt", "ab");
	h=fopen("..\\files\\h.txt", "rb");
	for (int i = 0; i < 2 * size; ++i)
	{
		fread(&tmp, sizeof(int), 1, f);
		if (tmp > 0)
		{
			fwrite(&tmp, sizeof(int), 1, g);
			cout << tmp << " ";
		}
	}
	for (int i = 0; i < size; ++i)
	{
		fread(&tmp, sizeof(int), 1, h);
		fwrite(&tmp, sizeof(int), 1, g);
		cout << tmp << " ";
	}
	fclose(f);
	fclose(h);
	cout << endl;
	f=fopen("..\\files\\f.txt", "rb");
	h=fopen("..\\files\\h.txt", "rb");
	int count = 0;
	for (int i = 0; i < 2 * size; ++i)
	{
		fread(&tmp, sizeof(int), 1, f);
		if (tmp > 0)
		{
			++count;
			fwrite(&tmp, sizeof(int), 1, g);
			cout << tmp << " ";
		}
		if (count == 2)
		{
			fread(&tmp, sizeof(int), 1, h);
			fwrite(&tmp, sizeof(int), 1, g);
			cout << tmp << " ";
			fread(&tmp, sizeof(int), 1, h);
			fwrite(&tmp, sizeof(int), 1, g);
			cout << tmp << " ";
			count = 0;
		}
	}
	cout << endl;
	fclose(f);
	fclose(g);
	fclose(h);

	system("pause");
}