#include "iostream"
using namespace std;
template <typename T>
T MaxNum(T a, T b)
{
	if (a > b) return a;
	else return b;
}

int main()
{
	char Max = MaxNum('c', 'x');
	cout << Max << endl;

	system("pause");
}