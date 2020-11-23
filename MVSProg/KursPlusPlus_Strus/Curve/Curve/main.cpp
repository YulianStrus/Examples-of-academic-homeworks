#include <iostream>
#include "cmath"
#include "windows.h"
#include "math.h"

using namespace std;

class Point
{
protected:
	int x;
	int y;
public:
	Point() { x = 0; y = 0; };
	Point(int x, int y) { this->x = x; this->y = y; }
	void SetX(int x) { this->x = x; }
	void SetY(int y) { this->y = y; }
	int GetX() { return x; }
	int GetY() { return y; }
	void Show() { cout << x << " " << y << endl; }
};

class Curve
{
protected:
	Point p1;
	Point p2;
public:
	Curve() {}
	Curve(Point p1, Point p2) { this->p1 = p1; this->p2 = p2; }
	void SetP1(Point p1) { this->p1 = p1; }
	void SetP2(Point p2) { this->p2 = p2; }
	Point GetP1() { return p1; }
	Point GetP2() { return p2; }
	void Show() { p1.Show(); p2.Show(); }
	virtual void length() = 0;
};

class Line : public Curve
{
public:
	Line() :Curve() {}
	Line(Point p1, Point p2) :Curve(p1, p2) {}
	void length() { cout << abs(sqrt(pow((p2.GetX() - p1.GetX()), 2) + pow((p2.GetY() - p1.GetY()), 2))) << endl; }
	void Show()
	{
		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);
		SelectObject(hdc, GetStockObject(WHITE_PEN));
		for (double i = 0; i <= 1; i += 0.001)
			SetPixel(hdc, (1 - i) * p1.GetX() + i * p2.GetX(), (1 - i) * p1.GetY() + i * p2.GetY(), RGB(255, 255, 255));
		ReleaseDC(hwnd, hdc);
	}
};

class arc : public Curve
{
protected:
	Point ref_p;
public:
	arc() : Curve() {}
	arc(Point p1, Point p2, Point ref_p) :Curve(p1, p2) { this->ref_p = ref_p; }
	void SetRefP(Point ref_p) { this->ref_p = ref_p; }
	Point GetRefP() { return ref_p; }
	void length()
	{
		cout << "\nLength: "<< sqrt(pow(((p1.GetX() - 2 * ref_p.GetX() + p2.GetX()) * 2), 2) + pow(((p1.GetY() - 2 * ref_p.GetY() + p2.GetY()) * 2), 2)) << endl;
	}
	void Show()
	{
		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);
		SelectObject(hdc, GetStockObject(WHITE_PEN));
		for (double i = 0; i <= 1; i += 0.001)
			SetPixel(hdc, (1 - i) * (1 - i) * p1.GetX() + 2 * i * (1 - i) * ref_p.GetX() + i * i * p2.GetX(), (1 - i) * (1 - i) * p1.GetY() + 2 * i * (1 - i) * ref_p.GetY() + i * i * p2.GetY(), RGB(0, 0, 255));
		ReleaseDC(hwnd, hdc);
	}
	void angle()
	{
		double an = (pow(sqrt(pow((ref_p.GetX() - p1.GetX()), 2) + pow((ref_p.GetY() - p1.GetY()), 2)), 2) + pow(sqrt(pow((p2.GetX() - ref_p.GetX()), 2) + pow((p2.GetY() - ref_p.GetY()), 2)), 2) - pow(sqrt(pow((p2.GetX() - p1.GetX()), 2) + pow((p2.GetY() - p1.GetY()), 2)), 2)) / 2 * sqrt(pow((ref_p.GetX() - p1.GetX()), 2) + pow((ref_p.GetY() - p1.GetY()), 2)) * sqrt(pow((p2.GetX() - ref_p.GetX()), 2) + pow((p2.GetY() - ref_p.GetY()), 2));
		char grad = 248;
		cout << "\nAngle: " << cos(an) * 180 / 3.14 << grad;
	}
	void radius()
	{
		cout << "\nRadius: " << sqrt(pow((p2.GetX() - p1.GetX()), 2) + pow((p2.GetY() - p1.GetY()), 2)) / 2;
	}
};

