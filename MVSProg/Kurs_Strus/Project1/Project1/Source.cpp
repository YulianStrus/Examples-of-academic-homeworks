#pragma once
#include "iostream"
#include "cstdio"
#include "Header.h"
using namespace std;


SportTab *Create(SportTab *mas, int size)
{
	mas = new SportTab[size];
	return mas;
}

void InitMas(SportTab *mas)
{
	mas[0] = { "Klochkova", "Jana", "Oleksandrivna", 7, 10, 1982, "Ukraine ", "Swiming  ", 4, 0, 0, 0 };
	mas[1] = { "Lomachenko", "Vasul", "Anatolijovich", 17, 02, 1988, "Ukraine ", "Box       ", 2, 0, 0, 0 };
	mas[2] = { "Vernaev   ", "Oleg", "Jurijovich", 29, 9, 1993, "Ukraine ", "Gymnastics", 1, 0, 0, 0 };
	mas[3] = { "Merleni", "Iruni", "Oleksiivna", 8, 2, 1982, "Ukraine ", "Fighting", 1, 0, 0, 0 };
	mas[4] = { "Bilonog", "Jurij", "Grugorovich", 9, 3, 1974, "Ukraine ", "Athletics", 1, 0, 0, 1 };
}

void ShowMas(SportTab *mas, int size, double *Age, double *Awd)
{
	cout << "\tFull name: " << "\t\t\t\tAge: " << "\t\tCountry: " << "\tSport: " << "\t\tAwards: " << "\t\Disqualification:" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << "\t" << mas[i].Surname << " " << mas[i].Name << " " << mas[i].Patronymic << "\t\t" << Age[i] << "\t" << mas[i].Country << "\t" << mas[i].Discipline.Sport << "\t" << Awd[i] << "\t" << mas[i].Discipline.Disqual << endl;
	}
}

void DelArr(SportTab *mas)
{
	delete[] mas;
}

void WriteFile(SportTab *mas, int size)
{
	FILE *f;
	f = fopen("..\\files\\info.txt", "wb");
	for (int i = 0; i < size; i++)
	{
		fwrite(&mas[i], sizeof(SportTab), 1, f);
	}
	fclose(f);
}

void ReadFile(SportTab *mas, int size)
{
	FILE *f;
	f = fopen("..\\files\\ini.txt", "rb");
	fread(mas, sizeof(SportTab), 1, f);
	fclose(f);
}

double AgeEmp(SportTab *mas, int size, double *Age, int d, int m, int y)
{

	for (int i = 0; i < size; i++)
	{
		if (d - mas[i].Birthday.day > 0)
		{
			if (m - mas[i].Birthday.month > 0)
			{
				Age[i] = (y - mas[i].Birthday.year) + (m - mas[i].Birthday.month) / 12;
			}
			else
			{
				Age[i] = ((y - 1) - mas[i].Birthday.year + ((m + 12) - mas[i].Birthday.month) / 12);
			}
		}
		else
		{
			if ((m - 1) - mas[i].Birthday.month > 0)
			{
				Age[i] = (y - mas[i].Birthday.year) + (m - mas[i].Birthday.month) / 12;
			}
			else
			{
				Age[i] = ((y - 1) - mas[i].Birthday.year + ((m + 12) - mas[i].Birthday.month) / 12);
			}
		}
	}

	return *Age;
}

double AwdEmp(SportTab *mas, int size, double *Awd)
{
	for (int i = 0; i < size; i++)
	{
		Awd[i] = mas[i].Discipline.Awards.gold + mas[i].Discipline.Awards.silver + mas[i].Discipline.Awards.bronz;
	}
	return *Awd;
}

