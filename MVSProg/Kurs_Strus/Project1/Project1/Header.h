#pragma once
#include "iostream"

struct Award
{
	int gold;
	int silver;
	int bronz;
};

struct Data
{
	int day;
	int month;
	int year;
};

struct Achievement
{
	char Sport[32];
	Award Awards;
	int Disqual;
};

struct SportTab
{
	char Surname[32];
	char Name[32];
	char Patronymic[32];
	Data Birthday;
	char Country[32];
	Achievement Discipline;
};

SportTab *Create(SportTab *mas, int size);
void InitMas(SportTab *mas);
void ShowMas(SportTab *mas, int size, double *Age, double *Awd);
void DelArr(SportTab *mas);
void WriteFile(SportTab *mas, int size);
void ReadFile(SportTab *mas, int size);
double AgeEmp(SportTab *mas, int size, double *Age, int d, int m, int y);
double AwdEmp(SportTab *mas, int size, double *Awd);
SportTab *AddMas(SportTab *mas, int size, int sizeN);
SportTab *DelElm(SportTab *mas, int size, char *sur, char *nm);
SportTab *EditSur(SportTab *mas, int size, char *sur, char *nm);
SportTab *EditName(SportTab *mas, int size, char *sur, char *nm);
SportTab *EditPatronymic(SportTab * mas, int size, char *sur, char *nm);
SportTab *EditBirth(SportTab * mas, int size, char *sur, char *nm);
SportTab *EditCountry(SportTab *mas, int size, char *sur, char *nm);
SportTab *EditSport(SportTab * mas, int size, char *sur, char *nm);
SportTab *EditAward(SportTab *mas, int size, char *sur, char *nm);
SportTab *EditDisqual(SportTab *mas, int size, char *sur, char *nm);
void FindSur(SportTab *mas, int size, double *Age, double *Awd, char *sur);
void FindName(SportTab *mas, int size, double *Age, double *Awd, char *nm);
void FindPatronymic(SportTab *mas, int size, double *Age, double *Awd, char *ptr);
void FindAge(SportTab *mas, int size, double *Age, double *Awd, int ag);
void FindYear(SportTab *mas, int size, double *Age, double *Awd, int yr);
void FindMonth(SportTab *mas, int size, double *Age, double *Awd, int mth);
void FindDay(SportTab *mas, int size, double *Age, double *Awd, int dy);
void FindCntr(SportTab *mas, int size, double *Age, double *Awd, char *cntr);
void FindSport(SportTab *mas, int size, double *Age, double *Awd, char *sprt);
void FindGold(SportTab *mas, int size, double *Age, double *Awd, int gld);
void FindSilver(SportTab *mas, int size, double *Age, double *Awd, int slvr);
void FindBronz(SportTab *mas, int size, double *Age, double *Awd, int brz);
void FindDisqual(SportTab *mas, int size, double *Age, double *Awd, int dsq);
SportTab *SortSur(SportTab * mas, int size);
SportTab *SortName(SportTab * mas, int size);
SportTab *SortPatronymic(SportTab * mas, int size);
SportTab *SortAge(SportTab * mas, int size, double *Age);
SportTab *SortCountry(SportTab * mas, int size);
SportTab *SortSport(SportTab * mas, int size);
SportTab *SortGold(SportTab * mas, int size);
SportTab *SortSilver(SportTab * mas, int size);
SportTab *SortBronze(SportTab * mas, int size);
SportTab *SortDisqual(SportTab * mas, int size);