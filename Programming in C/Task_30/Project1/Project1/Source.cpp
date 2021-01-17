#include "iostream"
#include "cstdio"
#include "fstream"
using namespace std;

int main()
{
	int k;
	char s, m = 0;
	while (m != 'q')
	{
		cout << "1 - Coded" << "\n2 - Decoded" << "\nq - Quit" << endl << endl;;
		cin >> m;
		switch (m)
		{
		case '1':
			cout << "Enter key number (3 - 10): ";
			cin >> k;
			if (k >= 3 && k <= 10)
			{
				ifstream f1;
				ofstream f2;
				f1.open("..\\files\\orign.txt");
				f2.open("..\\files\\cod.txt");
				while (!f1.eof())
				{

					s = f1.get();
					if (s == EOF) break;
					else if (s == ' ' || s == '\n') f2.put(s);
					else
					{
						s += k;
						f2.put(s);
					}
				}
				f1.close();
				f2.close();
				cout << endl;
			}
			else cout << "Error! Enter key number from 3 to 10" << endl << endl;;
			break;

		case '2':
			cout << "Enter key number (3 - 10): ";
			cin >> k;
			if (k >= 3 && k <= 10)
			{
				ifstream f3;
				ofstream f4;
				f3.open("..\\files\\cod.txt");
				f4.open("..\\files\\decod.txt");
				while (!f3.eof())
				{

					s = f3.get();
					if (s == EOF) break;
					else if (s == ' ' || s == '\n') f4.put(s);
					else
					{
						s -= k;
						f4.put(s);
					}
				}
				f3.close();
				f4.close();
				cout << endl;
			}
			else cout << "Error! Enter key number from 3 to 10" << endl << endl;;
			break;
		case 'q': break;
		}
	}
	system("pause");
	return 0;
}