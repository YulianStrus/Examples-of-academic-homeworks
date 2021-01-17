#include <iostream>
using namespace std;

class Data
{
	int day;
	int month;
	int year;
public:
	Data() { day = 5, month = 3, year = 2000; }
	Data(int d, int m, int y) { day = d, month = m, year = y; }
	void SetDay(int d) { day = d; }
	void SetMonth(int m) { month = m; }
	void SetYear(int y) {year = y; }
	int GetDay() { return day; }
	int GetMonth() { return month; }
	int GetYear() { return year; }

	void Show() {
		if (day / 10 < 1) cout << 0;
		cout << day << ".";
		if (month / 10 < 1)cout << 0;
		cout << month << "." << year;
	}
};

class Student
{
protected:
	char *SurName;
	char *Name;
	char *MidName;
	Data BD;
public:
	Student ();
	Student (char *SurName, char *Name, char *MidName);
	Student (const Student&other);
	Student operator=(const Student &other);
	~Student();
	void SetSurName(char *SurName) { this->SurName = new char[20]; strcpy(this->SurName, SurName); }
	void SetName(char *Name) { this->Name = new char[20]; strcpy(this->Name, Name); }
	void SetMidName(char *MidName) { this->MidName = new char[20]; strcpy(this->MidName, MidName); }
	char* GetSurname() { return SurName; }
	char* GetName() { return Name; }
	char* GetMidname() { return MidName; }
	void Add(char *SurName, char *Name, char *MidName, int d, int m, int y);
	void Show() { cout << SurName << " " << Name << " " << MidName << endl; }
};

Student::Student()
{
	SurName = new char[20];
	Name = new char[20];
	MidName = new char[20];
	strcpy(SurName, "Strus");
	strcpy(Name, "Yulian");
	strcpy(MidName, "Vasilyevich");
};
Student::Student(char * SurName, char * Name, char * MidName)
{
	this->SurName = new char[20];
	this->Name = new char[20];
	this->MidName = new char[20];
	strcpy(this->SurName, SurName);
	strcpy(this->Name, Name);
	strcpy(this->MidName, MidName);
};
Student::Student(const Student & other)
{
	this->SurName = new char[20];
	this->Name = new char[20];
	this->MidName = new char[20];
	strcpy(this->SurName, other.SurName);
	strcpy(this->Name, other.Name);
	strcpy(this->MidName, other.MidName);
};
Student Student::operator=(const Student & other)
{
	this->SurName = new char[20];
	this->Name = new char[20];
	this->MidName = new char[20];
	strcpy(this->SurName, other.SurName);
	strcpy(this->Name, other.Name);
	strcpy(this->MidName, other.MidName);
	return *this;
};
Student::~Student()
{
	delete[]SurName;
	delete[]Name;
	delete[]MidName;
};
void Student::Add(char *SurName, char *Name, char *MidName, int d, int m, int y)
{
	this->SurName = new char[20];
	this->Name = new char[20];
	this->MidName = new char[20];
	strcpy(this->SurName, SurName);
	strcpy(this->Name, Name);
	strcpy(this->MidName, MidName);
	BD.SetDay(d);
	BD.SetMonth(m);
	BD.SetYear(y);
};

class Aspirant : public Student
{
protected:
	Data DatGuard;
	double AverScore;
public:
	Aspirant() { AverScore = 11; DatGuard.SetDay(21); DatGuard.SetMonth(12); DatGuard.SetYear(2019); }
	Aspirant(double AverScore) { this->AverScore = AverScore; }
	void SetAverScore(double AverScore) { this->AverScore = AverScore; }
	void SetDatGuard (int d, int m, int y) { DatGuard.SetDay(d); DatGuard.SetMonth(m); DatGuard.SetYear(y); }
	double GetAverScore() { return AverScore; }
	Data GetDatGuard() { return DatGuard; }
	void Show() 
	{ 
		cout << "Full name: " << SurName << " " << Name << " " << MidName << "\tBirthday: "; BD.Show(); cout << "\tDate guard: "; DatGuard.Show(); cout << "\tAverage score: " << AverScore << endl;
	}
};

int main()
{
	Aspirant Person1;
	Person1.Show();

	system("pause");
	return 0;
}