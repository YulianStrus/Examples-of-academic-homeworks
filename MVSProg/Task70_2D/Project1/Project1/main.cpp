#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

class Catalog
{
	char *name;
	char *owner;
	char *phone;
	char *adress;
	char *occupation;

public:
	Catalog()
	{
		name = new char[100];
		strcpy(name, "AnyFirm");
		owner = new char[100];
		strcpy(owner, "Ivanov Ivan Ivanovich");
		phone = new char[14];
		strcpy(phone, "380679862280");
		adress = new char[256];
		strcpy(adress, "Podilska st. 22/5");
		occupation = new char[256];
		strcpy(occupation, "Copywriter");
	}
	Catalog(char *name, char *owner, char *phone, char *adress, char *occupation)
	{
		this->name = new char[100];
		strcpy(this->name, name);
		this->owner = new char[100];
		strcpy(this->owner, owner);
		this->phone = new char[14];
		strcpy(this->phone, phone);
		this->adress = new char[256];
		strcpy(this->adress, adress);
		this->occupation = new char[256];
		strcpy(this->occupation, occupation);
	}
	Catalog(const Catalog &other)
	{
		this->name = new char[100];
		strcpy(this->name, other.name);
		this->owner = new char[100];
		strcpy(this->owner, other.owner);
		this->phone = new char[14];
		strcpy(this->phone, other.phone);
		this->adress = new char[256];
		strcpy(this->adress, other.adress);
		this->occupation = new char[256];
		strcpy(this->occupation, other.occupation);
	}
	Catalog operator=(const Catalog &other)
	{
		this->name = new char[100];
		strcpy(this->name, other.name);
		this->owner = new char[100];
		strcpy(this->owner, other.owner);
		this->phone = new char[14];
		strcpy(this->phone, other.phone);
		this->adress = new char[256];
		strcpy(this->adress, other.adress);
		this->occupation = new char[256];
		strcpy(this->occupation, other.occupation);
		return *this;
	}
	~Catalog()
	{
		delete[]name;
		delete[]owner;
		delete[]phone;
		delete[]adress;
		delete[]occupation;
	}
	void SetName(char *name) { this->name = new char[100]; strcpy(this->name, name); }
	void SetOwner(char *owner) { this->owner = new char[100]; strcpy(this->owner, owner); }
	void SetPhone(char *phone) { this->phone = new char[14]; strcpy(this->phone, phone); }
	void SetAdress(char *adress) { this->adress = new char[256]; strcpy(this->adress, adress); }
	void SetOccupation(char *occupation) { this->occupation = new char[256]; strcpy(this->occupation, occupation); }
	char* GetName() { return name; }
	char* GetOwner() { return owner; }
	char* GetPhone() { return phone; }
	char* GetAdress() { return adress; }
	char* GetOccupation() { return occupation; }
	char* AddName()
	{
		cout << "Enter company name: ";
		gets_s(name, 100);
		return name;
	}
	char* AddOwner()
	{
		cout << "Enter owner: ";
		gets_s(owner, 100);
		return owner;
	}
	char* AddPhone()
	{
		cout << "Enter phone: ";
		gets_s(phone, 14);
		return phone;
	}
	char* AddAdress()
	{
		cout << "Enter adress: ";
		gets_s(adress, 256);
		return adress;
	}
	char* AddOccupation()
	{
		cout << "Enter occupation: ";
		gets_s(occupation, 256);
		return occupation;
	}
	void Show()
	{
		cout << "Name of company:      " << name << endl;
		cout << "   Owner:                " << owner << endl;
		cout << "   Phone:                " << phone << endl;
		cout << "   Adress:               " << adress << endl;
		cout << "   Occupation:           " << occupation << endl;
	}
};

void Save(Catalog *ArrayCatalog, int size)
{
	ofstream g;
	g.open("file.dat", ios_base::trunc);
	for (int i = 0; i < size; ++i)
	{
		g << ArrayCatalog[i].GetName() << endl;
		g << ArrayCatalog[i].GetOwner() << endl;
		g << ArrayCatalog[i].GetPhone() << endl;
		g << ArrayCatalog[i].GetAdress() << endl;
		g << ArrayCatalog[i].GetOccupation() << endl;
	}
	g.close();
	cout << "Save complete" << endl;;
}


Catalog* Add(Catalog *ArrayCatalog, int size)
{
	ArrayCatalog[size - 1].SetName(ArrayCatalog[size - 1].AddName());
	ArrayCatalog[size - 1].SetOwner(ArrayCatalog[size - 1].AddOwner());
	ArrayCatalog[size - 1].SetPhone(ArrayCatalog[size - 1].AddPhone());
	ArrayCatalog[size - 1].SetAdress(ArrayCatalog[size - 1].AddAdress());
	ArrayCatalog[size - 1].SetOccupation(ArrayCatalog[size - 1].AddOccupation());
	return ArrayCatalog;
}

