#include "iostream"
using namespace std;


void main()
{
	int *a = new int(5);
	double *b = new double (3.2);
	float *c = new float(8.4);

	cout << "a= " << *a << endl;
	cout << "b= " << *b << endl;
	cout << "c= " << *c << endl;

	double Prod = *a**b**c;
	
	cout << "a*b*c= " << Prod << endl;
	
	delete a;
	delete b;
	delete c;

	system("pause");
}
