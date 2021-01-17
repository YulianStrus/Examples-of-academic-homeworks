#include <iostream>
#include <fstream>
using namespace std;

class transfer;

class student
{
	char *FullName;
	int day;
	int month;
	int year;
	char *phone;
	char *city;
	char *country;
	char *name_institut;
	char *city_institut;
	char *country_institut;
	int numgroup;
public:
	student()
	{
		FullName = new char[100];
		strcpy(FullName, "Strus Yulian Vasilevich");
		day = 17;
		month = 11;
		year = 1989;
		phone = new char[14];
		strcpy(phone, "+380679862280");
		city = new char[25];
		strcpy(city, "Kamenec-Podolski");
		country = new char[25];
		strcpy(country, "Ukraine");
		name_institut = new char[100];
		strcpy(name_institut, "Lviv National Agrary University");
		city_institut = new char[25];
		strcpy(city_institut, "Lviv");
		country_institut = new char[25];
		strcpy(country_institut, "Ukraine");
		numgroup = 11;
	}
	student(char *FullName, int day, int month, int year, char *phone, char *city, char *country, char *name_institut, char *city_institut, char *country_institut, int numgroup)
	{
		this->FullName = new char[100];
		strcpy(this->FullName, FullName);
		this->day = day;
		this->month = month;
		this->year = year;
		this->phone = new char[14];
		strcpy(this->phone, phone);
		this->city = new char[25];
		strcpy(this->city, city);
		this->country = new char[25];
		strcpy(this->country, country);
		this->name_institut = new char[100];
		strcpy(this->name_institut, name_institut);
		this->city_institut = new char[25];
		strcpy(this->city_institut, city_institut);
		this->country_institut = new char[25];
		strcpy(this->country_institut, country_institut);
		this->numgroup = 131;
	}
	student(const student &other)
	{
		this->FullName = new char[100];
		strcpy(this->FullName, other.FullName);
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
		this->phone = new char[14];
		strcpy(this->phone, other.phone);
		this->city = new char[25];
		strcpy(this->city, other.city);
		this->country = new char[25];
		strcpy(this->country, other.country);
		this->name_institut = new char[100];
		strcpy(this->name_institut, other.name_institut);
		this->city_institut = new char[25];
		strcpy(this->city_institut, other.city_institut);
		this->country_institut = new char[25];
		strcpy(this->country_institut, other.country_institut);
		this->numgroup = other.numgroup;
	}
	student operator=(const student &other)
	{
		this->FullName = new char[100];
		strcpy(this->FullName, other.FullName);
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
		this->phone = new char[14];
		strcpy(this->phone, other.phone);
		this->city = new char[25];
		strcpy(this->city, other.city);
		this->country = new char[25];
		strcpy(this->country, other.country);
		this->name_institut = new char[100];
		strcpy(this->name_institut, other.name_institut);
		this->city_institut = new char[25];
		strcpy(this->city_institut, other.city_institut);
		this->country_institut = new char[25];
		strcpy(this->country_institut, other.country_institut);
		this->numgroup = other.numgroup;
		return *this;
	}
	~student()
	{
		delete[]FullName;
		delete[]phone;
		delete[]city;
		delete[]country;
		delete[]name_institut;
		delete[]city_institut;
		delete[]country_institut;
	}
	void SetFullName(char *FullName) { this->FullName = new char[100]; strcpy(this->FullName, FullName); }
	void SetDay(int day) { this->day = day; }
	void SetMonth(int month) { this->month = month; }
	void SetYear(int year) { this->year = year; }
	void SetPhone(char *phone) { this->phone = new char[14]; strcpy(this->phone, phone); }
	void SetCity(char *city) { strcpy(this->city, city); this->country = new char[25]; }
	void SetCountry(char *country) { this->country = new char[25]; strcpy(this->country, country); }
	void SetNameInstitut(char *name_institut) { this->name_institut = new char[100]; strcpy(this->name_institut, name_institut); }
	void SetCityInstitut(char *city_institut) { this->city_institut = new char[25]; strcpy(this->city_institut, city_institut); }
	void SetCountryInstitut(char *country_institut) { this->country_institut = new char[25]; strcpy(this->country_institut, country_institut); }
	void SetGroup(int numgroup) { this->numgroup = numgroup; }
	char* GetFullName() { return FullName; }
	int GetDay() { return day; }
	int GetMonth() { return month; }
	int GetYear() { return year; }
	char* GetPhone() { return phone; }
	char* GetCity() { return city; }
	char* GetCountry() { return country; }
	char* GetNameInstitut() { return name_institut; }
	char* GetCityInstitut() { return city_institut; }
	char* GetCountryInstitut() { return country_institut; }
	int GetGroup() { return numgroup; }

