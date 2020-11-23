#include <iostream>
#include <fstream>
using namespace std;

class Tellbook
{
	char *FullName;
	char *DomNum;
	char *RobNum;
	char *MobNum;
	char *info;

public:
	Tellbook()
	{
		FullName = new char[60];
		strcpy(FullName, "Strus Yulian Vasilevich");
		DomNum = new char[14];
		strcpy(DomNum, "038491234567");
		RobNum = new char[14];
		strcpy(RobNum, "380671234567");
		DomNum = new char[14];
		strcpy(MobNum, "380661234567");
		info = new char[300];
		strcpy(info, "This may be your ad");
	}
	Tellbook(char *FullName, char *DomNum, char *RobNum, char *MobNum, char *info)
	{
		this->FullName = new char[60];
		strcpy(FullName, FullName);
		this->DomNum = new char[14];
		strcpy(DomNum, DomNum);
		this->RobNum = new char[14];
		strcpy(RobNum, RobNum);
		this->DomNum = new char[14];
		strcpy(MobNum, MobNum);
		this->info = new char[300];
		strcpy(info, info);
	}
	Tellbook(const Tellbook & other)
	{
		this->FullName = new char[60];
		strcpy(this->FullName, other.FullName);
		this->DomNum = new char[14];
		strcpy(this->DomNum, other.DomNum);
		this->RobNum = new char[14];
		strcpy(this->RobNum, other.RobNum);
		this->DomNum = new char[14];
		strcpy(this->MobNum, other.MobNum);
		this->info = new char[300];
		strcpy(this->info, other.info);
	}
	Tellbook operator= (const Tellbook & other)
	{
		this->FullName = new char[60];
		strcpy(this->FullName, other.FullName);
		this->DomNum = new char[14];
		strcpy(this->DomNum, other.DomNum);
		this->RobNum = new char[14];
		strcpy(this->RobNum, other.RobNum);
		this->DomNum = new char[14];
		strcpy(this->MobNum, other.MobNum);
		this->info = new char[300];
		strcpy(this->info, other.info);
		return *this;
	}
	~Tellbook()
	{
		delete[]FullName;
		delete[]DomNum;
		delete[]RobNum;
		delete[]MobNum;
		delete[]info;
	}
	void SetFullName(char *FullName) { this->FullName = new char[60]; strcpy(this->FullName, FullName); }
	void SetDomNum(char *DomNum) { this->DomNum = new char[14]; strcpy(this->DomNum, DomNum); }
	void SetRobNum(char *RobNum) { this->RobNum = new char[14]; strcpy(this->RobNum, RobNum); }
	void SetMobNum(char *MobNum) { this->MobNum = new char[14]; strcpy(this->MobNum, MobNum); }
	void Setinfo(char *info) { this->info = new char[300]; strcpy(this->info, info); }

	char* GetFullName() { return FullName; }
	char* GetDomNum() { return DomNum; }
	char* GetRobNum() { return RobNum; }
	char* GetMobNum() { return MobNum; }
	char* Getinfo() { return info; }

	char* AddFullName() { cout << "Please enter full name: "; gets_s(FullName, 60); return FullName; }
	char* AddDomNum() { cout << "Please enter home phonenumber: "; gets_s(DomNum, 14); return DomNum; }
	char* AddRobNum() { cout << "Please enter work phonenumber: "; gets_s(RobNum, 14); return RobNum; }
	char* AddMobNum() { cout << "Please enter mobile phonenumber: "; gets_s(MobNum, 14); return RobNum; }
	char* Addinfo() { cout << "Please enter additional information: "; gets_s(info, 300); return info; }

	void ShowTab()
	{
		cout << "Full name:                 " << FullName << endl;
		cout << "   Home phonenumber        " << DomNum << endl;
		cout << "   Work phonenumber:       " << RobNum << endl;
		cout << "   Mobile phonenumber:     " << MobNum << endl;
		cout << "   Additional information: " << info << endl;
	}
};

Tellbook* Add(Tellbook *ArrAbonem, int size)
{
	ArrAbonem[size - 1].SetFullName(ArrAbonem[size - 1].AddFullName());
	ArrAbonem[size - 1].SetDomNum(ArrAbonem[size - 1].AddDomNum());
	ArrAbonem[size - 1].SetRobNum(ArrAbonem[size - 1].AddRobNum());
	ArrAbonem[size - 1].SetMobNum(ArrAbonem[size - 1].AddMobNum());
	ArrAbonem[size - 1].Setinfo(ArrAbonem[size - 1].Addinfo());
	return ArrAbonem;
}

void Save(Tellbook *ArrAbonem, int size)
{
	ofstream g;
	g.open("..\\files\\source.dat");
	for (int i = 0; i < size; ++i)
	{
		g << ArrAbonem[i].GetFullName() << endl;
		g << ArrAbonem[i].GetDomNum() << endl;
		g << ArrAbonem[i].GetRobNum() << endl;
		g << ArrAbonem[i].GetMobNum() << endl;
		g << ArrAbonem[i].Getinfo() << endl;
	}
	g.close();
	cout << "Save complete" << endl;;
}

