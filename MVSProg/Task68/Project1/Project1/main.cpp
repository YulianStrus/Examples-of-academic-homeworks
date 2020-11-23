#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "cmath"
#include "fstream"
using namespace std;

class Exception
{
	const char *s;
public:
	Exception() { s = "Unknown error"; }
	Exception(const char *s) { this->s = s; }
	void Show() { cout << s << endl << endl; }
};

class CheckCoordinates : public Exception
{
public:
	CheckCoordinates() :Exception("Error!!! Please enter coordinates") {}
};

class SameSave : public Exception
{
public:
	SameSave() : Exception("These coordinates have already been saved!") {}
};

class EmptyFile :public Exception
{
public:
	EmptyFile() :Exception("Error!!! Empty file!") {}
};

class DivisionZero : public Exception
{
public:
	DivisionZero() :Exception("Cannot divided to zero!") {}
};

class SameLoad : public Exception
{
public:
	SameLoad() :Exception("These coordinates have already been saved!") {}
};

class SameCoordinates :public Exception
{
public:
	SameCoordinates() :Exception("These coordinates have already been saved!") {}
};

class Coordinates
{
	double a1;
	double a2;
	double b1;
	double b2;
	int n;
public:
	Coordinates() { a1 = 0; a2 = 0; b1 = 0; b2 = 0; n = 0; }
	Coordinates(double a1, double a2, double b1, double b2, int n)
	{
		this->a1 = a1;
		this->a2 = a2;
		this->b1 = b1;
		this->b2 = b2;
		this->n = n;
	}
	void SetA1(double a1) { this->a1 = a1; }
	void SetA2(double a2) { this->a2 = a2; }
	void SetB1(double b1) { this->b1 = b1; }
	void SetB2(double b2) { this->b2 = b2; }
	void SetN(int n) { this->n = n; }
	double GetA1() { return a1; }
	double GetA2() { return a2; }
	double GetB1() { return b1; }
	double GetB2() { return b2; }
	int GetN() { return n; }
};

class Vector2d
{
private:
	double a1;
	double a2;
public:
	Vector2d()
	{
		a1 = 1;
		a2 = 1;
	}
	Vector2d(double a1, double a2)
	{
		this->a1 = a1;
		this->a2 = a2;
	}
	void SetA1(double a1) { this->a1 = a1; }
	void SetA2(double a2) { this->a2 = a2; }
	double GetA1() { return a1; }
	double GetA2() { return a2; }
	Vector2d operator+(int n) { return Vector2d(a1 + n, a2 + n); }
	Vector2d operator+(const Vector2d&other) { return Vector2d(this->a1 + other.a1, this->a2 + other.a2); }
	Vector2d operator-(int n) { return Vector2d(a1 - n, a2 - n); }
	Vector2d operator-() { return Vector2d(a1 = -a1, a2 = -a2); }
	Vector2d operator-(const Vector2d&other) { return Vector2d(this->a1 - other.a1, this->a2 - other.a2); }
	Vector2d operator*(int n) { return Vector2d(a1*n, a2*n); }
	double operator*(const Vector2d&other) { return (this->a1*other.a1) + (this->a2*other.a2); }
	Vector2d operator/(int n) { return Vector2d(a1 / n, a2 / n); }
	void operator+=(int n) { a1 += n; a2 += n; }
	void operator+=(const Vector2d&other) { this->a1 += other.a1; this->a2 += +other.a2; }
	void operator-=(int n) { a1 -= n; a2 -= n; }
	void operator-=(const Vector2d&other) { this->a1 -= other.a1; this->a2 -= other.a2; }
	void operator*=(int n) { a1 *= n; a2 *= n; }
	void operator*=(const Vector2d&other) { this->a1 *= other.a1; this->a2 *= other.a2; }
	void operator/=(int n) { a1 /= n; a2 /= n; }
};

