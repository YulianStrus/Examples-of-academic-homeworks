#include "iostream"
using namespace std;
void main()
{
	int w, h;
	char s;
	cout << "Enter width" << endl;
	cin >> w;
	cout << "Enter heidth " << endl;
	cin >> h;
	cout << "Enter symbol " << endl;
	cin >> s;
	for (int i = 0; i<h / 2; i++)
	{
		for (int j = 0; j<w; j++)
		{
			if (j >= (w / 2 - (int)i*((double)w / h)) && j <= (w / 2 + (int)i*((double)w / h)))
			{
				cout << s;
			}
			else
			{
				cout << ' ';
			}
		}
		cout << endl;
	}
	for (int i = h / 2; i >= 0; i--)
	{
		for (int j = 0; j<w; j++)
		{
			if (j >= (w / 2 - (int)i*((double)w / h)) && j <= (w / 2 + (int)i*((double)w / h)))
			{
				cout << s;
			}
			else
			{
				cout << ' ';
			}
		}
		cout << endl;
	}
	system("pause");
}
