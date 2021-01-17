#include "iostream"
using namespace std;

struct TelBook
{
	int dayB;
	int monthB;
	int yearB;
	int dayJ;
	int monthJ;
	int yearJ;
	char position[32];
	char surname[32];
	char name[32];
	char fatherName[64];
};

void InitDB(TelBook *DB);
void ShowDB(TelBook *DB, int size);
void DelArr(TelBook *DB);
void ShowWorker(TelBook * DB, int size);


void main()
{
	int size = 5;
	TelBook *DB = new TelBook[size];
	InitDB(DB);
	ShowDB(DB, size);
	cout << endl << endl << "Workers over 15 years of age, but not pensioners:" << endl;
	ShowWorker(DB, size);
	DelArr(DB);

	system("pause");
}


void InitDB(TelBook *DB)
{
	DB[0] = { 15, 3, 1980, 3, 7, 1993, "Project manager", "Krajnja", "Elvira", "Ivanivna"};
	DB[1] = { 21, 8, 1951, 14, 10, 2000, "Secretary", "Kipeckij", "Bohdana", "Valerivna"};
	DB[2] = { 6, 11, 1976, 22, 4, 1998, "Office worker", "Antenko", "Nazarij", "Petrovich" };
	DB[3] = { 18, 4, 1963, 7, 12, 2005, "Salesman", "Mitelskij", "Valerij", "Zenovijovich"};
	DB[4] = { 9, 12, 1988, 13, 2, 2010, "Manager", "Boreckij", "Sergij", "Ruslanovich"};
}
void ShowDB(TelBook * DB, int size)
{
	for (int i = 0; i < size; i++)
		cout << " Day birthday: " << DB[i].dayB << "." << DB[i].monthB << "." << DB[i].yearB << "\t  Date of joining: " << DB[i].dayJ << "." << DB[i].monthJ << "." << DB[i].yearJ << "\t Position: " << DB[i].position << "\t\t Full name: " << DB[i].surname << " " << DB[i].name << " " << DB[i].fatherName << endl;
}
void DelArr(TelBook * DB)
{
	delete[] DB;
}

void ShowWorker(TelBook * DB, int size)
{
	int a = 0;
	for (int i = 0; i < size; ++i)
	{
		if (((2018 - DB[i].yearJ) > 15) & ((2018 - DB[i].yearB < 65)))
		{
			cout << " Day birthday: " << DB[i].dayB << "." << DB[i].monthB << "." << DB[i].yearB << "\t  Date of joining: " << DB[i].dayJ << "." << DB[i].monthJ << "." << DB[i].yearJ << "\t Position: " << DB[i].position << "\t\t Full name: " << DB[i].surname << " " << DB[i].name << " " << DB[i].fatherName << endl;
			a++;
		}
	}
	if (a==0) cout << "Not found!" << endl;
}