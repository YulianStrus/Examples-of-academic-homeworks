#include "iostream"
using namespace std;

int main()
{
	char str[128];
	cout << "Enter string: ";
	gets_s(str);
	cout << "String: " << str << endl;
	char *p = strtok(str, ".,!? '");
	char *tmp = p;
	int n = strlen(tmp);
	while (p != NULL)
	{
		int W = strnicmp(tmp, p, n);
		if (W == 0) cout << p << endl;
		p = strtok(NULL, ".,!? ");
	}


	system("pause");
	return 0;
}