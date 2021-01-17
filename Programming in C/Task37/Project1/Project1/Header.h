#pragma once
#include "iostream"
using namespace std;

struct Date
{
	int day;
	int month;
	int year;
};

struct Employees
{
	char Surname[32];
	char Name[32];
	char Patronymic[32];
	char Sex[2];
	Date Birthday;
	Date Admission;
	Date Today;
};

Employees *Create(Employees *DB, int size);
void InitDB(Employees *DB, int size);
Employees *AddDB(Employees * DB, int size, int sizeN);
void ShowDB(Employees * DB, int size);
void DelDB(Employees * DB);
double AgeEmp(Employees *DB, int size, double *Age, int d, int m, int y);
double Standing(Employees *DB, int size, double *Stand, int d, int m, int y);
Employees *AddEmpl(Employees * DB, int size);
Employees *DelEmpl(Employees * DB, int size, char *sur, char *nm);
Employees *EditSur(Employees * DB, int size, char *sur, char *nm);
void FindSur(Employees * DB, int size, char *sur);
void FindAge(Employees * DB, int size, double *Age, int Fa);
void FindSymb(Employees *DB, int size);
void FindBirth(Employees *DB, int size, int m);
void FindMale(Employees *DB, int size);
void FindFemale(Employees *DB, int size);
void FindPens(Employees *DB, int size, double *Age, double *Stand);