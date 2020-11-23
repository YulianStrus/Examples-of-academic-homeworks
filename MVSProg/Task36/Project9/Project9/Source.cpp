#include "iostream"
using namespace std;

struct TelBook
{
	char Destination[32];
	int DepartHour;
	int DepartMin;
	int ArrivalHour;
	int ArrivalMin;
};

void InitDB(TelBook *DB);
void ShowTimeT(TelBook *DB, int size);
void DelArr(TelBook *DB);
TelBook* AddDest(TelBook *DB, int size);
TelBook* DelDest(TelBook *DB, int size, char *dest, int h, int m);

void main()
{
	int size = 5;
	TelBook *DB = new TelBook[size];
	int h, m;
	char a=0, dest[32];
	InitDB(DB);
	while (a != 'q')
	{
		cout << "\nEnter number: " << endl;
		cout << "\n\t1 - Bus timetable" << "\n\t2 - Delete flight" << "\n\t3 - Add flight" << "\n\tq - Exit" << endl;
		cin >> a;
		cout << endl;
		switch (a)
		{
		case '1':
			ShowTimeT(DB, size);
			break;
		case '2':
			cout << "Enter destination to delete: " << endl;
			cin.ignore();
			cin.getline(dest, 32);
			cout << "Enter hour: " << endl;
			cin >> h;
			cout << "Enter minutes: " << endl;
			cin >> m;
			DB = DelDest(DB, size, dest, h, m);
			size--;
			break;
		case '3':
			DB = AddDest(DB, size);
			size++;
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
	DB[0] = { "Kyiv", 10, 20, 14, 50};
	DB[1] = { "Lvov", 8, 35, 11, 25 };
	DB[2] = { "Vinnica", 11, 00, 12, 20 };
	DB[3] = { "Odesa", 23, 30, 6, 10 };
	DB[4] = { "Ternopol", 12, 50, 14, 30 };
}
void ShowTimeT(TelBook *DB, int size)
{
	for (int i = 0; i < size; i++)
		cout << "Destination: " << DB[i].Destination << "\t Bus departure time: " << DB[i].DepartHour << ":" << DB[i].DepartMin << "\t Bus arrival time: " << DB[i].ArrivalHour << ":" << DB[i].ArrivalMin << endl;
}
void DelArr(TelBook * DB)
{
	delete[] DB;
}

TelBook* AddDest(TelBook *DB, int size)
{
	TelBook *tmp = new TelBook[size + 1];
	for (int i = 0; i < size; ++i)
		tmp[i] = DB[i];

	cin.ignore();
	cout << "Enter destination: ";
	cin.getline(tmp[size].Destination, 32);
	cout << "Enter departure hour: ";
	cin >> tmp[size].DepartHour;
	cout << "Enter departure minute: ";
	cin >> tmp[size].DepartMin;
	cout << "Enter arrival hour: ";
	cin >> tmp[size].ArrivalHour;
	cout << "Enter arrival minute: ";
	cin >> tmp[size].ArrivalMin;

	DelArr(DB);
	++size;
	DB = new TelBook[size];
	for (int i = 0; i < size; ++i)
		DB[i] = tmp[i];

	DelArr(tmp);
	return DB;
}
TelBook* DelDest(TelBook *DB, int size, char *dest, int h, int m)
{
	int n;
	for (int i = 0; i < size; i++)
	{
		if ((stricmp(DB[i].Destination, dest)==0)&(DB[i].DepartHour == h)&(DB[i].DepartMin == m)) n = i;
	}
	size--;
	TelBook *tmp = new TelBook[size];
	for (int i = 0; i < n; ++i)
		tmp[i] = DB[i];

	for (int i = n; i < size; ++i)
		tmp[i] = DB[i + 1];

	DelArr(DB);

	DB = new TelBook[size];
	for (int i = 0; i < size; ++i)
		DB[i] = tmp[i];

	DelArr(tmp);
	return DB;
}