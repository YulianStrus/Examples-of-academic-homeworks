#pragma once
#include "iostream"
#include "Header.h"
#include "iomanip"

Employees *Create(Employees *DB, int size)
{
	DB = new Employees[size];
	return DB;
}

void InitDB(Employees *DB, int size)
{
	DB[0] = { "Petrov", "Mukola", "Muhajlovich", "M", 5, 12, 1985, 12, 5, 2000};
	DB[1] = { "Ivanova", "Polina", "Vasulivna", "F", 14, 9, 1954, 21, 8, 2000};
	DB[2] = { "Galkina", "Larisa", "Pavlivna", "F", 30, 1, 1999, 11, 9, 2017};
	DB[3] = { "Birukin", "Vitalij", "Petrovich", "M", 19, 6, 1986, 3, 12, 2010};
	DB[4] = { "Koval\'", "Taras", "Tarasovich", "M", 22, 9, 1961, 9, 11, 1980};
	
}

Employees *AddDB(Employees * DB, int size, int sizeN)
{
	Employees *tmp = new Employees;
	tmp = Create(tmp, sizeN);
	if (sizeN > size)
	{
		for (int i = 0; i < size; i++)
		{
			tmp[i] = DB[i];
		}
		for (int i = size; i < sizeN; i++)
		{
			cin.ignore();
			cout << "Enter surname: ";
			cin.getline(tmp[i].Surname, 32);
			cout << "Enter name: ";
			cin.getline(tmp[i].Name, 32);
			cout << "Enter patronimic: ";
			cin.getline(tmp[i].Patronymic, 32);
			cout << "Enter sex: M - Male F - Female: ";
			cin.getline(tmp[i].Sex, 2);
			cout << "Enter Birthday day: ";
			cin >> tmp[i].Birthday.day;
			cout << "Enter Birthday month: ";
			cin >> tmp[i].Birthday.month;
			cout << "Enter Birthday year: ";
			cin >> tmp[i].Birthday.year;
			cout << "Enter Admission day: ";
			cin >> tmp[i].Admission.day;
			cout << "Enter Admission month: ";
			cin >> tmp[i].Admission.month;
			cout << "Enter Admission year: ";
			cin >> tmp[i].Admission.year;
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < sizeN; i++)
		{
			tmp[i] = DB[i];
		}
	}

	DelDB(DB);

	Create(DB, sizeN);
	for (int i = 0; i < sizeN; i++)
	{
		DB[i] = tmp[i];
	}

	DelDB(tmp);
	return DB;

}

void ShowDB(Employees * DB, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << "  Full name: " << DB[i].Surname << " " << DB[i].Name << " " << DB[i].Patronymic << "\t Sex: " << DB[i].Sex << "\t Date of birth: " << DB[i].Birthday.day << "." << DB[i].Birthday.month << "." << DB[i].Birthday.year << "\t Admission date to work: " << DB[i].Admission.day << "." << DB[i].Admission.month << "." << DB[i].Admission.year << endl;
	}
}

void DelDB(Employees * DB)
{
	delete[] DB;
}

double AgeEmp(Employees *DB, int size, double *Age, int d, int m, int y)
{

	for (int i = 0; i < size; i++)
	{
		if (d - DB[i].Birthday.day > 0)
		{
			if (m - DB[i].Birthday.month > 0)
			{
				Age[i] = (y - DB[i].Birthday.year) + (m - DB[i].Birthday.month) / 12;
			}
			else
			{
				Age[i] = ((y - 1) - DB[i].Birthday.year + ((m + 12) - DB[i].Birthday.month) / 12);
			}
		}
		else
		{
			if ((m - 1) - DB[i].Birthday.month > 0)
			{
				Age[i] = (y - DB[i].Birthday.year) + (m - DB[i].Birthday.month) / 12;
			}
			else
			{
				Age[i] = ((y - 1) - DB[i].Birthday.year + ((m + 12) - DB[i].Birthday.month) / 12);
			}
		}
	}

	return *Age;
}