Catalog* AddLine(Catalog *ArrayCatalog, int &size)
{
	Catalog *temp = new Catalog[size];
	for (int i = 0; i < size; ++i)
		temp[i] = ArrayCatalog[i];
	delete[]ArrayCatalog;
	++size;
	ArrayCatalog = new Catalog[size];
	for (int i = 0; i < size - 1; ++i)
		ArrayCatalog[i] = temp[i];
	delete[]temp;
	ArrayCatalog = Add(ArrayCatalog, size);
	Save(ArrayCatalog, size);
	return ArrayCatalog;
}

Catalog* DeleteLine(Catalog *ArrayCatalog, int &size)
{
	int pos;
	int i_temp = 0;
	Catalog *temp = new Catalog[size - 1];
	cout << "Please enter position of catalog which you wanna delete" << endl;
	cin >> pos;
	cin.ignore();
	if (pos > 0 && pos <= size)
	{
		for (int i = 0; i < size; ++i)
		{
			if (i == pos - 1) continue;
			temp[i_temp] = ArrayCatalog[i];
			++i_temp;
		}
		delete[]ArrayCatalog;
		--size;
		ArrayCatalog = new Catalog[size];
		for (int i = 0; i < size; ++i)
			ArrayCatalog[i] = temp[i];
	}
	else
	{
		cout << "Error!. Please try again";
		ArrayCatalog = DeleteLine(ArrayCatalog, size);
	}
	delete[]temp;
	Save(ArrayCatalog, size);
	return ArrayCatalog;
}

void Show(Catalog *ArrayCatalog, int size)
{
	cout << "\t\t\t\tCompanies" << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << i + 1 << ". ";
		ArrayCatalog[i].Show();
		cout << endl;
	}
}

Catalog* Load(int &size)
{
	int count = 0;
	char *buf = new char[256];
	ifstream g;
	Catalog *temp = new Catalog[size];
	g.open("file.dat", ios_base::in);
	while (!g.eof())
	{
		g.getline(buf, sizeof(char[100]));
		temp[0].SetName(buf);
		g.getline(buf, sizeof(char[100]));
		temp[0].SetOwner(buf);
		g.getline(buf, sizeof(char[14]));
		temp[0].SetPhone(buf);
		g.getline(buf, sizeof(char[256]));
		temp[0].SetAdress(buf);
		g.getline(buf, sizeof(char[256]));
		temp[0].SetOccupation(buf);
		//g.ignore();
		++count;
	}
	size = count - 1;
	g.close();
	Catalog *ArrayCatalog = new Catalog[size];
	if (size == 0)
	{
		cout << "Error! Enter information about the first company." << endl;
		ArrayCatalog = AddLine(ArrayCatalog, size);
	}
	else
	{
		g.open("file.dat", ios_base::in);
		for (int i = 0; i < size; ++i)
		{
			g.getline(buf, sizeof(char[100]));
			ArrayCatalog[i].SetName(buf);
			g.getline(buf, sizeof(char[100]));
			ArrayCatalog[i].SetOwner(buf);
			g.getline(buf, sizeof(char[14]));
			ArrayCatalog[i].SetPhone(buf);
			g.getline(buf, sizeof(char[256]));
			ArrayCatalog[i].SetAdress(buf);
			g.getline(buf, sizeof(char[256]));
			ArrayCatalog[i].SetOccupation(buf);
			g.ignore();
		}
		g.close();
	}
	delete[]buf;
	return ArrayCatalog;
}

void FindByCompany(Catalog *ArrayCatalog, int size)
{
	int temp = 0;
	int count = 0;
	char name[100];
	cout << "Enter company: " << endl;
	gets_s(name, 100);
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < strlen(ArrayCatalog[i].GetName()); ++j)
		{
			if (ArrayCatalog[i].GetName()[j] == name[0])
			{
				temp = 0;
				for (int k = 0; k < strlen(name); ++k)
				{
					if (ArrayCatalog[i].GetName()[j + k] == name[k])
						++temp;
				}
			}
			if (temp == strlen(name))
			{
				temp = 0;
				++count;
				cout << i + 1 << ". ";
				ArrayCatalog[i].Show();
				cout << endl;
				break;
			}
		}
	}
	if (count == 0) cout << "There is no match" << endl << endl;
}

