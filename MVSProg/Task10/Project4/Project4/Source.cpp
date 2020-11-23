#include "iostream"
using namespace std;

int main()
{
	int a, b, c, K, K1, K2, S, Sk, Sc;
	cout << "Enter the length of the room " << endl;
	cin >> a;
	cout << "Enter the width of the room " << endl;
	cin >> b;
	cout << "Enter the length of the carpet side" << endl;
	cin >> c;
	if ((a > c) && (b > c)) { (K1 = a / c); (K2 = b / c); } else cout << "This carpet is too big";
	K = K1 * K2;
	Sk = a * b;
	Sc = K * (c*c);
	S = Sk - Sc;
	cout << K << " carpets need to be bought" << endl;
	cout << S << "m2 of the area will be uncovered" << endl;
	system("pause");
}
