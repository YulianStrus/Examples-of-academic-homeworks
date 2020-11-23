#include "iostream"
using namespace std;
template <typename T>
T MinNum(T a, T b, T c=5)
{
	if ((a < b)&(a < c)) return a;
	else if ((b < a)&(b < c)) return b;
	else if ((c < a)&(c < b)) return c;
}

int main()
{
	double Min = MinNum(5.6, 4.5);
	cout << Min << endl;

	system("pause");
}