void FindByOwner(Catalog *ArrayCatalog, int size)
{
	int temp = 0;
	int count = 0;
	char owner[100];
	cout << "Enter owner: " << endl;
	gets_s(owner, 100);
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < strlen(ArrayCatalog[i].GetOwner()); ++j)
		{
			if (ArrayCatalog[i].GetOwner()[j] == owner[0])
			{
				temp = 0;
				for (int k = 0; k < strlen(owner); ++k)
				{
					if (ArrayCatalog[i].GetOwner()[j + k] == owner[k])
						++temp;
				}
			}
			if (temp == strlen(owner))
			{
				temp = 0;
				++count;
				cout << i + 1 << ". ";
				ArrayCatalog[i].Show();
				cout << endl;
				break;
			}
		}
	}
	if (count == 0) cout << "There is no match" << endl << endl;
}

void FindByPhone(Catalog *ArrayCatalog, int size)
{
	int temp = 0;
	int count = 0;
	char phone[14];
	cout << "Enter phone number: " << endl;
	gets_s(phone, 14);
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < strlen(ArrayCatalog[i].GetPhone()); ++j)
		{
			if (ArrayCatalog[i].GetPhone()[j] == phone[0])
			{
				temp = 0;
				for (int k = 0; k < strlen(phone); ++k)
				{
					if (ArrayCatalog[i].GetPhone()[j + k] == phone[k])
						++temp;
				}
			}
			if (temp == strlen(phone))
			{
				temp = 0;
				++count;
				cout << i + 1 << ". ";
				ArrayCatalog[i].Show();
				cout << endl;
				break;
			}
		}
	}
	if (count == 0) cout << "There is no match" << endl << endl;
}

void FindByAdress(Catalog *ArrayCatalog, int size)
{
	int temp = 0;
	int count = 0;
	char adress[256];
	cout << "Enter adress: " << endl;
	gets_s(adress, 256);
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < strlen(ArrayCatalog[i].GetAdress()); ++j)
		{
			if (ArrayCatalog[i].GetAdress()[j] == adress[0])
			{
				temp = 0;
				for (int k = 0; k < strlen(adress); ++k)
				{
					if (ArrayCatalog[i].GetAdress()[j + k] == adress[k])
						++temp;
				}
			}
			if (temp == strlen(adress))
			{
				temp = 0;
				++count;
				cout << i + 1 << ". ";
				ArrayCatalog[i].Show();
				cout << endl;
				break;
			}
		}
	}
	if (count == 0) cout << "There is no match" << endl << endl;
}

void FindByOccupation(Catalog *ArrayCatalog, int size)
{
	int temp = 0;
	int count = 0;
	char occupation[256];
	cout << "Enter occupation: " << endl;
	gets_s(occupation, 256);
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < strlen(ArrayCatalog[i].GetOccupation()); ++j)
		{
			if (ArrayCatalog[i].GetOccupation()[j] == occupation[0])
			{
				temp = 0;
				for (int k = 0; k < strlen(occupation); ++k)
				{
					if (ArrayCatalog[i].GetOccupation()[j + k] == occupation[k])
						++temp;
				}
			}
			if (temp == strlen(occupation))
			{
				temp = 0;
				++count;
				cout << i + 1 << ". ";
				ArrayCatalog[i].Show();
				cout << endl;
				break;
			}
		}
	}
	if (count == 0) cout << "There is no match" << endl << endl;
}

int main()
{
	int size = 1;
	Catalog *ArrayCatalog = new Catalog[size];
	int s = 1, ms=1;
	while (s != 0)
	{
		cout << endl << "1. Add to catalog\n2. Remove from directory\n3. Show\n4. Find\n5. Save array\n6. Load array\n0. Exit" << endl;
		cin >> s;
		cin.ignore();
		cout << endl;
		if (s == 1) ArrayCatalog = AddLine(ArrayCatalog, size);
		else if (s == 2) ArrayCatalog = DeleteLine(ArrayCatalog, size);
		else if (s == 3) Show(ArrayCatalog, size);
		else if (s == 4) 
		{
			while(ms!=0)
			{
				cout << "1. By company\n2. By owner\n3. By phone\n4. By adress\n5. By occupation\n0. Back" << endl;
				cin >> ms;
				if (ms == 1)FindByCompany(ArrayCatalog, size);
				else if (ms == 2) FindByOwner(ArrayCatalog, size);
				else if (ms == 3) FindByPhone(ArrayCatalog, size);
				else if (ms == 4) FindByAdress(ArrayCatalog, size);
				else if (ms == 5) FindByOccupation(ArrayCatalog, size);
				else if (ms == 0) break;
				else
					cout << "Error! Enter number:" << endl << endl;
			}
		}
		else if (s == 5) Save(ArrayCatalog, size);
		else if (s == 6) Load(size);
		else if (s == 0) break;
		else
			cout << "Error! Enter number:" << endl << endl;
	}
	delete[]ArrayCatalog;

	system("pause");
	return 0;

}