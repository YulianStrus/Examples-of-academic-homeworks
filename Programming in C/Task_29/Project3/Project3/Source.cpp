#include "iostream"
#include "cstdio"
#include "time.h"
using namespace std;

struct student
{
	char name[25];
	char lastname[35];
	char group[10];
};

void main()
{
	int size = 1;
	int count = 0;
	student *ArrayData = new student[size];
	FILE *f;
	fopen_s(&f, "1.dat", "rb");
	while (!feof(f))
	{
		fread(&*ArrayData, sizeof(student), size, f);
		++count;
	}
	size = count - 1;
	fclose(f);
	delete[]ArrayData;
	ArrayData = new student[size];
	fopen_s(&f, "1.dat", "rb");
	fread(&*ArrayData, sizeof(student), size, f);
	fclose(f);
	int size1 = 0;
	char *temp = new char[10];
	temp = ArrayData[0].group;
	for (int i = 0; i < size; i++)
		if (strcmp(ArrayData[i].group, temp) == 0) ++size1;
	student *RPZ8 = new student[size1];
	student *RPZ7 = new student[size - size1];
	int count1 = 0, count2 = 0;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(ArrayData[i].group, temp) == 0)
		{
			RPZ8[count1] = ArrayData[i];
			++count1;
		}
		if (strcmp(ArrayData[i].group, temp) != 0)
		{
			RPZ7[count2] = ArrayData[i];
			++count2;
		}
	}
	temp = NULL;
	delete[]temp;
	cout << "\t\t\tRPZ8" << endl;
	for (int i = 0; i < size1; ++i)
		cout << i + 1 << ". " << RPZ8[i].name << " " << RPZ8[i].lastname << endl;
	int size2;
	size2 = size - size1;
	cout << "\n\t\t\tRPZ7" << endl;
	for (int i = 0; i < size2; ++i)
		cout << i + 1 << ". " << RPZ7[i].name << " " << RPZ7[i].lastname << endl;
	cout << "\t\t\tTask 1" << endl;
	cout << "\t\t\tRPZ8" << endl;
	student *temp1 = new student[1];
	for (int i = 0; i < size1 - 1; ++i)
	{
		for (int k = 0; k < size1 - i - 1; ++k)
		{
			if (strcmp(RPZ8[k].lastname, RPZ8[k + 1].lastname) > 0)
			{
				temp1[0] = RPZ8[k];
				RPZ8[k] = RPZ8[k + 1];
				RPZ8[k + 1] = temp1[0];
			}
		}
	}
	count1 = 0;
	for (int i = 0; i < size1; ++i)
	{
		count = 0;
		for (int k = i; k < size1; ++k)
		{
			if (strcmp(RPZ8[i].lastname, RPZ8[k].lastname) == 0)
				++count;
		}
		if (count > 1)
		{
			++count1;
			cout << count1 << ". " << RPZ8[i].lastname << " " << RPZ8[i].name << endl;
			for (int k = i + 1; k < size1; ++k)
			{
				if (strcmp(RPZ8[i].lastname, RPZ8[k].lastname) == 0)
					cout << "   " << RPZ8[k].lastname << " " << RPZ8[k].name << endl;
			}
		}
		i = i + count - 1;
	}
	cout << "\t\t\tRPZ7" << endl;
	for (int i = 0; i < size2 - 1; ++i)
	{
		for (int k = 0; k < size2 - i - 1; ++k)
		{
			if (strcmp(RPZ7[k].lastname, RPZ7[k + 1].lastname) > 0)
			{
				temp1[0] = RPZ7[k];
				RPZ7[k] = RPZ7[k + 1];
				RPZ7[k + 1] = temp1[0];
			}
		}
	}
	count1 = 0;
	for (int i = 0; i < size2; ++i)
	{
		count = 0;
		for (int k = i; k < size2; ++k)
		{
			if (strcmp(RPZ7[i].lastname, RPZ7[k].lastname) == 0)
				++count;
		}
		if (count > 1)
		{
			++count1;
			cout << count1 << ". " << RPZ7[i].lastname << " " << RPZ7[i].name << endl;
			for (int k = i + 1; k < size1; ++k)
			{
				if (strcmp(RPZ7[i].lastname, RPZ7[k].lastname) == 0)
					cout << "   " << RPZ7[k].lastname << " " << RPZ7[k].name << endl;
			}
		}
		i = i + count - 1;
	}
	cout << "\t\t\tTask 2" << endl;
	count1 = 0, count2 = 0;
	for (int i = 0; i < size1; ++i)
	{
		count = 0;
		for (int k = 0; k < size2; ++k)
		{
			if (strcmp(RPZ8[i].lastname, RPZ7[k].lastname) == 0)
				++count;
		}
		if (count > 0)
		{
			count = 0;
			for (int k = i; k < size1; ++k)
			{
				if (strcmp(RPZ8[i].lastname, RPZ8[k].lastname) == 0)
					++count;
			}
			if (count > 1)
			{
				++count1;
				cout << count1 << ". " << RPZ8[i].lastname << " " << RPZ8[i].name << " " << RPZ8[i].group << endl;
				for (int k = i + 1; k < size1; ++k)
				{
					if (strcmp(RPZ8[i].lastname, RPZ8[k].lastname) == 0)
						cout << "   " << RPZ8[k].lastname << " " << RPZ8[k].name << " " << RPZ8[k].group << endl;
				}
				for (int k = 0; k < size2; ++k)
				{
					if (strcmp(RPZ8[i].lastname, RPZ7[k].lastname) == 0)
						cout << "   " << RPZ7[k].lastname << " " << RPZ7[k].name << " " << RPZ7[k].group << endl;
				}
			}
			i = i + count - 1;
		}
	}
	cout << "\t\t\tTask 3" << endl;
	if (size1 > 35) cout << RPZ8[0].group << " have more than 35 students" << endl;
	FILE *g;
	fopen_s(&g, "2.dat", "wb");
	fwrite(&*RPZ7, sizeof(student), size2, g);
	fclose(g);
	delete[]temp1;
	delete[]RPZ7;
	delete[]RPZ8;
	delete[]ArrayData;
	cin.get();
	cin.get();
}