class triangle : public Line
{
protected:
	Point ref_p;
public:
	triangle() : Line() {}
	triangle(Point p1, Point p2, Point ref_p) :Line(p1, p2) { this->ref_p = ref_p; }
	void SetRefP(Point ref_p) { this->ref_p = ref_p; }
	Point GetRefP() { return ref_p; }
	void length()
	{
		double a = abs(sqrt(pow((p2.GetX() - p1.GetX()), 2) + pow((p2.GetY() - p1.GetY()), 2)));
		double b = abs(sqrt(pow((ref_p.GetX() - p2.GetX()), 2) + pow((ref_p.GetY() - p2.GetY()), 2)));
		double c = abs(sqrt(pow((p1.GetX() - ref_p.GetX()), 2) + pow((p1.GetY() - ref_p.GetY()), 2)));
		cout << a+b+c << endl;
	}
	void Show()
	{
		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);
		SelectObject(hdc, GetStockObject(WHITE_PEN));
		for (double i = 0; i <= 1; i += 0.001)
		{
			SetPixel(hdc, (1 - i) * p1.GetX() + i * p2.GetX(), (1 - i) * p1.GetY() + i * p2.GetY(), RGB(255, 0, 0));
			SetPixel(hdc, (1 - i) * p2.GetX() + i * ref_p.GetX(), (1 - i) * p2.GetY() + i * ref_p.GetY(), RGB(255, 0, 0));
			SetPixel(hdc, (1 - i) * ref_p.GetX() + i * p1.GetX(), (1 - i) * ref_p.GetY() + i * p1.GetY(), RGB(255, 0, 0));
		}
		ReleaseDC(hwnd, hdc);
	}
	double operator()()
	{
		double a = abs(sqrt(pow((p2.GetX() - p1.GetX()), 2) + pow((p2.GetY() - p1.GetY()), 2)));
		double b = abs(sqrt(pow((ref_p.GetX() - p2.GetX()), 2) + pow((ref_p.GetY() - p2.GetY()), 2)));
		double c = abs(sqrt(pow((p1.GetX() - ref_p.GetX()), 2) + pow((p1.GetY() - ref_p.GetY()), 2)));
		return a + b + c;
	}
	void Square()
	{
		auto square = [](Point p1, Point p2, Point ref_p)
		{
			double a = abs(sqrt(pow((p2.GetX() - p1.GetX()), 2) + pow((p2.GetY() - p1.GetY()), 2)));
			double b = abs(sqrt(pow((ref_p.GetX() - p2.GetX()), 2) + pow((ref_p.GetY() - p2.GetY()), 2)));
			double c = abs(sqrt(pow((p1.GetX() - ref_p.GetX()), 2) + pow((p1.GetY() - ref_p.GetY()), 2)));
			return sqrt(((a + b + c) / 2) * (((a + b + c) / 2) - a) * (((a + b + c) / 2) - b) * (((a + b + c) / 2) - c));
		};
		cout << "Square triangle = " << square(p1, p2, ref_p) << endl;
	}

	bool operator()(Point p1, Point p2, Point ref_p)
	{
		double a = abs(sqrt(pow((p2.GetX() - p1.GetX()), 2) + pow((p2.GetY() - p1.GetY()), 2)));
		double b = abs(sqrt(pow((ref_p.GetX() - p2.GetX()), 2) + pow((ref_p.GetY() - p2.GetY()), 2)));
		double c = abs(sqrt(pow((p1.GetX() - ref_p.GetX()), 2) + pow((p1.GetY() - ref_p.GetY()), 2)));

		if ((a < 0 || a >600) || (b < 0 || b >600) || (c < 0 || c >600) || (b+c <= a))
		{
			if (a < 0 || a >600)
				cout << "Incorrect width a. The width of screen 650px.\nFor the correct image please enter width less 600px\n\n";
			if (b < 0 || b >600)
				cout << "Incorrect width b. The width of screen 650px.\nFor the correct image please enter width less 600px\n\n";
			if (c < 0 || c >600)
				cout << "Incorrect width c. The width of screen 650px.\nFor the correct image please enter width less 600px\n\n";
			if (b + c <= a)
				cout << "The amount of catechins can not be less than hypotenuse.\n\n";
			return false;
		}
		else return true;
	}

};

class Parabola : public arc
{
public:
	Parabola() : arc() {}
	Parabola(Point p1, Point p2) :arc(p1, p2, ref_p) {}

