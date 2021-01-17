#include "iostream"
using namespace std;

struct Time
{
	unsigned short int hour : 5;
	unsigned short int milisec : 11;
	unsigned short int minutes : 6;
	unsigned short int second : 6;
	unsigned short int days : 4;
};

Time * WriteTime(Time *Day, int size, int d, int h, int m, int s, int ms);
void ShowTime(Time *Day, int size);
void DelArr(Time *Day);

void main()
{
	int size = 1;
	Time *Day = new Time[size];
	int d = 0, h = 0, m = 0, s = 0, ms = 0;
	Day = WriteTime(Day, size, d, h, m, s, ms);
	ShowTime(Day, size);

	DelArr(Day);
	system("pause");
}


Time * WriteTime(Time *Day, int size, int d, int h, int m, int s, int ms)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter hour (0-24): ";
		cin >> h;
		cout << "Enter minutes (0-60): ";
		cin >> m;
		cout << "Enter second (0-60): ";
		cin >> s;
		cout << "Enter milisecond (0-999): ";
		cin >> ms;

		while (ms > 999)
		{
			ms = (ms - 1000); s++;
		}
		while (s > 59)
		{
			s = (s - 60); m++;
		}
		while (m > 60)
		{
			m = (m - 60); h++;
		}
		while (h > 23)
		{
			h = (h - 24); d++;
		}

		Day[i].days = d;
		Day[i].hour = h;
		Day[i].minutes = m;
		Day[i].second = s;
		Day[i].milisec = ms;
	}

	return Day;
}

void ShowTime(Time *Day, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (Day[i].days > 0)
		{
			cout << Day[i].days << " d: " << Day[i].hour << " h: " << Day[i].minutes << " m: " << Day[i].second << " s: " << Day[i].milisec << " ms" << endl;
		}
		else
		{
			cout << Day[i].hour << " h: " << Day[i].minutes << " m: " << Day[i].second << " s: " << Day[i].milisec << " ms" << endl;
		}
	}
}

void DelArr(Time *Day)
{
	delete[] Day;
}