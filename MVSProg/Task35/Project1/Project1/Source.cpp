#include "iostream"
using namespace std;

struct TelBook
{
	char name[32];
	char surname[32];
	int telnumber;
};

void InitDB(TelBook *DB);
void ShowAbonem(TelBook *DB, int size);
void DelArr(TelBook *DB);
TelBook *EditAbonem(TelBook * DB, char *nm, char *snm, int size);
TelBook* AddAbonem(TelBook *DB, int size);
void FindForSurname(TelBook *DB, char *fd, int size);
void FindForNum(TelBook *DB, int size, int num);
TelBook* DelAbonem(TelBook *DB, int size, int num);

void main()
{
	int size = 5;
	TelBook *DB = new TelBook[size];
	int a,num; 	
	char fd[32], nm[32], snm[32];
	InitDB(DB);
	cout << "\nEnter number: " << endl;
	cout << "\t1 - Add abonent" << "\n\t2 - Delete abonent" << "\n\t3 - Edit abonent" << "\n\t4 - Show of all subscribers" << "\n\t5 - Find for surname" << "\n\t6 - Find for number" << endl;
	cin >> a;
	cout << endl;
	switch (a)
	{
	case 1: 
		DB = AddAbonem(DB, size); 
		size++;
		ShowAbonem(DB, size);
		DelArr(DB);
		break;
	case 2:
		cout << "Enter tel number to delete: " << endl;
		cin >> num;
		DB = DelAbonem(DB, size, num);
		size--;
		ShowAbonem(DB, size);
		DelArr(DB);
		break;
	case 3:
		cout << "Enter name: " << endl;
		cin >> nm;
		cout << "Enter surname: " << endl;
		cin >> snm;
		DB = EditAbonem(DB, nm, snm, size);
		ShowAbonem(DB, size);
		DelArr(DB);
		break;
	case 4:
		ShowAbonem(DB, size);
		break;
	case 5: 
		cout << "Enter surname to search: " << endl;
		cin >> fd;
		FindForSurname(DB, fd, size);
		break;
	case 6:
		cout << "Enter number to search: " << endl;
		cin >> num;
		FindForNum(DB, size, num); 
		break;
	default: cout << "Error!" << endl; break;
	}

	system("pause");
}


void InitDB(TelBook *DB)
{
	DB[0] = { "Vlad", "Kugaevskuj", 687139546 };
	DB[1] = { "Yulian", "Strus\'", 429781235 };
	DB[2] = { "Danulo", "Bodnar", 649782102};
	DB[3] = { "Volodja", "Zabolotnuj", 479513782};
	DB[4] = { "Nazar", "Potipaka", 479316852};
}
void ShowAbonem(TelBook * DB, int size)
{
	for (int i = 0; i < size; i++)
		cout << "Name: " << DB[i].name << "\t\t Surname: " << DB[i].surname << "\t\t Namber: " << DB[i].telnumber << endl;
}
void DelArr(TelBook * DB)
{
	delete [] DB;
}

TelBook* AddAbonem(TelBook * DB, int size)
{
	TelBook *tmp = new TelBook[size+1];
		for (int i = 0; i < size; ++i)
		{
			strcpy(tmp[i].name, DB[i].name);
			strcpy(tmp[i].surname, DB[i].surname);
			tmp[i].telnumber = DB[i].telnumber;
		}
		cin.ignore();
		cout << "Enter name: ";
		cin.getline(tmp[size].name, 32);
		cout << "Enter surname: ";
		cin.getline(tmp[size].surname, 32);
		cout << "Enter namber: ";
		cin >> tmp[size].telnumber;

		DelArr(DB);
		++size;
		DB = new TelBook[size];
		for (int i = 0; i < size; ++i)
		{
			strcpy(DB[i].name, tmp[i].name);
			strcpy(DB[i].surname, tmp[i].surname);
			DB[i].telnumber = tmp[i].telnumber;
		}

		DelArr(tmp);
		return DB;
}
TelBook *DelAbonem(TelBook * DB, int size, int num)
{
	int n;
	for (int i = 0; i < size; i++)
	{
		if (DB[i].telnumber == num) n = i;
	}
	size--;
	TelBook *tmp = new TelBook[size];
	for (int i = 0; i < n; ++i)
	{
		strcpy(tmp[i].name, DB[i].name);
		strcpy(tmp[i].surname, DB[i].surname);
		tmp[i].telnumber = DB[i].telnumber;
	}
	for (int i = n; i < size; ++i)
	{
		strcpy(tmp[i].name, DB[i + 1].name);
		strcpy(tmp[i].surname, DB[i + 1].surname);
		tmp[i].telnumber = DB[i + 1].telnumber;
	}
	DelArr(DB);

	DB = new TelBook[size];
	for (int i = 0; i < size; ++i)
	{
		strcpy(DB[i].name, tmp[i].name);
		strcpy(DB[i].surname, tmp[i].surname);
		DB[i].telnumber = tmp[i].telnumber;
	}

	DelArr(tmp);
	return DB;
}

TelBook *EditAbonem(TelBook * DB, char *nm, char *snm, int size)
{
	int n;
	for (int i = 0; i < size; i++)
	{
		int N = stricmp(DB[i].name, nm);
		int M = stricmp(DB[i].surname, snm);
			if ((N == 0)&(M == 0)) n = i;
	}
	
	TelBook *tmp = new TelBook[size];
	for (int i = 0; i < n; ++i)
	{
		strcpy(tmp[i].name, DB[i].name);
		strcpy(tmp[i].surname, DB[i].surname);
		tmp[i].telnumber = DB[i].telnumber;
	}
	cin.ignore();
	cout << "Enter new name: ";
	cin.getline(tmp[n].name, 32);
	cout << "Enter new surname: ";
	cin.getline(tmp[n].surname, 32);
	cout << "Enter new namber: ";
	cin >> tmp[n].telnumber;

	for (int i = n+1; i < size; ++i)
	{
		strcpy(tmp[i].name, DB[i].name);
		strcpy(tmp[i].surname, DB[i].surname);
		tmp[i].telnumber = DB[i].telnumber;
	}
	DelArr(DB);

	DB = new TelBook[size];
	for (int i = 0; i < size; ++i)
	{
		strcpy(DB[i].name, tmp[i].name);
		strcpy(DB[i].surname, tmp[i].surname);
		DB[i].telnumber = tmp[i].telnumber;
	}

	DelArr(tmp);
	return DB;
}

void FindForSurname(TelBook * DB, char *fd, int size)
{
	int F;
	for (int i = 0; i < size; i++)
	{
		F = stricmp(DB[i].surname, fd);
		if (F == 0) cout << "Name: " << DB[i].name << "\t\t Surname: " << DB[i].surname << "\t\t Namber: " << DB[i].telnumber << endl;
	}
}
void FindForNum(TelBook * DB, int size, int num)
{
	for (int i = 0; i < size; i++)
	{
		if (DB[i].telnumber == num) cout << "Name: " << DB[i].name << "\t\t Surname: " << DB[i].surname << "\t\t Namber: " << DB[i].telnumber << endl;
	}
}