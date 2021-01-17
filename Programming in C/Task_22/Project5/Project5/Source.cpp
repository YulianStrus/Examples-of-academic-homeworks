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
	char tmp[8] = "aeyuioj";
	while (p != NULL)
	{
		W = strspn(p, tmp);
		if (W == 0) cout << p << endl;
		p = strtok(NULL, ".,!? ");
	}
	

	system("pause");
	return 0;
}