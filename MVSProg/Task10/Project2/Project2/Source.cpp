#include <iostream> 
using namespace std;

void main()
{
	double P, N, S;
	cout << "Enter the maximum number of points ";
	cin >> S;
	cout << "Enter the number of student points ";
	cin >> N;
	P = N / S * 100;
	P >= 92 ? (P = 12):(P >= 70 ? (P = 8) : (P >= 50 ? P = 5 : P = 2));
	cout << "student rating = " << P << endl;
	system("pause");
}