	char* AddFullName() { cout << "Please enter full name: "; gets_s(FullName, 100); return FullName; }
	int AddDay() { cout << "Day:   "; cin >> day; return day; }
	int AddMonth() { cout << "Month: "; cin >> month; return month; }
	int AddYear() { cout << "Year:  "; cin >> year; cin.ignore(); return year; }
	char* AddPhone() { cout << "Please enter phone: "; gets_s(phone, 14); return phone;	}
	char* AddCity()	{ cout << "Please enter city: "; gets_s(city, 25); return city;	}
	char* AddCountry() { cout << "Please enter country: "; gets_s(country, 25); return country; }
	char* AddNameInstitut() { cout << "Please enter name of university: "; gets_s(name_institut, 100); return name_institut; }
	char* AddCityInstitut()	{ cout << "Please enter city of university: "; gets_s(city_institut, 25); return city_institut;	}
	char* AddCountryInstitut() { cout << "Please enter country of university: "; gets_s(country_institut, 25); return country_institut;	}
	int AddGroup() { cout << "Please enter group: "; cin >> numgroup; return numgroup; }

	void Show()
	{
		cout << "Full name:            " << FullName << endl;
		cout << "   Birthday:             " << day << "." << month << "." << year << endl;
		cout << "   Phone:                " << phone << endl;
		cout << "   Adress:               " << city << ", " << country << endl;
		cout << "   University:           " << name_institut << endl;
		cout << "   Adress of university: " << city_institut << ", " << country_institut << endl;
		cout << "   Number of group:      " << numgroup << endl;
	}
	friend transfer;
};

class transfer
{
public:
	transfer() {}
	void SetTransfer(student&obj, char *name_institut, char *city_institut, char *country_institut)
	{
		strcpy(obj.name_institut, name_institut);
		strcpy(obj.city_institut, city_institut);
		strcpy(obj.country_institut, country_institut);
	}
	void GetTransfer(student&obj)
	{
		cout << obj.GetFullName() << " transfer to " << obj.GetNameInstitut() << " from " << obj.GetCityInstitut() << ", " << obj.GetCountryInstitut() << endl;
	}
};

student* Add(student *ArrayStudent, int size)
{
	ArrayStudent[size - 1].SetFullName(ArrayStudent[size - 1].AddFullName());
	cout << endl << "\t\tPlease enter birthday:" << endl;
	ArrayStudent[size - 1].SetDay(ArrayStudent[size - 1].AddDay());
	ArrayStudent[size - 1].SetMonth(ArrayStudent[size - 1].AddMonth());
	ArrayStudent[size - 1].SetYear(ArrayStudent[size - 1].AddYear());
	ArrayStudent[size - 1].SetPhone(ArrayStudent[size - 1].AddPhone());
	ArrayStudent[size - 1].SetCity(ArrayStudent[size - 1].AddCity());
	ArrayStudent[size - 1].SetCountry(ArrayStudent[size - 1].AddCountry());
	ArrayStudent[size - 1].SetNameInstitut(ArrayStudent[size - 1].AddNameInstitut());
	ArrayStudent[size - 1].SetCityInstitut(ArrayStudent[size - 1].AddCityInstitut());
	ArrayStudent[size - 1].SetCountryInstitut(ArrayStudent[size - 1].AddCountryInstitut());
	ArrayStudent[size - 1].SetGroup(ArrayStudent[size - 1].AddGroup());
	return ArrayStudent;
}

