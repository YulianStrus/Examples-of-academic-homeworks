#include <iostream>
using namespace std;

class Person
{
	char *SurName;
	char *Name;
	char *MidName;
public:
	Person();
	Person(char *SurName, char *Name, char *MidName);
	Person(const Person&other);
	Person operator=(const Person &other);
	~Person();
	void SetSurName(char *SurName) { this->SurName = new char[30]; strcpy(this->SurName, SurName); }
	void SetName(char *Name) { this->Name = new char[20]; strcpy(this->Name, Name); }
	void SetMidName(char *MidName) { this->MidName = new char[30]; strcpy(this->MidName, MidName); }
	char* GetSurname() { return SurName; }
	char* GetName() { return Name; }
	char* GetMidname() { return MidName; }
	void Show() { cout << SurName << " " << Name << " " << MidName << endl; }
};
Person::Person()
{
	SurName = new char[20];
	Name = new char[20];
	MidName = new char[20];
	strcpy(SurName, "Strus");
	strcpy(Name, "Yulian");
	strcpy(MidName, "Vasilyevich");
};
Person::Person(char * SurName, char * Name, char * MidName)
{
	this->SurName = new char[20];
	this->Name = new char[20];
	this->MidName = new char[20];
	strcpy(this->SurName, SurName);
	strcpy(this->Name, Name);
	strcpy(this->MidName, MidName);
};
Person::Person(const Person & other)
{
	this->SurName = new char[20];
	this->Name = new char[20];
	this->MidName = new char[20];
	strcpy(this->SurName, other.SurName);
	strcpy(this->Name, other.Name);
	strcpy(this->MidName, other.MidName);
};
Person Person::operator=(const Person & other)
{
	this->SurName = new char[20];
	this->Name = new char[20];
	this->MidName = new char[20];
	strcpy(this->SurName, other.SurName);
	strcpy(this->Name, other.Name);
	strcpy(this->MidName, other.MidName);
	return *this;
};
Person::~Person()
{
	delete[]SurName;
	delete[]Name;
	delete[]MidName;
};

class Data
{	
		int day;
		int month;
		int year;
	public:
		Data() { day = 5, month = 3, year = 2000; }
		Data(int d, int m, int y) { day = d, month = m, year = y; }
	
	void Show();
};

	void Data::Show()
	{
		if (day / 10 < 1) cout << 0;
		cout << day << ".";
		if (month / 10 < 1)cout << 0;
		cout << month << "." << year << endl;
	}


	class Score
	{
		char **subject = new char*;
		int *score;
	public:
		Score();
		Score(int Score1, int Score2, int Score3, int Score4, int Score5);
		Score(const Score&other);
		Score operator=(const Score&other);
		~Score();
		void Show();
		int* GetScore() { return score; }
		char** GetSubject() { return subject; }

	};
	Score::Score()
	{
		subject = new char*[5];
		for (int i = 0; i < 5; ++i)
			subject[i] = new char[20];
		strcpy(subject[0], "Programming");
		strcpy(subject[1], "DateBase");
		strcpy(subject[2], "Proecting");
		strcpy(subject[3], "Mathematic");
		strcpy(subject[4], "English");
		score = new int[5];
		for (int i = 0; i < 5; ++i)
			score[i] = 5;
	}

	Score::Score(int Score1, int Score2, int Score3, int Score4, int Score5)
	{
		subject = new char*[5];
		for (int i = 0; i < 5; ++i)
			subject[i] = new char[20];
		strcpy(subject[0], "Programming");
		strcpy(subject[1], "DateBase");
		strcpy(subject[2], "Proecting");
		strcpy(subject[3], "Mathematic");
		strcpy(subject[4], "English");
		score = new int[5];
		score[0] = Score1;
		score[1] = Score2;
		score[2] = Score3;
		score[3] = Score4;
		score[4] = Score5;
	}

	Score::Score(const Score & other)
	{
		this->subject = new char*[5];
		for (int i = 0; i < 5; ++i)
			this->subject[i] = new char[20];
		for (int i = 0; i < 5; ++i)
			strcpy(this->subject[i], other.subject[i]);
		this->score = new int[5];
		for (int i = 0; i < 5; ++i)
			this->score[i] = other.score[i];
	}

	Score Score::operator=(const Score & other)
	{
		this->subject = new char*[5];
		for (int i = 0; i < 5; ++i)
			this->subject[i] = new char[20];
		for (int i = 0; i < 5; ++i)
			strcpy(this->subject[i], other.subject[i]);
		this->score = new int[5];
		for (int i = 0; i < 5; ++i)
			this->score[i] = other.score[i];
		return *this;
	}

	Score::~Score()
	{
		for (int i = 0; i < 5; ++i)
			delete[]subject[i];
		delete[]score;
	}

	void Score::Show()
	{
		for (int i = 0; i < 5; ++i)
			cout << i + 1 << ". " << subject[i] << " - " << score[i] << endl;
	}


