#include "iostream"
#include "cstdio"
#include "fstream"
using namespace std;

int main()
{
	ifstream f;
	f.open("..\\files\\f.txt");
	int k = 0;
	while (!f.eof())
	{
		if (f.get() == '\n')
			continue;
		++k;
	}
	cout << "Char number is: " << k << endl;
	f.close();
	system("pause");
	return 0;
}