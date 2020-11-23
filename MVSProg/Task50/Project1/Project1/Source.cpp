#include <iostream>
#include <time.h>
using namespace std;

class Reserv
{
	char *name = new char[30];
	int length;
	int width;
	int height;
public:
	void Add(char *name)
	{
		strcpy(this->name, "name");
		cout << "Vvedite width (m): ";
		cin >> width;
		cout << "Vvedite length (m):";
		cin >> length;
		cout << "Vvedite height (m): ";
		cin >> height;
	};
	void Show()
	{
		cout << "Name: " << name << endl;
		cout << "width (m): " << width << endl;
		cout << "length (m):" << length << endl;
		cout << "height (m): " << height << endl;
	};
	void Volume()
	{

		cout << "Volume: " << length * width*height << " m3" << endl;
	};
	void Area()
	{

		cout << "Area: " << length * width << " m2" << endl;
	};
	void Srav()
	{
		if (length*width*height < 10000)
		{
			cout << name << " - pool" << endl;
		}
		else
		{
			cout << name << " - sea" << endl;
		}

	};
	int Getsea()
	{
		return length * width * height;
	};

	Reserv(const Reserv &obj)
	{
		strcpy(name, obj.name);
		length = obj.length;
		width = obj.width;
		height = obj.height;
	};
	
	Reserv() 
	{
		strcpy(name, "Reserv");
		length = 1 + rand() % 1000;
		width = 1 + rand() % 50;
		height = 1 + rand() % 20;
	};

	~Reserv() { delete[] name;};
};


void main()
{
	srand(time(0));
	int n = 2;
	Reserv* a = new Reserv[n];
	Reserv b;
	int z = 0;
	for (int i = 0; i < n; i++)
	{
		a[i].Volume();
		a[i].Area();
		a[i].Srav();
		if (a[i].Getsea() > 12500)
		{
			z++;
		}

	}
	cout << z << endl;
	a[2].Show();

	a[2].Show();

	b = a[2];
	b.Show();

	cout << endl;

	a[2].Volume();
	a[2].Area();
	a[2].Srav();

	delete[] a;
	cin.get();
} 