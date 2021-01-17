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
	void SetYear(int y) { year = y; }
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

class Passport
{
protected:
	char *SurName;
	char *Name;
	char *MidName;
	char *Seria;
	int number;
	char *IssuedBy;
	Data WhenIssued;
public:
	Passport();
	Passport(char *SurName, char *Name, char *MidName, char *Seria, int number, char *IssuedBy);
	Passport(const Passport&other);
	Passport operator=(const Passport &other);
	~Passport();
	void SetSurName(char *SurName) { this->SurName = new char[20]; strcpy(this->SurName, SurName); }
	void SetName(char *Name) { this->Name = new char[20]; strcpy(this->Name, Name); }
	void SetMidName(char *MidName) { this->MidName = new char[20]; strcpy(this->MidName, MidName); }
	void SetSeria(char *Seria) { this->Seria = new char[3]; strcpy(this->Seria, Seria); }
	void SetNumber(int number) { this->number = number; }
	void SetIssuedBy(char *IssuedBy) { this->IssuedBy = new char[256]; strcpy(this->IssuedBy, IssuedBy); }
	char* GetSurName() { return SurName; }
	char* GetName() { return Name; }
	char* GetMidName() { return MidName; }
	char* GetSeria() { return Seria; }
	int GetNumber() { return number; }
	char* GetIssuedBy() { return IssuedBy; }
	void Add(char *SurName, char *Name, char *MidName, int d, int m, int y, char* Seria, int number, char* IssuedBy);
	void Show() { cout << "Full name: " << SurName << " " << Name << " " << MidName << "\tDate: "; WhenIssued.Show(); cout << "\tSeria: " << Seria << " " << number << "\tIssued by: " << IssuedBy << endl; }
};

Passport::Passport()
{
	SurName = new char[20];
	Name = new char[20];
	MidName = new char[20];
	Seria = new char[3];
	IssuedBy = new char[256];
	strcpy(SurName, "Strus");
	strcpy(Name, "Yulian");
	strcpy(MidName, "Vasilyevich");
	strcpy(Seria, "AA");
	number = 11111;
	strcpy(IssuedBy, "Dolynskym RV UMVS in Ivano-Frankivsk");
};
Passport::Passport(char *SurName, char *Name, char *MidName, char *Seria, int number, char *IssuedBy)
{
	this->SurName = new char[20];
	this->Name = new char[20];
	this->MidName = new char[20];
	this->Seria = new char[3];
	this->IssuedBy = new char[256];
	strcpy(this->SurName, SurName);
	strcpy(this->Name, Name);
	strcpy(this->MidName, MidName);
	strcpy(this->Seria, Seria);
	this->number = number;
	strcpy(this->IssuedBy, IssuedBy);
};
Passport::Passport(const Passport & other)
{
	this->SurName = new char[20];
	this->Name = new char[20];
	this->MidName = new char[20];
	this->Seria = new char[3];
	this->IssuedBy = new char[256];
	strcpy(this->SurName, SurName);
	strcpy(this->Name, Name);
	strcpy(this->MidName, MidName);
	strcpy(this->Seria, Seria);
	this->number = number;
	strcpy(this->IssuedBy, IssuedBy);
};
Passport Passport::operator=(const Passport & other)
{
	this->SurName = new char[20];
	this->Name = new char[20];
	this->MidName = new char[20];
	this->Seria = new char[3];
	this->IssuedBy = new char[256];
	strcpy(this->SurName, SurName);
	strcpy(this->Name, Name);
	strcpy(this->MidName, MidName);
	strcpy(this->Seria, Seria);
	this->number = number;
	strcpy(this->IssuedBy, IssuedBy);
	return *this;
};
Passport::~Passport()
{
	delete[]SurName;
	delete[]Name;
	delete[]MidName;
	delete[]Seria;
	delete[]IssuedBy;
};
void Passport::Add(char *SurName, char *Name, char *MidName, int d, int m, int y, char* Seria, int number, char* IssuedBy)
{
	this->SurName = new char[20];
	this->Name = new char[20];
	this->MidName = new char[20];
	this->Seria = new char[3];
	this->IssuedBy = new char[256];
	strcpy(this->SurName, SurName);
	strcpy(this->Name, Name);
	strcpy(this->MidName, MidName);
	strcpy(this->Seria, Seria);
	this->number = number;
	strcpy(this->IssuedBy, IssuedBy);
	WhenIssued.SetDay(d);
	WhenIssued.SetMonth(m);
	WhenIssued.SetYear(y);
};

class ForeignPassport : public Passport
{
protected:
	char *ForSeria;
	int ForNum;
	char *Visa;
	Data DateOfIssue;
public:
	ForeignPassport() { ForSeria = new char[3]; strcpy(ForSeria, "XX"); ForNum = 10101; Visa = new char[256]; strcpy(Visa, "Diplomatic"); DateOfIssue.SetDay(21); DateOfIssue.SetMonth(12); DateOfIssue.SetYear(2019); }
	ForeignPassport(char *ForSeria, int ForNum, char *Visa) { ForSeria = new char[3]; Visa = new char[256]; strcpy(this->ForSeria, ForSeria); this->ForNum = ForNum; strcpy(this->Visa, Visa); }
	void SetForSeria(char *ForSeria) { ForSeria = new char[3]; strcpy(this->ForSeria, ForSeria); }
	void SetForNum(int ForNum) { this->ForNum = ForNum; }
	void SetVisa(char *Visa) { Visa = new char[256]; strcpy(this->Visa, Visa); }
	void SetDateOfIssue(int d, int m, int y) { DateOfIssue.SetDay(d); DateOfIssue.SetMonth(m); DateOfIssue.SetYear(y); }
	char* GetForSeria() { return ForSeria; }
	int GetForNum() { return ForNum; }
	char* GetVisa() { return Visa; }
	Data GetDateOfIssue() { return DateOfIssue; }
	void Show()
	{
		cout << "Foreign passport: " << ForSeria << " " << ForNum << "\tVisa: " << Visa; cout << "\tDate Of Issue: "; DateOfIssue.Show(); cout << "\tPassport: Full name: " << SurName << " " << Name << " " << MidName << "\tDate: "; WhenIssued.Show(); cout << "\tSeria: " << Seria << " " << number << "\tIssued by: " << IssuedBy << endl;;
	}
};

int main()
{
	ForeignPassport Person1;
	Person1.Show();

	system("pause");
	return 0;
}