double Standing(Employees *DB, int size, double *Stand, int d, int m, int y)
{
	for (int i = 0; i < size; i++)
	{
		if (d - DB[i].Admission.day > 0)
		{
			if (m - DB[i].Admission.month > 0)
			{
				Stand[i] = (y - DB[i].Admission.year) + (m - DB[i].Admission.month)/12;
			}
			else
			{
				Stand[i] = ((y - 1) - DB[i].Admission.year)+ ((m + 12) - DB[i].Admission.month) / 12;
			}
		}
		else
		{
			if ((m - 1) - DB[i].Admission.month > 0)
			{
				Stand[i] = (y - DB[i].Admission.year) + (m - DB[i].Admission.month) / 12;
			}
			else
			{
				Stand[i] = ((y - 1) - DB[i].Admission.year) + ((m + 12) - DB[i].Admission.month) / 12;
			}
		}

	}
	return *Stand;
}

Employees *AddEmpl(Employees * DB, int size)
{
	Employees *tmp = new Employees;
	tmp = Create(tmp, size++);
	
	for (int i = 0; i < size; i++)
	{
		tmp[i] = DB[i];
	}
	cin.ignore();
	cout << "Enter surname: ";
	cin.getline(tmp[size].Surname, 32);
	cout << "Enter name: ";
	cin.getline(tmp[size].Name, 32);
	cout << "Enter patronimic: ";
	cin.getline(tmp[size].Patronymic, 32);
	cout << "Enter sex: M - Male F - Female: ";
	cin.getline(tmp[size].Sex, 2);
	cout << "Enter Birthday day: ";
	cin >> tmp[size].Birthday.day;
	cout << "Enter Birthday month: ";
	cin >> tmp[size].Birthday.month;
	cout << "Enter Birthday year: ";
	cin >> tmp[size].Birthday.year;
	cout << "Enter Admission day: ";
	cin >> tmp[size].Admission.day;
	cout << "Enter Admission month: ";
	cin >> tmp[size].Admission.month;
	cout << "Enter Admission year: ";
	cin >> tmp[size].Admission.year;
	cout << endl;


	DelDB(DB);

	size++;
	Create(DB, size);
	for (int i = 0; i < size; i++)
	{
		DB[i] = tmp[i];
	}

	DelDB(tmp);
	return DB;

}

Employees *DelEmpl(Employees * DB, int size, char *sur, char *nm)
{
	Employees *tmp = new Employees;
	tmp = Create(tmp, size--);
	int n;
	for (int i = 0; i < size; i++)
	{

		if ((stricmp(DB[i].Surname, sur) == 0)&(stricmp(DB[i].Name, nm) == 0))
			n = i;
	}

	for (int i = 0; i < n; i++)
	{
		tmp[i] = DB[i];
	}
	for (int i = n; i < size; i++)
	{
		tmp[i] = DB[i+1];
	}

	DelDB(DB);
	
	size--;
	Create(DB, size);
	for (int i = 0; i < size; i++)
	{
		DB[i] = tmp[i];
	}

	DelDB(tmp);
	return DB;
}

Employees *EditSur(Employees * DB, int size, char *sur, char *nm)
{

	for (int i = 0; i < size; i++)
	{

		if ((stricmp(DB[i].Surname, sur) == 0)&(stricmp(DB[i].Name, nm) == 0))
		{
			cin.ignore();
			cout << "Enter new surname: ";
			cin.getline(DB[i].Surname, 32);
		}
	}
	
	return DB;
}

void FindSur(Employees * DB, int size, char *sur)
{

	for (int i = 0; i < size; i++)
	{

		if (stricmp(DB[i].Surname, sur) == 0)
			cout << i + 1 << "  Full name: " << DB[i].Surname << " " << DB[i].Name << " " << DB[i].Patronymic << "\t Sex: " << DB[i].Sex << "\t Date of birth: " << DB[i].Birthday.day << "." << DB[i].Birthday.month << "." << DB[i].Birthday.year << "\t Admission date to work: " << DB[i].Admission.day << "." << DB[i].Admission.month << "." << DB[i].Admission.year << endl;
	}
}

void FindAge(Employees * DB, int size, double *Age, int Fa)
{
	for (int i = 0; i < size; i++)
	{

		if (Age[i]==Fa)
			cout << i + 1 << "  Full name: " << DB[i].Surname << " " << DB[i].Name << " " << DB[i].Patronymic << "\t Sex: " << DB[i].Sex << "\t Date of birth: " << DB[i].Birthday.day << "." << DB[i].Birthday.month << "." << DB[i].Birthday.year << "\t Admission date to work: " << DB[i].Admission.day << "." << DB[i].Admission.month << "." << DB[i].Admission.year << endl;
	}
}

