#include "iostream"
#include "stdio.h"
using namespace std;

struct TelBook
{
	char author[32];
	char name[32];
	int date;
	int price;
};

void InitDB(TelBook *DB);
void ShowDB(TelBook *DB, int size);
void DelArr(TelBook *DB);
void FindForAuthor(TelBook *DB, char *fd, int size);
void FindForDate(TelBook *DB, int size);

void main()
{
	int size = 5;
	TelBook *DB = new TelBook[size];
	char a = 0;
	char fd[32];
	InitDB(DB);
	while (a != 'q')
	{
		cout << "\nEnter number: " << endl;
		cout << "\t1 - Show of all Book" << "\n\t2 - Find for author" << "\n\t3 - Find for Date" << "\n\tq - Exit" << endl;
		cin >> a;
		cout << endl;
		switch (a)
		{
		case '1':
			ShowDB(DB, size);
			break;
		case '2':
			cout << "Enter author to search: " << endl;
			cin.ignore();
			cin.getline(fd, 32);
			FindForAuthor(DB, fd, size);
			break;
		case '3':
			FindForDate(DB, size);
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
	DB[0] = { "Franko I.J", "Zahar Berkut", 2000, 120 };
	DB[1] = { "Kostenko l.", "Krula", 2008, 80 };
	DB[2] = { "Kotljarevskij I.", "Eneida", 2010, 170};
	DB[3] = { "Franko I.J", "Boruslav Smijetsja", 2008, 90};
	DB[4] = { "Skrjabin", "Ja Pobeda i Berlin", 2015, 180};
}
void ShowDB(TelBook * DB, int size)
{
	for (int i = 0; i < size; i++)
		cout << "Author: " << DB[i].author << "\t Name: " << DB[i].name << "\t Date: " << DB[i].date << "\t Price: " << DB[i].price << endl;
}
void DelArr(TelBook * DB)
{
	delete[] DB;
}

void FindForAuthor(TelBook * DB, char *fd, int size)
{
	int F, n = 0;
	for (int i = 0; i < size; i++)
	{
		F = stricmp(DB[i].author, fd);
		if (F == 0)
		{
			cout << "Author: " << DB[i].author << "\t Name: " << DB[i].name << "\t Date: " << DB[i].date << "\t Price: " << DB[i].price << endl;
			n++;
		}
	}
	if (n == 0) cout << "Not found!" << endl;
}

void FindForDate(TelBook *DB, int size)
{
	int n = 0;
	for (int i = 0; i < size; i++)
	{
		if ((2018-DB[i].date) == 10)
		{
			cout << "Author: " << DB[i].author << "\t Name: " << DB[i].name << "\t Date: " << DB[i].date << "\t Price: " << DB[i].price << endl;
			n++;
		}
	}
	if (n == 0) cout << "Not found!" << endl;
}