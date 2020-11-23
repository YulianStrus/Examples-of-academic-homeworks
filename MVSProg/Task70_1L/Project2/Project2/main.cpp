#include "iostream"
#include "fstream"
using namespace std;

class Fraction
{
protected:
	int Num;
	int Denom;
public:
	Fraction() { Num = 1; Denom = 1; }
	Fraction(int a, int b) { Num = a; Denom = b; }
	void SetNum(int a) { Num = a; }
	void SetDem(int b) { Denom = b; }
	int GetNum() { return Num; }
	int GetDem() { return Denom; }
	Fraction operator+(Fraction&obj)
	{
		if (Num < 0 && Denom < 0) { Num = -Num; Denom = -Denom; }
		if (obj.Num < 0 && obj.Denom < 0) { obj.Num = -obj.Num; obj.Denom = -obj.Denom; }
		int Num_temp, Denom_temp;
		Num_temp = Num * obj.Denom + obj.Num * Denom;
		if (Num_temp < 0) Num_temp = -Num_temp;
		Denom_temp = Denom * obj.Denom;
		if (Denom_temp < 0) Denom_temp = -Denom_temp;
		for (int i = 2; i <= Num_temp; ++i)
		{
			if (Num_temp % i == 0)
			{
				if (Denom_temp % i == 0)
				{
					Num_temp /= i;
					Denom_temp /= i;
					i = 1;
				}
			}
		}
		if ((Num * obj.Denom + obj.Num * Denom) < 0) Num_temp = -Num_temp;
		if (Denom*obj.Denom < 0)Denom_temp = -Denom_temp;
		return Fraction(Num_temp, Denom_temp);

	}
	Fraction operator-(Fraction&obj)
	{
		if (Num < 0 && Denom < 0) { Num = -Num; Denom = -Denom; }
		if (obj.Num < 0 && obj.Denom < 0) { obj.Num = -obj.Num; obj.Denom = -obj.Denom; }
		int Num_temp, Denom_temp;
		Num_temp = Num * obj.Denom - obj.Num * Denom;
		if (Num_temp < 0) Num_temp = -Num_temp;
		Denom_temp = Denom * obj.Denom;
		if (Denom_temp < 0) Denom_temp = -Denom_temp;
		for (int i = 2; i <= Num_temp; ++i)
		{
			if (Num_temp % i == 0)
			{
				if (Denom_temp % i == 0)
				{
					Num_temp /= i;
					Denom_temp /= i;
					i = 1;
				}
			}
		}
		if ((Num * obj.Denom - obj.Num * Denom) < 0) Num_temp = -Num_temp;
		if (Denom*obj.Denom < 0)Denom_temp = -Denom_temp;
		return Fraction(Num_temp, Denom_temp);

	}
	Fraction operator*(Fraction&obj)
	{
		if (Num < 0 && Denom < 0) { Num = -Num; Denom = -Denom; }
		if (obj.Num < 0 && obj.Denom < 0) { obj.Num = -obj.Num; obj.Denom = -obj.Denom; }
		int Num_temp, Denom_temp;
		Num_temp = Num * obj.Num;
		if (Num_temp < 0) Num_temp = -Num_temp;
		Denom_temp = Denom * obj.Denom;
		if (Denom_temp < 0) Denom_temp = -Denom_temp;
		for (int i = 2; i <= Num_temp; ++i)
		{
			if (Num_temp % i == 0)
			{
				if (Denom_temp % i == 0)
				{
					Num_temp /= i;
					Denom_temp /= i;
					i = 1;
				}
			}
		}
		if (Num * obj.Num < 0) Num_temp = -Num_temp;
		if (Denom*obj.Denom < 0)Denom_temp = -Denom_temp;
		return Fraction(Num_temp, Denom_temp);

	}
	Fraction operator/(Fraction&obj)
	{
		if (Num < 0 && Denom < 0) { Num = -Num; Denom = -Denom; }
		if (obj.Num < 0 && obj.Denom < 0) { obj.Num = -obj.Num; obj.Denom = -obj.Denom; }
		int Num_temp, Denom_temp;
		Num_temp = Num * obj.Denom;
		if (Num_temp < 0) Num_temp = -Num_temp;
		Denom_temp = Denom * obj.Num;
		if (Denom_temp < 0) Denom_temp = -Denom_temp;
		for (int i = 2; i <= Num_temp; ++i)
		{
			if (Num_temp % i == 0)
			{
				if (Denom_temp % i == 0)
				{
					Num_temp /= i;
					Denom_temp /= i;
					i = 1;
				}
			}
		}
		if (Num * obj.Denom < 0) Num_temp = -Num_temp;
		if (Denom*obj.Num < 0)Denom_temp = -Denom_temp;
		return Fraction(Num_temp, Denom_temp);

	}
	void Show()
	{
		cout << Num << "/" << Denom;
	}
	void save(const char *filename)
	{
		ofstream fout(filename, ios::trunc | ios::binary);
		fout.write((char*)&Num, sizeof(int));
		fout.write((char*)&Denom, sizeof(int));
		fout.close();
	}	void open(const char *filename)
	{
		ifstream fin(filename, ios::in | ios::binary);
		fin.read((char*)&Num, sizeof(int));
		fin.read((char*)&Denom, sizeof(int));
		fin.close();
	}
};

int main()
{
	Fraction Num(7, 9);
	Fraction Num1(3, 5);
	Num.save("file.dat");
	Fraction Num2;
	Num2.open("file.dat");
	Fraction Num3;
	Num3 = Num1 + Num2;
	Num1.Show();	cout << " + "; Num2.Show(); cout << " = ";	Num3.Show();
	cout << endl;
	Num3 = Num1 - Num2;
	Num1.Show();	cout << " - "; Num2.Show(); cout << " = ";	Num3.Show();
	cout << endl;
	Num3 = Num1 * Num2;
	Num1.Show();	cout << " * "; Num2.Show(); cout << " = ";	Num3.Show();
	cout << endl;
	Num3 = Num1 / Num2;
	Num1.Show();	cout << " / "; Num2.Show(); cout << " = ";	Num3.Show();
	cout << endl;

	system("pause");
	return 0;
}