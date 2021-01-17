#include "iostream"
using namespace std;

int main()
{
	char str[128];
	cout << "Enter string: ";
	gets_s(str);
	cout << "String: " << str << endl;
	int W = 0;
	char *p = strtok(str, ".,!? ");
	while (p != NULL)
	{
		W++; p = strtok(NULL, ".,!? ");
	}
	cout << "Number word = " << W << endl;

	system("pause");
	return 0;
}