student* Copy(student *ArrayStudent, int &size)
{
	student *temp = new student[size];
	for (int i = 0; i < size; ++i)
		temp[i] = ArrayStudent[i];
	delete[]ArrayStudent;
	++size;
	ArrayStudent = new student[size];
	for (int i = 0; i < size - 1; ++i)
		ArrayStudent[i] = temp[i];
	delete[]temp;
	return ArrayStudent;
}

student* DeleteLine(student *ArrayStudent, int &size)
{
	int pos;
	int i_temp = 0;
	student *temp = new student[size - 1];
	cout << "Enter student number: " << endl;
	cin >> pos;
	cin.ignore();
	if (pos > 0 && pos <= size)
	{
		for (int i = 0; i < size; ++i)
		{
			if (i == pos - 1) continue;
			temp[i_temp] = ArrayStudent[i];
			++i_temp;
		}
		delete[]ArrayStudent;
		--size;
		ArrayStudent = new student[size];
		for (int i = 0; i < size; ++i)
			ArrayStudent[i] = temp[i];
	}
	else
	{
		cout << "The number is incorrect";
		ArrayStudent = DeleteLine(ArrayStudent, size);
	}
	delete[]temp;
	return ArrayStudent;
}

void Show(student *ArrayStudent, int size)
{
	cout << "Students" << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << i + 1 << ". ";
		ArrayStudent[i].Show();
		cout << endl;
	}
}

void Transfer(student *ArrayStudent, int size)
{
	if (size < 1) cout << "For transfer need at least 1 student" << endl;
	else
	{
		int pos;
		cout << "Enter the number of students for transfer" << endl;
		cin >> pos;
		cin.ignore();
		if (pos > 0 && pos <= size)
		{
			transfer tr;
			char *name_institut = new char[100];
			char *city_institut = new char[25];
			char *country_institut = new char[25];
			cout << "Please enter name of university: ";
			gets_s(name_institut, 100);
			cout << "Please enter city of university: ";
			gets_s(city_institut, 25);
			cout << "Please enter country of university: ";
			gets_s(country_institut, 25);
			tr.SetTransfer(ArrayStudent[pos - 1], name_institut, city_institut, country_institut);
			tr.GetTransfer(ArrayStudent[pos - 1]);
		}
		else
		{
			cout << "Incorrect number. Please try again";
			Transfer(ArrayStudent, size);
		}
	}
}

void menu(student *ArrayStudent, int size)
{
	int select;
	cout << endl << "1. Add student\n2. Copy student\n3. Show students\n4. Transfer student\n5. Delete student\n0. Exit" << endl;
	cin >> select;
	cin.ignore();
	cout << endl;
	switch (select)
	{
	case 1:
		ArrayStudent = Add(ArrayStudent, size);
		menu(ArrayStudent, size);
		break;
	case 2:
		ArrayStudent = Copy(ArrayStudent, size);
		menu(ArrayStudent, size);
		break;
	case 3:
		Show(ArrayStudent, size);
		menu(ArrayStudent, size);
		break;
	case 4:
		Transfer(ArrayStudent, size);
		menu(ArrayStudent, size);
		break;
	case 5:
		ArrayStudent = DeleteLine(ArrayStudent, size);
		menu(ArrayStudent, size);
		break;
	case 0:
		break;
	default:
		cout << "Incorrect choice!" << endl << endl;
		menu(ArrayStudent, size);
		break;
	}
}

int main()
{
	int size = 1;
	student *ArrayStudent = new student[size];
	menu(ArrayStudent, size);
	delete[]ArrayStudent;
	system("pause");
	return 0;
}