Coordinates EnterCoordinates(Coordinates c)
{
	double a1, a2, b1, b2;
	int n;
	cout << "Enter first point of first vector: ";
	cin >> a1;
	cout << "Enter second point of first vector: ";
	cin >> a2;
	cout << "Enter first point of second vector: ";
	cin >> b1;
	cout << "Enter second point of second vector: ";
	cin >> b2;
	cout << "Enter number: ";
	cin >> n;
	try
	{
		if (a1 == b1 && a2 == b2) throw SameCoordinates();
		else
		{
			c.SetA1(a1);
			c.SetA2(a2);
			c.SetB1(b1);
			c.SetB2(b2);
			c.SetN(n);
		}
	}
	catch (SameCoordinates&obj) { obj.Show(); }
	return c;
}

void Show(Coordinates c)
{
	Vector2d V1(c.GetA1(), c.GetA2());
	Vector2d V2(c.GetB1(), c.GetB2());
	Vector2d Vplus1 = V1 + c.GetN();
	Vector2d Vplus2 = V2 + c.GetN();
	cout << "Overload plus for number: " << "a(" << V1.GetA1() << ", " << V1.GetA2() << ") + " << c.GetN() << " = a(" << Vplus1.GetA1() << ", " << Vplus1.GetA2() << ")" << endl;
	cout << "                          " << "b(" << V2.GetA1() << ", " << V2.GetA2() << ") + " << c.GetN() << " = b(" << Vplus2.GetA1() << ", " << Vplus2.GetA2() << ")" << endl << endl;
	Vector2d Vplus = V1 + V2;
	cout << "Overload plus for vectors: " << "a(" << V1.GetA1() << ", " << V1.GetA2() << ") + " << "b(" << V2.GetA1() << ", " << V2.GetA2() << ") = c(" << Vplus.GetA1() << ", " << Vplus.GetA2() << ")" << endl << endl;
	Vector2d Vminus1 = V1 - c.GetN();
	Vector2d Vminus2 = V2 - c.GetN();
	Vector2d Vminus3 = V1; -Vminus3;
	Vector2d Vminus4 = V2; -Vminus4;
	Vector2d Vminus = V1 - V2;
	cout << "Overload minus for number: " << "a(" << V1.GetA1() << ", " << V1.GetA2() << ") - " << c.GetN() << " = a(" << Vminus1.GetA1() << ", " << Vminus1.GetA2() << ")" << endl;
	cout << "                           " << "b(" << V2.GetA1() << ", " << V2.GetA2() << ") - " << c.GetN() << " = b(" << Vminus2.GetA1() << ", " << Vminus2.GetA2() << ")" << endl << endl;
	cout << "Overload unary minus: " << "-a(" << Vminus3.GetA1() << ", " << Vminus3.GetA2() << ")" << endl;
	cout << "                      " << "-b(" << Vminus4.GetA1() << ", " << Vminus4.GetA2() << ")" << endl << endl;
	cout << "Overload minus for vectors: " << "a(" << V1.GetA1() << ", " << V1.GetA2() << ") - " << "b(" << V2.GetA1() << ", " << V2.GetA2() << ") = c(" << Vminus.GetA1() << ", " << Vminus.GetA2() << ")" << endl << endl;
	Vector2d Vmult1 = V1 * c.GetN();
	Vector2d Vmult2 = V2 * c.GetN();
	double Vmult = V1 * V2;
	cout << "Overload multiplication for number: " << "a(" << V1.GetA1() << ", " << V1.GetA2() << ") * " << c.GetN() << " = a(" << Vmult1.GetA1() << ", " << Vmult1.GetA2() << ")" << endl;
	cout << "                                    " << "b(" << V2.GetA1() << ", " << V2.GetA2() << ") * " << c.GetN() << " = b(" << Vmult2.GetA1() << ", " << Vmult2.GetA2() << ")" << endl << endl;
	cout << "Overload multiplication for vectors: " << "a(" << V1.GetA1() << ", " << V1.GetA2() << ") * " << "b(" << V2.GetA1() << ", " << V2.GetA2() << ") = " << Vmult << endl << endl;
	Vector2d Vplustot1, Vplustot2, Vplustot;
	Vplustot1 = V1;
	Vplustot2 = V2;
	Vplustot1 += c.GetN();
	Vplustot2 += c.GetN();
	Vplustot = V1;
	Vplustot += V2;
	cout << "Overload += for number: " << "a(" << V1.GetA1() << ", " << V1.GetA2() << ") + " << c.GetN() << " = a(" << Vplustot1.GetA1() << ", " << Vplustot1.GetA2() << ")" << endl;
	cout << "                        " << "b(" << V2.GetA1() << ", " << V2.GetA2() << ") + " << c.GetN() << " = b(" << Vplustot2.GetA1() << ", " << Vplustot2.GetA2() << ")" << endl << endl;
	cout << "Overload += for vectors: " << "a(" << V1.GetA1() << ", " << V1.GetA2() << ") + " << "b(" << V2.GetA1() << ", " << V2.GetA2() << ") = c(" << Vplustot.GetA1() << ", " << Vplustot.GetA2() << ")" << endl << endl;
	Vector2d Vminustot1, Vminustot2, Vminustot;
	Vminustot1 = V1;
	Vminustot2 = V2;
	Vminustot = V1;
	Vminustot1 -= c.GetN();
	Vminustot2 -= c.GetN();
	Vminustot -= V2;
	cout << "Overload -= for number: " << "a(" << V1.GetA1() << ", " << V1.GetA2() << ") - " << c.GetN() << " = a(" << Vminustot1.GetA1() << ", " << Vminustot1.GetA2() << ")" << endl;
	cout << "                        " << "b(" << V2.GetA1() << ", " << V2.GetA2() << ") - " << c.GetN() << " = b(" << Vminustot2.GetA1() << ", " << Vminustot2.GetA2() << ")" << endl << endl;
	cout << "Overload -= for vectors: " << "a(" << V1.GetA1() << ", " << V1.GetA2() << ") - " << "b(" << V2.GetA1() << ", " << V2.GetA2() << ") = c(" << Vminustot.GetA1() << ", " << Vminustot.GetA2() << ")" << endl << endl;
	Vector2d Vmultot1, Vmultot2, Vmultot;
	Vmultot1 = V1;
	Vmultot2 = V2;
	Vmultot = V1;
	Vmultot1 *= c.GetN();
	Vmultot2 *= c.GetN();
	Vmultot *= V2;
	cout << "Overload *= for number: " << "a(" << V1.GetA1() << ", " << V1.GetA2() << ") * " << c.GetN() << " = a(" << Vmultot1.GetA1() << ", " << Vmultot1.GetA2() << ")" << endl;
	cout << "                        " << "b(" << V2.GetA1() << ", " << V2.GetA2() << ") * " << c.GetN() << " = b(" << Vmultot2.GetA1() << ", " << Vmultot2.GetA2() << ")" << endl << endl;
	cout << "Overload *= for vectors: " << "a(" << V1.GetA1() << ", " << V1.GetA2() << ") * " << "b(" << V2.GetA1() << ", " << V2.GetA2() << ") = c(" << Vmultot.GetA1() << ", " << Vmultot.GetA2() << ")" << endl << endl;
	try
	{
		if (c.GetN() == 0) throw DivisionZero();
		else
		{
			Vector2d Vdiv1 = V1 / c.GetN();
			Vector2d Vdiv2 = V2 / c.GetN();
			cout << "Overload division for number: " << "a(" << V1.GetA1() << ", " << V1.GetA2() << ") / " << c.GetN() << " = a(" << Vdiv1.GetA1() << ", " << Vdiv1.GetA2() << ")" << endl;
			cout << "                              " << "b(" << V2.GetA1() << ", " << V2.GetA2() << ") / " << c.GetN() << " = b(" << Vdiv2.GetA1() << ", " << Vdiv2.GetA2() << ")" << endl << endl;
			Vector2d Vdivtot1, Vdivtot2;
			Vdivtot1 = V1;
			Vdivtot2 = V2;
			Vdivtot1 /= c.GetN();
			Vdivtot2 /= c.GetN();
			cout << "Overload /= for number: " << "a(" << V1.GetA1() << ", " << V1.GetA2() << ") / " << c.GetN() << " = a(" << Vdivtot1.GetA1() << ", " << Vdivtot1.GetA2() << ")" << endl;
			cout << "                        " << "b(" << V2.GetA1() << ", " << V2.GetA2() << ") / " << c.GetN() << " = b(" << Vdivtot2.GetA1() << ", " << Vdivtot2.GetA2() << ")" << endl << endl;
		}
	}
	catch (DivisionZero&obj) { obj.Show(); }
}

