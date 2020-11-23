#include "iostream"
#include "Namespace.h"
using namespace std;

int main()
{
	cout << "\n\n\tNamespace: \tFraction" << endl << endl;
	fraction::Fraction Number1(3, 5);
	fraction::Fraction Number2(7, 5);
	cout << Number1.GetNum() << "/" << Number1.GetDem() << " + " << Number2.GetNum() << "/" << Number2.GetDem() << " = " << Number1.SumNum(Number1.GetNum(), Number1.GetDem(), Number2.GetNum(), Number2.GetDem()) << "/" << Number1.SumDem(Number1.GetNum(), Number1.GetDem(), Number2.GetNum(), Number2.GetDem()) << endl;
	cout << Number1.GetNum() << "/" << Number1.GetDem() << " - " << Number2.GetNum() << "/" << Number2.GetDem() << " = " << Number1.SubNum(Number1.GetNum(), Number1.GetDem(), Number2.GetNum(), Number2.GetDem()) << "/" << Number1.SubDem(Number1.GetNum(), Number1.GetDem(), Number2.GetNum(), Number2.GetDem()) << endl;
	cout << Number1.GetNum() << "/" << Number1.GetDem() << " * " << Number2.GetNum() << "/" << Number2.GetDem() << " = " << Number1.MultiNum(Number1.GetNum(), Number1.GetDem(), Number2.GetNum(), Number2.GetDem()) << "/" << Number1.MultiDem(Number1.GetNum(), Number1.GetDem(), Number2.GetNum(), Number2.GetDem()) << endl;
	cout << Number1.GetNum() << "/" << Number1.GetDem() << " / " << Number2.GetNum() << "/" << Number2.GetDem() << " = " << Number1.DivNum(Number1.GetNum(), Number1.GetDem(), Number2.GetNum(), Number2.GetDem()) << "/" << Number1.DivDem(Number1.GetNum(), Number1.GetDem(), Number2.GetNum(), Number2.GetDem()) << endl;
	cout << endl << endl;


	cout << "\n\n\tNamespace: \tVector2D" << endl << endl;
	fraction::Vector2d v1(4, 6);
	fraction::Vector2d v2(7, 9);
	fraction::Vector2d v3;
	v3 = v1 + v2;
	v1.Show();
	cout << " + ";
	v2.Show();
	cout << " = ";
	v3.Show();
	cout << endl << endl;
	fraction::Vector2d v4;
	v4 = v1 - v2;
	v1.Show();
	cout << " - ";
	v2.Show();
	cout << " = ";
	v4.Show();
	cout << endl << endl;
	cout << "\n\n\tNamespace: \tPoint" << endl << endl;
	fraction::Point p(9, 5, 1);
	p.Show();
	cout << endl << endl;

	system("pause");
	return 0;
}