SportTab *AddMas(SportTab *mas, int size, int sizeN)
{
	SportTab *tmp = new SportTab;
	tmp = Create(tmp, sizeN);
	if (sizeN > size)
	{
		for (int i = 0; i < size; i++)
		{
			tmp[i] = mas[i];
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
			cout << "Enter Birthday day: ";
			cin >> tmp[i].Birthday.day;
			cout << "Enter Birthday month: ";
			cin >> tmp[i].Birthday.month;
			cout << "Enter Birthday year: ";
			cin >> tmp[i].Birthday.year;
			cout << "Enter country: ";
			cin.getline(tmp[i].Country, 32);
			cout << "Enter sport: ";
			cin.getline(tmp[i].Discipline.Sport, 32);
			cout << "Enter gold medal: ";
			cin >> tmp[i].Discipline.Awards.gold;
			cout << "Enter silver medal: ";
			cin >> tmp[i].Discipline.Awards.silver;
			cout << "Enter bronze medal: ";
			cin >> tmp[i].Discipline.Awards.bronz;
			cout << "Disqualification (\n1 -> Yes or \n0 - No): ";
			cin >> tmp[i].Discipline.Disqual;
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < sizeN; i++)
		{
			tmp[i] = mas[i];
		}
	}

	DelArr(mas);

	Create(mas, sizeN);
	for (int i = 0; i < sizeN; i++)
	{
		mas[i] = tmp[i];
	}

	DelArr(tmp);
	return mas;
}

SportTab *DelElm(SportTab * mas, int size, char *sur, char *nm)
{
	SportTab *tmp = new SportTab;
	tmp = Create(tmp, size--);
	int n;
	for (int i = 0; i < size; i++)
	{

		if ((stricmp(mas[i].Surname, sur) == 0)&(stricmp(mas[i].Name, nm) == 0))
			n = i;
	}

	for (int i = 0; i < n; i++)
	{
		tmp[i] = mas[i];
	}
	for (int i = n; i < size; i++)
	{
		tmp[i] = mas[i + 1];
	}

	DelArr(mas);

	size--;
	Create(mas, size);
	for (int i = 0; i < size; i++)
	{
		mas[i] = tmp[i];
	}

	DelArr(tmp);
	return mas;
}

SportTab *EditSur(SportTab * mas, int size, char *sur, char *nm)
{

	for (int i = 0; i < size; i++)
	{

		if ((stricmp(mas[i].Surname, sur) == 0)&(stricmp(mas[i].Name, nm) == 0))
		{
			cin.ignore();
			cout << "Enter new surname: ";
			cin.getline(mas[i].Surname, 32);
		}
	}

	return mas;
}

SportTab *EditName(SportTab * mas, int size, char *sur, char *nm)
{

	for (int i = 0; i < size; i++)
	{

		if ((stricmp(mas[i].Surname, sur) == 0)&(stricmp(mas[i].Name, nm) == 0))
		{
			cin.ignore();
			cout << "Enter new name: ";
			cin.getline(mas[i].Name, 32);
		}
	}

	return mas;
}

SportTab *EditPatronymic(SportTab * mas, int size, char *sur, char *nm)
{

	for (int i = 0; i < size; i++)
	{

		if ((stricmp(mas[i].Surname, sur) == 0)&(stricmp(mas[i].Name, nm) == 0))
		{
			cin.ignore();
			cout << "Enter new patronymic: ";
			cin.getline(mas[i].Patronymic, 32);
		}
	}

	return mas;
}

SportTab *EditBirth(SportTab * mas, int size, char *sur, char *nm)
{

	for (int i = 0; i < size; i++)
	{

		if ((stricmp(mas[i].Surname, sur) == 0)&(stricmp(mas[i].Name, nm) == 0))
		{
			cin.ignore();
			cout << "Enter new day of birth: ";
			cin >> mas[i].Birthday.day;
			cout << "Enter new month of birth: ";
			cin >> mas[i].Birthday.month;
			cout << "Enter new year of birth: ";
			cin >> mas[i].Birthday.year;
		}
	}

	return mas;
}

SportTab *EditCountry(SportTab * mas, int size, char *sur, char *nm)
{

	for (int i = 0; i < size; i++)
	{

		if ((stricmp(mas[i].Surname, sur) == 0)&(stricmp(mas[i].Name, nm) == 0))
		{
			cin.ignore();
			cout << "Enter new country: ";
			cin.getline(mas[i].Country, 32);
		}
	}

	return mas;
}

