#include "iostream"
using namespace std;

struct TelBook
{
	char name[32];
	char surname[32];
	char sex[32];
	int age;
	int growth;
	int	weight;
};

void InitDB(TelBook *DB, int size);
void ShowAbonem(TelBook *DB, int size);
void DelArr(TelBook *DB);
TelBook *EditAbonem(TelBook * DB, char *nm, char *snm, int size);



void main()
{
	int size = 3;
	TelBook *DB = new TelBook[size];
	int a; 	
	char nm[32], snm[32];
	cout << "Enter the number of people: ";
	cin >> size;
	cout << endl;
	cin.ignore();
	InitDB(DB, size);
	cout << "\nEnter number: " << endl;
	cout << "\n\t1 - Show of all subscribers" << "\n\t2 - Edit abonent" << endl;
	cin >> a;
	cout << endl;
	switch (a)
	{
	case 1:
		ShowAbonem(DB, size);
		break;
	case 2:
		cout << "Enter name: " << endl;
		cin >> nm;
		cout << "Enter surname: " << endl;
		cin >> snm;
		DB = EditAbonem(DB, nm, snm, size);
		ShowAbonem(DB, size);
		DelArr(DB);
		break;

	default: cout << "Error!" << endl; break;
	}

	system("pause");
}


void InitDB(TelBook *DB, int size)
{
	for (int i = 0; i < size; i++)
	{
		
		cout << "Enter name: ";
		cin.getline(DB[i].name, 32);
		cout << "Enter surname: ";
		cin.getline(DB[i].surname, 32);
		cout << "Enter sex: ";
		cin.getline(DB[i].sex, 32);
		cout << "Enter age: ";
		cin >> DB[i].age;
		cout << "Enter growth: ";
		cin >> DB[i].growth;
		cout << "Enter weight: ";
		cin >> DB[i].weight;
		cin.get();
		cout << endl;
	}
}
void ShowAbonem(TelBook * DB, int size)
{
	cout << "   Name: " << "\t\tSurname: " << "\tSex: " << "\tAge: " << "\tGrowth: " << "\tWeight: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << "  " << DB[i].name << "\t\t" << DB[i].surname << "\t\t" << DB[i].sex << "\t" << DB[i].age << "\t" << DB[i].growth << "\t\t" << DB[i].weight << endl;
	}
}
void DelArr(TelBook * DB)
{
	delete[] DB;
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
		strcpy(tmp[i].sex, DB[i].sex);
		tmp[i].age = DB[i].age;
		tmp[i].growth = DB[i].growth;
		tmp[i].weight = DB[i].weight;
	}
	
	cout << "\nEnter new name: ";
	cin.getline(tmp[n].name, 32);
	cout << "Enter new surname: ";
	cin.getline(tmp[n].surname, 32);
	cout << "Enter new sex: ";
	cin.getline(tmp[n].sex, 32);
	cout << "Enter new age: ";
	cin >> tmp[n].age;
	cout << "Enter new growth: ";
	cin >> tmp[n].growth;
	cout << "Enter new weight: ";
	cin >> tmp[n].weight;

	for (int i = n + 1; i < size; ++i)
	{
		strcpy(tmp[i].name, DB[i].name);
		strcpy(tmp[i].surname, DB[i].surname);
		strcpy(tmp[i].sex, DB[i].sex);
		tmp[i].age = DB[i].age;
		tmp[i].growth = DB[i].growth;
		tmp[i].weight = DB[i].weight;
	}
	DelArr(DB);

	DB = new TelBook[size];
	for (int i = 0; i < size; ++i)
	{
		strcpy(DB[i].name, tmp[i].name);
		strcpy(DB[i].surname, tmp[i].surname);
		strcpy(DB[i].sex, tmp[i].sex);
		DB[i].age = tmp[i].age;
		DB[i].growth = tmp[i].growth;
		DB[i].weight = tmp[i].weight;
	}

	DelArr(tmp);
	return DB;
}