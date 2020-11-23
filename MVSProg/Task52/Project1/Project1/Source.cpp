#include <iostream>
#include <string.h>
using namespace std;

class Overcoat
{
	char *type;
	int price;

public:
	Overcoat() { type = new char[20]; strcpy(type, "Jacet"); price = 1500; }
	~Overcoat() { delete[]type; }
	void SetType(char *tp, int prc, Overcoat &obj)
	{
		strcpy(obj.type, tp);
		obj.price = prc;
	}
	void showType()
	{
		cout << type;
	}
	void showOvercoat()
	{
		cout << type << " : " << price << endl;
	}
	friend bool operator== (Overcoat &O1, Overcoat &O2)
	{
		return (O1.type == O2.type);
	}
	Overcoat operator= (Overcoat &O2)
	{
		type = O2.type;
		price = O2.price;
		return *this;
	}
	friend bool operator< (Overcoat &O1, Overcoat &O2)
	{
		return O1.price < O2.price;
	}
};

int main()
{
	Overcoat OCoat1, OCoat2, OCoat3;
	OCoat1.SetType ("Jacket", 1588, OCoat2);
	OCoat2.SetType ("Coat", 2050, OCoat3);
	OCoat3.SetType ("Jacket", 2500, OCoat1);

	if (OCoat1 == OCoat3)
	{
		if (OCoat1 < OCoat3)
		{
			OCoat1.showType(); cout << "is more expensive than a "; OCoat2.showType();
		}

		else
		{
			OCoat2.showType(); cout << "is more expensive than a "; OCoat1.showType();
		}
	}

	OCoat1 = OCoat2;
	cout << "\nOvercoat 1 : ";
	OCoat1.showOvercoat();
	cout << "\nOvercoat 2 : ";
	OCoat2.showOvercoat();
	cout << "\nOvercoat 3 : ";
	OCoat3.showOvercoat();
	cin.get();
	return 0;
}