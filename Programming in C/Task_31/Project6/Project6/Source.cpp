#include "iostream"
#include "cstdio"
#include "fstream"
using namespace std;

int main()
{
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
	int len;
	len = strlen(mas[0]);
	for (int i = 1; i < size; ++i)
		if (len < strlen(mas[i])) len = strlen(mas[i]);
	cout << "The longest line = " << len << endl;
	delete[]mas;
	system("pause");
	return 0;
}