#include "iostream"
using namespace std;
void main()
{
	float a, b, c;
	cout << "Number of students who passed the exam ";
	cin >> a;
	cout << "Number of debtors ";
	cin >> b;
	c = 100 / (a+b) * a;
	b = 100 - c;
	cout << "Number of students who passed the exam = " << c << "\%\nNumber of debtors = " << b << "\%" << endl;
	system("pause");
}
