#include <iostream>
#include "string.h"
using namespace std;

class Pets
{
protected:
	char *name;
public:
	Pets() {};
	Pets(char *name) { this->name = new char[20]; strcpy(this->name, name);}
	void SetName(char *name) { this->name = new char[20]; strcpy(this->name, name);}
	char* GetName() { return name; }
};

class Dog: public Pets
{
	int paws;
public:
	Dog() { name = new char[20], strcpy(name, "Bobik"), paws = 4; };
	Dog(char *name, int paws) { this->name = new char[20]; strcpy(this->name, name); this->paws = paws; }
	void SetPaws (int paws) { this->paws = paws; }
	int GetPaws() { return paws; }
	void Show() { cout << "Dog name: " << name << ";\t paws: " << paws << endl; }
};

class Cat : public Pets
{
	int paws;
public:
	Cat() { name = new char[20], strcpy(name, "Grisha"), paws = 4; };
	Cat(char *name, int paws) { this->name = new char[20]; strcpy(this->name, name); this->paws = paws; }
	void SetPaws(int paws) { this->paws = paws; }
	int GetPaws() { return paws; }
	void Show() { cout << "Cat name: " << name << ";\t paws: " << paws << endl; }
};

class Parrot : public Pets
{
	int wings;
public:
	Parrot() { name = new char[20], strcpy(name, "Vova"), wings = 2; };
	Parrot(char *name, int wings) { this->name = new char[20]; strcpy(this->name, name); this->wings = wings; }
	void SeWings(int wings) { this->wings = wings; }
	int GetWings() { return wings; }
	void Show() { cout << "Parrot name: " << name << ";\t wings: " << wings << endl; }
};

int main()
{
	char *name = new char[10];
	int wings;
	Dog Bublic;
	Bublic.Show();
	strcpy(name, "Kyzja");
	Cat Vasja(name, 4);	
	Vasja.Show();
	cout << "Enter name parrot: ";
	gets_s(name,20);
	strcpy(name, name);
	cout << "Enter number wings: ";	
	cin >> wings;
	Parrot Kesha(name, wings);
	Kesha.Show();
	system("pause");
	return 0;
}