SportTab *EditSport(SportTab * mas, int size, char *sur, char *nm)
{

	for (int i = 0; i < size; i++)
	{

		if ((stricmp(mas[i].Surname, sur) == 0)&(stricmp(mas[i].Name, nm) == 0))
		{
			cin.ignore();
			cout << "Enter new sport: ";
			cin.getline(mas[i].Discipline.Sport, 32);
		}
	}

	return mas;
}

SportTab *EditAward(SportTab * mas, int size, char *sur, char *nm)
{

	for (int i = 0; i < size; i++)
	{

		if ((stricmp(mas[i].Surname, sur) == 0)&(stricmp(mas[i].Name, nm) == 0))
		{
			cin.ignore();
			cout << "Enter new award: " << endl;
			cout << "gold: ";
			cin >> mas[i].Discipline.Awards.gold;
			cout << "silver: ";
			cin >> mas[i].Discipline.Awards.silver;
			cout << "bronze: ";
			cin >> mas[i].Discipline.Awards.bronz;
		}
	}

	return mas;
}

SportTab *EditDisqual(SportTab * mas, int size, char *sur, char *nm)
{

	for (int i = 0; i < size; i++)
	{

		if ((stricmp(mas[i].Surname, sur) == 0)&(stricmp(mas[i].Name, nm) == 0))
		{
			cin.ignore();
			cout << "Disqualification (\n1 -> Yes or \n0 -> No): ";
			cin >> mas[i].Discipline.Disqual;
		}
	}

	return mas;
}

void FindSur(SportTab *mas, int size, double *Age, double *Awd, char *sur)
{

	for (int i = 0; i < size; i++)
	{

		if (stricmp(mas[i].Surname, sur) == 0)
			cout << i + 1 << "\t" << mas[i].Surname << " " << mas[i].Name << " " << mas[i].Patronymic << "\t" << Age[i] << "\t" << mas[i].Country << "\t" << mas[i].Discipline.Sport << "\t" << Awd[i] << "\t" << mas[i].Discipline.Disqual << endl;
	}
}

void FindName(SportTab *mas, int size, double *Age, double *Awd, char *nm)
{

	for (int i = 0; i < size; i++)
	{

		if (stricmp(mas[i].Name, nm) == 0)
			cout << i + 1 << "\t" << mas[i].Surname << " " << mas[i].Name << " " << mas[i].Patronymic << "\t" << Age[i] << "\t" << mas[i].Country << "\t" << mas[i].Discipline.Sport << "\t" << Awd[i] << "\t" << mas[i].Discipline.Disqual << endl;
	}
}

void FindPatronymic(SportTab *mas, int size, double *Age, double *Awd, char *ptr)
{

	for (int i = 0; i < size; i++)
	{

		if (stricmp(mas[i].Patronymic, ptr) == 0)
			cout << i + 1 << "\t" << mas[i].Surname << " " << mas[i].Name << " " << mas[i].Patronymic << "\t" << Age[i] << "\t" << mas[i].Country << "\t" << mas[i].Discipline.Sport << "\t" << Awd[i] << "\t" << mas[i].Discipline.Disqual << endl;
	}
}

void FindAge(SportTab *mas, int size, double *Age, double *Awd, int ag)
{

	for (int i = 0; i < size; i++)
	{

		if (Age[i] == ag)
			cout << i + 1 << "\t" << mas[i].Surname << " " << mas[i].Name << " " << mas[i].Patronymic << "\t" << Age[i] << "\t" << mas[i].Country << "\t" << mas[i].Discipline.Sport << "\t" << Awd[i] << "\t" << mas[i].Discipline.Disqual << endl;
	}
}

void FindYear(SportTab *mas, int size, double *Age, double *Awd, int yr)
{

	for (int i = 0; i < size; i++)
	{

		if (mas[i].Birthday.year == yr)
			cout << i + 1 << "\t" << mas[i].Surname << " " << mas[i].Name << " " << mas[i].Patronymic << "\t" << Age[i] << "\t" << mas[i].Country << "\t" << mas[i].Discipline.Sport << "\t" << Awd[i] << "\t" << mas[i].Discipline.Disqual << endl;
	}
}

