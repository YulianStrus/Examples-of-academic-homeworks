#include "iostream"
using namespace std;

class Data
{
	int day;
	int month;
	int year;
public:
	Data() { day = 5, month = 3, year = 2000; }
	Data(int d, int m, int y) { day = d, month = m, year = y; }
	void SetData(int d, int m, int y) { day = d, month = m, year = y; }

	void Show() {
		cout << "Birthday:\t";
		if (day / 10 < 1) cout << 0;
		cout << day << ".";
		if (month / 10 < 1)cout << 0;
		cout << month << "." << year;
	}
};

class Employer
{
protected:
	char *surname;
	char *name;
	char *midname;
	char *company;
	double salary;
	char *position;
	Data DB;
public:
	Employer();
	Employer(char *surname, char *name, char *midname, Data DB, char *company, char *position, double salary);
	~Employer();
	void SetSurname(char *surname) { this->surname = new char[30]; strcpy(this->surname, surname); }
	void SetName(char *name) { this->name = new char[20]; strcpy(this->name, name); }
	void SetMidname(char *midname) { this->midname = new char[30]; strcpy(this->midname, midname); }
	void SetCompany(char *company) { this->company = new char[30]; strcpy(this->company, company); }
	void SetPosition(char *position) { this->position = new char[30]; strcpy(this->position, position); }
	void SetSalary(char salary) { this->salary = salary; }
	char* GetSurname() { return surname; }
	char* GetName() { return name; }
	char* GetMidname() { return midname; }
	char* GetCompany() { return company; }
	char* GetPosition() { return position; }
	double GetSalary() { return salary; }
	virtual void Print() = 0;
};
Employer::Employer()
{
	surname = new char[30];
	name = new char[20];
	midname = new char[30];
	company = new char[50];
	position = new char[25];
	strcpy(surname, "Strus");
	strcpy(name, "Yulian");
	strcpy(midname, "Vasilyevich");
	strcpy(company, "Google");
	strcpy(position, "Programer");
	salary = 8500;
}

Employer::Employer(char *surname, char *name, char *midname, Data DB, char *company, char *position, double salary)
{
	this->DB = DB;
	this->surname = new char[30];
	this->name = new char[20];
	this->midname = new char[30];
	this->company = new char[50];
	this->position = new char[25];
	this->salary = salary;
	strcpy(this->surname, surname);
	strcpy(this->name, name);
	strcpy(this->midname, midname);
	strcpy(this->company, company);
	strcpy(this->position, position);	
}

Employer::~Employer()
{
	delete[]surname;
	delete[]name;
	delete[]midname;
	delete[]company;
	delete[]position;
}

class President : public Employer
{

public:
	President() : Employer(){}
	President(char *surname, char *name, char *midname, Data DB, char *company, char *position, double salary) : Employer (surname, name, midname, DB, company, position, salary) {}
	void Print();
};

void President::Print()
{
	cout << "\tPresident\nSurname:\t" << GetSurname() << "\nName:\t\t" << GetName() << "\nMidname:\t" << GetMidname() << endl;
	DB.Show();
	cout << "\nCompany:\t" << company << "\nPosition:\t" << position << "\nSalary:\t\t" << salary << endl << endl;
}

class Manager : public Employer
{
public:
	Manager() :Employer() {}
	Manager(char *surname, char *name, char *midname, Data DB, char *company, char *position, double salary) : Employer(surname, name, midname, DB, company, position, salary) {}
	void Print();
};

void Manager::Print()
{
	cout << "\tManager\nSurname:\t" << GetSurname() << "\nName:\t\t" << GetName() << "\nMidname:\t" << GetMidname() << endl;
	DB.Show();
	cout << "\nCompany:\t" << company << "\nPosition:\t" << position << "\nSalary:\t\t" << salary << endl << endl;
}

class Worker : public Employer
{
public:
	Worker() :Employer(){}
	Worker(char *surname, char *name, char *midname, Data DB, char *company, char *position, double salary) : Employer(surname, name, midname, DB, company, position, salary) {}
	void Print();
};

void Worker::Print()
{
	cout << "\tWorker\nSurname:\t" << GetSurname() << "\nName:\t\t" << GetName() << "\nMidname:\t" << GetMidname() << endl;
	DB.Show();
	cout << "\nCompany:\t" << company << "\nPosition:\t" << position << "\nSalary:\t\t" << salary << endl << endl;
}

int main()
{
	Data DB(23, 4, 1963);
	President pr("Petrenko", "Petro", "Petrovich", DB, "City" , "Mer", 35000);
	DB.SetData(9, 11, 2002);
	Manager mn("Ivanenko", "Ivan", "Ivanovich", DB, "PostPrint", "Writer", 13000);
	DB.SetData(16, 8, 1992);
	Worker wr("Tarasenko", "Taras", "Tarasovich", DB, "Prettl", "Locksmith", 9800);
	Employer *p;
	p = &pr;
	p->Print();
	p = &mn;
	p->Print();
	p = &wr;
	p->Print();

	system("pause");
	return 0;
}