#include "iostream"
#include "cstdio"
#include "fstream"
using namespace std;

int main()
{
	char l;
	cout << "Please enter letter: ";
	cin >> l;
	ifstream f;
	f.open("..\\files\\f.txt");
	int size = 0;
	while (!f.eof())
	{
		if (f.get() == '\n') ++size;
	}
	f.close();
	f.open("..\\files\\f.txt");
	char **mas = new char*[size];
	for (int i = 0; i < size; ++i)
		mas[i] = new char[256];
	for (int i = 0; i < size; ++i)
		f.getline(mas[i], 256);
	f.close();
	cout << endl;
	int len;
	int k = 0;
	for (int i = 0; i < size; ++i)
	{
		if (mas[i][0] == l) ++k;
		len = strlen(mas[i]);
		for (int j = 1; j < len; ++j)
		{
			if (mas[i][j] == ' ' || mas[i][j] == ',' || mas[i][j] == '.' || mas[i][j] == '!' || mas[i][j] == '?')
				if (mas[i][k + 1] == l)++k;
		}
	}
	cout << "The number of words that begin with " << "\"" <<l << "\" = " << k << endl;
	delete[]mas;
	system("pause");
	return 0;
}