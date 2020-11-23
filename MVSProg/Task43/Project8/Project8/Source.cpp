#include "iostream"
#include "cstdio"
#include "fstream"
using namespace std;

int main()
{
	ifstream f;
	ofstream n;
	f.open("..\\files\\f.txt");
	n.open("..\\files\\n.txt");
	char s;
	while (!f.eof())
	{
		s = f.get();
		if (s == EOF) break;
		else if (s == '1')
		{
			n.put('0');
			continue;
		}
		else if (s == '0') n.put('1');
		else n.put(s);
	}
	f.close();
	n.close();
	system("pause");
	return 0;
}