void FindSymb(Employees *DB, int size)
{
	char symb[2];
	cout << "Enter symbol: ";
	cin.ignore();
	cin.getline (symb, 2);
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		if (strnicmp(symb, DB[i].Surname, 1) == 0)
			cout << i + 1 << "  Full name: " << DB[i].Surname << " " << DB[i].Name << " " << DB[i].Patronymic << "\t Sex: " << DB[i].Sex << "\t Date of birth: " << DB[i].Birthday.day << "." << DB[i].Birthday.month << "." << DB[i].Birthday.year << "\t Admission date to work: " << DB[i].Admission.day << "." << DB[i].Admission.month << "." << DB[i].Admission.year << endl;
	}
}

void FindBirth(Employees *DB, int size, int m)
{
	int n=0;
	cout << "Birthday of the month:" << endl;
	for (int i = 0; i < size; i++)
	{
		if (DB[i].Birthday.month == m)
		{
			cout << i + 1 << "  Full name: " << DB[i].Surname << " " << DB[i].Name << " " << DB[i].Patronymic << "\t Sex: " << DB[i].Sex << "\t Date of birth: " << DB[i].Birthday.day << "." << DB[i].Birthday.month << "." << DB[i].Birthday.year << "\t Admission date to work: " << DB[i].Admission.day << "." << DB[i].Admission.month << "." << DB[i].Admission.year << endl;
			n++;
		}
	}
	if (n == 0) cout << "Not birthday of the month!" << endl;
}

void FindMale(Employees *DB, int size)
{
	int n = 0;
	cout << "Male:" << endl;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(DB[i].Sex, "M") == 0)
		{
			cout << i + 1 << "  Full name: " << DB[i].Surname << " " << DB[i].Name << " " << DB[i].Patronymic << "\t Sex: " << DB[i].Sex << "\t Date of birth: " << DB[i].Birthday.day << "." << DB[i].Birthday.month << "." << DB[i].Birthday.year << "\t Admission date to work: " << DB[i].Admission.day << "." << DB[i].Admission.month << "." << DB[i].Admission.year << endl;
			n++;
		}
	}
	if (n == 0) cout << "Not male!" << endl;
}

void FindFemale(Employees *DB, int size)
{
	int n = 0;
	cout << "Female:" << endl;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(DB[i].Sex, "F") == 0)
		{
			cout << i + 1 << "  Full name: " << DB[i].Surname << " " << DB[i].Name << " " << DB[i].Patronymic << "\t Sex: " << DB[i].Sex << "\t Date of birth: " << DB[i].Birthday.day << "." << DB[i].Birthday.month << "." << DB[i].Birthday.year << "\t Admission date to work: " << DB[i].Admission.day << "." << DB[i].Admission.month << "." << DB[i].Admission.year << endl;
			n++;
		}
	}
	if (n == 0) cout << "Not female!" << endl;
}

void FindPens(Employees *DB, int size, double *Age, double *Stand)
{
	int n = 0;
	cout << "Pensioner:" << endl;
	for (int i = 0; i < size; i++)
	{
		if (((strcmp(DB[i].Sex, "M") == 0)&(Age[i]>62)|(Stand[i]>35))|((strcmp(DB[i].Sex, "F") == 0)&(Age[i] > 60)|(Stand[i] > 30)))
		{
			cout << i + 1 << "  Full name: " << DB[i].Surname << " " << DB[i].Name << " " << DB[i].Patronymic << "\t Sex: " << DB[i].Sex << "\t Date of birth: " << DB[i].Birthday.day << "." << DB[i].Birthday.month << "." << DB[i].Birthday.year << "\t Admission date to work: " << DB[i].Admission.day << "." << DB[i].Admission.month << "." << DB[i].Admission.year << endl;
			cout << DB[i].Surname << " " << DB[i].Name << " " << DB[i].Patronymic << "\tAge: " << setprecision(3) << Age[i] << "\tStanding: " << setprecision(3) << Stand[i] << " year" << endl;
			n++;
		}
		cout << endl;
	}
	if (n == 0)
	{
		for (int i = 0; i < size; i++)
		{
			cout << "Not pensioner!" << endl;
			cout << DB[i].Surname << " " << DB[i].Name << " " << DB[i].Patronymic << "\tAge: " << setprecision(3) << Age[i] << "\tStanding: " << setprecision(3) << Stand[i] << " year" << endl;
		}
	}
}