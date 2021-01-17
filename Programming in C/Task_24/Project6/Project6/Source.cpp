#include "iostream"
using namespace std;

struct TelBook
{
	char surname[32];
	char name[32];
	int telnumber;
	char avto[32];
	char numavto[10];
};

void InitDB(TelBook *DB);
void ShowDB(TelBook *DB, int size);
void DelArr(TelBook *DB);
void FindForModel(TelBook *DB, char *fd, int size);

void main()
{
	int size = 5;
	TelBook *DB = new TelBook[size];
	char a = 0, fd[32];
	InitDB(DB);
	while (a != 'q')
	{
		cout << "\nEnter number: " << endl;
		cout << "\t1 - Show of all avto" << "\n\t2 - Find for number" << "\n\tq - Exit" << endl;
		cin >> a;
		cout << endl;
		switch (a)
		{
		case '1':
			ShowDB(DB, size);
			break;
		case '2':
			cout << "Enter model to search: " << endl;
			cin >> fd;
			FindForModel(DB, fd, size);
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
	DB[0] = { "Ferat", "Yurij", 159736842, "Lifan", "BC3250AE" };
	DB[1] = { "Pirash", "Taras", 716984352, "Lanos", "BX5294BB" };
	DB[2] = { "Opanas", "Inna", 794813852, "Dodge", "AE3748TK" };
	DB[3] = { "Biban", "David", 924853748, "Renault", "AT9647XE" };
	DB[4] = { "Ulan", "Olena", 197337915, "Deawoo", "AA4821OT" };
}
void ShowDB(TelBook * DB, int size)
{
	for (int i = 0; i < size; i++)
		cout << "Surname: " << DB[i].surname << "\t Name: " << DB[i].name << "\t Namber: " << DB[i].telnumber << "\t Model avto: " << DB[i].avto << "\t Namber avto: " << DB[i].numavto << endl;
}
void DelArr(TelBook * DB)
{
	delete[] DB;
}

void FindForModel(TelBook * DB, char *fd, int size)
{
	int F, n = 0;
	for (int i = 0; i < size; i++)
	{
		F = stricmp(DB[i].avto, fd);
		if (F == 0)
		{
			cout << "Surname: " << DB[i].surname << "\t Name: " << DB[i].name << "\t Namber: " << DB[i].telnumber << "\t Model avto: " << DB[i].avto << "\t Namber avto: " << DB[i].numavto << endl;
			n++;
		}
	}
	if (n == 0) cout << "Not found!" << endl;
}