	void length()
	{
		cout << sqrt(pow(((p1.GetX() - 2 * ((p1.GetX() + p2.GetX() / 2)) + p2.GetX()) * 2), 2) + pow(((p1.GetY() - 2 * ((p1.GetX() + p2.GetX() / 2)) + p2.GetY()) * 2), 2)) << endl;
	}
	void Show()
	{
		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);
		SelectObject(hdc, GetStockObject(WHITE_PEN));
		ref_p.SetX((p1.GetX() + p2.GetX()) / 2);
		ref_p.SetY((p1.GetX() + p2.GetX()) / 2);
		for (double i = 0; i <= 1; i += 0.001)
		{
			SetPixel(hdc, (1 - i) * (1 - i) * p1.GetX() + 2 * i * (1 - i) * ref_p.GetX() + i * i * p2.GetX(), (1 - i) * (1 - i) * p1.GetY() + 2 * i * (1 - i) * ref_p.GetY() + i * i * p2.GetY(), RGB(0, 255, 255));
		}
		ReleaseDC(hwnd, hdc);
	}
	double operator()()
	{
		return sqrt(pow(((p1.GetX() - 2 * ((p1.GetX() + p2.GetX() / 2)) + p2.GetX()) * 2), 2) + pow(((p1.GetY() - 2 * ((p1.GetX() + p2.GetX() / 2)) + p2.GetY()) * 2), 2));
	}
	void Square()
	{
		auto square = [](Point p1, Point p2)
		{
			double a = abs(sqrt(pow((p2.GetX() - p1.GetX()), 2) + pow((p2.GetY() - p1.GetY()), 2)));
			double b = abs(sqrt(pow(((p1.GetX() + p2.GetX() / 2) - p2.GetX()), 2) + pow(((p1.GetX() + p2.GetX() / 2) - p2.GetY()), 2)));
			double c = abs(sqrt(pow((p1.GetX() - (p1.GetX() + p2.GetX() / 2)), 2) + pow((p1.GetY() - (p1.GetX() + p2.GetX() / 2)), 2)));
			double cat = a / 2;
			double gip = (c * c) - (cat * cat);
			return (3.14 * cat * gip) / 2;
		};
		cout << "Square parabola = " << square(p1, p2) << endl;
	}
	bool operator()(Point p1, Point p2)
	{
		double a = abs(sqrt(pow((p2.GetX() - p1.GetX()), 2) + pow((p2.GetY() - p1.GetY()), 2)));
		double b = abs(sqrt(pow(((p1.GetX() + p2.GetX() / 2) - p2.GetX()), 2) + pow(((p1.GetX() + p2.GetX() / 2) - p2.GetY()), 2)));
		double c = abs(sqrt(pow((p1.GetX() - (p1.GetX() + p2.GetX() / 2)), 2) + pow((p1.GetY() - (p1.GetX() + p2.GetX() / 2)), 2)));

		if ((a < 0 || a >600) || (b < 0 || b >600) || (c < 0 || c >600) || (b + c <= a))
		{
			if (a < 0 || a >600)
				cout << "Incorrect width a. The width of screen 650px.\nFor the correct image please enter width less 600px\n\n";
			if (b < 0 || b >600)
				cout << "Incorrect width b. The width of screen 650px.\nFor the correct image please enter width less 600px\n\n";
			if (b + c <= a)
				cout << "The vertex of the parabola must not coincide with the x-coordinates of point A.\n\n";
			return false;
		}
		else return true;
	}

};


