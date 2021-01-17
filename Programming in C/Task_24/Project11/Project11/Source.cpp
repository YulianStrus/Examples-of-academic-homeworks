#include "iostream"
using namespace std;

struct TelBook
{
	char surname[32];
	char name[32];
	int rating1;
	int rating2;
	int rating3;
	int rating4;
	int rating5;
};

void InitDB(TelBook *DB);
void ShowDBStud(TelBook *DB, int size);
void DelArr(TelBook *DB);
void ShowStud(TelBook * DB, int size);
TelBook *SortDB(TelBook * DB, int size);



void main()
{
	int size = 5;
	TelBook *DB = new TelBook[size];
	InitDB(DB);
	int z = 0;
	char a = 0;
	while (a != 'q')
	{
		cout << "\nEnter number: " << endl;
		cout << "\t1 - Show of all student" << "\n\t2 - Show sort DB" << "\n\t3 - Show who was average score is not lower than 7.5." << "\n\tq - Exit" << endl;
		cin >> a;
		cout << endl;
		switch (a)
		{
		case '1':
			ShowDBStud(DB, size);
			break;
		case '2':
			DB = SortDB(DB, size);
			ShowDBStud(DB, size);
			break;
		case '3':
			ShowStud(DB, size);
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
	DB[0] = { "Krajnja", "Elvira", 10, 8, 11, 11, 9 };
	DB[1] = { "Antenko", "Nazarij", 7, 8, 6, 10, 6 };
	DB[2] = { "Kipeckij", "Bohdan", 9, 11, 10, 9, 11 };
	DB[3] = { "Mitelskij", "Valerij", 12, 11, 12, 9, 10 };
	DB[4] = { "Boreckij", "Sergij", 7, 6, 8, 7, 7 };
}
void ShowDBStud(TelBook * DB, int size)
{
	double z;
	for (int i = 0; i < size; i++)
	{
		z = DB[i].rating1 + DB[i].rating2 + DB[i].rating3 + DB[i].rating4 + DB[i].rating5;
		cout << " Surname: " << DB[i].surname << "\t  Name: " << DB[i].name << "\t  Rating: " << DB[i].rating1 << "\t" << DB[i].rating2 << "\t" << DB[i].rating3 << "\t" << DB[i].rating4 << "\t" << DB[i].rating5 << "\t Average score: " << z/5 << endl;
	}
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
			if (((DB[i].rating1+ DB[i].rating2+ DB[i].rating3+ DB[i].rating4+ DB[i].rating5)/5)> ((DB[i + 1].rating1+ DB[i + 1].rating2+ DB[i + 1].rating3+ DB[i + 1].rating4+ DB[i + 1].rating5)/5))
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

void ShowStud(TelBook * DB, int size)
{
	int n = 0;
	double z;
	for (int i = 0; i < size; ++i)
	{
		z = DB[i].rating1 + DB[i].rating2 + DB[i].rating3 + DB[i].rating4 + DB[i].rating5;
		if (z/5 > 7.5)
		{
			cout << " Surname: " << DB[i].surname << "\t  Name: " << DB[i].name << "\t  Rating: " << DB[i].rating1 << "\t" << DB[i].rating2 << "\t" << DB[i].rating3 << "\t" << DB[i].rating4 << "\t" << DB[i].rating5 << "\t Average score: " << z/5 << endl;
			n++;
		}
	}
	if (n == 0) cout << "Not found!" << endl;

}