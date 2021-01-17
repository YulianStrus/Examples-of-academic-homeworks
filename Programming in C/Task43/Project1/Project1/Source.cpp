#include "iostream"
#include "cstdio"
#include "fstream"
using namespace std;

int main()
{
	ofstream f;
	f.open("..\\files\\f.txt");
	f << "Hello world";
	f.close();
	return 0;
}