int main(void)
{
	Point cent_p(350, 350);
	Point p1(200, 100);
	Point p2(700, 100);
	
	int x1, x2, y1, y2, c1, c2;
	int menu = 1, line = 1, Arc = 1, Triangle = 1, parabola = 1;
	while (menu != 0)
	{
		cout << "\nEnter number: \n\t1.Line \n\t2.Arc \n\t3.Triangle \n\t4.Parabola \n\t0.Exit" << endl;
		cin >> menu;
		if (menu == 1)
		{
		/*	cout << "Enter point 1: ";
			cin >> x1;
			cin >> y1;
			Point p1(x1, y1);
			cout << "Enter point 2: ";
			cin >> x2;
			cin >> y2;
			Point p2(x2, y2);*/
			Line ln(p1, p2);
			while (line!=0)
			{
			cout << "\nEnter number: \n\t1.Show \n\t2.Length \n\t0.Main menu" << endl;
			cin >> line;
			if (line == 1)
			{
				cout << "\nLine: "; ln.Show(); cin.get();
			}
			else if (line == 2)
			{
				cout << "\nLine length: "; ln.length();
			}
			else if (line == 0)	break;
			else cout << "\nIncorrect select. Try again" << endl << endl;
			}
		}

		else if (menu == 2)
		{
		/*	cout << "Enter point 1: ";
			cin >> x1;
			cin >> y1;
			Point p1(x1, y1);
			cout << "Enter point 2: ";
			cin >> x2;
			cin >> y2;
			Point p2(x2, y2);
			cout << "Enter centr point: ";
			cin >> c1;
			cin >> c2;
			Point cent_p(c1, c2);*/
			arc ar(p1, p2, cent_p);
			while (Arc != 0)
			{
				cout << "\nEnter number: \n\t1.Show \n\t2.Length \n\t3.Angle \n\t4.Radius \n\t0.Main menu" << endl;
				cin >> Arc;
				if (Arc == 1)
				{
					cout << "\nArc: "; ar.Show(); cin.get();
				}
				else if (Arc == 2)
				{
					ar.length();
				}
				else if (Arc == 3)
				{
					ar.angle();
				}
				else if (Arc == 4)
				{
					ar.radius();
				}
				else if (Arc == 0)	break;
				else cout << "\nIncorrect select. Try again" << endl << endl;
			}
		}

		else if (menu == 3)
		{
			cout << "Enter point 1: ";
			cin >> x1;
			cin >> y1;
			Point p1(x1, y1);
			cout << "Enter point 2: ";
			cin >> x2;
			cin >> y2;
			Point p2(x2, y2);
			cout << "Enter centr point: ";
			cin >> c1;
			cin >> c2;
			Point cent_p(c1, c2);
			triangle tr(p1, p2, cent_p);
			if (!tr(p1, p2, cent_p)) cout << "Try again\n\n";
			else
			{

			while (Triangle != 0)
			{
				cout << "\nEnter number: \n\t1.Show \n\t2.Length \n\t3.Perimetr \n\t4.Square \n\t0.Main menu" << endl;
				cin >> Triangle;
				if (Triangle == 1)
				{

					cout << "\nTriangle: "; tr.Show(); cin.get();
				}
				else if (Triangle == 2)
				{
					cout << "\nTriangle length: "; tr.length();
				}
				else if (Triangle == 3)
				{
					cout << "\nPerimetr figure: " << tr() << endl;
				}
				else if (Triangle == 4)
				{
					tr.Square();
				}
				else if (Triangle == 0)	break;
				else cout << "\nIncorrect select. Try again" << endl << endl;
			}
			}
		}

		else if (menu == 4)
		{
	/*	cout << "Enter point 1: ";
		cin >> x1;
		cin >> y1;
		Point p1(x1, y1);
		cout << "Enter point 2: ";
		cin >> x2;
		cin >> y2;
		Point p2(x2, y2);
		cout << "Enter centr point: ";
		cin >> c1;
		cin >> c2;
		Point cent_p(c1, c2);*/
		Parabola pr(p1, p2);
		if (!pr(p1, p2)) cout << "Try again\n\n";
		else
		{
		while (parabola != 0)
		{
			cout << "\nEnter number: \n\t1.Show \n\t2.Length \n\t3.Perimetr \n\t4.Square \n\t0.Main menu" << endl;
			cin >> parabola;
			if (parabola == 1)
			{

				cout << "\nParabola: "; pr.Show(); cin.get();
			}
			else if (parabola == 2)
			{
				cout << "\nParabola length: "; pr.length();
			}
			else if (parabola == 3)
			{
				cout << "\nPerimetr figure: " << pr() << endl;
			}
			else if (parabola == 4)
			{
				pr.Square();
			}
			else if (parabola == 0)	break;
			else cout << "\nIncorrect select. Try again" << endl << endl;
		}
		}
		}
		else if (menu == 0)	break;
		else cout << "\nIncorrect select. Try again" << endl << endl;
	}

	system("pause");
}