Tellbook* AddSub(Tellbook *ArrAbonem, int &size)
{
	Tellbook *temp = new Tellbook[size];
	for (int i = 0; i < size; ++i)
		temp[i] = ArrAbonem[i];
	delete[]ArrAbonem;
	++size;
	ArrAbonem = new Tellbook[size];
	for (int i = 0; i < size - 1; ++i)
		ArrAbonem[i] = temp[i];
	delete[]temp;
	ArrAbonem = Add(ArrAbonem, size);
	Save(ArrAbonem, size);
	return ArrAbonem;
}

void ShowSub(Tellbook *ArrAbonem, int size)
{
	cout << "Students" << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << i + 1 << ". ";
		ArrAbonem[i].ShowTab();
		cout << endl;
	}
}

void FindSub(Tellbook *ArrAbonem, int &size)
{
	char FullNameFind[60];
	cout << "Enter full name: " << endl;
	gets_s(FullNameFind,60);

	for (int i = 0; i < size; ++i)
	{
//		if (stricmp(ArrAbonem[i].GetFullName, FullNameFind) == 0)
			cout << ShowSub << endl;
		cout << "Subscriber not found!" << endl;
	}
}

Tellbook* DeleteSub(Tellbook *ArrAbonem, int &size)
{
	char FullNameFind[60];
	int i_temp = 0, pos=0;
	Tellbook *temp = new Tellbook[size - 1];
	cout << "Enter full name: " << endl;
	gets_s(FullNameFind, 60);

	for (int i = 0; i < size; ++i)
	{
		//if (stricmp(ArrAbonem[i].GetFullName, FullNameFind) == 0)
			pos++;
		cout << "Subscriber not found!" << endl;
	}

	for (int i = 0; i < size; ++i)
	{
		if (i == pos - 1) continue;
		temp[i_temp] = ArrAbonem[i];
		++i_temp;
	}
	delete[]ArrAbonem;
	--size;
	ArrAbonem = new Tellbook[size];
	for (int i = 0; i < size; ++i)
		ArrAbonem[i] = temp[i];

	return ArrAbonem;
}

Tellbook* Load(int &size)
{
	int count = 0;
	char *buf1 = new char[100];
	ifstream g;
	Tellbook *temp = new Tellbook[size];
	g.open("..\\files\\source.dat");
	while (g.good())
	{
		g.getline(buf1, sizeof(char[60]));
		temp[0].SetFullName(buf1);
		g.getline(buf1, sizeof(char[14]));
		temp[0].SetDomNum(buf1);
		g.getline(buf1, sizeof(char[14]));
		temp[0].SetRobNum(buf1);
		g.getline(buf1, sizeof(char[14]));
		temp[0].SetMobNum(buf1);
		g.getline(buf1, sizeof(char[300]));
		temp[0].Setinfo(buf1);
		g.ignore();
		++count;
	}
	size = count - 1;
	g.close();
	Tellbook *ArrAbonem = new Tellbook[size];
	if (size == 0)
	{
		cout << "Subscriber not found!.\nPlease enter the first student." << endl;
		ArrAbonem = Add(ArrAbonem, size);
	}
	else
	{
		g.open("..\\files\\source.dat");
		for (int i = 0; i < size; ++i)
		{
			g.getline(buf1, sizeof(char[60]));
			temp[0].SetFullName(buf1);
			g.getline(buf1, sizeof(char[14]));
			temp[0].SetDomNum(buf1);
			g.getline(buf1, sizeof(char[14]));
			temp[0].SetRobNum(buf1);
			g.getline(buf1, sizeof(char[14]));
			temp[0].SetMobNum(buf1);
			g.getline(buf1, sizeof(char[300]));
			temp[0].Setinfo(buf1);
			g.ignore();
		}
		g.close();
	}
	delete[]buf1;
	return ArrAbonem;
}



void menu(Tellbook *ArrAbonem, int size)
{
	int select;
	cout << endl << "1. Add student\n2. Find student\n3. Show students\n4. Load student\n5. Save student\n6. Delete student\n0. Exit" << endl;
	cin >> select;
	cin.ignore();
	cout << endl;
	switch (select)
	{
	case 1:
		ArrAbonem = AddSub(ArrAbonem, size);
		menu(ArrAbonem, size);
		break;
	case 2:
		FindSub(ArrAbonem, size);
		menu(ArrAbonem, size);
		break;
	case 3:
		ShowSub(ArrAbonem, size);
		menu(ArrAbonem, size);
		break;
	case 4:
		ArrAbonem = Load(size);
		menu(ArrAbonem, size);
		break;
	case 5:
		Save(ArrAbonem, size);
		menu(ArrAbonem, size);
		break;
	case 6:
		ArrAbonem = DeleteSub(ArrAbonem, size);
		menu(ArrAbonem, size);
		break;
	case 0:
		break;
	default:
		cout << "Incorrect choice!" << endl << endl;
		menu(ArrAbonem, size);
		break;
	}
}

int main()
{
	int size = 1;
	Tellbook *ArrAbonem = new Tellbook[size];
	ArrAbonem = Load(size);
	menu(ArrAbonem, size);
	delete[]ArrAbonem;

	system("pause");
	return 0;
}