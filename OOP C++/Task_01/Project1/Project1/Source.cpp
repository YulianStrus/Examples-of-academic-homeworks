#include "iostream"
#include "cmath"
using namespace std;

class Fraction
{
private:
	int Num;
	int Denom;
public:
	Fraction(int a, int b) { Num = a; Denom = b; }
	void SetNum(int a) { Num = a; }
	void SetDem(int b) { Denom = b; }
	int GetNum() { return Num; }
	int GetDem() { return Denom; }
	int SumNum(int a1, int b1, int a2, int b2)
	{
		int Num, Denom;
		Num = a1 * b2 + a2 * b1;
		if (Num < 0) Num = -Num;
		Denom = b1 * b2;
		if (Denom < 0) Denom = -Denom;
		for (int i = 2; i <= Num; ++i)
		{
			if (Num % i == 0)
			{
				if (Denom % i == 0)
				{
					Num /= i;
					Denom /= i;
					i = 1;
				}
			}
		}
		if ((a1 * b2 + a2 * b1) < 0) return -Num;
		else return Num;
	}
	int SumDem(int a1, int b1, int a2, int b2)
	{
		int Num, Denom;
		Num = a1 * b2 + a2 * b1;
		if (Num < 0) Num = -Num;
		Denom = b1 * b2;
		if (Denom < 0) Denom = -Denom;
		for (int i = 2; i <= Num; ++i)
		{
			if (Num % i == 0)
			{
				if (Denom % i == 0)
				{
					Num /= i;
					Denom /= i;
					i = 1;
				}
			}
		}
		if (b1 * b2 < 0) return -Denom;
		else return Denom;
	}
	int SubNum(int a1, int b1, int a2, int b2)
	{
		int Num, Denom;
		Num = a1 * b2 - a2 * b1;
		if (Num < 0) Num = -Num;
		Denom = b1 * b2;
		if (Denom < 0) Denom = -Denom;
		for (int i = 2; i <= Num; ++i)
		{
			if (Num % i == 0)
			{
				if (Denom % i == 0)
				{
					Num /= i;
					Denom /= i;
					i = 1;
				}
			}
		}
		if ((a1 * b2 - a2 * b1) < 0) return -Num;
		else return Num;
	}
	int SubDem(int a1, int b1, int a2, int b2)
	{
		int Num, Denom;
		Num = a1 * b2 - a2 * b1;
		if (Num < 0) Num = -Num;
		Denom = b1 * b2;
		if (Denom < 0) Denom = -Denom;
		for (int i = 2; i <= Num; ++i)
		{
			if (Num % i == 0)
			{
				if (Denom % i == 0)
				{
					Num /= i;
					Denom /= i;
					i = 1;
				}
			}
		}
		if (b1 * b2 < 0) return -Denom;
		return Denom;
	}
	int MultiNum(int a1, int b1, int a2, int b2)
	{
		int Num, Denom;
		Num = a1 * a2;
		if (Num < 0) Num = -Num;
		Denom = b1 * b2;
		if (Denom < 0) Denom = -Denom;
		for (int i = 2; i <= Num; ++i)
		{
			if (Num % i == 0)
			{
				if (Denom % i == 0)
				{
					Num /= i;
					Denom /= i;
					i = 1;
				}
			}
		}
		if ((a1 * a2) < 0) return -Num;
		return Num;
	}
	int MultiDem(int a1, int b1, int a2, int b2)
	{
		int Num, Denom;
		Num = a1 * a2;
		if (Num < 0) Num = -Num;
		Denom = b1 * b2;
		if (Denom < 0) Denom = -Denom;
		for (int i = 2; i <= Num; ++i)
		{
			if (Num % i == 0)
			{
				if (Denom % i == 0)
				{
					Num /= i;
					Denom /= i;
					i = 1;
				}
			}
		}
		if (b1 * b2 < 0) return -Denom;
		else return Denom;
	}
	int DivNum(int a1, int b1, int a2, int b2)
	{
		int Num, Denom;
		Num = a1 * b2;
		if (Num < 0) Num = -Num;
		Denom = b1 * a2;
		if (Denom < 0) Denom = -Denom;
		for (int i = 2; i <= Num; ++i)
		{
			if (Num % i == 0)
			{
				if (Denom % i == 0)
				{
					Num /= i;
					Denom /= i;
					i = 1;
				}
			}
		}
		if (a1*b2 < 0) return -Num;
		else return Num;
	}
	int DivDem(int a1, int b1, int a2, int b2)
	{
		int Num, Denom;
		Num = a1 * b2;
		if (Num < 0) Num = -Num;
		Denom = b1 * a2;
		if (Denom < 0) Denom = -Denom;
		for (int i = 2; i <= Num; ++i)
		{
			if (Num % i == 0)
			{
				if (Denom % i == 0)
				{
					Num /= i;
					Denom /= i;
					i = 1;
				}
			}
		}
		if (b1 * a2 < 0) return -Denom;
		else return Denom;
	}
};

int main()
{
	int a, b;
	char x = 0;
	while (x != 'q')
	{
		cout << "Enter first number: " << endl;
		cout << "Numerator: ";
		cin >> a;
		cout << "Denominator: ";
		cin >> b;
		Fraction Number1(a, b);
		cout << "Enter second number: " << endl;
		cout << "Numerator: ";
		cin >> a;
		cout << "Denominator: ";
		cin >> b;
		Fraction Number2(a, b);
		cout << "Enter operation \n\t'+'\n\t'-'\n\t'*'\n\t'/'\n\tq - quit: ";
		cin >> x;
		switch (x)
		{
		case '+':	cout << Number1.GetNum() << "/" << Number1.GetDem() << " + " << Number2.GetNum() << "/" << Number2.GetDem() << " = " << Number1.SumNum(Number1.GetNum(), Number1.GetDem(), Number2.GetNum(), Number2.GetDem()) << "/" << Number1.SumDem(Number1.GetNum(), Number1.GetDem(), Number2.GetNum(), Number2.GetDem()) << endl; break;
		case '-':	cout << Number1.GetNum() << "/" << Number1.GetDem() << " - " << Number2.GetNum() << "/" << Number2.GetDem() << " = " << Number1.SubNum(Number1.GetNum(), Number1.GetDem(), Number2.GetNum(), Number2.GetDem()) << "/" << Number1.SubDem(Number1.GetNum(), Number1.GetDem(), Number2.GetNum(), Number2.GetDem()) << endl; break;
		case '*':	cout << Number1.GetNum() << "/" << Number1.GetDem() << " * " << Number2.GetNum() << "/" << Number2.GetDem() << " = " << Number1.MultiNum(Number1.GetNum(), Number1.GetDem(), Number2.GetNum(), Number2.GetDem()) << "/" << Number1.MultiDem(Number1.GetNum(), Number1.GetDem(), Number2.GetNum(), Number2.GetDem()) << endl; break;
		case '/':	cout << Number1.GetNum() << "/" << Number1.GetDem() << " / " << Number2.GetNum() << "/" << Number2.GetDem() << " = " << Number1.DivNum(Number1.GetNum(), Number1.GetDem(), Number2.GetNum(), Number2.GetDem()) << "/" << Number1.DivDem(Number1.GetNum(), Number1.GetDem(), Number2.GetNum(), Number2.GetDem()) << endl; break;
		case 'q': break;
		}
	}
	system("pause");
	return 0;
}