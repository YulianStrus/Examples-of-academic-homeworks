#include "iostream"
using namespace std;
void main()
{
	int a, b, c, d, e, sum;
	cout << "Input first digit ";
	cin >> a;
	cout << "Input first digit ";
	cin >> b;
	cout << "Input first digit ";
	cin >> c;
	cout << "Input first digit ";
	cin >> d;
	cout << "Input first digit ";
	cin >> e;
	sum = (a + b + c + d + e) / 5;
	if (sum >= 4) cout << "The student is admitted to the exam" << endl; else cout << "Student is not allowed to take the exam" << endl;
	system("pause");
}
