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
	--size;
	f.close();
	f.open("..\\files\\f.txt");
	char **mas = new char*[size];
	for (int i = 0; i < size; ++i)
		mas[i] = new char[256];
	for (int i = 0; i < size; ++i)
		f.getline(mas[i], 256);
	f.close();
	ofstream f2;
	f2.open("..\\files\\new.txt");
	for (int i = 0; i < size; ++i)
		f2 << mas[i] << endl;
	f2.close();
	delete[]mas;
	system("pause");
	return 0;
}