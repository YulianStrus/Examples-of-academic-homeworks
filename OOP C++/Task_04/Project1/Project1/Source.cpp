#include "iostream"
#include "cstdio"
#include "fstream"
using namespace std;

class house;
class appart;

class human
{
private:
	char *surname;
	char *name;
	char *midname;
public:
	human()
	{
		surname = new char[25];
		name = new char[20];
		midname = new char[25];
	}
	human(char *surname, char *name, char *midname)
	{
		this->surname = new char[25];
		this->name = new char[20];
		this->midname = new char[25];
		strcpy(this->surname, surname);
		strcpy(this->name, name);
		strcpy(this->midname, midname);
	}
	human(const human &other)
	{
		this->surname = new char[25];
		this->name = new char[20];
		this->midname = new char[25];
		strcpy(this->surname, other.surname);
		strcpy(this->name, other.name);
		strcpy(this->midname, other.midname);
	}
	human operator=(const human &other)
	{
		this->surname = new char[25];
		this->name = new char[20];
		this->midname = new char[25];
		strcpy(this->surname, other.surname);
		strcpy(this->name, other.name);
		strcpy(this->midname, other.midname);
		return *this;
	}
	~human()
	{
		delete[]surname;
		delete[]name;
		delete[]midname;
	}
	void SetSurName(char *surname) { this->surname = new char[25]; strcpy(this->surname, surname); }
	void SetName(char *name) { this->name = new char[20]; strcpy(this->name, name); }
	void SetMidName(char *midname) { this->midname = new char[25]; strcpy(this->midname, midname); }
	inline char* GetSurName() { return surname; }
	inline char* GetName() { return name; }
	inline char* GetMidName() { return midname; }
	friend appart;
};

class appart
{
private:
	int size;
	int numb;
	human *hum;
public:
	appart() { size = 1; numb = 0; hum = new human[size]; }
	appart(int size, int numb, human *hum)
	{
		this->size = size;
		this->numb = numb;
		this->hum = new human[size];
		for (int i = 0; i < size; ++i)
			this->hum[i] = hum[i];
	}
	appart(const appart &other)
	{
		this->numb = other.numb;
		this->size = other.size;
		this->hum = new human[size];
		for (int i = 0; i < size; ++i)
			this->hum[i] = other.hum[i];
	}
	appart operator=(const appart &other)
	{
		this->numb = other.numb;
		this->size = other.size;
		this->hum = new human[size];
		for (int i = 0; i < size; ++i)
			this->hum[i] = other.hum[i];
		return *this;
	}
	~appart() { delete[]hum; }
	void SetNumb(int numb) { this->numb = numb; }
	void SetSize(int size) { this->size = size; }
	void SetHum(human *hum)
	{
		this->hum = new human[size];
		for (int i = 0; i < size; ++i)
			this->hum[i] = hum[i];
	}
	int GetNumb() { return numb; }
	int GetSize() { return size; }
	human* GetHum() { return hum; }
	void SetAppart(human&obj, char *surname, char *name, char *midname)
	{
		strcpy(obj.surname, surname);
		strcpy(obj.name, name);
		strcpy(obj.midname, midname);
	}
	void GetAppart(human&obj)
	{
		cout << obj.GetSurName() << " " << obj.GetName() << " " << obj.GetMidName() << endl;
	}
	friend house;
};

class house
{
private:
	int size;
	char *name;
public:
	house() { size = 1; name = new char[100]; }
	house(int size, char *name)
	{
		this->size = size;
		this->name = new char[100];
		strcpy(this->name, name);
	}
	house(const house &other)
	{
		this->size = other.size;
		this->name = new char[100];
		strcpy(this->name, name);
	}
	house operator=(const house &other)
	{
		this->size = other.size;
		this->name = new char[100];
		strcpy(this->name, name);
		return *this;
	}
	~house() { delete[]name; }
	void SetSize(int size) { this->size = size; }
	void SetName(char *name) { this->name = new char[100]; strcpy(this->name, name); }
	int GetSize() { return size; }
	char* GetName() { return name; }
	void SetHouse(appart&obj, int numb, int size)
	{
		obj.size = size;
		obj.numb = numb;
	}
};


char* AddNameHouse()
{
	char *name = new char[100];
	cout << "Please enter name of house: ";
	gets_s(name, 100);
	return name;
}

int main()
{
	house h1;
	h1.SetName(AddNameHouse());
	int appsize;
	cout << endl << "Please enter how many appartments in " << h1.GetName() << ": ";
	cin >> appsize;
	cin.ignore();
	h1.SetSize(appsize);
	appart *app = new appart[h1.GetSize()];
	int humsize;
	human *hum;
	for (int i = 0; i < h1.GetSize(); ++i)
	{
		int numb;
		cout << "Please enter number of appartment: ";
		cin >> numb;
		cout << "Please enter how many humans in " << numb << " appart live: ";
		cin >> humsize;
		cin.ignore();
		h1.SetHouse(app[i], numb, humsize);
		hum = new human[app[i].GetSize()];
		for (int k = 0; k < app[i].GetSize(); ++k)
		{
			cout << k + 1 << ". ";
			char *surname = new char[25];
			cout << "Surname: ";
			gets_s(surname, 25);
			char *name = new char[20];
			cout << "   Name: ";
			gets_s(name, 20);
			char *midname = new char[25];
			cout << "   Middle name: ";
			gets_s(midname, 25);
			app[i].SetAppart(hum[k], surname, name, midname);
			cout << endl;
		}
		app[i].SetHum(hum);
		delete[]hum;
	}
	cout << "\t\t\t" << h1.GetName() << endl;
	for (int i = 0; i < h1.GetSize(); ++i)
	{
		cout << "App: " << app[i].GetNumb() << endl;
		hum = new human[app[i].GetSize()];
		hum = app[i].GetHum();
		for (int k = 0; k < app[i].GetSize(); ++k)
		{
			cout << k + 1 << ". ";
			app[i].GetAppart(hum[k]);
		}
		cout << endl;
		delete[]hum;
	}
	system("pause");
	return 0;
}