class Student
{
	Person Pr;
	Data BD;
	Score scr;
	double average;
public:
	Student() { average = 5; }
	Student(Person Pr, Data BD, Score scr);
	void SetPIP(Person Pr) { this->Pr = Pr; }
	void SetBirthday(Data bd) { this->BD = BD; }
	void SetScore(Score scr) { this->scr = scr; }
	void SetAverage(Score scr);
	Person GetPIP() { return Pr; }
	Data GetBirthday() { return BD; }
	Score GetScore() { return scr; }
	double GetAverage() { return average; }
	void ShowBirthday();
	void ShowScore() { scr.Show(); cout << endl; }
	void ShowPerfect();
	void ShowSubject(int select);

};
Student::Student(Person Pr, Data BD, Score scr)
{
	this->Pr = Pr;
	this->BD = BD;
	this->scr = scr;
	double sum = 0;
	int *score = new int[5];
	score = scr.GetScore();
	for (int i = 0; i < 5; ++i)
		sum += score[i];
	this->average = sum / 5.0;
	score = NULL;
	delete[]score;
}

void Student::SetAverage(Score scr)
{
	double sum = 0;
	int *score = new int[5];
	score = scr.GetScore();
	for (int i = 0; i < 5; ++i)
		sum += score[i];
	average = sum / 5.0;
	score = NULL;
	delete[]score;
}

void Student::ShowBirthday()
{
	cout << "Full name: ";
	Pr.Show();
	cout << "Birthday:  ";
	BD.Show();
	cout << endl;
}

void Student::ShowPerfect()
{
	int count = 0;
	int *score = new int[5];
	score = scr.GetScore();
	char **subject = new char*[5];
	for (int i = 0; i < 5; ++i)
		subject[i] = new char[20];
	subject = scr.GetSubject();
	for (int i = 0; i < 5; ++i)
	{
		if (score[i] == 5)
		{
			++count;
			if (count == 1) cout << "The student have 5 from:" << endl;
			cout << count << ". " << subject[i] << endl;
		}
	}
	if (count == 0) cout << "The student DON'T have subject with  5" << endl << endl;
	else cout << endl;
	score = NULL;
	delete[]score;
	for (int i = 0; i < 5; ++i)
	{
		subject[i] = NULL;
		delete[]subject[i];
	}
}

void Student::ShowSubject(int select)
{
	int *score = new int[5];
	score = scr.GetScore();
	cout << "Student have = " << score[select - 1] << endl;
	score = NULL;
	delete[]score;
}


int main()
{
	Person Pr;
	Data BD(11, 9, 2000);
	Score scr(5, 3, 4, 4, 5);
	Student st(Pr, BD, scr);
	st.ShowBirthday();
	st.ShowScore();
	cout << "Average score = " << st.GetAverage() << endl << endl;
	st.ShowPerfect();
	int s;
	cout << "\tPlease select subject:\n1. Programming\n2. DateBase\n3. Proecting\n4. Mathematic\n5. English" << endl;
	cin >> s;
	while (s < 1 || s > 5)
	{
		cout << "Wrong select" << endl << endl;
		cout << "\tPlease select subject:\n1. Programming\n2. DateBase\n3. Proecting\n4. Mathematic\n5. English" << endl;
		cin >> s;
	}
	st.ShowSubject(s);
	system("pause");
	return 0;
}