void FindMonth(SportTab *mas, int size, double *Age, double *Awd, int mth)
{

	for (int i = 0; i < size; i++)
	{

		if (mas[i].Birthday.month == mth)
			cout << i + 1 << "\t" << mas[i].Surname << " " << mas[i].Name << " " << mas[i].Patronymic << "\t" << Age[i] << "\t" << mas[i].Country << "\t" << mas[i].Discipline.Sport << "\t" << Awd[i] << "\t" << mas[i].Discipline.Disqual << endl;
	}
}

void FindDay(SportTab *mas, int size, double *Age, double *Awd, int dy)
{

	for (int i = 0; i < size; i++)
	{

		if (mas[i].Birthday.day == dy)
			cout << i + 1 << "\t" << mas[i].Surname << " " << mas[i].Name << " " << mas[i].Patronymic << "\t" << Age[i] << "\t" << mas[i].Country << "\t" << mas[i].Discipline.Sport << "\t" << Awd[i] << "\t" << mas[i].Discipline.Disqual << endl;
	}
}

void FindCntr(SportTab *mas, int size, double *Age, double *Awd, char *cntr)
{

	for (int i = 0; i < size; i++)
	{

		if (stricmp(mas[i].Country, cntr) == 0)
			cout << i + 1 << "\t" << mas[i].Surname << " " << mas[i].Name << " " << mas[i].Patronymic << "\t" << Age[i] << "\t" << mas[i].Country << "\t" << mas[i].Discipline.Sport << "\t" << Awd[i] << "\t" << mas[i].Discipline.Disqual << endl;
	}
}

void FindSport(SportTab *mas, int size, double *Age, double *Awd, char *sprt)
{

	for (int i = 0; i < size; i++)
	{

		if (stricmp(mas[i]
.Country, sprt) == 0)
			cout << i + 1 << "\t" << mas[i].Surname << " " << mas[i].Name << " " << mas[i].Patronymic << "\t" << Age[i] << "\t" << mas[i].Country << "\t" << mas[i].Discipline.Sport << "\t" << Awd[i] << "\t" << mas[i].Discipline.Disqual << endl;
	}
}

void FindGold(SportTab *mas, int size, double *Age, double *Awd, int gld)
{

	for (int i = 0; i < size; i++)
	{

		if (mas[i].Discipline.Awards.gold == gld)
			cout << i + 1 << "\t" << mas[i].Surname << " " << mas[i].Name << " " << mas[i].Patronymic << "\t" << Age[i] << "\t" << mas[i].Country << "\t" << mas[i].Discipline.Sport << "\t" << Awd[i] << "\t" << mas[i].Discipline.Disqual << endl;
	}
}

void FindSilver(SportTab *mas, int size, double *Age, double *Awd, int slvr)
{

	for (int i = 0; i < size; i++)
	{

		if (mas[i].Discipline.Awards.silver == slvr)
			cout << i + 1 << "\t" << mas[i].Surname << " " << mas[i].Name << " " << mas[i].Patronymic << "\t" << Age[i] << "\t" << mas[i].Country << "\t" << mas[i].Discipline.Sport << "\t" << Awd[i] << "\t" << mas[i].Discipline.Disqual << endl;
	}
}

void FindBronz(SportTab *mas, int size, double *Age, double *Awd, int brz)
{

	for (int i = 0; i < size; i++)
	{

		if (mas[i].Discipline.Awards.bronz == brz)
			cout << i + 1 << "\t" << mas[i].Surname << " " << mas[i].Name << " " << mas[i].Patronymic << "\t" << Age[i] << "\t" << mas[i].Country << "\t" << mas[i].Discipline.Sport << "\t" << Awd[i] << "\t" << mas[i].Discipline.Disqual << endl;
	}
}

void FindDisqual(SportTab *mas, int size, double *Age, double *Awd, int dsq)
{

	for (int i = 0; i < size; i++)
	{

		if (mas[i].Discipline.Awards.bronz == dsq)
			cout << i + 1 << "\t" << mas[i].Surname << " " << mas[i].Name << " " << mas[i].Patronymic << "\t" << Age[i] << "\t" << mas[i].Country << "\t" << mas[i].Discipline.Sport << "\t" << Awd[i] << "\t" << mas[i].Discipline.Disqual << endl;
	}
}

