#include <iostream>
#include <string>
using namespace std;

class Flat
{
	int square;
	int price;

public:
	Flat() { }
	
	void SetType(int sq, int prc)
	{
		square = sq;
		price = prc;
	}
	void showInfo()
	{
		cout << square << ":" << price;
	}
	friend bool operator== (Flat &O1, Flat &O2)
	{
		return (O1.square == O2.square);
	}
	Flat operator= (Flat &O2)
	{
		square = O2.square;
		price = O2.price;
		return *this;
	}
	friend bool operator< (Flat &O1, Flat &O2)
	{
		return O1.price < O2.price;
	}
};

int main()
{
	Flat OCoat1, OCoat2, OCoat3;
	OCoat1.SetType(60, 21000);
	OCoat2.SetType(38, 15000);
	OCoat3.SetType(60, 21000);

	if (OCoat1 == OCoat3)
	{
		if (OCoat1 < OCoat2)
		{
			OCoat1.showInfo(); cout << " cheaper than a ";  OCoat2.showInfo();
		}

		else
		{
			OCoat2.showInfo(); cout << " cheaper than a "; OCoat1.showInfo();
		}
	}
	else OCoat3 = OCoat2;

	cout << "\nFlat 1 : ";
	OCoat1.showInfo();
	cout << "\nFlat 2 : ";
	OCoat2.showInfo();
	cout << "\nFlat 3 : ";
	OCoat3.showInfo();
	cin.get();
	return 0;
}