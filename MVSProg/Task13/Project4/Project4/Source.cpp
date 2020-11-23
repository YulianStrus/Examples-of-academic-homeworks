#include "iostream"
using namespace std;
void main()
{
	int a, b;
	char s;
	cout << "input count of colun "; cin >> a; cout << endl;
	cout << "input count of row "; cin >> b; cout << endl;
	cout << "input symbol"; cin >> s; cout << endl;
	int i = 1, j = 1;
	while (true)
	{
		if (i < a + 1)
		{
			if (j == 1 || j == b)
			{
				cout << s;
				++i;
			}
			if (j > 1 && j < b)
			{
				if (i == 1 || i == a)
				{
					cout << s;
					++i;
				}
				else
				{
					cout << " ";
					++i;
				} 
			}
		}
		else
		{
			j++;
			i = 1;
			cout << endl;
		} 
	}
	
	system("pause");
}