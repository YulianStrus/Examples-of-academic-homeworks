#include "iostream"
using namespace std;
void main()
{
	

	cout << "Version a: " << endl;
	double Sa = 100, Ua = 20, Ya, n = 2;
	do
	{
		Sa = Sa + (Sa * 5 / 100);
		Ua = Ua + (Ua * 2 / 100);
		Ya = Ua * Sa;
		cout <<"In " << n << " years, crop capacity = " << Ya << " centners" << endl;
		++n;
	} while (n <= 8);
	cout << endl;
	
	cout << "Version b: " << endl;
	double Sb = 110.25, i = 4;
	do
	{
		Sb = Sb + (Sb * 5 / 100);
		
		cout << "In " << i << " years, area = " << Sb << " hectares" << endl;
		++i;
	} while (i <= 8);
	cout << endl;

	cout << "Version c: " << endl;
	double Sc = 100, Uc = 20, Yc, Pc = 2000, j = 2;
	do
	{
		Sc = Sc + (Sc * 5 / 100);
		Uc = Uc + (Uc * 2 / 100);
		Yc = Uc * Sc;
		Pc = Pc + Yc;
		++j;
	} while (j <= 6);	
	cout << "For the first 6 years, the pain was collected = " << Pc << " centners" << endl << endl;

	cout << "Version d: " << endl;
	double Ud = 20, m = 1;
	do
	{
		Ud = Ud + (Ud * 2 / 100);
		++m;
	} while (Ud < 22);
	cout << "In " << m << " year, crop capacity > 22 centners" << endl << endl;

	cout << "Version e: " << endl;
	double Se = 100, o = 1;
	do
	{
		Se = Se + (Se * 5 / 100);
		++o;
	} while (Se <= 120);
	cout << "In " << o << " year, area > 120 hectares" << endl << endl;

	cout << "Version f: " << endl;
	double Uf = 20, Pf = 20, k = 2;
	do
	{
		Uf = Uf + (Uf * 2 / 100);
		Pf = Pf + Uf;
		++k;
	} while (Pf < 800);
	cout << "In " << k << " year, total harvest collected for all time > 800 centners per hectare" << endl << endl;

	system("pause");
}