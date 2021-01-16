#include "iostream"
using namespace std;

struct TelBook
{
	int day;
	int month;
	int year;
	char surname[32];
	char name[32];	
	int telnumber;
};

void InitDB(TelBook *DB);
void ShowAbonem(TelBook *DB, int size);
void DelArr(TelBook *DB);
TelBook *ShowNovem(TelBook * DB, int size, int z);


void main()
{
	int size = 5;
	TelBook *DB = new TelBook[size];
	InitDB(DB);
	ShowAbonem(DB, size);
	int z = 0;
	for (int i = 0; i < size; i++)
		if (DB[i].month == 11) z++;
	if (z == 0) cout << "\nNot found!" << endl;
	else
	{
		DB = ShowNovem(DB, size, z);
		size = z;
		cout << endl << endl;
		ShowAbonem(DB, size);
	}
	DelArr(DB);
	system("pause");
}


void InitDB(TelBook *DB)
{
	DB[0] = { 25, 11, 1999, "Krajnja", "Elvira", 687139546 };
	DB[1] = { 11, 11, 2001, "Antenko", "Nazarij'", 429781235 };
	DB[2] = { 13, 10, 2000, "Kipeckij", "Bohdan", 649782102 };
	DB[3] = { 19, 11, 2000, "Mitelskij", "Valerij", 479513782 };
	DB[4] = { 15, 12, 2001, "Boreckij", "Sergij", 479316852 };
}
void ShowAbonem(TelBook * DB, int size)
{
	for (int i = 0; i < size; i++)
		cout << "Data birthday: " << DB[i].day << "." << DB[i].month << "." << DB[i].year << "\t\t Surname: " << DB[i].surname << "\t\t Name: " << DB[i].name << "\t\t Namber: " << DB[i].telnumber << endl;
}
void DelArr(TelBook * DB)
{
	delete[] DB;
}

TelBook* ShowNovem(TelBook * DB, int size, int z)
{
	
	int a = 0;
	
	TelBook *tmp = new TelBook[size];
	for (int i = 0; i < size; ++i)
	if (DB[i].month==11)
	{
		tmp[a] = DB[i];
		a++;
	}
	
	DelArr(DB);
	size=z;
	DB = new TelBook[size];
	TelBook srt;
	bool change = true;
	while (change)
	{
		change = false;
		for (int i = 0; i < size - 1; ++i)
		{
			if (strcmp(tmp[i].surname,tmp[i+1].surname)>0)
			{
				srt = tmp[i];
				tmp[i] = tmp[i + 1];
				tmp[i + 1] = srt;

				change = true;
			}
		}
	}

	for (int i = 0; i < size; ++i)
	{
		DB[i] = tmp[i];
	}
	DelArr(tmp);
	return DB;
}