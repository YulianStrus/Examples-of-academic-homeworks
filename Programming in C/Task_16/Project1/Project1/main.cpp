#include "Header.h"
int main()
{
	int a;
	cout << "Enter number: " << endl;
	cin >> a;
	int g = Kyb(a);
	cout << "Kyb " << a << " = " << g << endl << endl;

	double d;
	cout << "Enter number: " << endl;
	cin >> d;
	double h = Kyb(d);
	cout << "Kyb " << d << " = " << h << endl << endl;

	// -------- Summa --------------
	int b;
	cout << "Enter first number: " << endl;
	cin >> a;
	cout << "Enter second number: " << endl;
	cin >> b;
	int Si = Sum(a, b);
	cout << a << " + " << b << " = " << Si << endl << endl;

	double e;
	cout << "Enter first number: " << endl;
	cin >> d;
	cout << "Enter second number: " << endl;
	cin >> e;
	double Sj = Sum(d, e);
	cout << d << " + " << e << " = " << Sj << endl << endl;
	
	int c;
	cout << "Enter first number: " << endl;
	cin >> a;
	cout << "Enter second number: " << endl;
	cin >> b;
	cout << "Enter third number: " << endl;
	cin >> c;
	int Sk = Sum(a, b, c);
	cout << a << " + " << b << " + " << c << " = " << Sk << endl << endl;

	double f;
	cout << "Enter first number: " << endl;
	cin >> d;
	cout << "Enter second number: " << endl;
	cin >> e;
	cout << "Enter third number: " << endl;
	cin >> f;
	double Sl = Sum(d, e, f);
	cout << d << " + " << e << " + " << f << " = " << Sl << endl << endl;


	// -------- Product --------------
	cout << "Enter first number: " << endl;
	cin >> a;
	cout << "Enter second number: " << endl;
	cin >> b;
	int Pi = Prod(a, b);
	cout << a << " * " << b << " = " << Pi << endl << endl;

	cout << "Enter first number: " << endl;
	cin >> d;
	cout << "Enter second number: " << endl;
	cin >> e;
	double Pj = Prod(d, e);
	cout << d << " * " << e << " = " << Pj << endl << endl;

	cout << "Enter first number: " << endl;
	cin >> a;
	cout << "Enter second number: " << endl;
	cin >> b;
	cout << "Enter third number: " << endl;
	cin >> c;
	int Pk = Prod(a, b, c);
	cout << a << " * " << b << " * " << c << " = " << Pk << endl << endl;

	cout << "Enter first number: " << endl;
	cin >> d;
	cout << "Enter second number: " << endl;
	cin >> e;
	cout << "Enter third number: " << endl;
	cin >> f;
	double Pl = Prod(d, e, f);
	cout << d << " * " << e << " * " << f << " = " << Pl << endl << endl;


	// -------- Min --------------
	cout << "Enter first number: " << endl;
	cin >> a;
	cout << "Enter second number: " << endl;
	cin >> b;
	int Mni = Min(a, b);
	cout <<"Min = " << Mni << endl << endl;

	cout << "Enter first number: " << endl;
	cin >> d;
	cout << "Enter second number: " << endl;
	cin >> e;
	double Mnj = Min(d, e);
	cout <<"Min = " << Mnj << endl << endl;

	cout << "Enter first number: " << endl;
	cin >> a;
	cout << "Enter second number: " << endl;
	cin >> b;
	cout << "Enter third number: " << endl;
	cin >> c;
	int Mnk = Min(a, b, c);
	cout << "Min = " << Mnk << endl << endl;

	cout << "Enter first number: " << endl;
	cin >> d;
	cout << "Enter second number: " << endl;
	cin >> e;
	cout << "Enter third number: " << endl;
	cin >> f;
	double Mnl = Min(d, e, f);
	cout << "Min = " << Mnl << endl << endl;


	// -------- Max --------------
	cout << "Enter first number: " << endl;
	cin >> a;
	cout << "Enter second number: " << endl;
	cin >> b;
	int Mxi = Max(a, b);
	cout << "Max = " << Mxi << endl << endl;

	cout << "Enter first number: " << endl;
	cin >> d;
	cout << "Enter second number: " << endl;
	cin >> e;
	double Mxj = Max(d, e);
	cout << "Max = " << Mxj << endl << endl;

	cout << "Enter first number: " << endl;
	cin >> a;
	cout << "Enter second number: " << endl;
	cin >> b;
	cout << "Enter third number: " << endl;
	cin >> c;
	int Mxk = Max(a, b, c);
	cout << "Max = " << Mxk << endl << endl;

	cout << "Enter first number: " << endl;
	cin >> d;
	cout << "Enter second number: " << endl;
	cin >> e;
	cout << "Enter third number: " << endl;
	cin >> f;
	double Mxl = Max(d, e, f);
	cout << "Max = " << Mxl << endl << endl;

	system("pause");
}