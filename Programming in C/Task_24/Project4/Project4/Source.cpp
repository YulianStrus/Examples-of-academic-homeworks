#include "iostream"
using namespace std;

struct TelBook
{
	char surname[32];
	char name[32];
	char adress[64];
	int telnumber;
	int day;
	int month;
	int year;
};

void InitDB(TelBook *DB);
void ShowDBStud(TelBook *DB, int size);
void DelArr(TelBook *DB);
TelBook *SortDB(TelBook * DB, int size);
TelBook *ShowAutumn(TelBook * DB, int size, int z);


void main()
{
	int size = 5;
	TelBook *DB = new TelBook[size];
	InitDB(DB);
	int z = 0;
	for (int i = 0; i < size; i++)
		if ((DB[i].month == 11) || (DB[i].month == 10) || (DB[i].month == 9)) z++;
	char a = 0;
	while (a != 'q')
	{
		cout << "\nEnter number: " << endl;
		cout << "\t1 - Show of all student" << "\n\t2 - Show sort DB" << "\n\t3 - Show who was born in autumn" << "\n\tq - Exit" << endl;
		cin >> a;
		cout << endl;
		switch (a)
		{
		case '1':
			ShowDBStud(DB, size);
			break;
		case '2':
			DB=SortDB(DB, size);
			ShowDBStud(DB, size);
			break;
		case '3':
			if (z == 0) cout << "\nNot found!" << endl;
			else
			{
				DB = ShowAutumn(DB, size, z);
				size = z;
				cout << endl << endl;
				cout << "Birthday in Autumn:" << endl;
				ShowDBStud(DB, size);
			}
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
	DB[0] = { "Krajnja", "Elvira", "Khmelnickij", 687139546, 10, 10, 1999 };
	DB[1] = { "Antenko", "Nazarij", "Khmelnickij", 429781235, 18, 4, 2001, };
	DB[2] = { "Kipeckij", "Bohdan", "Chernivci", 649782102,  13, 1, 2000 };
	DB[3] = { "Mitelskij", "Valerij", "Vinnica", 479513782, 19, 11, 2000 };
	DB[4] = { "Boreckij", "Sergij", "Khmelnickij", 479316852, 15, 12, 2001 };
}
void ShowDBStud(TelBook * DB, int size)
{
	for (int i = 0; i < size; i++)
		cout  << " Surname: " << DB[i].surname << "\t  Name: " << DB[i].name << "\t  Adress: " << DB[i].adress << "\t  Namber: " << DB[i].telnumber << "  Data birthday: " << DB[i].day << "." << DB[i].month << "." << DB[i].year << endl;
}
void DelArr(TelBook * DB)
{
	delete[] DB;
}

TelBook *SortDB(TelBook * DB, int size)
{
	TelBook srt;
	bool change = true;
	while (change)
	{
		change = false;
		for (int i = 0; i < size - 1; ++i)
		{
			if (DB[i].year > DB[i + 1].year)
			{
				srt = DB[i];
				DB[i] = DB[i + 1];
				DB[i + 1] = srt;

				change = true;
			}
		}
	}
	while (change)
	{
		change = false;
		for (int i = 0; i < size - 1; ++i)
		{
			if (DB[i].month > DB[i + 1].month)
			{
				srt = DB[i];
				DB[i] = DB[i + 1];
				DB[i + 1] = srt;

				change = true;
			}
		}
	}
	while (change)
	{
		change = false;
		for (int i = 0; i < size - 1; ++i)
		{
			if (DB[i].day > DB[i + 1].day)
			{
				srt = DB[i];
				DB[i] = DB[i + 1];
				DB[i + 1] = srt;

				change = true;
			}
		}
	}

	return DB;
}

TelBook* ShowAutumn(TelBook * DB, int size, int z)
{

	int a = 0;

	TelBook *tmp = new TelBook[size];
	for (int i = 0; i < size; ++i)
		if (((DB[i].month == 11) || (DB[i].month == 10) || (DB[i].month == 9)))
		{
			tmp[a] = DB[i];
			a++;
		}

	DelArr(DB);
	size = z;
	DB = new TelBook[size];
	TelBook srt;
	bool change = true;
	while (change)
	{
		change = false;
		for (int i = 0; i < size - 1; ++i)
		{
			if (strcmp(tmp[i].surname, tmp[i + 1].surname) > 0)
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