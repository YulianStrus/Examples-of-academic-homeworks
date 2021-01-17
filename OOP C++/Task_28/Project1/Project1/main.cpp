#include "iostream"
#include "fstream"
#include <list>
#include <iterator>
using namespace std;

class RSt
{
	int num;
	int day;
	int month;
	int year;
	int hour;
	int min;
	char *station;
public:
	RSt()
	{
		num = 1094;
		day = 16;
		month = 8;
		year = 2019;
		hour = 11;
		min = 45;
		station = new char[100];
		strcpy(station, "Odesa");
	}
	RSt(int num, int day, int month, int year, int hour, int min, char *station)
	{
		this->num = num;
		this->day = day;
		this->month = month;
		this->year = year;
		this->hour = hour;
		this->min = min;
		this->station = new char[100];
		strcpy(this->station, station);
	}
	RSt(const RSt &other)
	{
		this->num = other.num;
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
		this->hour = other.hour;
		this->min = other.min;
		this->station = new char[100];
		strcpy(this->station, other.station);
	}
	RSt operator=(const RSt &other)
	{
		this->num = other.num;
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
		this->hour = other.hour;
		this->min = other.min;
		this->station = new char[100];
		strcpy(this->station, other.station);
		return *this;
	}
	~RSt()
	{
		delete[]station;
	}
	void SetNum(int num) { this->num = num; }
	void SetDay(int day) { this->day = day; }
	void SetMonth(int month) { this->month = month; }
	void SetYear(int year) { this->year = year; }
	void SetHour(int hour) { this->hour = hour; }
	void SetMinutes(int min) { this->min = min; }
	void SetData(int day, int month, int year, int hour, int min) { this->day = day; this->month = month; this->year = year; this->hour = hour; this->min = min; }
	void SetStation(char *station) { this->station = new char[100]; strcpy(this->station, station); }
	int GetNum() { return num; }
	int GetDay() { return day; }
	int GetMonth() { return month; }
	int GetYear() { return year; }
	int GetHour() { return hour; }
	int GetMinutes() { return min; }
	char* GetStation() { return station; }

	int AddNum()
	{
		cout << "Enter number: ";
		cin >> num;
		return num;
	}
	int AddDay()
	{
		cout << "Enter data:";
		cin >> day;
		return day;
	}
	int AddMonth()
	{
		cout << "Enter month:";
		cin >> month;
		return month;
	}
	int AddYear()
	{
		cout << "Enter year:";
		cin >> year;
		return year;
	}
	int AddHour()
	{
		cout << "Enter hour:";
		cin >> hour;
		return hour;
	}
	int AddMinutes()
	{
		cout << "Enter minutes:";
		cin >> min;
		return min;
	}
	char *AddStation()
	{
		cin.ignore();
		cout << "Enter station of destination: ";
		cin.getline(station, 100);
		return station;
	}
	void ShowData()
	{
		cout << "Data: ";
		if (day / 10 < 1) cout << 0;
		cout << day << ".";
		if (month / 10 < 1)cout << 0;
		cout << month << "." << year << " " << hour << ":" << min << endl;
	}
	void Show()
	{
		cout << "Station of destination:  " << station << endl;
		cout << "Number train:   " << num << endl;
		ShowData();
	}
};

list<RSt> Add(list<RSt> RailwayStation)
{
	RSt temp;
	temp.SetNum(temp.AddNum());
	temp.SetDay(temp.AddDay());
	temp.SetMonth(temp.AddMonth());
	temp.SetYear(temp.AddYear());
	temp.SetHour(temp.AddHour());
	temp.SetMinutes(temp.AddMinutes());
	temp.SetStation(temp.AddStation());
	RailwayStation.push_back(temp);
	return RailwayStation;
}

void Show( list <RSt> RailwayStation)
{
	list<RSt>::iterator it = RailwayStation.begin();
	cout << "\t\tRailway Station: " << endl;
	for (int i = 0; i < RailwayStation.size(); ++i)
	{
		cout << i + 1 << ". ";
		it->Show();
		advance(it, i);
		cout << endl;
	}
	cout << endl;
}

void FindByNumber(list <RSt> RailwayStation)
{
	list<RSt>::iterator it = RailwayStation.begin();
	int num;
	int count = 0;
	cout << "Please enter number of train: ";
	cin >> num;
	for (int i = 0; i < RailwayStation.size(); ++i)
	{
		if (num == it->GetNum())
		{
			cout << i + 1 << ". ";
			it->Show();
			cout << endl;
			count++;
		}
		advance(it, i);
	}
	if (count == 0) cout << "There is no match" << endl << endl;
}

void Save(list <RSt> RailwayStation)
{
	list<RSt>::iterator it = RailwayStation.begin();
	ofstream g;
	g.open("file.txt");
	for (int i = 0; i < RailwayStation.size(); ++i)
	{
		g << it->GetNum() << endl;
		g << it->GetDay() << endl;
		g << it->GetMonth() << endl;
		g << it->GetYear() << endl;
		g << it->GetHour() << endl;
		g << it->GetMinutes() << endl;
		g << it->GetStation() << endl;
	}
	g.close();
	cout << "Save complete" << endl;
}

list<RSt> Load()
{
	int count = 0;
	char *buf = new char[100];
	int ibuf;
	ifstream g;
	RSt temp;
	g.open("file.txt");
	while (g.good())
	{
		g.getline(buf, 20);
		temp.SetStation(buf);
		g >> ibuf;
		temp.SetNum(ibuf);
		g >> ibuf;
		temp.SetDay(ibuf);
		g >> ibuf;
		temp.SetMonth(ibuf);
		g >> ibuf;
		temp.SetYear(ibuf);
		g >> ibuf;
		temp.SetHour(ibuf);
		g >> ibuf;
		temp.SetMinutes(ibuf);
//		g.ignore();
		++count;
	}
	list<RSt>RailwayStation(count - 1);
	g.close();
	if (RailwayStation.size() == 0)
	{
		cout << "Error! File is empty." << endl;
		RailwayStation = Add(RailwayStation);
	}
	else
	{
		list<RSt>::iterator it = RailwayStation.begin();
		g.open("file.txt");
		for (int i = 0; i < RailwayStation.size(); ++i)
		{

			g.getline(buf, 20);
			it->SetStation(buf);
			g >> ibuf;
			it->SetNum(ibuf);
			g >> ibuf;
			it->SetDay(ibuf);
			g >> ibuf;
			it->SetMonth(ibuf);
			g >> ibuf;
			it->SetYear(ibuf);
			g >> ibuf;
			it->SetHour(ibuf);
			g >> ibuf;
			it->SetMinutes(ibuf);

			//g.ignore();
		}
		g.close();
	}
	delete[]buf;
	return RailwayStation;
}


int main()
{
	list<RSt>RailwayStation;
	RailwayStation = Load();
	int m = 1;
	while (m != 0)
	{
		cout << "1. Add train\n2. Show\n3. Show by train\n4. Save\n0. Exit\n" << endl;
		cin >> m;
		if (m == 0) break;
		else if (m == 1) RailwayStation = Add(RailwayStation);
		else if (m == 2) Show(RailwayStation);
		else if (m == 3) FindByNumber(RailwayStation);
		else if (m == 4) Save(RailwayStation);
		else cout << "Error! Incorrect select" << endl << endl;
	}

	system("pause");
	return 0;
}