bool CheckFile()
{
	ifstream g;
	g.open("file.dat");
	g.seekg(0, ios_base::end);
	if (g.tellg() > 0)
	{
		g.close();
		return true;
	}
	else
	{
		g.close();
		return false;
	}
}

bool Check(Coordinates c)
{
	Coordinates temp;
	double buf;
	ifstream g;
	g.open("file.dat");
	g >> buf;
	temp.SetA1(buf);
	g >> buf;
	temp.SetA2(buf);
	g >> buf;
	temp.SetB1(buf);
	g >> buf;
	temp.SetB2(buf);
	g >> buf;
	temp.SetN(buf);
	if (temp.GetA1() == c.GetA1() && temp.GetA2() == c.GetA2() && temp.GetB1() == c.GetB1() && temp.GetB2() == c.GetB2() && temp.GetN() == c.GetN()) return true;
	else return false;
}

Coordinates Load(Coordinates c)
{
	try
	{
		if (!CheckFile()) throw EmptyFile();
		else
		{
			try
			{
				if (Check(c)) throw SameLoad();
				else
				{
					double buf;
					ifstream g;
					g.open("file.dat");
					g >> buf;
					c.SetA1(buf);
					g >> buf;
					c.SetA2(buf);
					g >> buf;
					c.SetB1(buf);
					g >> buf;
					c.SetB2(buf);
					g >> buf;
					c.SetN(buf);
					g.close();
				}
			}
			catch (SameLoad&obj) { obj.Show(); }
		}
	}
	catch (EmptyFile&obj) { obj.Show(); }
	return c;
}

