#include "iostream"
#include "cstdio"
#include "fstream"
using namespace std;

int main()
{
	char n, s, m = '0', k[4];
	int count = 0;
	while (m != 'q')
	{
		cout << "1 - Coded" << "\n2 - Decoded" << "\nq - Quit" << endl << endl;
		cin >> m;
		cin.ignore();
		//		switch (m)			//Не працює
		//		{
		//		case '1':
		if (m == '1')
		{
			cout << "Enter key number (3 - 10): ";
			gets_s(k, 4);
			ifstream o;
			ofstream c;

			o.open("..\\files\\orign.txt");
			c.open("..\\files\\cod.txt");
			while (!o.eof())
			{

				s = o.get();
				if (s == EOF) break;
				else if (s == '\n') c.put(s);
				else
				{
					if (count >= 3) count = 0;
					n = s ^ k[count];
					if (n == '\n' || n == '\t' || n == '\v' || n == '\b' || n == EOF) c.put(s);
					else c.put(n);
					++count;
				}
			}
			count = 0;
			o.close();
			c.close();
			//			break;
		}
		//		case '2':
		if (m == '2')
		{
			cout << "Enter key number (3 - 10): ";
			gets_s(k, 4);
			ifstream c;
			ofstream d;
			c.open("..\\files\\cod.txt");
			d.open("..\\files\\decod.txt");
			while (!c.eof())
			{

				s = c.get();
				if (s == EOF) break;
				else if (s == '\n') d.put(s);
				else

				{
					if (count == 3) count = 0;
					n = s ^ k[count];
					if (n == '\n' || n == '\t' || n == '\v' || n == '\b' || n == '\r')d.put(s);
					else d.put(n);
					++count;
				}
			}
			c.close();
			d.close();
			//			break;
		}

		//		case 'q': break;

	}
	system("pause");
	return 0;
}