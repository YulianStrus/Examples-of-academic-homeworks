#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class String
{
	char *str;
	int len;
public:
	String() { len = 81; str = new char[len]; strcpy(str, "It`s first string");}
	String(int x) { len = x + 1; str = new char[len]; strcpy(this->str, str); }
	~String() { delete[] str; }
	void Enter() { cout << "Enter line = "; cin.ignore(); gets_s(str, len); }
	void Show() { cout << "You to enter line = "; cout << str << endl; }
	String(const String& S) { this ->len = S.len; str = new char[len + 1]; strcpy(S.str, str); }
};

int main() 
{
	int size=40;
	String line;
	line.Show();
	cout << "Size line = ";
	cin >> size;
	String line2(size);
	line2.Enter();
	line2.Show();

	system("pause");
	return 0;
}