void Save(Coordinates c)
{
	try
	{
		if (Check(c)) throw SameSave();
		else
		{
			ofstream g;
			g.open("file.dat");
			g << c.GetA1() << endl;
			g << c.GetA2() << endl;
			g << c.GetB1() << endl;
			g << c.GetB2() << endl;
			g << c.GetN() << endl;
			g.close();
		}
	}
	catch (SameSave&obj) { obj.Show(); }
}

int main()
{
	Coordinates c;
	int m = 1;
	while (m != 0)
	{
	cout << "1. Enter coordinates\n2. Show\n3. Load from file\n4. Save in file\n0. Exit" << endl << endl;
	cin >> m;
	if (m == 1)
		c = EnterCoordinates(c);
	else if (m == 2)
		try
		{
			if (c.GetA1() == 0 && c.GetA2() == 0 && c.GetB1() == 0 && c.GetB2() == 0 && c.GetN() == 0) throw CheckCoordinates();
			else Show(c);
		}
		catch (CheckCoordinates&obj) { obj.Show(); }
	else if (m == 3)
		c = Load(c);
	else if (m == 4)
		try
	{
		if (c.GetA1() == 0 && c.GetA2() == 0 && c.GetB1() == 0 && c.GetB2() == 0 && c.GetN() == 0) throw CheckCoordinates();
		else Save(c);
	}
	catch (CheckCoordinates&obj) { obj.Show(); }
	else if (m == 0)
		break;
	else
		cout << "Incorrect select. Try again" << endl
		<< endl;
	}
	system("pause");
	return 0;
}