SportTab *SortSur(SportTab * mas, int size)
{

	SportTab tmp;
	bool chng = true;
	while (chng)
	{
		chng = false;

		for (int i = 0; i < size - 1; ++i)
		{
			if (strnicmp(mas[i].Surname, mas[i+1].Surname, 1) > 0)
			{
				tmp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = tmp;
				chng = true;
			}
		}
	}

	return mas;
}

SportTab *SortName(SportTab * mas, int size)
{

	SportTab tmp;
	bool chng = true;
	while (chng)
	{
		chng = false;

		for (int i = 0; i < size - 1; ++i)
		{
			if (strnicmp(mas[i].Name, mas[i + 1].Name, 1) > 0)
			{
				tmp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = tmp;
				chng = true;
			}
		}
	}

	return mas;
}

SportTab *SortPatronymic(SportTab * mas, int size)
{

	SportTab tmp;
	bool chng = true;
	while (chng)
	{
		chng = false;

		for (int i = 0; i < size - 1; ++i)
		{
			if (strnicmp(mas[i].Patronymic, mas[i + 1].Patronymic, 1) > 0)
			{
				tmp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = tmp;
				chng = true;
			}
		}
	}

	return mas;
}

SportTab *SortAge(SportTab * mas, int size, double *Age)
{

	SportTab tmp;
	bool chng = true;
	while (chng)
	{
		chng = false;
		for (int i = 0; i < size - 1; ++i)
		{
			if (Age[i] > Age[i + 1])
			{
				tmp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = tmp;
				chng = true;
			}
		}
	}

	return mas;
}

SportTab *SortCountry(SportTab * mas, int size)
{


	SportTab tmp;
	bool chng = true;
	while (chng)
	{
		chng = false;

		for (int i = 0; i < size - 1; ++i)
		{
			if (strnicmp(mas[i].Country, mas[i + 1].Country, 1) > 0)
			{
				tmp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = tmp;
				chng = true;
			}
		}
	}

	return mas;
}

SportTab *SortSport(SportTab * mas, int size)
{

	SportTab tmp;
	bool chng = true;
	while (chng)
	{
		chng = false;

		for (int i = 0; i < size - 1; ++i)
		{
			if (strnicmp(mas[i].Discipline.Sport, mas[i + 1].Discipline.Sport, 1) > 0)
			{
				tmp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = tmp;
				chng = true;
			}
		}
	}

	return mas;
}

SportTab *SortGold(SportTab * mas, int size)
{

	SportTab tmp;
	bool chng = true;
	while (chng)
	{
		chng = false;
		for (int i = 0; i < size - 1; ++i)
		{
			if (mas[i].Discipline.Awards.gold > mas[i + 1].Discipline.Awards.gold)
			{
				tmp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = tmp;
				chng = true;
			}
		}
	}

	return mas;
}

SportTab *SortSilver(SportTab * mas, int size)
{

	SportTab tmp;
	bool chng = true;
	while (chng)
	{
		chng = false;
		for (int i = 0; i < size - 1; ++i)
		{
			if (mas[i].Discipline.Awards.silver > mas[i + 1].Discipline.Awards.silver)
			{
				tmp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = tmp;
				chng = true;
			}
		}
	}

	return mas;
}

SportTab *SortBronze(SportTab * mas, int size)
{

	SportTab tmp;
	bool chng = true;
	while (chng)
	{
		chng = false;
		for (int i = 0; i < size - 1; ++i)
		{
			if (mas[i].Discipline.Awards.bronz > mas[i + 1].Discipline.Awards.bronz)
			{
				tmp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = tmp;
				chng = true;
			}
		}
	}

	return mas;
}

SportTab *SortDisqual(SportTab * mas, int size)
{

	SportTab tmp;
	bool chng = true;
	while (chng)
	{
		chng = false;
		for (int i = 0; i < size - 1; ++i)
		{
			if (mas[i].Discipline.Disqual > mas[i + 1].Discipline.Disqual)
			{
				tmp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = tmp;
				chng = true;
			}
		}
	}
	return mas;
}