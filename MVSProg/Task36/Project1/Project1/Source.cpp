#include "iostream"
using namespace std;

struct TelBook
{
	char surname[32];
	char name[32];
	char adress[64];
	int telnumber;
};

void InitDB(TelBook *DB);
void ShowAbonem(TelBook *DB, int size);
void DelArr(TelBook *DB);
TelBook* AddAbonem(TelBook *DB, int size);
void FindOksana(TelBook * DB, int size);


void main()
{
	int size = 5;
	TelBook *DB = new TelBook[size];
	InitDB(DB);
	char a=0;
	while (a != 'q')
	{
	cout << "\nEnter number: " << endl;
	cout << "\t1 - Show of all subscribers" << "\n\t2 - Add abonent" << "\n\t3 - Find a girlfriend Oksana" << "\n\tq - Exit" << endl;
	cin >> a;
	cout << endl;
		switch (a)
		{
		case '1':
			ShowAbonem(DB, size);
			break;
		case '2':
			DB = AddAbonem(DB, size);
			size++;
			break;
		case '3':
			FindOksana(DB, size);
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
	DB[0] = { "Juhim", "Fedir", "Lviv", 687139546 };
	DB[1] = { "Susel", "Ivan", "Kyiv", 429781235 };
	DB[2] = { "Bobra", "Taras", "Harkiv", 649782102 };
	DB[3] = { "Livan", "Oksana", "Sumy", 479513782 };
	DB[4] = { "Kalin", "Olena", "Odesa", 479316852 };
}
void ShowAbonem(TelBook * DB, int size)
{
	for (int i = 0; i < size; i++)
		cout << "Surname: " << DB[i].surname << "\t\t Name: " << DB[i].name << "\t\t Adress: " << DB[i].adress << "\t\t Namber: " << DB[i].telnumber << endl;
}
void DelArr(TelBook * DB)
{
	delete[] DB;
}
TelBook* AddAbonem(TelBook * DB, int size)
{
	TelBook *tmp = new TelBook[size + 1];
	for (int i = 0; i < size; ++i)
		tmp[i] = DB[i];
	cin.ignore();
	cout << "Enter surname: ";
	cin.getline(tmp[size].surname, 32);
	cout << "Enter name: ";
	cin.getline(tmp[size].name, 32);
	cout << "Enter adress: ";
	cin.getline(tmp[size].adress, 64);
	cout << "Enter namber: ";
	cin >> tmp[size].telnumber;

	DelArr(DB);
	++size;
	DB = new TelBook[size];
	for (int i = 0; i < size; ++i)
		DB[i] = tmp[i];

	DelArr(tmp);
	return DB;

}
void FindOksana(TelBook * DB, int size)
{
	char fd[32] = { "Oksana" };
	int F;
	for (int i = 0; i < size; i++)
	{
		F = stricmp(DB[i].name, fd);
		if (F == 0) cout << "Surname: " << DB[i].surname << "\t\t Name: " << DB[i].name << "\t\t Adress: " << DB[i].adress << "\t\t Namber: " << DB[i].telnumber << endl;
	}
}
