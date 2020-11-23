#include "iostream"
#include "cstdio"
#include "fstream"
using namespace std;

int main()
{
	int size = 5;
	char **mas = new char*[size];
	for (int i = 0; i < size; ++i)
		mas[i] = new char[256];
	for (int i = 0; i < size; ++i)
	{
		cout << "Please enter " << i + 1 << " string" << endl;
		gets_s(mas[i], 256);
	}
	for (int i = 0; i < size; i++)
		cout << mas[i] << endl;
	ofstream f;
	f.open("..\\files\\f.txt");
	for (int i = 0; i < size; i++)
		f << mas[i] << endl;
	f.close();
	delete[]mas;
	return 0;
}