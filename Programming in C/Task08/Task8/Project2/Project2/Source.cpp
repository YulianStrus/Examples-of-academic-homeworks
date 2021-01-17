#include "iostream"
using namespace std;
int main()
{
	float x, x1, x2, x3; int n, n1, n2, n3;
	cout << "Enter the weight of the cake (gram) " << endl;
	cin >> x;
	cout << "Enter the weight of the first fat man (kilogram)" << endl;
	cin >> x1;
	cout << "Enter the weight of the second fat man (kilogram)" << endl;
	cin >> x2;
	cout << "Enter the weight of the third fat man (kilogram)" << endl;
	cin >> x3;
	n1 = x1 / 2 / (x / 1000);
	n2 = x2 / 2 / (x / 1000);
	n3 = x3 / 2 / (x / 1000);
	if ((n1 < n2) && (n1 < n3)) { n2 = n1 * 2; n3 = n1 * 4; }
	else if ((n2 < n1) && (n2 < n3)) { n1 = n2 / 2; n3 = n2 * 2; }
	else if ((n3 < n1) && (n3 < n2)) { n1 = n3 / 4; n2 = n3 / 2; }
	n = n1 + n2 + n3;
	cout << "Fat men ate " << n << " cakes" << endl;
	system("pause");
	return 0;
}