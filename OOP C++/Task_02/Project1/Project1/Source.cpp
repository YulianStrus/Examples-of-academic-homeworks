#include "iostream"
#include "cmath"
#include "fstream"
using namespace std;

class Point
{
private:
	int x;
	int y;
	int z;
public:
	Point() { x = 3, y = 4, z = 5; }
	Point(int a, int b, int c){ x=a, y = b, z = c;}
	void SetX(int a) { x = a; }
	void SetY(int b) { y = b; }
	void SetZ(int c) { z = c; }
	int GetX() { return x; }
	int GetY() { return y; }
	int GetZ() { return z; }
};

int main()
{
	int a, b, c;
	char q='1';
	Point XYZ(3,4,5);
	while (q != 'q')
	{
		cout << "Select a menu item: \n\t1 - Enter Point \n\t2 - Write in file \n\tq - Quit " << endl;
		cin >> q;
		if (q == '1')
		{
			cout << "Enter x - point: ";
			cin >> a;
			cout << "Enter y - point: ";
			cin >> b;
			cout << "Enter z - point: ";
			cin >> c;
			Point XYZ1(a, b, c);
			cout << "X = " << XYZ1.GetX() << endl;
			cout << "Y = " << XYZ1.GetY() << endl;
			cout << "Z = " << XYZ1.GetZ() << endl;
			XYZ = XYZ1;
			cout << endl;
		}
		else if (q == '2')
		{
			ofstream f;
			f.open("ini.dat");
			f << "X = " << XYZ.GetX() << endl;
			f << "Y = " << XYZ.GetY() << endl;
			f << "Z = " << XYZ.GetZ() << endl;
			cout << endl;
			f.close();
		}
		else if (q == '3')
		{
			char r;
			ifstream f;
			f.open("ini.dat");
			for (; f.peek() != EOF;)
			{
				f >> r;
				cout << r << " ";
			}
			cout << endl;
			f.close();
		}
	}
	system("pause");
	return 0;
}