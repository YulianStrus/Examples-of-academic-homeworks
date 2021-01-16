#include "iostream"
using namespace std;

struct TelBook
{
	char name[32];
	char firm[32];
	int cost;
	int number;
};

void InitDB(TelBook *DB);
void ShowAbonem(TelBook *DB, int size);
void DelArr(TelBook *DB);
TelBook *EditItem(TelBook * DB, char *nm, char *fi, int size);
void FindItem(TelBook *DB, char *nmf, int size);

void main()
{
	int size = 5;
	TelBook *DB = new TelBook[size];
	char a=0, fi[32], nm[32], nmf[32];
	InitDB(DB);
	while (a != 'q')
	{
		cout << "\nEnter number: " << endl;
		cout << "\t1 - Show item" << "\n\t2 - Edit item" << "\n\t3 - Find item" << "\n\tq - Exit" << endl;
		cin >> a;
		cout << endl;
		switch (a)
		{
		case '1':
			ShowAbonem(DB, size);
			break;
		case '2':
			cout << "Enter name to search: " << endl;
			cin.ignore();
			gets_s (nm, 32);
			cout << "Enter firm to search: " << endl;
			gets_s (fi, 32);
			DB = EditItem(DB, nm, fi, size);
			break;
		case '3':
			cout << "Enter name to search: " << endl;
			cin.ignore();
			gets_s(nmf, 32);
			FindItem(DB, nmf, size);
			break;
		case 'q':
			break;
		default: cout << "Error!" << endl; break;
		}
	}
	DelArr(DB);

	system("pause");
}


void InitDB(TelBook *DB)
{
	DB[0] = { "Core i7 - 8086K", "Intel", 14200, 3 };
	DB[1] = { "HyperX FURY 8 GB", "Kingston", 2010, 8 };
	DB[2] = { "Core i5 - 7640X", "Intel", 7785, 5 };
	DB[3] = { "GeForce GTX 1050", "MSI", 4470, 1 };
	DB[4] = { "A1000 240 GB", "Kingston", 1988, 0 };
}
void ShowAbonem(TelBook * DB, int size)
{
	for (int i = 0; i < size; i++)
		cout << "Name: " << DB[i].name << "\t\t Firm: " << DB[i].firm << "\t\t Cost: " << DB[i].cost << "\t\t Number: " << DB[i].number << endl;
}
void DelArr(TelBook * DB)
{
	delete[] DB;
}

TelBook *EditItem(TelBook * DB, char *nm, char *fi, int size)
{
	int z;
	for (int i = 0; i < size; i++)
		if ((stricmp(DB[i].name, nm) == 0)&(stricmp(DB[i].firm, fi) == 0))
			z = i;
	cout << "Enter new cost:" << endl;
	cin >> DB[z].cost;

	return DB;
}

void FindItem(TelBook * DB, char *nmf, int size)
{
	int F, z = 0;
	for (int i = 0; i < size; i++)
	{
		F = stricmp(DB[i].name, nmf);
		if ((F == 0)&(DB[i].number != 0))
		{
			cout << "Name: " << DB[i].name << "\t\t Firm: " << DB[i].firm << "\t\t Cost: " << DB[i].cost << "\t\t Number: " << DB[i].number << endl;
			z++;
		}
	}
	if (z == 0) cout << "\n The details are over!" << endl;

}